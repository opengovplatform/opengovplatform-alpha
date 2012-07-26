<?php

/**
 * Implementation of hook_content_default_fields().
 */
function video_field_for_faq_content_default_fields() {
  $fields = array();

  // Exported field: field_audio
  $fields['faq-field_audio'] = array(
    'field_name' => 'field_audio',
    'type_name' => 'faq',
    'display_settings' => array(
      'weight' => '31',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'mp3player_Default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'mp3player_Default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp3',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '50M',
      'max_filesize_per_node' => '500M',
      'label' => 'Audio',
      'weight' => '31',
      'description' => '',
      'type' => 'filefield_widget',
      'module' => 'filefield',
    ),
  );

  // Exported field: field_content_creator
  $fields['faq-field_content_creator'] = array(
    'field_name' => 'field_content_creator',
    'type_name' => 'faq',
    'display_settings' => array(
      'weight' => '35',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'userreference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'userreference',
    'active' => '1',
    'referenceable_roles' => array(
      '11' => 11,
      '2' => 0,
      '10' => 0,
      '18' => 0,
      '3' => 0,
      '9' => 0,
      '12' => 0,
      '4' => 0,
      '6' => 0,
      '13' => 0,
      '15' => 0,
    ),
    'referenceable_status' => '1',
    'advanced_view' => 'user_reference_list',
    'advanced_view_args' => '11',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'reverse_link' => 0,
      'default_value' => array(
        '0' => array(
          'uid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Select A Content Creator',
      'weight' => '35',
      'description' => 'Select One Of the Content creators from the list',
      'type' => 'userreference_select',
      'module' => 'userreference',
    ),
  );

  // Exported field: field_moderator
  $fields['faq-field_moderator'] = array(
    'field_name' => 'field_moderator',
    'type_name' => 'faq',
    'display_settings' => array(
      'weight' => '37',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'hidden',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'userreference',
    'required' => '1',
    'multiple' => '0',
    'module' => 'userreference',
    'active' => '1',
    'referenceable_roles' => array(
      '12' => 12,
      '2' => 0,
      '10' => 0,
      '18' => 0,
      '11' => 0,
      '3' => 0,
      '9' => 0,
      '4' => 0,
      '6' => 0,
      '13' => 0,
      '15' => 0,
    ),
    'referenceable_status' => '1',
    'advanced_view' => 'user_reference_list',
    'advanced_view_args' => '12',
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'reverse_link' => 0,
      'default_value' => array(
        '0' => array(
          'uid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Select A Moderator',
      'weight' => '37',
      'description' => 'Select A Moderator From The List',
      'type' => 'userreference_select',
      'module' => 'userreference',
    ),
  );

  // Exported field: field_video
  $fields['faq-field_video'] = array(
    'field_name' => 'field_video',
    'type_name' => 'faq',
    'display_settings' => array(
      'weight' => '31',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'video_plain',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'video_plain',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'video_plain',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'video_plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'video_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'video_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'mp4 mpeg avi mpg wmv flv mov',
      'file_path' => 'videos',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'default_video_thumb' => NULL,
      'default_dimensions' => '176x144',
      'default_player_dimensions' => '176x144',
      'autoconversion' => 1,
      'autothumbnail' => 'no',
      'label' => 'Video',
      'weight' => '31',
      'description' => '',
      'type' => 'uploadfield_widget',
      'module' => 'uploadfield',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Audio');
  t('Select A Content Creator');
  t('Select A Moderator');
  t('Video');

  return $fields;
}
