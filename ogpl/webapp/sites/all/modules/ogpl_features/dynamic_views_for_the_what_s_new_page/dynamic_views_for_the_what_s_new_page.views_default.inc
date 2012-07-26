<?php

/**
 * Implementation of hook_views_default_views().
 */
function dynamic_views_for_the_what_s_new_page_views_default_views() {
  $views = array();

  // Exported view: latest_dataset
  $view = new view;
  $view->name = 'latest_dataset';
  $view->description = '';
  $view->tag = '';
  $view->base_table = 'node';
  $view->core = 0;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('relationships', array(
    'field_ds_agency_name_nid' => array(
      'label' => 'Agency Name',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_ds_agency_name_nid',
      'table' => 'node_data_field_ds_agency_name',
      'field' => 'field_ds_agency_name_nid',
      'relationship' => 'none',
    ),
    'field_ds_sub_agency_nid' => array(
      'label' => 'Sub Agency Name',
      'required' => 0,
      'delta' => -1,
      'id' => 'field_ds_sub_agency_nid',
      'table' => 'node_data_field_ds_sub_agency',
      'field' => 'field_ds_sub_agency_nid',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('fields', array(
    'title' => array(
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
        'trim' => 1,
        'max_length' => '50',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'field_ds_agency_short_name_value' => array(
      'label' => 'Agency/Sub-Agency',
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
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_ds_agency_short_name_value',
      'table' => 'node_data_field_ds_agency_short_name',
      'field' => 'field_ds_agency_short_name_value',
      'relationship' => 'none',
    ),
    'field_ds_description_value' => array(
      'label' => 'Description',
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
        'trim' => 1,
        'max_length' => '150',
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
      'exclude' => 0,
      'id' => 'field_ds_description_value',
      'table' => 'node_data_field_ds_description',
      'field' => 'field_ds_description_value',
      'relationship' => 'none',
    ),
    'field_ds_sub_agency_short_name_value' => array(
      'label' => 'Agency/Sub-Agency',
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
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_ds_sub_agency_short_name_value',
      'table' => 'node_data_field_ds_sub_agency_short_name',
      'field' => 'field_ds_sub_agency_short_name_value',
      'relationship' => 'none',
    ),
    'field_ds_sector_nid' => array(
      'label' => 'Sector',
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
      'label_type' => 'custom',
      'format' => 'plain',
      'multiple' => array(
        'group' => 1,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => 0,
      ),
      'exclude' => 0,
      'id' => 'field_ds_sector_nid',
      'table' => 'node_data_field_ds_sector',
      'field' => 'field_ds_sector_nid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'phpcode' => array(
      'label' => 'Average Overall Rating',
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
$a=0;
			 $q=0;
			 $u=0;
			 $acc=votingapi_select_results(array(\'content_id\' => $data->nid, \'tag\' =>\'voteaccessibility\', \'function\' => \'average\'));
			 $qual=votingapi_select_results(array(\'content_id\' => $data->nid, \'tag\' =>\'votequality\', \'function\' => \'average\'));
			 $usab=votingapi_select_results(array(\'content_id\' => $data->nid, \'tag\' =>\'voteusability\', \'function\' => \'average\'));
			 $oldrange=(25-0);
			 $newrange=(40-20);
			 
			 	$a=(int)$acc[0][\'value\'];		
			    $q=(int)$qual[0][\'value\'];
				$u=(int)$usab[0][\'value\'];
				
				
			  if($acc!=null)
			   {
				 if($a>=0&&$a<25)
				 {
				   $a=((($a-0)*$newrange)/$oldrange)+20;
				 }
				 else if($a>=25&&$a<50)
				 {
				    $a=((($a-25)*$newrange)/$oldrange)+40;
				 }
				 else if($a>=50&&$a<75)
				 {
				    $a=((($a-50)*$newrange)/$oldrange)+60;
				 }
				 else if($a>=75&&$a<100)
				 {
				    $a=((($a-75)*$newrange)/$oldrange)+80;
				 }
						   
			   }
			    if($qual!=null)
			   {
				 if($q>=0&&$q<25)
				 {
				   $q=((($q-0)*$newrange)/$oldrange)+20;
				 }
				 else if($q>=25&&$q<50)
				 {
				    $q=((($q-25)*$newrange)/$oldrange)+40;
				 }
				 else if($q>=50&&$q<75)
				 {
				    $q=((($q-50)*$newrange)/$oldrange)+60;
				 }
				 else if($q>=75&&$q<100)
				 {
				    $q=((($q-75)*$newrange)/$oldrange)+80;
				 }
						   
			   }
			    if($usab!=null)
			   {
				 if($u>=0&&$u<25)
				 {
				   $u=((($u-0)*$newrange)/$oldrange)+20;
				 }
				 else if($u>=25&&$u<50)
				 {
				    $u=((($u-25)*$newrange)/$oldrange)+40;
				 }
				 else if($u>=50&&$u<75)
				 {
				    $u=((($u-50)*$newrange)/$oldrange)+60;
				 }
				 else if($u>=75&&$u<100)
				 {
				    $u=((($u-75)*$newrange)/$oldrange)+80;
				 }
						   
			   }
						 
			 $value=(int)(($a+$q+$u)/3);
			 $value=$value/10;
			$value=round($value);
			$value=$value*10;
			if($value<10)
			  $value=0;
			else if($value>=10 && $value<30)
				$value=20;	
			else if($value>=30 &&$value<50)
				$value=40;	
			else if($value>=50 &&$value<70)
				$value=60;	
			else if($value>=70 &&$value<90)
				$value=80;	
			else if($value>=90 &&$value<=100)
				$value=100;			
			  $vote1= rate_get_results(\'node\', $data->nid, 1);
                          $vote2 = rate_get_results(\'node\', $data->nid, 2);
                          $vote3=rate_get_results(\'node\', $data->nid, 3);
                           $vote=$vote1[\'count\'];
                          if($vote2[\'count\']>$vote) $vote=$vote2[\'count\'];
                          if($vote3[\'count\']>$vote)$vote=$vote3[\'count\'];
                         $votes=\'<span style="margin-left: 5px;" >(\'.$vote.\' votes)</span>\'; 
                         return theme(\'fivestar_static\',$value).$votes;
                  ?>',
      'exclude' => 0,
      'id' => 'phpcode',
      'table' => 'customfield',
      'field' => 'phpcode',
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
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'null' => array(
      'default_action' => 'ignore',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => 'Latest Datasets in Last %1 days',
      'breadcrumb' => '',
      'default_argument_type' => 'fixed',
      'default_argument' => '',
      'validate_type' => 'none',
      'validate_fail' => 'not found',
      'must_not_be' => 0,
      'id' => 'null',
      'table' => 'views',
      'field' => 'null',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        2 => 0,
        10 => 0,
        18 => 0,
        11 => 0,
        3 => 0,
        9 => 0,
        12 => 0,
        4 => 0,
        6 => 0,
        13 => 0,
        14 => 0,
        15 => 0,
      ),
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_fixed' => '',
      'default_argument_user' => 0,
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'faq' => 0,
        'imageflow' => 0,
        'flags' => 0,
        'country_data' => 0,
        'state_data_site' => 0,
        'rotating_panel' => 0,
        'feedback_reply' => 0,
        'feedback' => 0,
        'access_type_downloadable' => 0,
        'access_type_embed_link' => 0,
        'access_type_execute_upon_access' => 0,
        'agency' => 0,
        'block' => 0,
        'catalog_type_data_apps' => 0,
        'catalog_type_data_service' => 0,
        'catalog_type_data_tools' => 0,
        'catalog_type_document' => 0,
        'catalog_type_raw_data' => 0,
        'chart' => 0,
        'dataset' => 0,
        'feedback_review' => 0,
        'geospatial_metadata' => 0,
        'page' => 0,
        'policy_program_data_quality' => 0,
        'policy_program_open_government' => 0,
        'policy_program_privacy' => 0,
        'profile' => 0,
        'sector' => 0,
        'statistical_metadata' => 0,
        'story' => 0,
        'subject_keyword' => 0,
        'sub_agency' => 0,
        'upload_docs' => 0,
        'webform' => 0,
        'whats_new' => 0,
      ),
      'validate_argument_node_access' => 0,
      'validate_argument_nid_type' => 'nid',
      'validate_argument_vocabulary' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
        5 => 0,
      ),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_php' => '',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'catalog_type_data_service' => 'catalog_type_data_service',
        'dataset' => 'dataset',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
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
        10 => '10',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'php' => array(
      'operator' => '=',
      'value' => '',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'use_php_setup' => 0,
      'php_setup' => '',
      'php_filter' => '',
      'sql_filter' => 'if(is_numeric($view->args[0])){
return "FROM_UNIXTIME(workflow_node.stamp) > date_sub(curdate(), interval {$view->args[0]} day)";}
else
return "FROM_UNIXTIME(workflow_node.stamp) > date_sub(curdate(), interval 7 day)";
',
      'id' => 'php',
      'table' => 'views',
      'field' => 'php',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
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
  $handler->override_option('css_class', 'ds-list-head title');
  $handler->override_option('header', '<?php
/* Calculating average ratings for all items (AR) */
  $result=db_query("select distinct(content_id) as nid from votingapi_vote V LEFT JOIN node N on V.content_id=N.nid where N.type=\'dataset\' ");
  while($row=db_fetch_object($result))
  {
     $sum=$sum+get_average_ratings($row->nid);
     $count++;
  }
  
  $AR=$sum/$count;
  //print "AR=".$AR;

  /*Calculating average number of votes for all items (AV) */
$result=db_query("select distinct(content_id) as nid from votingapi_vote V LEFT JOIN node N on V.content_id=N.nid where N.type=\'dataset\' ");

  $sum=0;
  while($row=db_fetch_object($result))
  {   
     $sum=$sum+get_average_rating_votes($row->nid);
  }
  $AV=$sum/$count;
  $AV=round($AV);

 variable_set(\'average_rating\',$AR);
 variable_set(\'average_votes\',$AV); 
?>');
  $handler->override_option('header_format', '3');
  $handler->override_option('header_empty', 0);
  $handler->override_option('empty', '<?php
$view=views_get_current_view();
print \'No datasets were uploaded in last \'.$view->args[0].\' days\';
?>');
  $handler->override_option('empty_format', '3');
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'summary' => '',
    'columns' => array(
      'title' => 'title',
      'field_ds_agency_short_name_value' => 'field_ds_agency_short_name_value',
      'field_ds_description_value' => 'title',
      'field_ds_sub_agency_short_name_value' => 'field_ds_agency_short_name_value',
      'field_ds_sector_nid' => 'field_ds_sector_nid',
      'phpcode' => 'phpcode',
      'field_agency_short_name_value' => 'field_agency_short_name_value',
      'field_sa_subagency_short_name_value' => 'field_agency_short_name_value',
    ),
    'info' => array(
      'title' => array(
        'sortable' => 0,
        'separator' => '<br/>',
      ),
      'field_ds_agency_short_name_value' => array(
        'separator' => '/',
      ),
      'field_ds_description_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_ds_sub_agency_short_name_value' => array(
        'separator' => '',
      ),
      'field_ds_sector_nid' => array(
        'separator' => '',
      ),
      'phpcode' => array(
        'separator' => '',
      ),
      'field_agency_short_name_value' => array(
        'sortable' => 0,
        'separator' => '/',
      ),
      'field_sa_subagency_short_name_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('fields', array(
    'title' => array(
      'label' => 'Title',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => '',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '[title] ',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '50',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'field_agency_short_name_value' => array(
      'label' => 'Agency/Sub-Agency',
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
      'hide_alter_empty' => 1,
      'link_to_node' => 0,
      'label_type' => 'custom',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_agency_short_name_value',
      'table' => 'node_data_field_agency_short_name',
      'field' => 'field_agency_short_name_value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'field_ds_agency_name_nid',
    ),
    'field_sa_subagency_short_name_value' => array(
      'label' => 'Sub-Agency Short Name',
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
      'hide_alter_empty' => 1,
      'link_to_node' => 0,
      'label_type' => 'widget',
      'format' => 'default',
      'multiple' => array(
        'group' => TRUE,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => FALSE,
      ),
      'exclude' => 0,
      'id' => 'field_sa_subagency_short_name_value',
      'table' => 'node_data_field_sa_subagency_short_name',
      'field' => 'field_sa_subagency_short_name_value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'field_ds_sub_agency_nid',
    ),
    'field_ds_description_value' => array(
      'label' => 'Description',
      'alter' => array(
        'alter_text' => 1,
        'text' => '<p>[field_ds_description_value] </p>',
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
        'trim' => 1,
        'max_length' => '150',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 1,
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
      'exclude' => 0,
      'id' => 'field_ds_description_value',
      'table' => 'node_data_field_ds_description',
      'field' => 'field_ds_description_value',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'field_ds_sector_nid' => array(
      'label' => 'Category',
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
      'label_type' => 'custom',
      'format' => 'plain',
      'multiple' => array(
        'group' => 1,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => 0,
      ),
      'exclude' => 0,
      'id' => 'field_ds_sector_nid',
      'table' => 'node_data_field_ds_sector',
      'field' => 'field_ds_sector_nid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode' => array(
      'label' => 'Average Overall Rating',
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
      'hide_alter_empty' => 1,
      'value' => '<?php

$avg_rating=variable_get(\'average_rating\',0);
$avg_votes=variable_get(\'average_votes\',0);
$value=calculate_ratings($data->nid,$avg_rating,$avg_votes);


 $vote1= rate_get_results(\'node\', $data->nid, 1);
  $vote2 = rate_get_results(\'node\', $data->nid, 2);
  $vote3=rate_get_results(\'node\', $data->nid, 3);
  $vote=$vote1[\'count\'];
  if($vote2[\'count\']>$vote) $vote=$vote2[\'count\'];
  if($vote3[\'count\']>$vote)$vote=$vote3[\'count\'];                 
  		           
  if($vote==1)  $votes=\'<span style="margin-left: 20px;">(\'.$vote.\' vote)</span>\';        
  else   
  $votes=\'<span style="margin-left: 20px;">(\'.$vote.\' votes)</span>\';
return theme(\'fivestar_static\',$value).$votes;
?>',
      'exclude' => 0,
      'id' => 'phpcode',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('empty', '<?php
$view=views_get_current_view();
print \'<div style="font-size:1.3em;">No datasets were uploaded in last \'.$view->args[0].\' days</div>\';
?>');
  $handler->override_option('path', 'new/%');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));

  $views[$view->name] = $view;

  return $views;
}
