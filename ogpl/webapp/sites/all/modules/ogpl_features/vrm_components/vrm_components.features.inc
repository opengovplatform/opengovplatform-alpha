<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function vrm_components_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => 1);
  }
  elseif ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function vrm_components_node_info() {
  $items = array(
    'feedback' => array(
      'name' => t('Feedback'),
      'module' => 'features',
      'description' => t('Feedback used for Visitors Review Management'),
      'has_title' => '1',
      'title_label' => t('Sender Name'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'feedback_reply' => array(
      'name' => t('Feedback Reply'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Subject'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
    'feedback_review' => array(
      'name' => t('Feedback Review'),
      'module' => 'features',
      'description' => '',
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
function vrm_components_views_api() {
  return array(
    'api' => '2',
  );
}
