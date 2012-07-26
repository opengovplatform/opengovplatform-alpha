<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function ogpl_operator_collaboration_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function ogpl_operator_collaboration_node_info() {
  $items = array(
    'upload_docs' => array(
      'name' => t('Reference Documents'),
      'module' => 'features',
      'description' => t('Document library where the system administrator or PMO can upload arbitrary documents.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Webform'),
      'module' => 'features',
      'description' => t('Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'whats_new' => array(
      'name' => t('What\'s New'),
      'module' => 'features',
      'description' => t('What\'s New notifications (ticker for authenticated users, widget area for anonymous users).'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
