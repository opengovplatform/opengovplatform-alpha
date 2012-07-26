<?php

/**
 * Implementation of hook_views_default_views().
 */
function agency_wise_metrics_views_default_views() {
  $views = array();

  // Exported view: agency_datasets
  $view = new view;
  $view->name = 'agency_datasets';
  $view->description = 'Agency Datasets';
  $view->tag = '';
  $view->base_table = 'node';
  $view->core = 6;
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
    'phpcode_1' => array(
      'label' => 'High Value',
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

$result=db_result(db_query("select * from content_type_dataset ds INNER JOIN content_type_policy_program_open_government ppog on ds.nid=ppog.nid where ds.nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' ")); 

if($result) return \'Yes\';
else return \'No\';


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
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
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
        'max_length' => '75',
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
    'phpcode' => array(
      'label' => 'Ratings',
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
                         $votes=\'<span > (\'.$vote.\' votes)</span>\'; 
                         return theme(\'fivestar_static\',$value).$votes;
?>',
      'exclude' => 0,
      'id' => 'phpcode',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'field_agency_short_name_value' => array(
      'label' => 'Agency Short Name',
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
      'exclude' => 0,
      'id' => 'field_agency_short_name_value',
      'table' => 'node_data_field_agency_short_name',
      'field' => 'field_agency_short_name_value',
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
      'relationship' => 'field_ds_sub_agency_nid',
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
      'format' => 'default',
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
      'relationship' => 'none',
    ),
    'phpcode_2' => array(
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
      'value' => '<?php
$result=db_query("SELECT field_sector_title_value as sector FROM `content_field_ds_sector` s INNER JOIN content_type_sector sec on s.`field_ds_sector_nid`=sec.nid where s.nid=$data->nid");
$cat=\'\';
while($row=db_fetch_object($result))
{

if($cat==\'\') $cat=$row->sector;
else
$cat.=\' : \'.$row->sector;

}
return $cat;
?>',
      'exclude' => 0,
      'id' => 'phpcode_2',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('arguments', array(
    'field_ds_agency_name_nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '',
      'breadcrumb' => '',
      'default_argument_type' => 'node',
      'default_argument' => '',
      'validate_type' => 'node',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'field_ds_agency_name_nid',
      'table' => 'node_data_field_ds_agency_name',
      'field' => 'field_ds_agency_name_nid',
      'validate_user_argument_type' => 'uid',
      'validate_user_roles' => array(
        2 => 0,
        10 => 0,
        16 => 0,
        11 => 0,
        3 => 0,
        9 => 0,
        12 => 0,
        4 => 0,
        6 => 0,
        15 => 0,
        13 => 0,
        14 => 0,
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'agency' => 'agency',
        'faq' => 0,
        'imageflow' => 0,
        'flags' => 0,
        'rotating_panel' => 0,
        'access_type_downloadable' => 0,
        'access_type_embed_link' => 0,
        'access_type_execute_upon_access' => 0,
        'catalog_type_data_apps' => 0,
        'catalog_type_data_service' => 0,
        'catalog_type_data_tools' => 0,
        'catalog_type_document' => 0,
        'catalog_type_raw_data' => 0,
        'dataset' => 0,
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
      'validate_argument_vocabulary' => array(),
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
      'sql_filter' => 'if($view->args[2]==1)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_raw_data\' ";
}
else if($view->args[2]==2)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_document\' ";
}
else if($view->args[2]==3)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_data_apps\' ";
}
else if($view->args[2]==4)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_data_tools\' ";
}
else if($view->args[2]==5)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_data_service\' ";
}',
      'id' => 'php',
      'table' => 'views',
      'field' => 'php',
      'relationship' => 'none',
    ),
    'php_1' => array(
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
      'sql_filter' => 'if($view->args[1]==\'-\')
{
return "node_data_field_ds_agency_name.field_ds_sub_agency_nid IS NULL";
}

if(!strlen(strstr($view->args[1], "main_"))>0 )
{
return "node_data_field_ds_agency_name.field_ds_sub_agency_nid=\'".$view->args[1]."\' ";
}',
      'id' => 'php_1',
      'table' => 'views',
      'field' => 'php',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
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
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('header_format', '3');
  $handler->override_option('header_empty', 0);
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'summary' => '',
    'columns' => array(
      'title' => 'title',
      'phpcode' => 'phpcode',
      'field_ds_agency_name_nid' => 'field_ds_agency_name_nid',
      'field_ds_sector_nid' => 'field_ds_sector_nid',
      'field_ds_sub_agency_name_value' => 'field_ds_agency_name_nid',
      'field_ds_description_value' => 'title',
    ),
    'info' => array(
      'title' => array(
        'sortable' => 0,
        'separator' => '<br>',
      ),
      'phpcode' => array(
        'separator' => '',
      ),
      'field_ds_agency_name_nid' => array(
        'separator' => '',
      ),
      'field_ds_sector_nid' => array(
        'separator' => '',
      ),
      'field_ds_sub_agency_name_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_ds_description_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('block', 'Block', 'block_1');
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
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'phpcode' => array(
      'label' => 'Ratings',
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
			
                    return theme(\'fivestar_static\',$value);
?>',
      'exclude' => 0,
      'id' => 'phpcode',
      'table' => 'customfield',
      'field' => 'phpcode',
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
      'format' => 'default',
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
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'field_ds_sub_agency_short_name_value' => array(
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
      'id' => 'field_ds_sub_agency_short_name_value',
      'table' => 'node_data_field_ds_sub_agency_short_name',
      'field' => 'field_ds_sub_agency_short_name_value',
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
        'max_length' => '100',
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
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
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
        'operator' => 'sid_op',
        'label' => 'Workflow: Current state',
        'use_operator' => 0,
        'identifier' => 'sid',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
        'bef_select_all_none' => 0,
      ),
      'id' => 'sid',
      'table' => 'workflow_node',
      'field' => 'sid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('fields', array(
    'phpcode_1' => array(
      'label' => '',
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

$result=db_result(db_query("select * from content_type_dataset ds INNER JOIN content_type_policy_program_open_government ppog on ds.nid=ppog.nid where ds.nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' ")); 

if($result) return \'<h1>*</h1>\';


?>',
      'exclude' => 0,
      'id' => 'phpcode_1',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
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
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode' => array(
      'label' => 'Ratings',
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
  if($vote==1)   $votes=\'<span>(\'.$vote.\' vote)</span>\'; 
else		           
  $votes=\'<span>(\'.$vote.\' votes)</span>\'; 
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
    'field_agency_short_name_value' => array(
      'label' => 'Agency/Sub-Agency ',
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
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'field_ds_description_value' => array(
      'label' => 'Description',
      'alter' => array(
        'alter_text' => 1,
        'text' => '<p>[field_ds_description_value]</p>',
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
        'max_length' => '75',
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
  ));
  $handler->override_option('arguments', array(
    'field_ds_agency_name_nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '%1',
      'breadcrumb' => '',
      'default_argument_type' => 'node',
      'default_argument' => '',
      'validate_type' => 'node',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'field_ds_agency_name_nid',
      'table' => 'node_data_field_ds_agency_name',
      'field' => 'field_ds_agency_name_nid',
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
        14 => 0,
        13 => 0,
        17 => 0,
        15 => 0,
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'agency' => 'agency',
        'diymap' => 0,
        'faq' => 0,
        'page' => 0,
        'imageflow' => 0,
        'flags' => 0,
        'geo_data' => 0,
        'rotating_panel' => 0,
        'access_type_downloadable' => 0,
        'access_type_embed_link' => 0,
        'access_type_execute_upon_access' => 0,
        'catalog_type_data_apps' => 0,
        'catalog_type_data_service' => 0,
        'catalog_type_data_tools' => 0,
        'catalog_type_document' => 0,
        'catalog_type_raw_data' => 0,
        'dataset' => 0,
        'geospatial_metadata' => 0,
        'openlayers_test_type' => 0,
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
      'validate_argument_vocabulary' => array(),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_php' => '',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
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
      'sql_filter' => 'if($view->args[2]==1)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_raw_data\' ";
}
else if($view->args[2]==2)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_document\' ";
}
else if($view->args[2]==3)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_data_apps\' ";
}
else if($view->args[2]==4)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_data_tools\' ";
}
else if($view->args[2]==5)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_data_service\' ";
}',
      'id' => 'php',
      'table' => 'views',
      'field' => 'php',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'php_1' => array(
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
      'sql_filter' => 'if($view->args[1]==\'-\')
{
return "node_data_field_ds_agency_name.field_ds_sub_agency_nid IS NULL";
}

if(!strlen(strstr($view->args[1], "main_"))>0 )
{
return "node_data_field_ds_agency_name.field_ds_sub_agency_nid=\'".$view->args[1]."\' ";
}',
      'id' => 'php_1',
      'table' => 'views',
      'field' => 'php',
      'override' => array(
        'button' => 'Use default',
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
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
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
       
        $this_page = $_SERVER[\'REQUEST_URI\'];
	$last =substr($this_page,0,strripos($this_page,\'/\'));
        $slast =substr($last,0,strripos($last,\'/\'));
	$third_last=strripos($slast,\'/\');
	$argument=substr($this_page,$third_last);
	
		$qpos;
     if(strlen(strstr($this_page,"?")))
      {
              $qpos=strpos($this_page,\'?\');
               
       }
	$li=strripos($this_page,\'/\');

       if($qpos!=0)
	$arg=substr($this_page,$li,2);
	else
	$arg=substr($this_page,$li);
       		
	if($arg==\'/1\'||$arg==\'/2\'||$arg==\'/3\'||$arg==\'/4\'||$arg==\'/5\')
	 {
	   $this_page=substr($this_page,0,$li);
	 } 
         global $base_url;

$view = views_get_current_view();
$arg0 = $view->args[0];
$arg1 = $view->args[1];

if($arg1==\'-\') $sub_agency=\'IS NULL\';
else $sub_agency="= $arg1";

if(!strlen(strstr($view->args[1], "main_"))>0 )
$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid  INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_raw_data\' AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_nid $sub_agency AND n.status=1"));
else
$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_raw_data\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 "));

if(!strlen(strstr($view->args[1], "main_"))>0 )
$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_document\' AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_nid $sub_agency AND n.status=1"));
else
$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_document\' AND field_ds_agency_name_nid=$arg0 AND n.status=1"));

if(!strlen(strstr($view->args[1], "main_"))>0 )
$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN (\'catalog_type_data_apps\') AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_nid $sub_agency AND n.status=1"));
else
$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN (\'catalog_type_data_apps\')  AND field_ds_agency_name_nid=$arg0 AND n.status=1"));

if(!strlen(strstr($view->args[1], "main_"))>0 )
$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_data_tools\' AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_nid $sub_agency AND n.status=1 "));
else
$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid  INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_data_tools\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 "));

if(!strlen(strstr($view->args[1], "main_"))>0 )
$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_data_service\' AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_nid $sub_agency AND n.status=1 "));
else
$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid  INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_data_service\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 "));



		
	 print \'<div class="catalog-tabs-menu fLeft" style="margin-top:7px;height:23px;">\';
	 print \'<ul class="catalog-tabs" style="position:absolute;">\';
	if($arg==\'/1\' && $raw )
  	 print \'<li><a style="padding:1px 30px;" class="active" href="\'.$this_page.\'/1" title="Raw Dataset Catalogs">Raw Dataset Catalogs</a></li>\';
	else if($raw)
	  print \'<li><a style="padding:0px 30px;" href="\'.$this_page.\'/1" title="Raw Dataset Catalogs">Raw Dataset Catalogs</a></li>\';

	 if($arg==\'/2\' && $doc)
  	 print \'<li><a style="padding:1px 30px;" class="active" href="\'.$this_page.\'/2" title="Document Catalogs">Document Catalogs</a></li>\';
	else if($doc)
	  print \'<li><a style="padding:0px 30px;" href="\'.$this_page.\'/2" title="Document Catalogs">Document Catalogs</a></li>\';

	if($arg==\'/3\' && $apps)
  	 print \'<li><a style="padding:1px 30px;"  class="active" href="\'.$this_page.\'/3" title="App Catalogs">App Catalogs</a></li>\';
	else if($apps)
	  print \'<li><a style="padding:0px 30px;" href="\'.$this_page.\'/3" title="App Catalogs">App Catalogs</a></li>\';

	if($arg==\'/4\' && $tool)
  	 print \'<li><a style="padding:1px 30px;"  class="active" href="\'.$this_page.\'/4" title="Tool Catalogs">Tool Catalogs</a></li>\';
	else if($tool)
	  print \'<li><a style="padding:0px 30px;" href="\'.$this_page.\'/4" title="Tool Catalogs">Tool  Catalogs</a></li>\';

	if($arg==\'/5\' && $ser)
  	 print \'<li><a style="padding:1px 30px;"  class="active" href="\'.$this_page.\'/5" title="Service Catalogs">Service Catalogs</a></li>\';
	else if($ser)
	  print \'<li><a style="padding:0px 30px;" href="\'.$this_page.\'/5" title="Service Catalogs">Service Catalogs</a></li>\';

	print\'</ul></div>\';


?>
<div class="page-title-border cBoth">&nbsp;</div>
<?php print l(\'<< Back to Agency Wise Report\',\'agency-publications/agency-wise\',array(\'attributes\' => array(\'class\' => \'metricsbacklink\',\'title\'=>\'Back to Agency Wise Report\'))); 
print \'<div style="margin-top:-15px;" class="download-report">Download report as: <a  title="CSV Download" class="hyperlink" href="\'.$base_url.\'/federalagency/datasets-agency/csv\'.$argument.\'?itemcount=500"><img alt="CSV" src="[token global site-url]sites/all/themes/ogpl_css3/images/csv.png" /></a> \' ;

print \'<a  title="XLS Download"  class="hyperlink" href="\'.$base_url.\'/federalagency/datasets-agency/xls\'.$argument.\'?itemcount=500"><img alt="XLS" src="[token global site-url]sites/all/themes/ogpl_css3/images/xls.png" /></a>\';

print \'<a style="padding-left:3px;" title="PDF Download" class="hyperlink" href="\'.$base_url.\'/printpdf/agency-publications/datasets-agency/pdf\'.$argument.\'?itemcount=500 "><img alt="PDF" src="[token global site-url]sites/all/themes/ogpl_css3/images/pdf.png" /></a></div>\'; ?>
');
  $handler->override_option('header_empty', 1);
  $handler->override_option('footer', '<br/>
<p>* Asterisks denote agency-reported high-value datasets. </p>');
  $handler->override_option('footer_format', '4');
  $handler->override_option('footer_empty', 0);
  $handler->override_option('empty', '<?php
global $base_url;

print \'<div style="font:bold 1.3em arial; padding-top:10px">No matching records found. Please try your search again or <a style="color:blue;" href="\'.$base_url.\'/suggest_dataset" title="Suggest a dataset">suggest a dataset.</a></div>\';

?>


');
  $handler->override_option('empty_format', '3');
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'summary' => '',
    'columns' => array(
      'phpcode_1' => 'phpcode_1',
      'title' => 'title',
      'phpcode' => 'phpcode',
      'field_agency_short_name_value' => 'field_agency_short_name_value',
      'field_sa_subagency_short_name_value' => 'field_agency_short_name_value',
      'field_ds_sector_nid' => 'field_ds_sector_nid',
      'field_ds_description_value' => 'title',
    ),
    'info' => array(
      'phpcode_1' => array(
        'separator' => '',
      ),
      'title' => array(
        'sortable' => 1,
        'separator' => '<br/>',
      ),
      'phpcode' => array(
        'separator' => '',
      ),
      'field_agency_short_name_value' => array(
        'sortable' => 1,
        'separator' => '/',
      ),
      'field_sa_subagency_short_name_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_ds_sector_nid' => array(
        'separator' => '',
      ),
      'field_ds_description_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => 'title',
  ));
  $handler->override_option('path', 'agency-publications/datasets-agency');
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
  $handler = $view->new_display('views_data_export', 'CSV', 'views_data_export_1');
  $handler->override_option('fields', array(
    'phpcode_1' => array(
      'label' => 'High Value',
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

$result=db_result(db_query("select * from content_type_dataset ds INNER JOIN content_type_policy_program_open_government ppog on ds.nid=ppog.nid where ds.nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' ")); 

if($result) return \'Yes\';
else return \'No\';


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
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
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
        'max_length' => '75',
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
    'phpcode' => array(
      'label' => 'Ratings',
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
  		           
  $votes=\'<span style="margin-left: 20px;"> (\'.$vote.\' votes)</span>\'; 
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
    'field_agency_short_name_value' => array(
      'label' => 'Agency Short Name',
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
      'format' => 'default',
      'multiple' => array(
        'group' => 1,
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_reversed' => 0,
      ),
      'exclude' => 1,
      'id' => 'field_ds_sector_nid',
      'table' => 'node_data_field_ds_sector',
      'field' => 'field_ds_sector_nid',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_2' => array(
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
      'value' => '<?php
$result=db_query("SELECT field_sector_title_value as sector FROM `content_field_ds_sector` s INNER JOIN content_type_sector sec on s.`field_ds_sector_nid`=sec.nid where s.nid=$data->nid");
$cat=\'\';
while($row=db_fetch_object($result))
{

if($cat==\'\') $cat=$row->sector;
else
$cat.=\' | \'.$row->sector;

}
return $cat;
?>',
      'exclude' => 0,
      'id' => 'phpcode_2',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('items_per_page', '0');
  $handler->override_option('style_plugin', 'views_data_export_csv');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
    'attach_text' => 'CSV',
    'provide_file' => 1,
    'filename' => '%view--%timestamp-full.csv',
    'help' => '',
    'parent_sort' => 0,
    'separator' => ',',
    'quote' => 1,
    'trim' => 1,
    'replace_newlines' => 0,
    'newline_replacement' => ':',
    'header' => 1,
    'encoding' => 'ASCII',
  ));
  $handler->override_option('row_plugin', '');
  $handler->override_option('path', 'federalagency/datasets-agency/csv');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'primary-links',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array());
  $handler->override_option('sitename_title', FALSE);
  $handler->override_option('use_batch', '0');
  $handler = $view->new_display('views_data_export', 'XLS', 'views_data_export_2');
  $handler->override_option('fields', array(
    'phpcode_1' => array(
      'label' => 'High Value',
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

$result=db_result(db_query("select * from content_type_dataset ds INNER JOIN content_type_policy_program_open_government ppog on ds.nid=ppog.nid where ds.nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' ")); 

if($result) return \'Yes\';
else return \'No\';


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
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
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
        'max_length' => '75',
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
    'phpcode' => array(
      'label' => 'Ratings',
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

$avg_rating=variable_get(\'average_rating\',0);
$avg_votes=variable_get(\'average_votes\',0);
$value=calculate_ratings($data->nid,$avg_rating,$avg_votes);


 $vote1= rate_get_results(\'node\', $data->nid, 1);
  $vote2 = rate_get_results(\'node\', $data->nid, 2);
  $vote3=rate_get_results(\'node\', $data->nid, 3);
  $vote=$vote1[\'count\'];
  if($vote2[\'count\']>$vote) $vote=$vote2[\'count\'];
  if($vote3[\'count\']>$vote)$vote=$vote3[\'count\'];                 
  		           
  $votes=\'<span style="margin-left: 20px;"> (\'.$vote.\' votes)</span>\'; 
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
    'field_agency_short_name_value' => array(
      'label' => 'Agency Short Name',
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
      'format' => 'default',
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
      'relationship' => 'none',
    ),
    'phpcode_2' => array(
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
      'value' => '<?php
$result=db_query("SELECT field_sector_title_value as sector FROM `content_field_ds_sector` s INNER JOIN content_type_sector sec on s.`field_ds_sector_nid`=sec.nid where s.nid=$data->nid");
$cat=\'\';
while($row=db_fetch_object($result))
{

if($cat==\'\') $cat=$row->sector;
else
$cat.=\' : \'.$row->sector;

}
return $cat;
?>',
      'exclude' => 1,
      'id' => 'phpcode_2',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('items_per_page', '0');
  $handler->override_option('style_plugin', 'views_data_export_xls');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
    'attach_text' => 'XLS',
    'provide_file' => 1,
    'filename' => '%view--%timestamp-full.xls',
    'help' => '',
    'parent_sort' => 0,
  ));
  $handler->override_option('row_plugin', '');
  $handler->override_option('path', 'federalagency/datasets-agency/xls');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'primary-links',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array());
  $handler->override_option('sitename_title', FALSE);
  $handler->override_option('use_batch', '0');
  $handler = $view->new_display('page', 'PDF', 'page_2');
  $handler->override_option('fields', array(
    'phpcode_1' => array(
      'label' => '',
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

$result=db_result(db_query("select * from content_type_dataset ds INNER JOIN content_type_policy_program_open_government ppog on ds.nid=ppog.nid where ds.nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' ")); 

if($result) return \'<h1>*</h1>\';


?>',
      'exclude' => 0,
      'id' => 'phpcode_1',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
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
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode' => array(
      'label' => 'Ratings',
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

$avg_rating=variable_get(\'average_rating\',0);
$avg_votes=variable_get(\'average_votes\',0);
$value=calculate_ratings($data->nid,$avg_rating,$avg_votes);


 $vote1= rate_get_results(\'node\', $data->nid, 1);
  $vote2 = rate_get_results(\'node\', $data->nid, 2);
  $vote3=rate_get_results(\'node\', $data->nid, 3);
  $vote=$vote1[\'count\'];
  if($vote2[\'count\']>$vote) $vote=$vote2[\'count\'];
  if($vote3[\'count\']>$vote)$vote=$vote3[\'count\'];                 
  		           
  $votes=\'<span> (\'.$vote.\' votes)</span>\'; 
return ($value/20).$votes;
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
    'field_agency_short_name_value' => array(
      'label' => 'Agency/Sub-Agency ',
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
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'field_ds_description_value' => array(
      'label' => 'Description',
      'alter' => array(
        'alter_text' => 1,
        'text' => '<p>[field_ds_description_value]</p>',
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
        'max_length' => '75',
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
  ));
  $handler->override_option('arguments', array(
    'field_ds_agency_name_nid' => array(
      'default_action' => 'default',
      'style_plugin' => 'default_summary',
      'style_options' => array(),
      'wildcard' => 'all',
      'wildcard_substitution' => 'All',
      'title' => '%1',
      'breadcrumb' => '',
      'default_argument_type' => 'node',
      'default_argument' => '',
      'validate_type' => 'node',
      'validate_fail' => 'not found',
      'break_phrase' => 0,
      'not' => 0,
      'id' => 'field_ds_agency_name_nid',
      'table' => 'node_data_field_ds_agency_name',
      'field' => 'field_ds_agency_name_nid',
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
        14 => 0,
        13 => 0,
        17 => 0,
        15 => 0,
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'agency' => 'agency',
        'diymap' => 0,
        'faq' => 0,
        'page' => 0,
        'imageflow' => 0,
        'flags' => 0,
        'geo_data' => 0,
        'rotating_panel' => 0,
        'access_type_downloadable' => 0,
        'access_type_embed_link' => 0,
        'access_type_execute_upon_access' => 0,
        'catalog_type_data_apps' => 0,
        'catalog_type_data_service' => 0,
        'catalog_type_data_tools' => 0,
        'catalog_type_document' => 0,
        'catalog_type_raw_data' => 0,
        'dataset' => 0,
        'geospatial_metadata' => 0,
        'openlayers_test_type' => 0,
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
      'validate_argument_vocabulary' => array(),
      'validate_argument_type' => 'tid',
      'validate_argument_transform' => 0,
      'validate_user_restrict_roles' => 0,
      'validate_argument_php' => '',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
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
      'sql_filter' => 'if($view->args[2]==1)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_raw_data\' ";
}
else if($view->args[2]==2)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_document\' ";
}
else if($view->args[2]==3)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_data_apps\' ";
}
else if($view->args[2]==4)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_data_tools\' ";
}
else if($view->args[2]==5)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_data_service\' ";
}',
      'id' => 'php',
      'table' => 'views',
      'field' => 'php',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'php_1' => array(
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
      'sql_filter' => 'if($view->args[1]==\'-\')
{
return "node_data_field_ds_agency_name.field_ds_sub_agency_nid IS NULL";
}

if(!strlen(strstr($view->args[1], "main_"))>0 )
{
return "node_data_field_ds_agency_name.field_ds_sub_agency_nid=\'".$view->args[1]."\' ";
}',
      'id' => 'php_1',
      'table' => 'views',
      'field' => 'php',
      'override' => array(
        'button' => 'Use default',
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
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('header', '<?php
	$this_page = $_SERVER[\'REQUEST_URI\'];
	$last =substr($this_page,0,strripos($this_page,\'/\'));
        $slast =substr($last,0,strripos($last,\'/\'));
	$third_last=strripos($slast,\'/\');
	$argument=substr($this_page,$third_last);
	
	//print_r($a);
	//$node=node_load($nid);
	//$title1=$node->title;

	//print \'<h2 class="page-title">\'.$title1.\'</h2>\';	
		$qpos;
     if(strlen(strstr($this_page,"?")))
      {
              $qpos=strpos($this_page,\'?\');
               
       }
	$li=strripos($this_page,\'/\');

       if($qpos!=0)
	$arg=substr($this_page,$li,2);
	else
	$arg=substr($this_page,$li);
       		
	if($arg==\'/1\'||$arg==\'/2\'||$arg==\'/3\'||$arg==\'/4\'||$arg==\'/5\')
	 {
	   $this_page=substr($this_page,0,$li);
	 } 
         global $base_url;

$view = views_get_current_view();
$arg0 = $view->args[0];
$arg1 = $view->args[1];

if($arg1==\'-\') $sub_agency=\'IS NULL\';
else $sub_agency="= $arg1";

if(!strlen(strstr($view->args[1], "main_"))>0 )
$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid  INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_raw_data\' AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_nid $sub_agency AND n.status=1"));
else
$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_raw_data\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 "));

if(!strlen(strstr($view->args[1], "main_"))>0 )
$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_document\' AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_nid $sub_agency AND n.status=1"));
else
$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_document\' AND field_ds_agency_name_nid=$arg0 AND n.status=1"));

if(!strlen(strstr($view->args[1], "main_"))>0 )
$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN (\'catalog_type_data_apps\') AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_nid $sub_agency AND n.status=1"));
else
$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN (\'catalog_type_data_apps\')  AND field_ds_agency_name_nid=$arg0 AND n.status=1"));

if(!strlen(strstr($view->args[1], "main_"))>0 )
$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_data_tools\' AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_nid $sub_agency AND n.status=1 "));
else
$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid  INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_data_tools\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 "));

if(!strlen(strstr($view->args[1], "main_"))>0 )
$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_data_service\' AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_nid $sub_agency AND n.status=1 "));
else
$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid  INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_data_service\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 "));

 print \'<div class="catalog-tabs-menu fLeft" style="margin-top:7px;">\';
	 print \'<ul class="catalog-tabs">\';
	if($arg==\'/1\' && $raw )
  	 print \'Catalog Type: Raw Dataset Catalogs\';
	
	 if($arg==\'/2\' && $doc)
  	 print \'Catalog Type: Document Catalogs\';
	
	if($arg==\'/3\' && $apps)
  	 print \'Catalog Type: App Catalogs\';

	if($arg==\'/4\' && $tool)
  	 print \'Catalog Type: Tool Catalogs\';
	
	if($arg==\'/5\' && $ser)
  	 print \'Catalog Type: Service Catalogs\';

	print\'</ul></div>\';


?>
<div class="page-title-border cBoth">&nbsp;</div>
<iframe width="1px" height="1px" style="display: none;" name="download-frame"></iframe>');
  $handler->override_option('header_empty', 1);
  $handler->override_option('footer', '
* Asterisks denote agency-reported high-value datasets. ');
  $handler->override_option('footer_format', '2');
  $handler->override_option('footer_empty', 0);
  $handler->override_option('empty', '<?php
global $base_url;

print \'<div style="font:bold 1.3em arial; padding-top:10px">No matching records found. Please try your search again or <a style="color:blue;" href="\'.$base_url.\'/suggest_dataset">suggest a dataset.</a></div>\';

?>


');
  $handler->override_option('empty_format', '3');
  $handler->override_option('use_pager', '1');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'summary' => '',
    'columns' => array(
      'phpcode_1' => 'phpcode_1',
      'title' => 'title',
      'phpcode' => 'phpcode',
      'field_agency_short_name_value' => 'field_agency_short_name_value',
      'field_sa_subagency_short_name_value' => 'field_agency_short_name_value',
      'field_ds_sector_nid' => 'field_ds_sector_nid',
      'field_ds_description_value' => 'title',
    ),
    'info' => array(
      'phpcode_1' => array(
        'separator' => '',
      ),
      'title' => array(
        'sortable' => 0,
        'separator' => '<br>',
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
      'field_ds_sector_nid' => array(
        'separator' => '',
      ),
      'field_ds_description_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => 'title',
  ));
  $handler->override_option('path', 'agency-publications/datasets-agency/pdf');
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

  // Exported view: agency_wise_report
  $view = new view;
  $view->name = 'agency_wise_report';
  $view->description = 'Agency Wise Report';
  $view->tag = '';
  $view->base_table = 'node';
  $view->core = 6;
  $view->api_version = '2';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'nid' => array(
      'label' => 'Nid',
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
      'exclude' => 1,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => 'Agency/Sub-Agency',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'content/testview2/[nid]/0/1',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '20',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'field_agency_short_name_value' => array(
      'label' => 'Agency Short Name',
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
      'id' => 'field_agency_short_name_value',
      'table' => 'node_data_field_agency_short_name',
      'field' => 'field_agency_short_name_value',
      'relationship' => 'none',
    ),
    'markup' => array(
      'label' => 'Sub-Agency Name',
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
      'hide_alter_empty' => 0,
      'value' => '',
      'format' => '1',
      'exclude' => 0,
      'id' => 'markup',
      'table' => 'customfield',
      'field' => 'markup',
      'relationship' => 'none',
    ),
    'markup_1' => array(
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
      'hide_alter_empty' => 0,
      'value' => '',
      'format' => '1',
      'exclude' => 0,
      'id' => 'markup_1',
      'table' => 'customfield',
      'field' => 'markup',
      'relationship' => 'none',
    ),
    'phpcode' => array(
      'label' => 'Raw Data',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_raw_data\')AND ds.field_ds_agency_name_nid =$data->nid AND  WF.sid=10"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid   where ( ds.field_ds_catlog_type_type =\'catalog_type_raw_data\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10  "));

if($val)
return $total.\' <span style="color:red;">(\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 1,
      'id' => 'phpcode',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_1' => array(
      'label' => 'Documents',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_document\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10
"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid where (ds.field_ds_catlog_type_type =\'catalog_type_document\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\'  AND WF.sid=10"));

if($val)
return $total.\' <span style="color:red;">(\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_1',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_2' => array(
      'label' => 'Apps',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_data_apps\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10
"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid where (ds.field_ds_catlog_type_type =\'catalog_type_data_apps\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 "));

if($val)
return $total.\' <span style="color:red;">(\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_2',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_3' => array(
      'label' => 'Tools',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_data_tools\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10
"));

$val=db_result(db_query("SELECT Count(*)  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid where (ds.field_ds_catlog_type_type =\'catalog_type_data_tools\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 "));

if($val)
return $total.\'<span style="color:red;"> (\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_3',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_6' => array(
      'label' => 'Services',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_data_service\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10
"));

$val=db_result(db_query("SELECT Count(*)  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid  where (ds.field_ds_catlog_type_type =\'catalog_type_data_service\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 "));

if($val)
return $total.\'<span style="color:red;"> (\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_6',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_4' => array(
      'label' => 'Total',
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
      'hide_alter_empty' => 0,
      'value' => '<?php


$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE ds.field_ds_agency_name_nid =$data->nid AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid where ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\' AND ds.field_ds_catlog_type_type IS NOT NULL  AND WF.sid=10"));

if($val)
return $total.\'<span style="color:red;"> (\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_4',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_5' => array(
      'label' => 'Date of Last Submission',
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
      'hide_alter_empty' => 0,
      'value' => '<?php
global $base_url;
$total=db_result(db_query("SELECT max(WF.stamp) FROM content_type_dataset ds INNER JOIN workflow_node WF On WF.nid=ds.nid   where ds.field_ds_agency_name_nid=$data->nid AND  ds.field_ds_catlog_type_type IS NOT NULL  AND WF.sid=10  "));

$result=db_query("SELECT  distinct ds.field_ds_sub_agency_nid as sub,sa.field_sa_subagency_name_value as name FROM content_type_dataset ds LEFT JOIN content_type_sub_agency as sa On sa.nid=ds.field_ds_sub_agency_nid INNER JOIN workflow_node WF on WF.nid=ds.nid where ds.field_ds_agency_name_nid=$data->nid AND WF.sid=10 AND ds.field_ds_catlog_type_type IS NOT NULL order by sa.field_sa_subagency_name_value asc  ");	

$sub_agency="";
$null_agency=\'\';
$null_sub_agency_row=\'\';
$last_sub=\'\';
$catalog_type=array(\'catalog_type_raw_data\',\'catalog_type_document\',\'catalog_type_data_apps\',\'catalog_type_data_tools\',\'catalog_type_data_service\');

while ($row = mysql_fetch_object($result)) 
{	$raw_sub=0;        $raw_sub_val=0;
        $doc_sub=0;        $doc_sub_val=0;
        $app_sub=0;        $app_sub_val=0;
        $tool_sub=0;        $tool_sub_val=0;
        $ser_sub=0;        $ser_sub_val=0;
        $total_sub=0;        $total_sub_val=0;
        $latest_sub=\'\';

if($null_agency)
{ if(strcmp($row->name,$null_agency)>0)
    {  $sub_agency.=$null_sub_agency_row ;
     $null_agency=\'\';
     }
  }

if($row->sub==null){ $sub_ag=\' IS NULL\' ;}

else  {$sub_ag=" = $row->sub"; }

$short_sub=db_result(db_query("SELECT  field_sa_subagency_short_name_value as sub FROM content_type_sub_agency sa where sa.nid $sub_ag "));	

if($short_sub!=\'\') $short_name=\' (\'.$short_sub.\')\'; else $short_name=\'\';

if($row->sub!=null){ $agency=$row->name;  $link=$row->sub;}
else
{$null_agency=$data->node_title;
 $short_name=db_result(db_query("Select field_agency_short_name_value from content_type_agency where nid=$data->nid"));
 $short_name=\' (\'. $short_name.\')\';
$link=\'-\';
}
$default=1;
$flag=0;
$sub_agency.= \'<tr class="ds-list-item-new  sub-agency-font" >\';
$cat_val=\'\';
for($i=0;$i<5;$i++)
{
$raw_sub=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON   ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE ( ds.field_ds_catlog_type_type = \'$catalog_type[$i]\') 
AND ds.field_ds_agency_name_nid =$data->nid  AND ds.field_ds_sub_agency_nid $sub_ag  AND WF.sid=10  "));

$raw_sub_val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid LEFT JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid where ( ds.field_ds_catlog_type_type =\'$catalog_type[$i]\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\' AND ds.field_ds_sub_agency_nid $sub_ag AND WF.sid=10  "));
if($raw_sub_val!=0) $raw_sub_val=\'<span style="color:red;"> (\'.$raw_sub_val.\')</span>\'; else $raw_sub_val=\'\';

if($flag==0){
if($raw_sub!=0 && $i==0) {$default=1; $flag=1;}
else if($raw_sub!=0 && $i==1){ $default=2; $flag=1;}
else if($raw_sub!=0 && $i>=2) {$default=3; $flag=1;}
}
if($row->sub==null)
$null_sub_agency_row.=\'<td style="text-align:center;">\'.$raw_sub.$raw_sub_val.\'</td>\';
else
$cat_val.=\'<td style="text-align:center;">\'.$raw_sub.$raw_sub_val.\'</td>\';

}

if($row->sub!=null)
$sub_agency.=\'<td style="padding-left:20px"><a href="\'.$base_url.\'/agency-publications/datasets-agency/\'.$data->nid.\'/\'.$link.\'/\'.$default.\'">\'.$agency.$short_name.\'</a></td>\'.$cat_val;

else
$null_sub_agency_row=\'<tr class="ds-list-item-new  sub-agency-font" ><td style="padding-left:20px"><a href="\'.$base_url.\'/agency-publications/datasets-agency/\'.$data->nid.\'/\'.$link.\'/\'.$default.\'">\'.$null_agency.$short_name.\'</a></td>\'.$null_sub_agency_row; 

$total_sub=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE ds.field_ds_agency_name_nid =$data->nid AND ds.field_ds_sub_agency_nid  $sub_ag AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10 "));

$total_sub_val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid  where  ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND ds.field_ds_sub_agency_nid  $sub_ag AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10 "));

$latest_sub=db_result(db_query("SELECT max(WF.stamp) FROM content_type_dataset ds INNER JOIN workflow_node WF On WF.nid=ds.nid  where ds.field_ds_agency_name_nid=$data->nid AND ds.field_ds_sub_agency_nid $sub_ag AND WF.sid=10 AND ds.field_ds_catlog_type_type IS NOT NULL "));

if($latest_sub==0) $latest_sub=\'\';
if($total_sub_val!=0) $total_sub_val=\' <span style="color:red;">(\'.$total_sub_val.\')</span>\'; else $total_sub_val=\'\';

if($row->sub==null)
$null_sub_agency_row.=\'<td style="text-align:center;">\'.$total_sub.$total_sub_val.\'</td><td style="text-align:center;">\'.format_date($latest_sub,\'custom\',variable_get(\'date_format_front_date_format\',\'\'),NULL,NULL).\'</td></tr>\';
else
$sub_agency.=\'<td style="text-align:center;">\'.$total_sub.$total_sub_val.\'</td><td style="text-align:center;">\'.format_date($latest_sub,\'custom\',variable_get(\'date_format_front_date_format\',\'\'),NULL,NULL).\'</td></tr>\';

$last_sub=$row->sub;
}

if($null_agency)
{ if(strcmp($last_sub,$null_agency)<0)
    {  $sub_agency.=$null_sub_agency_row ;
     $null_agency=\'\';
     }
  }

if ($total) $date=format_date($total,\'custom\',variable_get(\'date_format_front_date_format\',\'\'),NULL,NULL);
else $date=\'\';
return $date.$sub_agency;
?>',
      'exclude' => 0,
      'id' => 'phpcode_5',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('sorts', array(
    'title' => array(
      'order' => 'ASC',
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'agency' => 'agency',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => 'type_op',
        'label' => 'Node: Type',
        'use_operator' => 0,
        'identifier' => 'type',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
        'bef_select_all_none' => 0,
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'field_ds_agency_name_nid',
      'override' => array(
        'button' => 'Override',
      ),
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
      'sql_filter' => '',
      'id' => 'php',
      'table' => 'views',
      'field' => 'php',
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
  $handler->override_option('header_format', '3');
  $handler->override_option('header_empty', 0);
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'summary' => '',
    'columns' => array(
      'nid' => 'nid',
      'title' => 'title',
      'phpcode' => 'phpcode',
      'phpcode_1' => 'phpcode_1',
      'phpcode_2' => 'phpcode_2',
      'phpcode_3' => 'phpcode_3',
    ),
    'info' => array(
      'nid' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'title' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'phpcode' => array(
        'separator' => '',
      ),
      'phpcode_1' => array(
        'separator' => '',
      ),
      'phpcode_2' => array(
        'separator' => '',
      ),
      'phpcode_3' => array(
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->override_option('fields', array(
    'nid' => array(
      'label' => 'Nid',
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
      'exclude' => 1,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'none',
    ),
    'phpcode_7' => array(
      'label' => 'catalog_type',
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

$view = views_get_current_view();
$arg0 = $data->nid;
$default=1;

$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_raw_data\' AND field_ds_agency_name_nid=$arg0 AND n.status=1"));
if($raw==0)
{$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_document\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 "));
 if($doc!=0)
  $default=2;
}
if($raw==0 && $doc==0)
{
$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  where wf.sid=10 and field_ds_catlog_type_type IN (\'catalog_type_data_apps\')  AND field_ds_agency_name_nid=$arg0 AND n.status=1 "));
 if($apps!=0)
  $default=3;
 
}
if($raw==0 && $doc==0 && $apps==0)
{
$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  where wf.sid=10 and field_ds_catlog_type_type IN (\'catalog_type_data_tools\')  AND field_ds_agency_name_nid=$arg0 AND n.status=1 "));
 if($tool!=0)
  $default=4;
}
if($raw==0 && $doc==0 && $apps==0 && $tool==0){
$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  where wf.sid=10 and field_ds_catlog_type_type IN (\'catalog_type_data_service\')  AND field_ds_agency_name_nid=$arg0 AND n.status=1 "));
 if($ser!=0)
  $default=5;
}


return $default;

?>
',
      'exclude' => 1,
      'id' => 'phpcode_7',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'field_agency_short_name_value' => array(
      'label' => 'Agency Short Name',
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
      'id' => 'field_agency_short_name_value',
      'table' => 'node_data_field_agency_short_name',
      'field' => 'field_agency_short_name_value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => 'Agency/Sub-Agency/Organization',
      'alter' => array(
        'alter_text' => 1,
        'text' => '[title] ([field_agency_short_name_value])',
        'make_link' => 1,
        'path' => 'agency-publications/datasets-agency/[nid]/main_[title]/[phpcode_7]',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '[title] ',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '20',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode' => array(
      'label' => 'Raw Datasets',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_raw_data\')AND ds.field_ds_agency_name_nid =$data->nid AND  WF.sid=10 AND n.status=1"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid  where ( ds.field_ds_catlog_type_type =\'catalog_type_raw_data\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 AND n.status=1  "));

if($val)
return $total.\' <span style="color:red;">(\'.$val.\')</span>\';
else  return $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_1' => array(
      'label' => 'Documents',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_document\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10 AND n.status=1
"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid  where (ds.field_ds_catlog_type_type =\'catalog_type_document\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\'  AND WF.sid=10 AND n.status=1 "));

if($val)
return $total.\' <span style="color:red;">(\'.$val.\')</span>\';
else return $total;
?>',
      'exclude' => 0,
      'id' => 'phpcode_1',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_2' => array(
      'label' => 'Apps ',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_data_apps\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10 AND n.status=1
"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid where (ds.field_ds_catlog_type_type =\'catalog_type_data_apps\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 AND n.status=1"));

if($val)
return $total.\' <span style="color:red;">(\'.$val.\')</span>\';
else return $total;
?>',
      'exclude' => 0,
      'id' => 'phpcode_2',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_3' => array(
      'label' => 'Tools',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid  WHERE (ds.field_ds_catlog_type_type = \'catalog_type_data_tools\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10 AND n.status=1
"));

$val=db_result(db_query("SELECT Count(*)  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid  where (ds.field_ds_catlog_type_type =\'catalog_type_data_tools\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 AND n.status=1 "));

if($val)
return $total.\'<span style="color:red;"> (\'.$val.\')</span>\';
else return $total;
?>',
      'exclude' => 0,
      'id' => 'phpcode_3',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_6' => array(
      'label' => 'Services',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_data_service\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10 AND n.status=1
"));

$val=db_result(db_query("SELECT Count(*)  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid  INNER JOIN node n on ds.nid=n.nid where (ds.field_ds_catlog_type_type =\'catalog_type_data_service\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 AND n.status=1 "));

if($val)
return $total.\'<span style="color:red;"> (\'.$val.\')</span>\';
else return $total;
?>',
      'exclude' => 0,
      'id' => 'phpcode_6',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_4' => array(
      'label' => 'Total',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE ds.field_ds_agency_name_nid =$data->nid AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10 AND n.status=1"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid where ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\' AND ds.field_ds_catlog_type_type IS NOT NULL  AND WF.sid=10 AND n.status=1"));

if($val)
return $total.\'<span style="color:red;"> (\'.$val.\')</span>\';
else return $total;
?>',
      'exclude' => 0,
      'id' => 'phpcode_4',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_5' => array(
      'label' => 'Date Of Last Submission',
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
      'hide_alter_empty' => 0,
      'value' => '<?php
global $base_url;
$total=db_result(db_query("SELECT max(WF.stamp) FROM content_type_dataset ds INNER JOIN workflow_node WF On WF.nid=ds.nid   where ds.field_ds_agency_name_nid=$data->nid AND  ds.field_ds_catlog_type_type IS NOT NULL  AND WF.sid=10  "));

$result=db_query("SELECT  distinct ds.field_ds_sub_agency_nid as sub,sa.field_sa_subagency_name_value as name FROM content_type_dataset ds LEFT JOIN content_type_sub_agency as sa On sa.nid=ds.field_ds_sub_agency_nid INNER JOIN workflow_node WF on WF.nid=ds.nid where ds.field_ds_agency_name_nid=$data->nid AND WF.sid=10 AND ds.field_ds_catlog_type_type IS NOT NULL order by sa.field_sa_subagency_name_value asc  ");	

$sub_agency="";
$null_agency=\'\';
$null_sub_agency_row=\'\';
$last_sub=\'\';
$catalog_type=array(\'catalog_type_raw_data\',\'catalog_type_document\',\'catalog_type_data_apps\',\'catalog_type_data_tools\',\'catalog_type_data_service\');

while ($row = mysql_fetch_object($result)) 
{	$raw_sub=0;        $raw_sub_val=0;
        $doc_sub=0;        $doc_sub_val=0;
        $app_sub=0;        $app_sub_val=0;
        $tool_sub=0;        $tool_sub_val=0;
        $ser_sub=0;        $ser_sub_val=0;
        $total_sub=0;        $total_sub_val=0;
        $latest_sub=\'\';

if($null_agency)
{ if(strcmp($row->name,$null_agency)>0)
    {  $sub_agency.=$null_sub_agency_row ;
     $null_agency=\'\';
     }
  }

if($row->sub==null){ $sub_ag=\' IS NULL\' ;}

else  {$sub_ag=" = $row->sub"; }

$short_sub=db_result(db_query("SELECT  field_sa_subagency_short_name_value as sub FROM content_type_sub_agency sa where sa.nid $sub_ag "));	

if($short_sub!=\'\') $short_name=\' (\'.$short_sub.\')\'; else $short_name=\'\';

if($row->sub!=null){ $agency=$row->name;  $link=$row->sub;}
else
{$null_agency=$data->node_title;
 $short_name=db_result(db_query("Select field_agency_short_name_value from content_type_agency where nid=$data->nid"));
 $short_name=\' (\'. $short_name.\')\';
$link=\'-\';
}
$default=1;
$flag=0;
$sub_agency.= \'\';
$cat_val=\'\';
for($i=0;$i<5;$i++)
{
$raw_sub=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON   ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE ( ds.field_ds_catlog_type_type = \'$catalog_type[$i]\') 
AND ds.field_ds_agency_name_nid =$data->nid  AND ds.field_ds_sub_agency_nid $sub_ag  AND WF.sid=10  "));

$raw_sub_val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid LEFT JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid where ( ds.field_ds_catlog_type_type =\'$catalog_type[$i]\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\' AND ds.field_ds_sub_agency_nid $sub_ag AND WF.sid=10  "));
if($raw_sub_val!=0) $raw_sub_val=\'<span style="color:red;"> (\'.$raw_sub_val.\')</span>\'; else $raw_sub_val=\'\';

if($flag==0){
if($raw_sub!=0 && $i==0) {$default=1; $flag=1;}
else if($raw_sub!=0 && $i==1){ $default=2; $flag=1;}
else if($raw_sub!=0 && $i>=2) {$default=3; $flag=1;}
}
if($row->sub==null)
$null_sub_agency_row.=\'<td style="text-align:center;">\'.$raw_sub.$raw_sub_val.\'</td>\';
else
$cat_val.=\'<td style="text-align:center;">\'.$raw_sub.$raw_sub_val.\'</td>\';

}

if($row->sub!=null)
$sub_agency.=\'<tr class="ds-list-item-new  sub-agency-font" ><td style="padding-left:20px"><a href="\'.$base_url.\'/agency-publications/datasets-agency/\'.$data->nid.\'/\'.$link.\'/\'.$default.\'">\'.$agency.$short_name.\'</a></td>\'.$cat_val;

else
$null_sub_agency_row=\'<tr class="ds-list-item-new  sub-agency-font" ><td style="padding-left:20px"><a href="\'.$base_url.\'/agency-publications/datasets-agency/\'.$data->nid.\'/\'.$link.\'/\'.$default.\'">\'.$null_agency.$short_name.\'</a></td>\'.$null_sub_agency_row; 

$total_sub=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE ds.field_ds_agency_name_nid =$data->nid AND ds.field_ds_sub_agency_nid  $sub_ag AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10 "));

$total_sub_val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid  where  ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND ds.field_ds_sub_agency_nid  $sub_ag AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10 "));

$latest_sub=db_result(db_query("SELECT max(WF.stamp) FROM content_type_dataset ds INNER JOIN workflow_node WF On WF.nid=ds.nid  where ds.field_ds_agency_name_nid=$data->nid AND ds.field_ds_sub_agency_nid $sub_ag AND WF.sid=10 AND ds.field_ds_catlog_type_type IS NOT NULL "));

if($latest_sub==0) $latest_sub=\'\';
if($total_sub_val!=0) $total_sub_val=\' <span style="color:red;">(\'.$total_sub_val.\')</span>\'; else $total_sub_val=\'\';

if($row->sub==null)
$null_sub_agency_row.=\'<td style="text-align:center;">\'.$total_sub.$total_sub_val.\'</td><td style="text-align:center;">\'.format_date($latest_sub,\'custom\',variable_get(\'date_format_front_date_format\',\'\'),NULL,NULL).\'</td></tr>\';
else
$sub_agency.=\'<td style="text-align:center;">\'.$total_sub.$total_sub_val.\'</td><td style="text-align:center;">\'.format_date($latest_sub,\'custom\',variable_get(\'date_format_front_date_format\',\'\'),NULL,NULL).\'</td></tr>\';

$last_sub=$row->sub;
}

if($null_agency)
{ if(strcmp($last_sub,$null_agency)<0)
    {  $sub_agency.=$null_sub_agency_row ;
     $null_agency=\'\';
     }
  }

if ($total) $date=format_date($total,\'custom\',variable_get(\'date_format_front_date_format\',\'\'),NULL,NULL);
else $date=\'\';
return $date.$sub_agency;
?>',
      'exclude' => 0,
      'id' => 'phpcode_5',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'agency' => 'agency',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => 'type_op',
        'label' => 'Node: Type',
        'use_operator' => 0,
        'identifier' => 'type',
        'bef_filter_description' => '',
        'bef_format' => 'default',
        'optional' => 1,
        'single' => 1,
        'remember' => 0,
        'reduce' => 0,
        'bef_select_all_none' => 0,
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
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
      'php_filter' => '$res=db_result(db_query("select count(*) from content_type_dataset  DS  Left Join workflow_node WF on DS.nid=WF.nid where WF.sid=10 AND DS.field_ds_agency_name_nid=$data->nid AND DS.field_ds_catlog_type_type IS NOT NULL"));
if($res>0) return false;
else return true;',
      'sql_filter' => '',
      'id' => 'php',
      'table' => 'views',
      'field' => 'php',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'Agency Wise');
  $handler->override_option('header', '<?php

global $base_url;

print \'<h1 class="metrics-visitorstats-table-heading fLeft">Agency Wise</h1>\';

print \'<div class="download-report">Download report as: <a title="CSV Download"  class="hyperlink"  href="\'.$base_url.\'/federalagency/agency-wise/csv"><img alt="CSV" src="[token global site-url]sites/all/themes/ogpl_css3/images/csv.png" /></a> \' ;

print \'<a title="XLS Download"  class="hyperlink" href="\'.$base_url.\'/federalagency/agency-wise/xls"><img alt="XLS" src="[token global site-url]sites/all/themes/ogpl_css3/images/xls.png" /></a>\';

print \'<a style="padding-left:3px;" title="PDF Download" class="hyperlink" href="\'.$base_url.\'/printpdf/agency-publications/agency-wise/pdf"><img alt="PDF" src="[token global site-url]sites/all/themes/ogpl_css3/images/pdf.png" /></a></div>\';

print \'<div style="display:inline-block;"><p>OGPL offers a platform for government agencies to publish their raw datasets, documents, apps, tools and services, allowing important and featured ones to be marked as high value datasets. Get a consolidated view of Agency/Sub-Agency wise publications right here. Drill down to view individual datasets.</p></div>\';

?>
');
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'summary' => '',
    'columns' => array(
      'nid' => 'nid',
      'field_agency_short_name_value' => 'field_agency_short_name_value',
      'title' => 'title',
      'phpcode' => 'phpcode',
      'phpcode_1' => 'phpcode_1',
      'phpcode_2' => 'phpcode_2',
      'phpcode_3' => 'phpcode_3',
      'phpcode_6' => 'phpcode_6',
      'phpcode_4' => 'phpcode_4',
      'phpcode_5' => 'phpcode_5',
    ),
    'info' => array(
      'nid' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_agency_short_name_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'title' => array(
        'sortable' => 1,
        'separator' => '',
      ),
      'phpcode' => array(
        'separator' => '',
      ),
      'phpcode_1' => array(
        'separator' => '',
      ),
      'phpcode_2' => array(
        'separator' => '',
      ),
      'phpcode_3' => array(
        'separator' => '',
      ),
      'phpcode_6' => array(
        'separator' => '',
      ),
      'phpcode_4' => array(
        'separator' => '',
      ),
      'phpcode_5' => array(
        'separator' => '',
      ),
    ),
    'default' => 'title',
  ));
  $handler->override_option('path', 'agency-publications/agency-wise');
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
  $handler = $view->new_display('views_data_export', 'CSV', 'views_data_export_1');
  $handler->override_option('fields', array(
    'nid' => array(
      'label' => 'Nid',
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
      'exclude' => 1,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => 'Agency',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'content/testview2/[nid]/1',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '20',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'field_agency_short_name_value' => array(
      'label' => 'Agency Short Name',
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
      'exclude' => 0,
      'id' => 'field_agency_short_name_value',
      'table' => 'node_data_field_agency_short_name',
      'field' => 'field_agency_short_name_value',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'markup' => array(
      'label' => 'Sub-Agency Name',
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
      'hide_alter_empty' => 0,
      'value' => '',
      'format' => '1',
      'exclude' => 0,
      'id' => 'markup',
      'table' => 'customfield',
      'field' => 'markup',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'markup_1' => array(
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
      'hide_alter_empty' => 0,
      'value' => '',
      'format' => '1',
      'exclude' => 0,
      'id' => 'markup_1',
      'table' => 'customfield',
      'field' => 'markup',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode' => array(
      'label' => 'Raw Datasets (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_raw_data\')AND ds.field_ds_agency_name_nid =$data->nid AND  WF.sid=10 AND n.status=1"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid  where ( ds.field_ds_catlog_type_type =\'catalog_type_raw_data\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 AND n.status=1  "));

if($val)
return $total.\' <span style="color:red;">(\'.$val.\')</span>\';
else return $total
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
    'phpcode_1' => array(
      'label' => 'Documents (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_document\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10 AND n.status=1
"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid  where (ds.field_ds_catlog_type_type =\'catalog_type_document\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\'  AND WF.sid=10 AND n.status=1 "));

if($val)
return $total.\' <span style="color:red;">(\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_1',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_2' => array(
      'label' => 'Apps (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_data_apps\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10 AND n.status=1
"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid where (ds.field_ds_catlog_type_type =\'catalog_type_data_apps\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 AND n.status=1"));

if($val)
return $total.\' <span style="color:red;">(\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_2',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_3' => array(
      'label' => 'Tools (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid  WHERE (ds.field_ds_catlog_type_type = \'catalog_type_data_tools\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10 AND n.status=1
"));

$val=db_result(db_query("SELECT Count(*)  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid  where (ds.field_ds_catlog_type_type =\'catalog_type_data_tools\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 AND n.status=1 "));

if($val)
return $total.\'<span style="color:red;"> (\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_3',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_6' => array(
      'label' => 'Services (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_data_service\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10 AND n.status=1
"));

$val=db_result(db_query("SELECT Count(*)  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid  INNER JOIN node n on ds.nid=n.nid where (ds.field_ds_catlog_type_type =\'catalog_type_data_service\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 AND n.status=1 "));

if($val)
return $total.\'<span style="color:red;"> (\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_6',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_4' => array(
      'label' => 'Total (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE ds.field_ds_agency_name_nid =$data->nid AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10 AND n.status=1"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid where ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\' AND ds.field_ds_catlog_type_type IS NOT NULL  AND WF.sid=10 AND n.status=1"));

if($val)
return $total.\'<span style="color:red;"> (\'.$val.\')</span>\';
else return $total
?>
',
      'exclude' => 0,
      'id' => 'phpcode_4',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_5' => array(
      'label' => 'Date Of last Submission',
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
      'hide_alter_empty' => 0,
      'value' => '<?php
global $base_url;
$total=db_result(db_query("SELECT max(WF.stamp) FROM content_type_dataset ds INNER JOIN workflow_node WF On WF.nid=ds.nid   where ds.field_ds_agency_name_nid=$data->nid AND  ds.field_ds_catlog_type_type IS NOT NULL  AND WF.sid=10  "));

$result=db_query("SELECT  distinct ds.field_ds_sub_agency_nid as sub,sa.field_sa_subagency_name_value as name FROM content_type_dataset ds LEFT JOIN content_type_sub_agency as sa On sa.nid=ds.field_ds_sub_agency_nid INNER JOIN workflow_node WF on WF.nid=ds.nid where ds.field_ds_agency_name_nid=$data->nid AND WF.sid=10 AND ds.field_ds_catlog_type_type IS NOT NULL order by sa.field_sa_subagency_name_value asc  ");	

$sub_agency="";
$null_agency=\'\';
$null_sub_agency_row=\'\';
$last_sub=\'\';
$catalog_type=array(\'catalog_type_raw_data\',\'catalog_type_document\',\'catalog_type_data_apps\',\'catalog_type_data_tools\',\'catalog_type_data_service\');

while ($row = mysql_fetch_object($result)) 
{	$raw_sub=0;        $raw_sub_val=0;
        $doc_sub=0;        $doc_sub_val=0;
        $app_sub=0;        $app_sub_val=0;
        $tool_sub=0;        $tool_sub_val=0;
        $ser_sub=0;        $ser_sub_val=0;
        $total_sub=0;        $total_sub_val=0;
        $latest_sub=\'\';

if($null_agency)
{ if(strcmp($row->name,$null_agency)>0)
    {  $sub_agency.=$null_sub_agency_row ;
     $null_agency=\'\';
     }
  }

if($row->sub==null){ $sub_ag=\' IS NULL\' ;}

else  {$sub_ag=" = $row->sub"; }

$short_sub=db_result(db_query("SELECT  field_sa_subagency_short_name_value as sub FROM content_type_sub_agency sa where  sa.nid $sub_ag "));	

if($short_sub!=\'\') $short_name=\' ,\'.$short_sub.\'\'; else $short_name=\',\';

if($row->sub!=null){ $agency=$row->name;  $link=$row->sub;}
else
{$null_agency=$data->node_title;
 $short_name=db_result(db_query("Select field_agency_short_name_value from content_type_agency where nid=$data->nid"));
 $short_name=\' ,\'. $short_name.\'\';
$link=\'-\';
}
$default=1;
$flag=0;
$sub_agency.= \'\';
$cat_val=\'\';
for($i=0;$i<5;$i++)
{
$raw_sub=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON   ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE ( ds.field_ds_catlog_type_type = \'$catalog_type[$i]\') 
AND ds.field_ds_agency_name_nid =$data->nid  AND ds.field_ds_sub_agency_nid $sub_ag  AND WF.sid=10  "));

$raw_sub_val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid LEFT JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid where ( ds.field_ds_catlog_type_type =\'$catalog_type[$i]\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\' AND ds.field_ds_sub_agency_nid $sub_ag AND WF.sid=10  "));
if($raw_sub_val!=0) $raw_sub_val=\'<span style="color:red;"> (\'.$raw_sub_val.\')</span>\'; else $raw_sub_val=\'\';

if($flag==0){
if($raw_sub!=0 && $i==0) {$default=1; $flag=1;}
else if($raw_sub!=0 && $i==1){ $default=2; $flag=1;}
else if($raw_sub!=0 && $i>=2) {$default=3; $flag=1;}
}
if($row->sub==null)
$null_sub_agency_row.=\'<td style="text-align:center;">\'.$raw_sub.$raw_sub_val.\'</td>,\';
else
$cat_val.=\'<td style="text-align:center;">\'.$raw_sub.$raw_sub_val.\'</td>,\';

}

if($row->sub!=null)
$sub_agency.=\'
, ,<tr class="ds-list-item-new  sub-agency-font" ><td style="padding-left:20px"><a href="\'.$base_url.\'/agency-publications/datasets-agency/\'.$data->nid.\'/\'.$link.\'/\'.$default.\'">\'.$agency.$short_name.\'</a></td>,\'.$cat_val;

else
$null_sub_agency_row=\'
, ,<tr  class="ds-list-item-new  sub-agency-font" ><td style="padding-left:20px"><a href="\'.$base_url.\'/agency-publications/datasets-agency/\'.$data->nid.\'/\'.$link.\'/\'.$default.\'">\'.$null_agency.$short_name.\'</a></td>,\'.$null_sub_agency_row; 

$total_sub=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE ds.field_ds_agency_name_nid =$data->nid AND ds.field_ds_sub_agency_nid  $sub_ag AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10 "));

$total_sub_val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid  where  ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND ds.field_ds_sub_agency_nid  $sub_ag AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10 "));

$latest_sub=db_result(db_query("SELECT max(WF.stamp) FROM content_type_dataset ds INNER JOIN workflow_node WF On WF.nid=ds.nid  where ds.field_ds_agency_name_nid=$data->nid AND ds.field_ds_sub_agency_nid $sub_ag AND WF.sid=10 AND ds.field_ds_catlog_type_type IS NOT NULL "));

if($latest_sub==0) $latest_sub=\'\';
if($total_sub_val!=0) $total_sub_val=\' <span style="color:red;">(\'.$total_sub_val.\')</span>\'; else $total_sub_val=\'\';

if($row->sub==null)
$null_sub_agency_row.=\'<td style="text-align:center;">\'.$total_sub.$total_sub_val.\'</td><td style="text-align:center;">\'.format_date($latest_sub,\'custom\',variable_get(\'date_format_front_date_format\',\'\'),NULL,NULL).\'</td></tr>\';
else
$sub_agency.=\'<td style="text-align:center;">\'.$total_sub.$total_sub_val.\'</td><td style="text-align:center;">\'.format_date($latest_sub,\'custom\',variable_get(\'date_format_front_date_format\',\'\'),NULL,NULL).\'</td></tr>\';

$last_sub=$row->sub;
}

if($null_agency)
{ if(strcmp($last_sub,$null_agency)<0)
    {  $sub_agency.=$null_sub_agency_row ;
     $null_agency=\'\';
     }
  }

$date=format_date($total,\'custom\',variable_get(\'date_format_front_date_format\',\'\'),NULL,NULL);
return $date.$sub_agency;
?>',
      'exclude' => 0,
      'id' => 'phpcode_5',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'CSV');
  $handler->override_option('items_per_page', '0');
  $handler->override_option('style_plugin', 'views_data_export_csv');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
    'attach_text' => 'CSV',
    'provide_file' => 1,
    'filename' => '%view--%timestamp-full.csv',
    'help' => '',
    'parent_sort' => 0,
    'separator' => ',',
    'quote' => 0,
    'trim' => 1,
    'replace_newlines' => 0,
    'newline_replacement' => '',
    'header' => 1,
    'encoding' => 'ASCII',
  ));
  $handler->override_option('row_plugin', '');
  $handler->override_option('path', 'federalagency/agency-wise/csv');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'primary-links',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array());
  $handler->override_option('sitename_title', 0);
  $handler->override_option('use_batch', '0');
  $handler = $view->new_display('views_data_export', 'XLS', 'views_data_export_2');
  $handler->override_option('fields', array(
    'nid' => array(
      'label' => 'Nid',
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
      'exclude' => 1,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'title' => array(
      'label' => 'Agency',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'content/testview2/[nid]/1',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 1,
        'max_length' => '20',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'field_agency_short_name_value' => array(
      'label' => 'Agency Short Name',
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
      'exclude' => 0,
      'id' => 'field_agency_short_name_value',
      'table' => 'node_data_field_agency_short_name',
      'field' => 'field_agency_short_name_value',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'markup' => array(
      'label' => 'Sub-Agency Name',
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
      'hide_alter_empty' => 0,
      'value' => '',
      'format' => '1',
      'exclude' => 0,
      'id' => 'markup',
      'table' => 'customfield',
      'field' => 'markup',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'markup_1' => array(
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
      'hide_alter_empty' => 0,
      'value' => '',
      'format' => '1',
      'exclude' => 0,
      'id' => 'markup_1',
      'table' => 'customfield',
      'field' => 'markup',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode' => array(
      'label' => 'Raw Datasets (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_raw_data\')AND ds.field_ds_agency_name_nid =$data->nid AND  WF.sid=10 AND n.status=1"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid  where ( ds.field_ds_catlog_type_type =\'catalog_type_raw_data\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 AND n.status=1  "));

if($val)
return $total.\' <span style="color:red;">(\'.$val.\')</span>\';
else return $total;
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
    'phpcode_1' => array(
      'label' => 'Documents (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_document\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10 AND n.status=1
"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid  where (ds.field_ds_catlog_type_type =\'catalog_type_document\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\'  AND WF.sid=10 AND n.status=1 "));

if($val)
return $total.\' <span style="color:red;">(\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_1',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_2' => array(
      'label' => 'Apps (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_data_apps\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10 AND n.status=1
"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid where (ds.field_ds_catlog_type_type =\'catalog_type_data_apps\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 AND n.status=1"));

if($val)
return $total.\' <span style="color:red;">(\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_2',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_3' => array(
      'label' => 'Tools (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid  WHERE (ds.field_ds_catlog_type_type = \'catalog_type_data_tools\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10 AND n.status=1
"));

$val=db_result(db_query("SELECT Count(*)  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid  where (ds.field_ds_catlog_type_type =\'catalog_type_data_tools\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 AND n.status=1 "));

if($val)
return $total.\'<span style="color:red;"> (\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_3',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_6' => array(
      'label' => 'Services (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_data_service\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10 AND n.status=1
"));

$val=db_result(db_query("SELECT Count(*)  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid  INNER JOIN node n on ds.nid=n.nid where (ds.field_ds_catlog_type_type =\'catalog_type_data_service\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 AND n.status=1 "));

if($val)
return $total.\'<span style="color:red;"> (\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_6',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_4' => array(
      'label' => 'Total (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE ds.field_ds_agency_name_nid =$data->nid AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10 AND n.status=1"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid where ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\' AND ds.field_ds_catlog_type_type IS NOT NULL  AND WF.sid=10 AND n.status=1"));

if($val)
return $total.\'<span style="color:red;"> (\'.$val.\')</span>\';
else return $total
?>
',
      'exclude' => 0,
      'id' => 'phpcode_4',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_5' => array(
      'label' => 'Date Of Last Submission',
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
      'hide_alter_empty' => 0,
      'value' => '<?php
global $base_url;
$total=db_result(db_query("SELECT max(WF.stamp) FROM content_type_dataset ds INNER JOIN workflow_node WF On WF.nid=ds.nid   where ds.field_ds_agency_name_nid=$data->nid AND  ds.field_ds_catlog_type_type IS NOT NULL  AND WF.sid=10  "));

$result=db_query("SELECT  distinct ds.field_ds_sub_agency_nid as sub,sa.field_sa_subagency_name_value as name FROM content_type_dataset ds LEFT JOIN content_type_sub_agency as sa On sa.nid=ds.field_ds_sub_agency_nid INNER JOIN workflow_node WF on WF.nid=ds.nid where ds.field_ds_agency_name_nid=$data->nid AND WF.sid=10 AND ds.field_ds_catlog_type_type IS NOT NULL order by sa.field_sa_subagency_name_value asc  ");	

$sub_agency="";
$null_agency=\'\';
$null_sub_agency_row=\'\';
$last_sub=\'\';
$catalog_type=array(\'catalog_type_raw_data\',\'catalog_type_document\',\'catalog_type_data_apps\',\'catalog_type_data_tools\',\'catalog_type_data_service\');

while ($row = mysql_fetch_object($result)) 
{	$raw_sub=0;        $raw_sub_val=0;
        $doc_sub=0;        $doc_sub_val=0;
        $app_sub=0;        $app_sub_val=0;
        $tool_sub=0;        $tool_sub_val=0;
        $ser_sub=0;        $ser_sub_val=0;
        $total_sub=0;        $total_sub_val=0;
        $latest_sub=\'\';

if($null_agency)
{ if(strcmp($row->name,$null_agency)>0)
    {  $sub_agency.=$null_sub_agency_row ;
     $null_agency=\'\';
     }
  }

if($row->sub==null){ $sub_ag=\' IS NULL\' ;}

else  {$sub_ag=" = $row->sub"; }

$short_sub=db_result(db_query("SELECT  field_sa_subagency_short_name_value as sub FROM content_type_sub_agency sa where sa.field_sa_subagency_agency_nid=$data->nid  AND sa.nid $sub_ag "));	

if($short_sub!=\'\') $short_name=\'\'.$short_sub.\'\'; else $short_name=\'\';

if($row->sub!=null){ $agency=$row->name;  $link=$row->sub;}
else
{$null_agency=$data->node_title;
 $short_name=db_result(db_query("Select field_agency_short_name_value from content_type_agency where nid=$data->nid"));
 $short_name=\'\'. $short_name.\'\';
$link=\'-\';
}
$default=1;
$flag=0;
$sub_agency.= \'\';
$cat_val=\'\';
for($i=0;$i<5;$i++)
{
$raw_sub=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON   ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE ( ds.field_ds_catlog_type_type = \'$catalog_type[$i]\') 
AND ds.field_ds_agency_name_nid =$data->nid  AND ds.field_ds_sub_agency_nid $sub_ag  AND WF.sid=10  "));

$raw_sub_val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid LEFT JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid where ( ds.field_ds_catlog_type_type =\'$catalog_type[$i]\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\' AND ds.field_ds_sub_agency_nid $sub_ag AND WF.sid=10  "));
if($raw_sub_val!=0) $raw_sub_val=\'<span style="color:red;"> (\'.$raw_sub_val.\')</span>\'; else $raw_sub_val=\'\';

if($flag==0){
if($raw_sub!=0 && $i==0) {$default=1; $flag=1;}
else if($raw_sub!=0 && $i==1){ $default=2; $flag=1;}
else if($raw_sub!=0 && $i>=2) {$default=3; $flag=1;}
}
if($row->sub==null)
$null_sub_agency_row.=\'<td style="text-align:center;">\'.$raw_sub.$raw_sub_val.\'</td>\';
else
$cat_val.=\'<td style="text-align:center;">\'.$raw_sub.$raw_sub_val.\'</td>\';

}

if($row->sub!=null)
$sub_agency.=\'<tr class="ds-list-item-new  sub-agency-font" ><td></td><td></td><td style="padding-left:20px"><a href="\'.$base_url.\'/agency-publications/datasets-agency/\'.$data->nid.\'/\'.$link.\'/\'.$default.\'">\'.$agency.\'</td><td>\'.$short_name.\'</a></td>\'.$cat_val;

else
$null_sub_agency_row=\'<tr  class="ds-list-item-new  sub-agency-font" ><td></td><td></td><td style="padding-left:20px"><a href="\'.$base_url.\'/agency-publications/datasets-agency/\'.$data->nid.\'/\'.$link.\'/\'.$default.\'">\'.$null_agency.\'</td><td>\'.$short_name.\'</a></td>\'.$null_sub_agency_row; 

$total_sub=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE ds.field_ds_agency_name_nid =$data->nid AND ds.field_ds_sub_agency_nid  $sub_ag AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10 "));

$total_sub_val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid  where  ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND ds.field_ds_sub_agency_nid  $sub_ag AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10 "));

$latest_sub=db_result(db_query("SELECT max(WF.stamp) FROM content_type_dataset ds INNER JOIN workflow_node WF On WF.nid=ds.nid  where ds.field_ds_agency_name_nid=$data->nid AND ds.field_ds_sub_agency_nid $sub_ag AND WF.sid=10 AND ds.field_ds_catlog_type_type IS NOT NULL "));

if($latest_sub==0) $latest_sub=\'\';
if($total_sub_val!=0) $total_sub_val=\' <span style="color:red;">(\'.$total_sub_val.\')</span>\'; else $total_sub_val=\'\';

if($row->sub==null)
$null_sub_agency_row.=\'<td style="text-align:center;">\'.$total_sub.$total_sub_val.\'</td><td style="text-align:center;">\'.format_date($latest_sub,\'custom\',variable_get(\'date_format_front_date_format\',\'\'),NULL,NULL).\'</td></tr>\';
else
$sub_agency.=\'<td style="text-align:center;">\'.$total_sub.$total_sub_val.\'</td><td style="text-align:center;">\'.format_date($latest_sub,\'custom\',variable_get(\'date_format_front_date_format\',\'\'),NULL,NULL).\'</td></tr>\';

$last_sub=$row->sub;
}

if($null_agency)
{ if(strcmp($last_sub,$null_agency)<0)
    {  $sub_agency.=$null_sub_agency_row ;
     $null_agency=\'\';
     }
  }
$date=format_date($total,\'custom\',variable_get(\'date_format_front_date_format\',\'\'),NULL,NULL);
return $date.$sub_agency;
?>',
      'exclude' => 0,
      'id' => 'phpcode_5',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('items_per_page', '0');
  $handler->override_option('style_plugin', 'views_data_export_xls');
  $handler->override_option('style_options', array(
    'mission_description' => FALSE,
    'description' => '',
    'attach_text' => 'XLS',
    'provide_file' => 1,
    'filename' => '%view--%timestamp-full .xls',
    'help' => '',
    'parent_sort' => 0,
  ));
  $handler->override_option('row_plugin', '');
  $handler->override_option('path', 'federalagency/agency-wise/xls');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'primary-links',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('displays', array(
    'default' => 'default',
    'page_1' => 0,
  ));
  $handler->override_option('sitename_title', FALSE);
  $handler->override_option('use_batch', '0');
  $handler = $view->new_display('page', 'PDF', 'page_2');
  $handler->override_option('fields', array(
    'nid' => array(
      'label' => 'Nid',
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
      'exclude' => 1,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'relationship' => 'none',
    ),
    'phpcode_7' => array(
      'label' => 'catalog_type',
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

$view = views_get_current_view();
$arg0 = $data->nid;
$default=1;

$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_raw_data\' AND field_ds_agency_name_nid=$arg0 AND n.status=1"));
if($raw==0)
{$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_document\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 "));
 if($doc!=0)
  $default=2;
}
if($raw==0 && $doc==0)
{
$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  where wf.sid=10 and field_ds_catlog_type_type IN (\'catalog_type_data_apps\')  AND field_ds_agency_name_nid=$arg0 AND n.status=1 "));
 if($apps!=0)
  $default=3;
 
}
if($raw==0 && $doc==0 && $apps==0)
{
$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  where wf.sid=10 and field_ds_catlog_type_type IN (\'catalog_type_data_tools\')  AND field_ds_agency_name_nid=$arg0 AND n.status=1 "));
 if($tool!=0)
  $default=4;
}
if($raw==0 && $doc==0 && $apps==0 && $tool==0){
$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  where wf.sid=10 and field_ds_catlog_type_type IN (\'catalog_type_data_service\')  AND field_ds_agency_name_nid=$arg0 AND n.status=1 "));
 if($ser!=0)
  $default=5;
}


return $default;

?>
',
      'exclude' => 1,
      'id' => 'phpcode_7',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'field_agency_short_name_value' => array(
      'label' => 'Agency Short Name',
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
      'id' => 'field_agency_short_name_value',
      'table' => 'node_data_field_agency_short_name',
      'field' => 'field_agency_short_name_value',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'title' => array(
      'label' => 'Agency/Sub-Agency/Organization',
      'alter' => array(
        'alter_text' => 1,
        'text' => '[title] ([field_agency_short_name_value])',
        'make_link' => 1,
        'path' => 'agency-publications/datasets-agency/[nid]/main_[title]/[phpcode_7]',
        'absolute' => 0,
        'link_class' => '',
        'alt' => '',
        'rel' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '20',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'html' => 0,
        'strip_tags' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode' => array(
      'label' => 'Raw Datasets (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_raw_data\')AND ds.field_ds_agency_name_nid =$data->nid AND  WF.sid=10 AND n.status=1"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid  where ( ds.field_ds_catlog_type_type =\'catalog_type_raw_data\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 AND n.status=1  "));

if($val)
return $total.\' <span style="color:red;">(\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_1' => array(
      'label' => 'Documents (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_document\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10 AND n.status=1
"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid  where (ds.field_ds_catlog_type_type =\'catalog_type_document\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\'  AND WF.sid=10 AND n.status=1 "));

if($val)
return $total.\' <span style="color:red;">(\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_1',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_2' => array(
      'label' => 'Apps (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_data_apps\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10 AND n.status=1
"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid where (ds.field_ds_catlog_type_type =\'catalog_type_data_apps\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 AND n.status=1"));

if($val)
return $total.\' <span style="color:red;">(\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_2',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_3' => array(
      'label' => 'Tools (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid  WHERE (ds.field_ds_catlog_type_type = \'catalog_type_data_tools\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10 AND n.status=1
"));

$val=db_result(db_query("SELECT Count(*)  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid  where (ds.field_ds_catlog_type_type =\'catalog_type_data_tools\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 AND n.status=1 "));

if($val)
return $total.\'<span style="color:red;"> (\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_3',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_6' => array(
      'label' => 'Services (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE (ds.field_ds_catlog_type_type = \'catalog_type_data_service\')
AND 
ds.field_ds_agency_name_nid =$data->nid AND WF.sid=10 AND n.status=1
"));

$val=db_result(db_query("SELECT Count(*)  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid  INNER JOIN node n on ds.nid=n.nid where (ds.field_ds_catlog_type_type =\'catalog_type_data_service\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND WF.sid=10 AND n.status=1 "));

if($val)
return $total.\'<span style="color:red;"> (\'.$val.\')</span>\';
else return $total
?>',
      'exclude' => 0,
      'id' => 'phpcode_6',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_4' => array(
      'label' => 'Total (high-value)',
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
      'hide_alter_empty' => 0,
      'value' => '<?php

$total=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid WHERE ds.field_ds_agency_name_nid =$data->nid AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10 AND n.status=1"));

$val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid INNER JOIN node n on ds.nid=n.nid where ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\' AND ds.field_ds_catlog_type_type IS NOT NULL  AND WF.sid=10 AND n.status=1"));

if($val)
return $total.\'<span style="color:red;"> (\'.$val.\')</span>\';
else return $total
?>
',
      'exclude' => 0,
      'id' => 'phpcode_4',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_5' => array(
      'label' => 'Date Of Last Submission',
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
      'hide_alter_empty' => 0,
      'value' => '<?php
global $base_url;
$total=db_result(db_query("SELECT max(WF.stamp) FROM content_type_dataset ds INNER JOIN workflow_node WF On WF.nid=ds.nid   where ds.field_ds_agency_name_nid=$data->nid AND  ds.field_ds_catlog_type_type IS NOT NULL  AND WF.sid=10  "));

$result=db_query("SELECT  distinct ds.field_ds_sub_agency_nid as sub,sa.field_sa_subagency_name_value as name FROM content_type_dataset ds LEFT JOIN content_type_sub_agency as sa On sa.nid=ds.field_ds_sub_agency_nid INNER JOIN workflow_node WF on WF.nid=ds.nid where ds.field_ds_agency_name_nid=$data->nid AND WF.sid=10 AND ds.field_ds_catlog_type_type IS NOT NULL order by sa.field_sa_subagency_name_value asc  ");	

$sub_agency="";
$null_agency=\'\';
$null_sub_agency_row=\'\';
$last_sub=\'\';
$catalog_type=array(\'catalog_type_raw_data\',\'catalog_type_document\',\'catalog_type_data_apps\',\'catalog_type_data_tools\',\'catalog_type_data_service\');

while ($row = mysql_fetch_object($result)) 
{	$raw_sub=0;        $raw_sub_val=0;
        $doc_sub=0;        $doc_sub_val=0;
        $app_sub=0;        $app_sub_val=0;
        $tool_sub=0;        $tool_sub_val=0;
        $ser_sub=0;        $ser_sub_val=0;
        $total_sub=0;        $total_sub_val=0;
        $latest_sub=\'\';

if($null_agency)
{ if(strcmp($row->name,$null_agency)>0)
    {  $sub_agency.=$null_sub_agency_row ;
     $null_agency=\'\';
     }
  }

if($row->sub==null){ $sub_ag=\' IS NULL\' ;}

else  {$sub_ag=" = $row->sub"; }

$short_sub=db_result(db_query("SELECT  field_sa_subagency_short_name_value as sub FROM content_type_sub_agency sa where  sa.nid $sub_ag "));	

if($short_sub!=\'\') $short_name=\' (\'.$short_sub.\')\'; else $short_name=\'\';

if($row->sub!=null){ $agency=$row->name;  $link=$row->sub;}
else
{$null_agency=$data->node_title;
 $short_name=db_result(db_query("Select field_agency_short_name_value from content_type_agency where nid=$data->nid"));
 $short_name=\' (\'. $short_name.\')\';
$link=\'-\';
}
$default=1;
$flag=0;
$sub_agency.= \'\';
$cat_val=\'\';
for($i=0;$i<5;$i++)
{
$raw_sub=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON   ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE ( ds.field_ds_catlog_type_type = \'$catalog_type[$i]\') 
AND ds.field_ds_agency_name_nid =$data->nid  AND ds.field_ds_sub_agency_nid $sub_ag  AND WF.sid=10  "));

$raw_sub_val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid LEFT JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid INNER JOIN workflow_node WF On WF.nid=ds.nid where ( ds.field_ds_catlog_type_type =\'$catalog_type[$i]\') AND ds.field_ds_agency_name_nid=$data->nid AND ppog.	field_ppog_high_value_dataset_value=\'Yes\' AND ds.field_ds_sub_agency_nid $sub_ag AND WF.sid=10  "));
if($raw_sub_val!=0) $raw_sub_val=\'<span style="color:red;"> (\'.$raw_sub_val.\')</span>\'; else $raw_sub_val=\'\';

if($flag==0){
if($raw_sub!=0 && $i==0) {$default=1; $flag=1;}
else if($raw_sub!=0 && $i==1){ $default=2; $flag=1;}
else if($raw_sub!=0 && $i>=2) {$default=3; $flag=1;}
}
if($row->sub==null)
$null_sub_agency_row.=\'<td style="text-align:center;">\'.$raw_sub.$raw_sub_val.\'</td>\';
else
$cat_val.=\'<td style="text-align:center;">\'.$raw_sub.$raw_sub_val.\'</td>\';

}

if($row->sub!=null)
$sub_agency.=\'<tr class="ds-list-item-new  sub-agency-font" ><td style="padding-left:20px"><a href="\'.$base_url.\'/agency-publications/datasets-agency/\'.$data->nid.\'/\'.$link.\'/\'.$default.\'">\'.$agency.$short_name.\'</a></td>\'.$cat_val;

else
$null_sub_agency_row=\'<tr class="ds-list-item-new  sub-agency-font" ><td style="padding-left:20px"><a href="\'.$base_url.\'/agency-publications/datasets-agency/\'.$data->nid.\'/\'.$link.\'/\'.$default.\'">\'.$null_agency.$short_name.\'</a></td>\'.$null_sub_agency_row; 

$total_sub=db_result(db_query("SELECT count( DISTINCT ds.nid ) FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN workflow_node WF On WF.nid=ds.nid WHERE ds.field_ds_agency_name_nid =$data->nid AND ds.field_ds_sub_agency_nid  $sub_ag AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10 "));

$total_sub_val=db_result(db_query("SELECT count( DISTINCT ds.nid )  FROM  content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid INNER JOIN content_type_policy_program_open_government ppog ON ds.nid=ppog.nid  INNER JOIN workflow_node WF On WF.nid=ds.nid  where  ds.field_ds_agency_name_nid=$data->nid AND ppog.field_ppog_high_value_dataset_value=\'Yes\' AND ds.field_ds_sub_agency_nid  $sub_ag AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.sid=10 "));

$latest_sub=db_result(db_query("SELECT max(WF.stamp) FROM content_type_dataset ds INNER JOIN workflow_node WF On WF.nid=ds.nid  where ds.field_ds_agency_name_nid=$data->nid AND ds.field_ds_sub_agency_nid $sub_ag AND WF.sid=10 AND ds.field_ds_catlog_type_type IS NOT NULL "));

if($latest_sub==0) $latest_sub=\'\';
if($total_sub_val!=0) $total_sub_val=\' <span style="color:red;">(\'.$total_sub_val.\')</span>\'; else $total_sub_val=\'\';

if($row->sub==null)
$null_sub_agency_row.=\'<td style="text-align:center;">\'.$total_sub.$total_sub_val.\'</td><td style="text-align:center;">\'.format_date($latest_sub,\'custom\',variable_get(\'date_format_front_date_format\',\'\'),NULL,NULL).\'</td></tr>\';
else
$sub_agency.=\'<td style="text-align:center;">\'.$total_sub.$total_sub_val.\'</td><td style="text-align:center;">\'.format_date($latest_sub,\'custom\',variable_get(\'date_format_front_date_format\',\'\'),NULL,NULL).\'</td></tr>\';

$last_sub=$row->sub;
}

if($null_agency)
{ if(strcmp($last_sub,$null_agency)<0)
    {  $sub_agency.=$null_sub_agency_row ;
     $null_agency=\'\';
     }
  }

if ($total) $date=format_date($total,\'custom\',variable_get(\'date_format_front_date_format\',\'\'),NULL,NULL);
else $date=\'\';
return $date.$sub_agency;
?>',
      'exclude' => 0,
      'id' => 'phpcode_5',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('title', 'Agency Wise');
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'summary' => '',
    'columns' => array(
      'nid' => 'nid',
      'phpcode_7' => 'phpcode_7',
      'field_agency_short_name_value' => 'field_agency_short_name_value',
      'title' => 'title',
      'phpcode' => 'phpcode',
      'phpcode_1' => 'phpcode_1',
      'phpcode_2' => 'phpcode_2',
      'phpcode_3' => 'phpcode_3',
      'phpcode_6' => 'phpcode_6',
      'phpcode_4' => 'phpcode_4',
      'phpcode_5' => 'phpcode_5',
    ),
    'info' => array(
      'nid' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'phpcode_7' => array(
        'separator' => '',
      ),
      'field_agency_short_name_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'title' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'phpcode' => array(
        'separator' => '',
      ),
      'phpcode_1' => array(
        'separator' => '',
      ),
      'phpcode_2' => array(
        'separator' => '',
      ),
      'phpcode_3' => array(
        'separator' => '',
      ),
      'phpcode_6' => array(
        'separator' => '',
      ),
      'phpcode_4' => array(
        'separator' => '',
      ),
      'phpcode_5' => array(
        'separator' => '',
      ),
    ),
    'default' => 'title',
  ));
  $handler->override_option('path', 'agency-publications/agency-wise/pdf');
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
