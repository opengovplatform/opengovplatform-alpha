<?php

/**
 * Implementation of hook_quicktabs_default_quicktabs().
 */
function vrm_components_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass;
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'vrm_admin_tabs_list';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = 0;
  $quicktabs->default_tab = TRUE;
  $quicktabs->title = 'Vrm Admin Tabs List';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_1',
      'args' => '',
      'get_displays' => 'vdisp_0',
      'title' => 'All',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_7',
      'args' => '',
      'get_displays' => 'vdisp_1',
      'title' => 'My List',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_3',
      'args' => '',
      'get_displays' => 'vdisp_2',
      'title' => 'Opened',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_4',
      'args' => '',
      'get_displays' => 'vdisp_3',
      'title' => 'Assigned',
      'weight' => '-97',
      'type' => 'view',
    ),
    4 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_5',
      'args' => '',
      'get_displays' => 'vdisp_4',
      'title' => 'Replied',
      'weight' => '-96',
      'type' => 'view',
    ),
    5 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_6',
      'args' => '',
      'get_displays' => 'vdisp_5',
      'title' => 'Reviewed',
      'weight' => '-95',
      'type' => 'view',
    ),
    6 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_13',
      'args' => '',
      'get_displays' => 'vdisp_6',
      'title' => 'Reverted',
      'weight' => '-94',
      'type' => 'view',
    ),
    7 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_16',
      'args' => '',
      'get_displays' => 'vdisp_7',
      'title' => 'Closed',
      'weight' => '-93',
      'type' => 'view',
    ),
    8 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_15',
      'args' => '',
      'get_displays' => 'vdisp_8',
      'title' => 'Archived',
      'weight' => '-92',
      'type' => 'view',
    ),
    9 => array(
      'vid' => 'VRM_all_feedback_list',
      'display' => 'page_17',
      'args' => '',
      'get_displays' => 'vdisp_9',
      'title' => 'Irrelevant',
      'weight' => '-91',
      'type' => 'view',
    ),
  );
  $quicktabs->style = 'nostyle';
  $export['vrm_admin_tabs_list'] = $quicktabs;

  return $export;
}
