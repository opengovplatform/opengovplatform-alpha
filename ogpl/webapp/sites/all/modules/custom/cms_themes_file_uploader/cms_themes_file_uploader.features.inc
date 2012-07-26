<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cms_themes_file_uploader_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function cms_themes_file_uploader_node_info() {
  $items = array(
    'theme_file_uploader' => array(
      'name' => t('Theme Files'),
      'module' => 'features',
      'description' => t('Theme Files contains css,images,logo used to apply different theme colors and contrast to the site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function cms_themes_file_uploader_views_api() {
  return array(
    'api' => '2',
  );
}
