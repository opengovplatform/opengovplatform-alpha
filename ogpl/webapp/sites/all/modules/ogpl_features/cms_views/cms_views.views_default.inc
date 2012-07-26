<?php

/**
 * Implementation of hook_views_default_views().
 */
function cms_views_views_default_views() {
  $views = array();

  // Exported view: content_management
  $view = new view;
  $view->name = 'content_management';
  $view->description = 'content management';
  $view->tag = '';
  $view->base_table = 'node';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'field_content_creator_uid' => array(
      'label' => 'Content Creator',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_content_creator_uid',
      'table' => 'node_data_field_content_creator',
      'field' => 'field_content_creator_uid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'field_moderator_uid' => array(
      'label' => 'Moderator',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_moderator_uid',
      'table' => 'node_data_field_moderator',
      'field' => 'field_moderator_uid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'title_1' => array(
      'label' => 'Title',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'link_to_node_revision' => 0,
      'exclude' => 0,
      'id' => 'title_1',
      'table' => 'node_revisions',
      'field' => 'title',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'type' => array(
      'label' => 'Type',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'machine_name' => 0,
      'exclude' => 0,
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'changed' => array(
      'label' => 'Updated date',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'medium',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'changed',
      'table' => 'node',
      'field' => 'changed',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'name' => array(
      'label' => 'Content Creator',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_user' => 1,
      'overwrite_anonymous' => 0,
      'anonymous_text' => '',
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'field_content_creator_uid',
    ),
    'name_1' => array(
      'label' => 'Moderator',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_user' => 1,
      'overwrite_anonymous' => 0,
      'anonymous_text' => '',
      'exclude' => 0,
      'id' => 'name_1',
      'table' => 'users',
      'field' => 'name',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'field_moderator_uid',
    ),
    'phpcode' => array(
      'label' => 'Duration ',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'value' => '<?php

$duration= (round(( time() - $data->workflow_node_stamp ) / ( 60 * 60 * 24 )) ); 
$duration_hours=(round(( time() - $data->workflow_node_stamp ) / ( 60 * 60 )) ); 
$duration_minutes=(round(( time() - $data->workflow_node_stamp ) / ( 60)) );

if($duration==0 && $duration_hours>0)
{
if($duration_hours==1)
return $duration_hours." hour";
else
return $duration_hours." hours";
}
else if($duration_hours==0 && $duration_minutes>0)
{if($duration_minutes==1)
return $duration_minutes." minute";
else
return $duration_minutes." minutes";
}
else if($duration_minutes==0)
return (round( time() - $data->workflow_node_stamp )). " seconds ";
else 
{if($duration==1)
return $duration." day";
else
return $duration." days";
}
?>',
      'exclude' => 0,
      'id' => 'phpcode',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'cms_allowed_operations' => array(
      'label' => 'Operations',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'text' => '',
      'exclude' => 0,
      'id' => 'cms_allowed_operations',
      'table' => 'node',
      'field' => 'cms_allowed_operations',
      'relationship' => 'none',
      'preview_link_text' => 'Preview',
      'download_link_text' => '',
      'approve_link_text' => 'Approve',
      'sendback_link_text' => 'Send Back',
      'publish_link_text' => '',
      'submit_link_text' => 'Submit',
      'edit_link_text' => 'Edit',
      'delete_link_text' => 'Delete',
      'update_request_link_text' => 'Update',
      'delete_request_link_text' => 'Delete',
      'display_workflow_state' => 1,
    ),
    'stamp_1' => array(
      'label' => 'Current time',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'small',
      'custom_date_format' => '',
      'exclude' => 1,
      'id' => 'stamp_1',
      'table' => 'workflow_node',
      'field' => 'stamp',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'field_expiry_date_value' => array(
      'label' => 'Enter the Expiry Date',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'group' => '',
      ),
      'repeat' => array(
        'show_repeat_rule' => '',
      ),
      'fromto' => array(
        'fromto' => 'both',
      ),
      'exclude' => 1,
      'id' => 'field_expiry_date_value',
      'table' => 'node_data_field_expiry_date',
      'field' => 'field_expiry_date_value',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'phpcode_1' => array(
      'label' => 'Due For Review',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'value' => '<?php
$exp_date=db_result(db_query("select date(field_expiry_date_value) from node LEFT JOIN content_field_expiry_date node_data_field_expiry_date ON node.vid = node_data_field_expiry_date.vid where node.nid=$data->nid"));
$var_subtracted_date = date(\'Y-m-d\', strtotime(\'-\'.$data->node_data_field_no_ofdays_field_no_ofdays_value.\'days\', strtotime($exp_date))); 
//return $var_subtracted_date;

$todays_date = date("Y-m-d"); 
$today = strtotime($todays_date); 
$expiration_date = strtotime($var_subtracted_date);
if ($today >= $expiration_date && ($data->node_data_field_expiry_date_field_expiry_date_value!=NULL) && ($data->workflow_states_state=="Published")) { $valid = "(Due For Review: ".$exp_date.")"; } 

return \'<b><i>\' .$valid.\'</i></b>\';
?>',
      'exclude' => 1,
      'id' => 'phpcode_1',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'field_no_ofdays_value' => array(
      'label' => 'Notify Before (Days)',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 1,
      'id' => 'field_no_ofdays_value',
      'table' => 'node_data_field_no_ofdays',
      'field' => 'field_no_ofdays_value',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'state' => array(
      'label' => 'Current state name',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'state',
      'table' => 'workflow_states',
      'field' => 'state',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'stamp' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'stamp',
      'table' => 'workflow_node',
      'field' => 'stamp',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'block' => 'block',
        'country_data' => 'country_data',
        'faq' => 'faq',
        'imageflow' => 'imageflow',
        'page' => 'page',
        'rotating_panel' => 'rotating_panel',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'type_op',
        'identifier' => 'type',
        'label' => 'Content Type',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 0,
        'single' => 0,
        'remember' => 0,
        'reduce' => 1,
        'bef_select_all_none' => 1,
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'sid' => array(
      'operator' => 'in',
      'value' => array(
        17 => '17',
        18 => '18',
        22 => '22',
        19 => '19',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'sid_op',
        'identifier' => 'sid',
        'label' => 'Workflow Step',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 0,
        'single' => 0,
        'remember' => 0,
        'reduce' => 1,
        'bef_select_all_none' => 1,
      ),
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Content List');
  $handler->override_option('css_class', 'cms-workflow-view');
  $handler->override_option('empty', 'There are no items to display');
  $handler->override_option('empty_format', '1');
  $handler->override_option('use_pager', '1');
  $handler->override_option('distinct', 0);
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'desc',
    'summary' => '',
    'columns' => array(
      'title_1' => 'title_1',
      'type' => 'type',
      'changed' => 'changed',
      'name' => 'name',
      'name_1' => 'name_1',
      'phpcode' => 'phpcode',
      'dms_allowed_operations' => 'dms_allowed_operations',
      'stamp_1' => 'stamp_1',
      'field_expiry_date_value' => 'field_expiry_date_value',
      'phpcode_1' => 'phpcode_1',
      'field_no_ofdays_value' => 'field_no_ofdays_value',
      'state' => 'state',
    ),
    'info' => array(
      'title_1' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'type' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'changed' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'name_1' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'phpcode' => array(
        'separator' => '',
      ),
      'dms_allowed_operations' => array(
        'separator' => '',
      ),
      'stamp_1' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'field_expiry_date_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'phpcode_1' => array(
        'separator' => '',
      ),
      'field_no_ofdays_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'state' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => 'changed',
  ));
  $handler = $view->new_display('block_path', 'Content Management Summary For Publisher', 'block_path_2');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $handler->override_option('path', '');

  $views[$view->name] = $view;

  // Exported view: content_mgmt_cmsadmin
  $view = new view;
  $view->name = 'content_mgmt_cmsadmin';
  $view->description = 'content management';
  $view->tag = '';
  $view->base_table = 'node';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'field_content_creator_uid' => array(
      'label' => 'Select A Content Creator',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_content_creator_uid',
      'table' => 'node_data_field_content_creator',
      'field' => 'field_content_creator_uid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'field_moderator_uid' => array(
      'label' => 'Select A Moderator',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_moderator_uid',
      'table' => 'node_data_field_moderator',
      'field' => 'field_moderator_uid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'title_1' => array(
      'label' => 'Title',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'link_to_node_revision' => 0,
      'exclude' => 0,
      'id' => 'title_1',
      'table' => 'node_revisions',
      'field' => 'title',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'type' => array(
      'label' => 'Type',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'machine_name' => 0,
      'exclude' => 0,
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'changed' => array(
      'label' => 'Updated date',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'medium',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'changed',
      'table' => 'node',
      'field' => 'changed',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'name' => array(
      'label' => 'Content Creator',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_user' => 1,
      'overwrite_anonymous' => 0,
      'anonymous_text' => '',
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'field_content_creator_uid',
    ),
    'name_1' => array(
      'label' => 'Moderator',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_user' => 1,
      'overwrite_anonymous' => 0,
      'anonymous_text' => '',
      'exclude' => 0,
      'id' => 'name_1',
      'table' => 'users',
      'field' => 'name',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'field_moderator_uid',
    ),
    'phpcode' => array(
      'label' => 'Duration ',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'value' => '<?php

$duration= (round(( time() - $data->workflow_node_stamp ) / ( 60 * 60 * 24 )) ); 
$duration_hours=(round(( time() - $data->workflow_node_stamp ) / ( 60 * 60 )) ); 
$duration_minutes=(round(( time() - $data->workflow_node_stamp ) / ( 60)) );

if($duration==0 && $duration_hours>0)
{
if($duration_hours==1)
return $duration_hours." hour";
else
return $duration_hours." hours";
}
else if($duration_hours==0 && $duration_minutes>0)
{if($duration_minutes==1)
return $duration_minutes." minute";
else
return $duration_minutes." minutes";
}
else if($duration_minutes==0)
return (round( time() - $data->workflow_node_stamp )). " seconds ";
else 
{if($duration==1)
return $duration." day";
else
return $duration." days";
}
?>',
      'exclude' => 0,
      'id' => 'phpcode',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'cms_allowed_operations' => array(
      'label' => 'Operations',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'text' => '',
      'exclude' => 0,
      'id' => 'cms_allowed_operations',
      'table' => 'node',
      'field' => 'cms_allowed_operations',
      'relationship' => 'none',
      'preview_link_text' => 'Preview',
      'download_link_text' => '',
      'approve_link_text' => 'Approve',
      'sendback_link_text' => 'Send Back',
      'publish_link_text' => 'Publish',
      'submit_link_text' => 'Submit',
      'edit_link_text' => 'Edit',
      'delete_link_text' => 'Delete',
      'update_request_link_text' => 'Update',
      'delete_request_link_text' => 'Delete',
      'display_workflow_state' => 1,
    ),
    'stamp' => array(
      'label' => 'Current time',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'small',
      'custom_date_format' => '',
      'exclude' => 1,
      'id' => 'stamp',
      'table' => 'workflow_node',
      'field' => 'stamp',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'stamp' => array(
      'id' => 'stamp',
      'table' => 'workflow_node',
      'field' => 'stamp',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'block' => 'block',
        'country_data' => 'country_data',
        'faq' => 'faq',
        'imageflow' => 'imageflow',
        'page' => 'page',
        'rotating_panel' => 'rotating_panel',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'type_op',
        'identifier' => 'type',
        'label' => 'Content Type',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 0,
        'single' => 0,
        'remember' => 0,
        'reduce' => 1,
        'bef_select_all_none' => 1,
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'sid' => array(
      'operator' => 'in',
      'value' => array(
        17 => '17',
        18 => '18',
        22 => '22',
        19 => '19',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'sid_op',
        'identifier' => 'sid',
        'label' => 'Workflow Step',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 0,
        'single' => 0,
        'remember' => 0,
        'reduce' => 1,
        'bef_select_all_none' => 1,
      ),
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Content List');
  $handler->override_option('css_class', 'cms-workflow-view');
  $handler->override_option('empty', 'There are no items to display');
  $handler->override_option('empty_format', '1');
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'desc',
    'summary' => '',
    'columns' => array(
      'title_1' => 'title_1',
      'type' => 'type',
      'changed' => 'changed',
      'name' => 'name',
      'name_1' => 'name_1',
      'phpcode' => 'phpcode',
      'dms_allowed_operations' => 'dms_allowed_operations',
      'stamp' => 'stamp',
    ),
    'info' => array(
      'title_1' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'type' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'changed' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'name_1' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'phpcode' => array(
        'separator' => '',
      ),
      'dms_allowed_operations' => array(
        'separator' => '',
      ),
      'stamp' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => 'changed',
  ));
  $handler = $view->new_display('block_path', 'Content Management Summary For CMS Administer', 'block_path_1');
  $handler->override_option('sorts', array(
    'stamp' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'stamp',
      'table' => 'workflow_node',
      'field' => 'stamp',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $handler->override_option('path', '');

  $views[$view->name] = $view;

  // Exported view: content_mgmt_contentcreator
  $view = new view;
  $view->name = 'content_mgmt_contentcreator';
  $view->description = 'content management';
  $view->tag = '';
  $view->base_table = 'node';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'field_content_creator_uid' => array(
      'label' => 'Select A Content Creator',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_content_creator_uid',
      'table' => 'node_data_field_content_creator',
      'field' => 'field_content_creator_uid',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'field_moderator_uid' => array(
      'label' => 'Moderator',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_moderator_uid',
      'table' => 'node_data_field_moderator',
      'field' => 'field_moderator_uid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'title_1' => array(
      'label' => 'Title',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'link_to_node_revision' => 0,
      'exclude' => 0,
      'id' => 'title_1',
      'table' => 'node_revisions',
      'field' => 'title',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'type' => array(
      'label' => 'Type',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'machine_name' => 0,
      'exclude' => 0,
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'changed' => array(
      'label' => 'Updated date',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'medium',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'changed',
      'table' => 'node',
      'field' => 'changed',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'name' => array(
      'label' => 'Moderator',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_user' => 1,
      'overwrite_anonymous' => 0,
      'anonymous_text' => '',
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'field_moderator_uid',
    ),
    'phpcode' => array(
      'label' => 'Duration ',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'value' => '<?php

$duration= (round(( time() - $data->workflow_node_stamp ) / ( 60 * 60 * 24 )) ); 
$duration_hours=(round(( time() - $data->workflow_node_stamp ) / ( 60 * 60 )) ); 
$duration_minutes=(round(( time() - $data->workflow_node_stamp ) / ( 60)) );

if($duration==0 && $duration_hours>0)
{
if($duration_hours==1)
return $duration_hours." hour";
else
return $duration_hours." hours";
}
else if($duration_hours==0 && $duration_minutes>0)
{if($duration_minutes==1)
return $duration_minutes." minute";
else
return $duration_minutes." minutes";
}
else if($duration_minutes==0)
return (round( time() - $data->workflow_node_stamp )). " seconds ";
else 
{if($duration==1)
return $duration." day";
else
return $duration." days";
}
?>',
      'exclude' => 0,
      'id' => 'phpcode',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'cms_allowed_operations' => array(
      'label' => 'Operations',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'text' => '',
      'exclude' => 0,
      'id' => 'cms_allowed_operations',
      'table' => 'node',
      'field' => 'cms_allowed_operations',
      'relationship' => 'none',
      'preview_link_text' => 'Preview',
      'download_link_text' => '',
      'approve_link_text' => 'Approve',
      'sendback_link_text' => 'Send Back',
      'publish_link_text' => 'Publish',
      'submit_link_text' => 'Submit',
      'edit_link_text' => 'Edit',
      'delete_link_text' => 'Delete',
      'update_request_link_text' => 'Update',
      'delete_request_link_text' => 'Delete',
      'display_workflow_state' => 1,
    ),
    'stamp' => array(
      'label' => 'Current time',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'small',
      'custom_date_format' => '',
      'exclude' => 1,
      'id' => 'stamp',
      'table' => 'workflow_node',
      'field' => 'stamp',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'field_expiry_date_value' => array(
      'label' => 'Enter the Expiry Date',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'group' => '',
      ),
      'repeat' => array(
        'show_repeat_rule' => '',
      ),
      'fromto' => array(
        'fromto' => 'both',
      ),
      'exclude' => 1,
      'id' => 'field_expiry_date_value',
      'table' => 'node_data_field_expiry_date',
      'field' => 'field_expiry_date_value',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'field_no_ofdays_value' => array(
      'label' => 'Notify Before (Days)',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 1,
      'id' => 'field_no_ofdays_value',
      'table' => 'node_data_field_no_ofdays',
      'field' => 'field_no_ofdays_value',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'phpcode_1' => array(
      'label' => 'PHP code',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'value' => '<?php
$exp_date=db_result(db_query("select date(field_expiry_date_value) from node LEFT JOIN content_field_expiry_date node_data_field_expiry_date ON node.vid = node_data_field_expiry_date.vid where node.nid=$data->nid"));

$var_subtracted_date = date(\'d-m-Y\', strtotime(\'-\'.$data->node_data_field_no_ofdays_field_no_ofdays_value.\'days\', strtotime($exp_date))); 
//return $var_subtracted_date;

$todays_date = date("d-m-Y"); 
$today = strtotime($todays_date); 
$expiration_date = strtotime($var_subtracted_date);
$expiry_date=date(\'d-m-Y\', strtotime($exp_date));
if ($today >= $expiration_date && ($data->node_data_field_expiry_date_field_expiry_date_value!=NULL) && ($data->workflow_states_state=="Published")) { $valid = "(Due For Review: ".$expiry_date.")"; } 

return \'<b><i><font color="#AA1144">\' .$valid.\'</font></i></b>\';
?>',
      'exclude' => 0,
      'id' => 'phpcode_1',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'state' => array(
      'label' => 'Current state name',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 1,
      'id' => 'state',
      'table' => 'workflow_states',
      'field' => 'state',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'stamp' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'stamp',
      'table' => 'workflow_node',
      'field' => 'stamp',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'block' => 'block',
        'country_data' => 'country_data',
        'faq' => 'faq',
        'imageflow' => 'imageflow',
        'page' => 'page',
        'rotating_panel' => 'rotating_panel',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'type_op',
        'identifier' => 'type',
        'label' => 'Select Content Type',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 0,
        'single' => 0,
        'remember' => 1,
        'reduce' => 1,
        'bef_select_all_none' => 0,
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'sid' => array(
      'operator' => 'in',
      'value' => array(
        17 => '17',
        18 => '18',
        22 => '22',
        19 => '19',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'sid_op',
        'identifier' => 'sid',
        'label' => 'Select Workflow Step',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 0,
        'single' => 0,
        'remember' => 1,
        'reduce' => 1,
        'bef_select_all_none' => 0,
      ),
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'uid_current' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'uid_current',
      'table' => 'users',
      'field' => 'uid_current',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'field_content_creator_uid',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Content List');
  $handler->override_option('css_class', 'cms-workflow-view');
  $handler->override_option('empty', 'There are no items to display');
  $handler->override_option('empty_format', '1');
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'desc',
    'summary' => '',
    'columns' => array(
      'title_1' => 'title_1',
      'type' => 'type',
      'changed' => 'changed',
      'name' => 'name',
      'phpcode' => 'phpcode',
      'dms_allowed_operations' => 'dms_allowed_operations',
      'stamp' => 'stamp',
      'field_expiry_date_value' => 'field_expiry_date_value',
      'field_no_ofdays_value' => 'field_no_ofdays_value',
      'phpcode_1' => 'title_1',
      'state' => 'state',
    ),
    'info' => array(
      'title_1' => array(
        'sortable' => 1,
        'separator' => '   ',
      ),
      'type' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'changed' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'phpcode' => array(
        'separator' => '',
      ),
      'dms_allowed_operations' => array(
        'separator' => '',
      ),
      'stamp' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_expiry_date_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_no_ofdays_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'phpcode_1' => array(
        'separator' => '',
      ),
      'state' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => 'changed',
  ));
  $handler = $view->new_display('block_path', 'Content Management Summary For Content Creator', 'block_path_1');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $handler->override_option('path', '');

  $views[$view->name] = $view;

  // Exported view: content_mgmt_moderator
  $view = new view;
  $view->name = 'content_mgmt_moderator';
  $view->description = 'content management';
  $view->tag = '';
  $view->base_table = 'node';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'field_moderator_uid' => array(
      'label' => 'Select A Moderator',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_moderator_uid',
      'table' => 'node_data_field_moderator',
      'field' => 'field_moderator_uid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'field_content_creator_uid' => array(
      'label' => 'Content Creator',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_content_creator_uid',
      'table' => 'node_data_field_content_creator',
      'field' => 'field_content_creator_uid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'title_1' => array(
      'label' => 'Title',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'link_to_node_revision' => 0,
      'exclude' => 0,
      'id' => 'title_1',
      'table' => 'node_revisions',
      'field' => 'title',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'type' => array(
      'label' => 'Type',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'machine_name' => 0,
      'exclude' => 0,
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'changed' => array(
      'label' => 'Updated date',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'medium',
      'custom_date_format' => '',
      'exclude' => 0,
      'id' => 'changed',
      'table' => 'node',
      'field' => 'changed',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'name' => array(
      'label' => 'Content Creator',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_user' => 1,
      'overwrite_anonymous' => 0,
      'anonymous_text' => '',
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'field_content_creator_uid',
    ),
    'stamp' => array(
      'label' => 'Current time',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'date_format' => 'small',
      'custom_date_format' => '',
      'exclude' => 1,
      'id' => 'stamp',
      'table' => 'workflow_node',
      'field' => 'stamp',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'phpcode' => array(
      'label' => 'Duration ',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'value' => '<?php

$duration= (round(( time() - $data->workflow_node_stamp ) / ( 60 * 60 * 24 )) ); 
$duration_hours=(round(( time() - $data->workflow_node_stamp ) / ( 60 * 60 )) ); 
$duration_minutes=(round(( time() - $data->workflow_node_stamp ) / ( 60)) );

if($duration==0 && $duration_hours>0)
{
if($duration_hours==1)
return $duration_hours." hour";
else
return $duration_hours." hours";
}
else if($duration_hours==0 && $duration_minutes>0)
{if($duration_minutes==1)
return $duration_minutes." minute";
else
return $duration_minutes." minutes";
}
else if($duration_minutes==0)
return (round( time() - $data->workflow_node_stamp )). " seconds ";
else 
{if($duration==1)
return $duration." day";
else
return $duration." days";
}
?>',
      'exclude' => 0,
      'id' => 'phpcode',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'cms_allowed_operations' => array(
      'label' => 'Operations',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'text' => '',
      'exclude' => 0,
      'id' => 'cms_allowed_operations',
      'table' => 'node',
      'field' => 'cms_allowed_operations',
      'relationship' => 'none',
      'preview_link_text' => 'Preview',
      'download_link_text' => '',
      'approve_link_text' => 'Approve',
      'sendback_link_text' => 'Send Back',
      'publish_link_text' => 'Publish',
      'submit_link_text' => 'Submit',
      'edit_link_text' => 'Edit',
      'delete_link_text' => 'Delete',
      'update_request_link_text' => 'Update',
      'delete_request_link_text' => 'Delete',
      'display_workflow_state' => 1,
    ),
  ));
  $handler->override_option('sorts', array(
    'stamp' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'stamp',
      'table' => 'workflow_node',
      'field' => 'stamp',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'block' => 'block',
        'country_data' => 'country_data',
        'faq' => 'faq',
        'imageflow' => 'imageflow',
        'page' => 'page',
        'rotating_panel' => 'rotating_panel',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'type_op',
        'identifier' => 'type',
        'label' => 'Content Type',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 0,
        'single' => 0,
        'remember' => 0,
        'reduce' => 1,
        'bef_select_all_none' => 1,
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'sid' => array(
      'operator' => 'in',
      'value' => array(
        17 => '17',
        18 => '18',
        22 => '22',
        19 => '19',
      ),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'sid_op',
        'identifier' => 'sid',
        'label' => 'Workflow Step',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 0,
        'single' => 0,
        'remember' => 0,
        'reduce' => 1,
        'bef_select_all_none' => 1,
      ),
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'uid_current' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'uid_current',
      'table' => 'users',
      'field' => 'uid_current',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'field_moderator_uid',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Content List');
  $handler->override_option('css_class', 'cms-workflow-view');
  $handler->override_option('empty', 'There are no items to display');
  $handler->override_option('empty_format', '1');
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'desc',
    'summary' => '',
    'columns' => array(
      'title_1' => 'title_1',
      'type' => 'type',
      'changed' => 'changed',
      'name' => 'name',
      'stamp' => 'stamp',
      'phpcode' => 'phpcode',
      'dms_allowed_operations' => 'dms_allowed_operations',
    ),
    'info' => array(
      'title_1' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'type' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'changed' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'name' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'stamp' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'phpcode' => array(
        'separator' => '',
      ),
      'dms_allowed_operations' => array(
        'separator' => '',
      ),
    ),
    'default' => 'changed',
  ));
  $handler = $view->new_display('block_path', 'Content Management Summary For Moderator', 'block_path_1');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $handler->override_option('path', '');

  $views[$view->name] = $view;

  return $views;
}
