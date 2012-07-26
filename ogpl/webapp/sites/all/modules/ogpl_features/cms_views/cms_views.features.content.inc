<?php

/**
 * Implementation of hook_content_default_fields().
 */
function cms_views_content_default_fields() {
  $fields = array();

  // Exported field: field_content_creator
  $fields['block-field_content_creator'] = array(
    'field_name' => 'field_content_creator',
    'type_name' => 'block',
    'display_settings' => array(
      'weight' => '10',
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
      'weight' => '10',
      'description' => 'Select One Of the Content creators from the list',
      'type' => 'userreference_select',
      'module' => 'userreference',
    ),
  );

  // Exported field: field_expiry_date
  $fields['block-field_expiry_date'] = array(
    'field_name' => 'field_expiry_date',
    'type_name' => 'block',
    'display_settings' => array(
      'weight' => '12',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
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
    'type' => 'datetime',
    'required' => '0',
    'multiple' => '0',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'utc',
    'todate' => '',
    'repeat' => 0,
    'repeat_collapsed' => '',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'blank',
      'default_value_code' => '',
      'default_value2' => 'same',
      'default_value_code2' => '',
      'input_format' => 'j M Y',
      'input_format_custom' => '',
      'increment' => '1',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'above',
      'label' => 'Enter the Expiry Date',
      'weight' => '12',
      'description' => 'Enter The Date Of Expiry',
      'type' => 'date_popup',
      'module' => 'date',
    ),
  );

  // Exported field: field_instructions
  $fields['block-field_instructions'] = array(
    'field_name' => 'field_instructions',
    'type_name' => 'block',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
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
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_instructions][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Instructions',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_moderator
  $fields['block-field_moderator'] = array(
    'field_name' => 'field_moderator',
    'type_name' => 'block',
    'display_settings' => array(
      'weight' => '11',
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
      'weight' => '11',
      'description' => 'Select A Moderator From The List',
      'type' => 'userreference_select',
      'module' => 'userreference',
    ),
  );

  // Exported field: field_no_ofdays
  $fields['block-field_no_ofdays'] = array(
    'field_name' => 'field_no_ofdays',
    'type_name' => 'block',
    'display_settings' => array(
      'weight' => '13',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
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
    'type' => 'number_integer',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '30',
          '_error_element' => 'default_value_widget][field_no_ofdays][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Notify Before (Days)',
      'weight' => '13',
      'description' => 'Enter the Number of Days here. ',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Exported field: field_content_creator
  $fields['imageflow-field_content_creator'] = array(
    'field_name' => 'field_content_creator',
    'type_name' => 'imageflow',
    'display_settings' => array(
      'weight' => '9',
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
      'weight' => '9',
      'description' => 'Select One Of the Content creators from the list',
      'type' => 'userreference_select',
      'module' => 'userreference',
    ),
  );

  // Exported field: field_moderator
  $fields['imageflow-field_moderator'] = array(
    'field_name' => 'field_moderator',
    'type_name' => 'imageflow',
    'display_settings' => array(
      'weight' => '10',
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
      'weight' => '10',
      'description' => 'Select A Moderator From The List',
      'type' => 'userreference_select',
      'module' => 'userreference',
    ),
  );

  // Exported field: field_content_creator
  $fields['page-field_content_creator'] = array(
    'field_name' => 'field_content_creator',
    'type_name' => 'page',
    'display_settings' => array(
      'weight' => '9',
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
      'weight' => '9',
      'description' => 'Select One Of the Content creators from the list',
      'type' => 'userreference_select',
      'module' => 'userreference',
    ),
  );

  // Exported field: field_instructions
  $fields['page-field_instructions'] = array(
    'field_name' => 'field_instructions',
    'type_name' => 'page',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'above',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
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
      '5' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => '5',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_instructions][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Instructions',
      'weight' => '-4',
      'description' => '',
      'type' => 'text_textarea',
      'module' => 'text',
    ),
  );

  // Exported field: field_moderator
  $fields['page-field_moderator'] = array(
    'field_name' => 'field_moderator',
    'type_name' => 'page',
    'display_settings' => array(
      'weight' => '10',
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
      'weight' => '10',
      'description' => 'Select A Moderator From The List',
      'type' => 'userreference_select',
      'module' => 'userreference',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Enter the Expiry Date');
  t('Instructions');
  t('Notify Before (Days)');
  t('Select A Content Creator');
  t('Select A Moderator');

  return $fields;
}
