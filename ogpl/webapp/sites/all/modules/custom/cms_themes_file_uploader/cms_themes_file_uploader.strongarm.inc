<?php

/**
 * Implementation of hook_strongarm().
 */
function cms_themes_file_uploader_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_theme_file_uploader';
  $strongarm->value = '0';
  $export['comment_anonymous_theme_file_uploader'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_theme_file_uploader';
  $strongarm->value = '3';
  $export['comment_controls_theme_file_uploader'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_theme_file_uploader';
  $strongarm->value = '4';
  $export['comment_default_mode_theme_file_uploader'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_theme_file_uploader';
  $strongarm->value = '1';
  $export['comment_default_order_theme_file_uploader'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_theme_file_uploader';
  $strongarm->value = '50';
  $export['comment_default_per_page_theme_file_uploader'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_theme_file_uploader';
  $strongarm->value = '0';
  $export['comment_form_location_theme_file_uploader'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_theme_file_uploader';
  $strongarm->value = '1';
  $export['comment_preview_theme_file_uploader'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_theme_file_uploader';
  $strongarm->value = '1';
  $export['comment_subject_field_theme_file_uploader'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_theme_file_uploader';
  $strongarm->value = '0';
  $export['comment_theme_file_uploader'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_theme_file_uploader';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '0',
    'revision_information' => '20',
    'author' => '20',
    'options' => '25',
    'comment_settings' => '30',
    'menu' => '-2',
    'path' => '30',
    'attachments' => '30',
    'detailed_question' => '10',
    'workflow' => '10',
    'print' => '30',
    'nodewords' => '10',
  );
  $export['content_extra_weights_theme_file_uploader'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_theme_file_uploader';
  $strongarm->value = '0';
  $export['language_content_type_theme_file_uploader'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_theme_file_uploader';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_theme_file_uploader'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_theme_file_uploader';
  $strongarm->value = '1';
  $export['upload_theme_file_uploader'] = $strongarm;

  return $export;
}
