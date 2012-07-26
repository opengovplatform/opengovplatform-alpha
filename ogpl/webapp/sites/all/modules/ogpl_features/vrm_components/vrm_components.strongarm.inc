<?php

/**
 * Implementation of hook_strongarm().
 */
function vrm_components_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_feedback';
  $strongarm->value = '0';
  $export['comment_anonymous_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_feedback_reply';
  $strongarm->value = '0';
  $export['comment_anonymous_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_feedback_review';
  $strongarm->value = '0';
  $export['comment_anonymous_feedback_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_feedback';
  $strongarm->value = '3';
  $export['comment_controls_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_feedback_reply';
  $strongarm->value = '3';
  $export['comment_controls_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_controls_feedback_review';
  $strongarm->value = '3';
  $export['comment_controls_feedback_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_feedback';
  $strongarm->value = '4';
  $export['comment_default_mode_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_feedback_reply';
  $strongarm->value = '4';
  $export['comment_default_mode_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_feedback_review';
  $strongarm->value = '4';
  $export['comment_default_mode_feedback_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_feedback';
  $strongarm->value = '1';
  $export['comment_default_order_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_feedback_reply';
  $strongarm->value = '1';
  $export['comment_default_order_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_order_feedback_review';
  $strongarm->value = '1';
  $export['comment_default_order_feedback_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_feedback';
  $strongarm->value = '50';
  $export['comment_default_per_page_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_feedback_reply';
  $strongarm->value = '50';
  $export['comment_default_per_page_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_feedback_review';
  $strongarm->value = '50';
  $export['comment_default_per_page_feedback_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_feedback';
  $strongarm->value = '2';
  $export['comment_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_feedback_reply';
  $strongarm->value = '0';
  $export['comment_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_feedback_review';
  $strongarm->value = '0';
  $export['comment_feedback_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_feedback';
  $strongarm->value = '0';
  $export['comment_form_location_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_feedback_reply';
  $strongarm->value = '0';
  $export['comment_form_location_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_feedback_review';
  $strongarm->value = '0';
  $export['comment_form_location_feedback_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_feedback';
  $strongarm->value = '0';
  $export['comment_preview_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_feedback_reply';
  $strongarm->value = '1';
  $export['comment_preview_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_feedback_review';
  $strongarm->value = '1';
  $export['comment_preview_feedback_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_feedback';
  $strongarm->value = '1';
  $export['comment_subject_field_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_feedback_reply';
  $strongarm->value = '1';
  $export['comment_subject_field_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_feedback_review';
  $strongarm->value = '1';
  $export['comment_subject_field_feedback_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_feedback';
  $strongarm->value = array(
    'title' => '-5',
    'revision_information' => '11',
    'author' => '12',
    'options' => '13',
    'comment_settings' => '14',
    'menu' => '7',
    'taxonomy' => '-2',
    'path' => '15',
    'detailed_question' => '9',
    'workflow' => '8',
    'print' => '16',
    'nodewords' => '10',
  );
  $export['content_extra_weights_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_feedback_reply';
  $strongarm->value = array(
    'title' => '7',
    'revision_information' => '13',
    'author' => '12',
    'options' => '14',
    'comment_settings' => '15',
    'menu' => '9',
    'path' => '17',
    'custom_breadcrumbs' => '18',
    'workflow' => '11',
    'print' => '16',
    'nodewords' => '10',
  );
  $export['content_extra_weights_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_feedback_review';
  $strongarm->value = array(
    'detailed_question' => '13',
    'print' => '19',
    'title' => '9',
    'revision_information' => '15',
    'author' => '16',
    'options' => '17',
    'comment_settings' => '21',
    'menu' => '11',
    'path' => '20',
    'attachments' => '18',
    'workflow' => '14',
    'nodewords' => '12',
  );
  $export['content_extra_weights_feedback_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_feedback';
  $strongarm->value = '0';
  $export['language_content_type_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_feedback_reply';
  $strongarm->value = '0';
  $export['language_content_type_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_feedback_review';
  $strongarm->value = '0';
  $export['language_content_type_feedback_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_feedback';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_feedback_reply';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_feedback_review';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_feedback_review'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_feedback';
  $strongarm->value = '0';
  $export['upload_feedback'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_feedback_reply';
  $strongarm->value = '1';
  $export['upload_feedback_reply'] = $strongarm;

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_feedback_review';
  $strongarm->value = '1';
  $export['upload_feedback_review'] = $strongarm;

  return $export;
}
