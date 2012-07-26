<?php
ini_set("memory_limit", "512M");

/**
 * @file
 * An example installation profile that uses a database dump to recreate a
 * Drupal site rather than API function calls of a traditional installation
 * profile.
 */

/**
 * Implementation of hook_profile_modules().
 */
function ogpl2_profile_modules() {
  // The database dump will take care of enabling the required modules for us.
  // Return an empty array to just enable the required modules.
  return array();
}

/**
 * Implementation of hook_profile_details().
 */
function ogpl2_profile_details() {
  $description = st('Select this profile to install the Open Government Platform powering your community website.');
  $description .= '<br/><a href="http://opengovplatform.org/" target="_blank">
                  <img alt="Open Government Platform" title="Open Government Platform"
                  src="./profiles/ogpl/logo.png"/></a>';

  return array(
    'name' => 'OGPL2',
    'description' => $description,
  );
}

/**
 * Implementation of hook_profile_form_alter().
 */
function ogpl2_form_alter(&$form, $form_state, $form_id) {
  // Add an additional submit handler. 
  if ($form_id == 'install_configure') {
    $form['#submit'][] = 'ogpl2_form_submit';
  }
}

/**
 * Custom form submit handler for configuration form.
 *
 * Drops all data from existing database, imports database dump, and restores
 * values entered into configuration form.
 */
function ogpl2_form_submit($form, &$form_state) {
  // Import database dump file.
  $dump_file = dirname(__FILE__) . '/db.sql';
  $success = import_dump($dump_file);

  if (!$success) {
    return;
  }

  $base_url = drupal_detect_baseurl();
  db_query("UPDATE {content_field_ds_reference_url} SET field_ds_reference_url_url = replace(field_ds_reference_url_url, 'http://example.com','$base_url') where 1");
  db_query("UPDATE {content_type_access_type_downloadable} SET field_atd_access_point_url = replace(field_atd_access_point_url, 'http://example.com','$base_url') where 1");
  db_query("UPDATE {download_count} SET referrer = replace(referrer, 'http://example.com', '$base_url') where 1");
  db_query("UPDATE {node_revisions} SET body = replace(body, 'http://example.com', '$base_url') where 1");
  db_query("UPDATE {node_revisions} SET teaser = replace(teaser, 'http://example.com',  '$base_url') where 1");
  db_query("UPDATE {web_download_count} SET access_point_url = replace(access_point_url, 'http://example.com',  '$base_url') where 1");
  db_query("UPDATE {content_type_dataset} SET field_ds_access_url_url = replace(field_ds_access_url_url, 'http://example.com',  '$base_url') where 1");

  variable_set('textsize_cookie_domain', implode('/', explode('/', $_SERVER['PHP_SELF'], -1)) . '/');

  // Now re-set the values they filled in during the previous step.
  variable_set('site_name', $form_state['values']['site_name']);
  variable_set('site_mail', $form_state['values']['site_mail']);
  variable_set('date_default_timezone', $form_state['values']['date_default_timezone']);
  variable_set('clean_url', $form_state['values']['clean_url']);
  variable_set('update_status_module', $form_state['values']['update_status_module']);

  // Perform additional clean-up tasks.
  variable_del('file_directory_temp');

  // Replace their username and password and log them in.
  $name = $form_state['values']['account']['name'];
  $pass = $form_state['values']['account']['pass'];
  $mail = $form_state['values']['account']['mail'];
  db_query("UPDATE {users} SET name = '%s', pass = MD5('%s'), mail = '%s' WHERE uid = 1", $name, $pass, $mail);
  user_authenticate(array('name' => $name, 'pass' => $pass));

  // Finally, redirect them to the front page to show off what they've done.
  drupal_goto('<front>');
}

/// The rest is copy/paste/modify code from demo module. ///

/**
 * Imports a database dump file.
 *
 * @see demo_reset().
 */
function import_dump($filename) {
  // Open dump file.
  if (!file_exists($filename) || !($fp = fopen($filename, 'r'))) {
    drupal_set_message(t('Unable to open dump file %filename.', array('%filename' => $filename)), 'error');
    return FALSE;
  }

  // Drop all existing tables.
  foreach (list_tables() as $table) {
    db_query("DROP TABLE %s", $table);
  }

  // Load data from dump file.
  $success = TRUE;
  $query = '';
  $new_line = TRUE;

  while (!feof($fp)) {
    // Better performance on PHP 5.2.x when leaving out buffer size to
    // fgets().
    $data = fgets($fp);
    if ($data === FALSE) {
      break;
    }
    // Skip empty lines (including lines that start with a comment).
    if ($new_line && ($data == "\n" || !strncmp($data, '--', 2) || !strncmp($data, '#', 1))) {
      continue;
    }

    $query .= $data;
    $len = strlen($data);
    if ($data[$len - 1] == "\n") {
      if ($data[$len - 2] == ';') {
        // Reached the end of a query, now execute it.
        if (!_db_query($query, FALSE)) {
          $success = FALSE;
        }
        $query = '';
      }
      $new_line = TRUE;
    }
    else {
      // Continue adding data from the same line.
      $new_line = FALSE;
    }
  }
  fclose($fp);

  if (!$success) {
    drupal_set_message(t('Failed importing database from %filename.', array('%filename' => $filename)), 'error');
  }

  return $success;
}

/**
 * Returns a list of tables in the active database.
 *
 * Only returns tables whose prefix matches the configured one (or ones, if
 * there are multiple).
 *
 * @see demo_enum_tables()
 */
function list_tables() {
  global $db_prefix;

  $tables = array();

  if (is_array($db_prefix)) {
    // Create a regular expression for table prefix matching.
    $rx = '/^' . implode('|', array_filter($db_prefix)) . '/';
  }
  else if ($db_prefix != '') {
    $rx = '/^' . $db_prefix . '/';
  }

  switch ($GLOBALS['db_type']) {
    case 'mysql':
    case 'mysqli':
      $result = db_query("SHOW TABLES");
      break;

    case 'pgsql':
      $result = db_query("SELECT table_name FROM information_schema.tables WHERE table_schema = '%s'", 'public');
      break;
  }

  while ($table = db_fetch_array($result)) {
    $table = reset($table);
    if (is_array($db_prefix)) {
      // Check if table name matches a configured prefix.
      if (preg_match($rx, $table, $matches)) {
        $table_prefix = $matches[0];
        $plain_table = substr($table, strlen($table_prefix));
        if ($db_prefix[$plain_table] == $table_prefix || $db_prefix['default'] == $table_prefix) {
          $tables[] = $table;
        }
      }
    }
    else if ($db_prefix != '') {
      if (preg_match($rx, $table)) {
        $tables[] = $table;
      }
    }
    else {
      $tables[] = $table;
    }
  }

  return $tables;
}

