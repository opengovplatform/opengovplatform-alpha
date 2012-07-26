<?php

/**
 * Implementation of hook_views_default_views().
 */
function month_wise_metrics_views_default_views() {
  $views = array();

  // Exported view: datasets_by_agency_per_month
  $view = new view;
  $view->name = 'datasets_by_agency_per_month';
  $view->description = 'Datasets  By Agency Per Month';
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
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
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
        'max_length' => '80',
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
                         $votes=\'<span  > (\'.$vote.\' votes)</span>\'; 
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
        'text' => '[field_ds_sector_nid]&nbsp;',
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
        'button' => 'Override',
      ),
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
      'sql_filter' => 'if(is_numeric($view->args[1]) && $view->args[1]<=12){
$startdate= mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) - $view->args[1]*30*3600*24;
$enddate= mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) - ($view->args[1]-1)*30*3600*24;

return "workflow_node.stamp BETWEEN {$startdate} AND {$enddate} ";
}


else if($view->args[1]==13)
{
$startdate= mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) - 12*30*3600*24;
$enddate= mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'));

return "workflow_node.stamp BETWEEN {$startdate} AND {$enddate} ";


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
      'sql_filter' => '$default=1;
if($view->args[3]==1)
{
$arg0 = $view->args[0];
$arg1 = $view->args[1];
$arg2 = $view->args[2];
if($arg2==\'-\') $arg2="IS NULL";
else  $arg2="=".$arg2;

if($arg1<13){
$start=mktime(0,0,0,date(\'m\'),1,date(\'Y\'))-$arg1*30*24*3600;
$end=mktime(0,0,0,date(\'m\'),1,date(\'Y\'))-($arg1-1)*30*24*3600;
}
else
{
$start=mktime(0,0,0,date(\'m\'),1,date(\'Y\'))-12*30*24*3600;
$end=mktime(0,0,0,date(\'m\'),1,date(\'Y\'));
}
if(!strlen(strstr($view->args[2], "main_"))>0 )
$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_raw_data\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_raw_data\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

if($raw) 
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_raw_data\' ";

if(!strlen(strstr($view->args[2], "main_"))>0 )
$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_document\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_document\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

if($doc) 
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_document\' ";

if(!strlen(strstr($view->args[2], "main_"))>0 )
$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_apps\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_apps\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

if($apps)
return "node_data_field_ds_agency_name.field_ds_catlog_type_type IN (\'catalog_type_data_apps\') ";


if(!strlen(strstr($view->args[2], "main_"))>0 )
$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_tools\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND ffield_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_tools\' ) AND field_ds_agency_name_nid=$arg0  AND n.status=1 AND wf.stamp between $start AND $end "));

if($tool)
return "node_data_field_ds_agency_name.field_ds_catlog_type_type IN (\'catalog_type_data_tools\') ";


if(!strlen(strstr($view->args[2], "main_"))>0 )
$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_service\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_service\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

if($ser)
return "node_data_field_ds_agency_name.field_ds_catlog_type_type IN (\'catalog_type_data_service\') ";
}
else if($view->args[3]==2)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_document\' ";
}
else if($view->args[3]==3)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type IN (\'catalog_type_data_apps\') ";
}
else if($view->args[3]==4)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_data_tools\' ";
}
else if($view->args[3]==5)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_data_service\' ";
}',
      'id' => 'php_1',
      'table' => 'views',
      'field' => 'php',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    ),
    'php_2' => array(
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
      'sql_filter' => 'if(!strlen(strstr($view->args[2], "main_"))>0 )
{
  if ($view->args[2]==\'-\') return "node_data_field_ds_agency_name.field_ds_sub_agency_nid IS NULL ";
else 
return "node_data_field_ds_agency_name.field_ds_sub_agency_nid=\'".$view->args[2]."\' ";
}',
      'id' => 'php_2',
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
  $handler->override_option('header', '<?php

$startdate=date(\'M-Y\', mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) - ($view->args[1]-1)*30*3600*24);

echo $startdate;

?>');
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
      'stamp' => 'stamp',
      'field_ds_agency_name_nid' => 'field_ds_agency_name_nid',
      'field_ds_sub_agency_name_value' => 'field_ds_agency_name_nid',
      'field_ds_sector_nid' => 'field_ds_sector_nid',
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
      'stamp' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_ds_agency_name_nid' => array(
        'separator' => '/',
      ),
      'field_ds_sub_agency_name_value' => array(
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
    'default' => '-1',
  ));
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
  if($vote==1) $votes=\'<span>(\'.$vote.\' vote)</span>\'; 
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
        13 => 0,
        15 => 0,
      ),
      'relationship' => 'none',
      'default_options_div_prefix' => '',
      'default_argument_user' => 0,
      'default_argument_fixed' => '',
      'default_argument_php' => '',
      'validate_argument_node_type' => array(
        'agency' => 'agency',
        'faq' => 0,
        'access_type_downloadable' => 0,
        'catalog_type_data_apps' => 0,
        'catalog_type_data_service' => 0,
        'catalog_type_data_tools' => 0,
        'catalog_type_document' => 0,
        'catalog_type_raw_data' => 0,
        'dataset' => 0,
        'geospatial_metadata' => 0,
        'policy_program_data_quality' => 0,
        'policy_program_open_government' => 0,
        'policy_program_privacy' => 0,
        'profile' => 0,
        'sector' => 0,
        'statistical_metadata' => 0,
        'sub_agency' => 0,
        'sub_sector' => 0,
        'subject_keyword' => 0,
        'target_audience' => 0,
        'page' => 0,
        'imageflow' => 0,
        'country_data' => 0,
        'state_data_site' => 0,
        'rotating_panel' => 0,
        'feedback_reply' => 0,
        'feedback' => 0,
        'block' => 0,
        'feedback_review' => 0,
        'story' => 0,
        'theme_file_uploader' => 0,
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
      'override' => array(
        'button' => 'Use default',
      ),
      'default_taxonomy_tid_term_page' => 0,
      'default_taxonomy_tid_node' => 0,
      'default_taxonomy_tid_limit' => 0,
      'default_taxonomy_tid_vids' => array(
        1 => 0,
        2 => 0,
        3 => 0,
        4 => 0,
        5 => 0,
      ),
    ),
    'null' => array(
      'id' => 'null',
      'table' => 'views',
      'field' => 'null',
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
      'sql_filter' => 'if(is_numeric($view->args[1]) && $view->args[1]<=12){
$startdate= mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) - $view->args[1]*30*3600*24;
$enddate= mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) - ($view->args[1]-1)*30*3600*24;

return "workflow_node.stamp BETWEEN {$startdate} AND {$enddate} ";
}


else if($view->args[1]==13)
{
$startdate= mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) - 12*30*3600*24;
$enddate= mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'));

return "workflow_node.stamp BETWEEN {$startdate} AND {$enddate} ";


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
      'sql_filter' => '$default=1;
if($view->args[3]==1)
{
$arg0 = $view->args[0];
$arg1 = $view->args[1];
$arg2 = $view->args[2];
if($arg2==\'-\') $arg2="IS NULL";
else  $arg2="=".$arg2;

if($arg1<13){
$start=mktime(0,0,0,date(\'m\'),1,date(\'Y\'))-$arg1*30*24*3600;
$end=mktime(0,0,0,date(\'m\'),1,date(\'Y\'))-($arg1-1)*30*24*3600;
}
else
{
$start=mktime(0,0,0,date(\'m\'),1,date(\'Y\'))-12*30*24*3600;
$end=mktime(0,0,0,date(\'m\'),1,date(\'Y\'));
}
if(!strlen(strstr($view->args[2], "main_"))>0 )
$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_raw_data\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_raw_data\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

if($raw) 
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_raw_data\' ";

if(!strlen(strstr($view->args[2], "main_"))>0 )
$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_document\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_document\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

if($doc) 
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_document\' ";

if(!strlen(strstr($view->args[2], "main_"))>0 )
$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_apps\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_apps\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

if($apps)
return "node_data_field_ds_agency_name.field_ds_catlog_type_type IN (\'catalog_type_data_apps\') ";


if(!strlen(strstr($view->args[2], "main_"))>0 )
$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_tools\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND ffield_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_tools\' ) AND field_ds_agency_name_nid=$arg0  AND n.status=1 AND wf.stamp between $start AND $end "));

if($tool)
return "node_data_field_ds_agency_name.field_ds_catlog_type_type IN (\'catalog_type_data_tools\') ";


if(!strlen(strstr($view->args[2], "main_"))>0 )
$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_service\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_service\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

if($ser)
return "node_data_field_ds_agency_name.field_ds_catlog_type_type IN (\'catalog_type_data_service\') ";
}
else if($view->args[3]==2)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_document\' ";
}
else if($view->args[3]==3)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type IN (\'catalog_type_data_apps\') ";
}
else if($view->args[3]==4)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_data_tools\' ";
}
else if($view->args[3]==5)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_data_service\' ";
}',
      'id' => 'php_1',
      'table' => 'views',
      'field' => 'php',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'php_2' => array(
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
      'sql_filter' => 'if(!strlen(strstr($view->args[2], "main_"))>0 )
{
  if ($view->args[2]==\'-\') return "node_data_field_ds_agency_name.field_ds_sub_agency_nid IS NULL ";
else 
return "node_data_field_ds_agency_name.field_ds_sub_agency_nid=\'".$view->args[2]."\' ";
}',
      'id' => 'php_2',
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
$path = drupal_get_path_alias($_GET[\'q\']); //get alias of URL
$path = explode(\'/\', $path);
$date =$path[3];
if($date!=\'13\')
$startdate=date(\'F-Y\', mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) - ($date)*30*3600*24);
else if($date==\'13\')
$startdate=\'the Past 12 Months\';

if(date(\'m\')==\'3\' && $date==\'1\')
{ $year=date(\'Y\', mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) - ($date)*30*3600*24);
  $startdate=\'February-\'.$year;
}

$agency=$path[2];
//echo "(Datasets Published in $startdate )";
$node=node_load($agency);
drupal_set_title("$node->title ( Datasets Published in $startdate )") ;

	$this_page = $_SERVER[\'REQUEST_URI\'];
	$last =substr($this_page,0,strripos($this_page,\'/\'));
        $slast =substr($last,0,strripos($last,\'/\'));
	$tlast =substr($slast,0,strripos($slast,\'/\'));
	$fourth_last=strripos($tlast,\'/\');
	$argument=substr($this_page,$fourth_last);
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
$arg2 = $view->args[2];
if($arg2==\'-\') $arg2="IS NULL";
else  $arg2="=".$arg2;

if($arg1<13){
$start=mktime(0,0,0,date(\'m\'),1,date(\'Y\'))-$arg1*30*24*3600;
$end=mktime(0,0,0,date(\'m\'),1,date(\'Y\'))-($arg1-1)*30*24*3600;
}
else {
$start=mktime(0,0,0,date(\'m\'),1,date(\'Y\'))-12*30*24*3600;
$end=mktime(0,0,0,date(\'m\'),1,date(\'Y\'));
}
if(!strlen(strstr($view->args[2], "main_"))>0 )
$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_raw_data\' AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_nid $arg2 AND n.status=1 AND wf.stamp between $start AND $end"));
else
$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_raw_data\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

if(!strlen(strstr($view->args[2], "main_"))>0 )
$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_document\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_document\'  AND n.status=1 AND field_ds_agency_name_nid=$arg0 AND wf.stamp between $start AND $end "));

if(!strlen(strstr($view->args[2], "main_"))>0 )
$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_apps\' ) AND n.status=1  AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_apps\') AND field_ds_agency_name_nid=$arg0  AND n.status=1 AND wf.stamp between $start AND $end "));

if(!strlen(strstr($view->args[2], "main_"))>0 )
$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_tools\') AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_nid $arg2  AND wf.stamp between $start AND $end"));
else
$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_tools\') AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

if(!strlen(strstr($view->args[2], "main_"))>0 )
$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_service\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_service\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

$doc_act=0;
$app_act=0;	
$tool_act=0;
$ser_act=0;
	 print \'<div class="catalog-tabs-menu" style="margin-top:7px;height:23px;">\';
	 print \'<ul class="catalog-tabs" style="position:absolute;">\';
	if($arg==\'/1\')
  	{ 
            if($raw)
            print \'<li><a  style="padding:1px 30px;"  class="active" href="\'.$this_page.\'/1" title="Raw Dataset Catalogs">Raw Dataset Catalogs</a></li>\';  
            else if($doc)
            {print \'<li><a style="padding:1px 30px;"   class="active" href="\'.$this_page.\'/2" title="Document Catalogs">Document Catalogs</a></li> \'; $doc_act=1;}
            else if ($apps)
             {print \'<li><a style="padding:1px 30px;"   class="active" href="\'.$this_page.\'/3" title="App Catalogs">App Catalogs</a></li>\'; $app_act=1;}
            else if ($tool)
             {print \'<li><a style="padding:1px 30px;"   class="active" href="\'.$this_page.\'/4" title="Tool Catalogs">Tool Catalogs</a></li>\'; $tool_act=1;}
            else if ($ser)
             {print \'<li><a style="padding:1px 30px;"   class="active" href="\'.$this_page.\'/5" title="Service Catalogs">Service Catalogs</a></li>\'; $ser_act=1;}
         }
	else if($raw)
	  print \'<li><a  style="padding:0px 30px;"  href="\'.$this_page.\'/1" title="Raw Dataset Catalogs">Raw Dataset Catalogs</a></li>\';

	 if($arg==\'/2\' && $doc  )
  	{ print \'<li><a style="padding:1px 30px;"   class="active" href="\'.$this_page.\'/2" title="Document Catalogs">Document Catalogs</a></li>\'; }
	else if($doc && !$doc_act)
	  print \'<li><a  style="padding:0px 30px;"   href="\'.$this_page.\'/2" title="Document Catalogs">Document Catalogs</a></li>\';

	if($arg==\'/3\' && $apps )
  	{ print \'<li><a style="padding:1px 30px;"   class="active" href="\'.$this_page.\'/3" title="App Catalogs">App Catalogs</a></li>\'; }
	else if($apps && !$app_act)
	  print \'<li><a   style="padding:0px 30px;"   href="\'.$this_page.\'/3" title="App Catalogs">App Catalogs</a></li>\';

	if($arg==\'/4\' && $tool )
  	{ print \'<li><a style="padding:1px 30px;"   class="active" href="\'.$this_page.\'/4" title="Tool Catalogs">Tool Catalogs</a></li>\'; }
	else if($tool && !$tool_act)
	  print \'<li><a   style="padding:0px 30px;"   href="\'.$this_page.\'/4" title="Tool Catalogs">Tool Catalogs</a></li>\';

	if($arg==\'/5\' && $ser )
  	{ print \'<li><a style="padding:1px 30px;"   class="active" href="\'.$this_page.\'/5" title="Service Catalogs">Service Catalogs</a></li>\'; }
	else if($ser && !$ser_act)
	  print \'<li><a   style="padding:0px 30px;"   href="\'.$this_page.\'/5" title="Service Catalogs">Service Catalogs</a></li>\';

	print\'</ul></div>\';
?>
<div class="page-title-border">&nbsp;</div>
<?php print l(\'<< Back to Month Wise Report\',\'agency-publications/month-wise\',array(\'attributes\' => array(\'class\' => \'metricsbacklink\',\'title\'=>\'Back to Month Wise Report\'))); 

print \'<div style="margin-top:-18px;" class="download-report">Download report as: <a title="CSV Download" class="hyperlink"  href="\'.$base_url.\'/federalagency/agency-publications-month/csv\'.$argument.\'?itemcount=500"><img alt="CSV" src="[token global site-url]sites/all/themes/ogpl_css3/images/csv.png" /></a> \' ;

print \'<a title="XLS Download" class="hyperlink" href="\'.$base_url.\'/federalagency/agency-publications-month/xls\'.$argument.\'?itemcount=500"><img alt="XLS" src="[token global site-url]sites/all/themes/ogpl_css3/images/xls.png" /></a>\';

print \'<a style="padding-left:3px;" title="PDF Download"  class="hyperlink" href="\'.$base_url.\'/printpdf/agency-publications/agency-publications-month/pdf\'.$argument.\'?itemcount=500"><img alt="PDF" src="[token global site-url]sites/all/themes/ogpl_css3/images/pdf.png" /></a></div>\';


 ?>
');
  $handler->override_option('header_empty', 1);
  $handler->override_option('footer', '<br/>
<p>* Asterisks denote agency-reported high-value datasets. </p>');
  $handler->override_option('footer_format', '4');
  $handler->override_option('footer_empty', 0);
  $handler->override_option('empty', '<?php
global $base_url;

print \'<div style="font:bold 1.3em arial; padding-top:10px">No matching records found. Please try your search again or <a class="hyperlink"  href="\'.$base_url.\'/suggest_dataset" title="Suggest a dataset">suggest a dataset.</a></div>\';

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
      'stamp' => 'stamp',
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
      'stamp' => array(
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
  $handler->override_option('path', 'agency-publications/agency-publications-month/%');
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
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
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
        'max_length' => '80',
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
        'text' => '[field_ds_sector_nid]&nbsp;',
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
    'trim' => 0,
    'replace_newlines' => 1,
    'newline_replacement' => ' ',
    'header' => 1,
    'encoding' => 'ASCII',
  ));
  $handler->override_option('row_plugin', '');
  $handler->override_option('path', 'federalagency/agency-publications-month/csv');
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
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
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
        'max_length' => '80',
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
                         $votes=\'<span  > (\'.$vote.\' votes)</span>\'; 
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
        'text' => '[field_ds_sector_nid]&nbsp;',
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
        'button' => 'Override',
      ),
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
  $handler->override_option('path', 'federalagency/agency-publications-month/xls');
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
    'null' => array(
      'id' => 'null',
      'table' => 'views',
      'field' => 'null',
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
      'sql_filter' => 'if(is_numeric($view->args[1]) && $view->args[1]<=12){
$startdate= mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) - $view->args[1]*30*3600*24;
$enddate= mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) - ($view->args[1]-1)*30*3600*24;

return "workflow_node.stamp BETWEEN {$startdate} AND {$enddate} ";
}


else if($view->args[1]==13)
{
$startdate= mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) - 12*30*3600*24;
$enddate= mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'));

return "workflow_node.stamp BETWEEN {$startdate} AND {$enddate} ";


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
      'sql_filter' => '$default=1;
if($view->args[3]==1)
{
$arg0 = $view->args[0];
$arg1 = $view->args[1];
$arg2 = $view->args[2];
if($arg2==\'-\') $arg2="IS NULL";
else  $arg2="=".$arg2;

if($arg1<13){
$start=mktime(0,0,0,date(\'m\'),1,date(\'Y\'))-$arg1*30*24*3600;
$end=mktime(0,0,0,date(\'m\'),1,date(\'Y\'))-($arg1-1)*30*24*3600;
}
else
{
$start=mktime(0,0,0,date(\'m\'),1,date(\'Y\'))-12*30*24*3600;
$end=mktime(0,0,0,date(\'m\'),1,date(\'Y\'));
}
if(!strlen(strstr($view->args[2], "main_"))>0 )
$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_raw_data\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_raw_data\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

if($raw) 
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_raw_data\' ";

if(!strlen(strstr($view->args[2], "main_"))>0 )
$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_document\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_document\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

if($doc) 
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_document\' ";

if(!strlen(strstr($view->args[2], "main_"))>0 )
$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_apps\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_apps\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

if($apps)
return "node_data_field_ds_agency_name.field_ds_catlog_type_type IN (\'catalog_type_data_apps\') ";


if(!strlen(strstr($view->args[2], "main_"))>0 )
$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_tools\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND ffield_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_tools\' ) AND field_ds_agency_name_nid=$arg0  AND n.status=1 AND wf.stamp between $start AND $end "));

if($tool)
return "node_data_field_ds_agency_name.field_ds_catlog_type_type IN (\'catalog_type_data_tools\') ";


if(!strlen(strstr($view->args[2], "main_"))>0 )
$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_service\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_nid $arg2 AND wf.stamp between $start AND $end"));
else
$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_service\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

if($ser)
return "node_data_field_ds_agency_name.field_ds_catlog_type_type IN (\'catalog_type_data_service\') ";
}
else if($view->args[3]==2)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_document\' ";
}
else if($view->args[3]==3)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type IN (\'catalog_type_data_apps\') ";
}
else if($view->args[3]==4)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_data_tools\' ";
}
else if($view->args[3]==5)
{
return "node_data_field_ds_agency_name.field_ds_catlog_type_type=\'catalog_type_data_service\' ";
}',
      'id' => 'php_1',
      'table' => 'views',
      'field' => 'php',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'php_2' => array(
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
      'sql_filter' => 'if(!strlen(strstr($view->args[2], "main_"))>0 )
{
  if ($view->args[2]==\'-\') return "node_data_field_ds_agency_name.field_ds_sub_agency_nid IS NULL ";
else 
return "node_data_field_ds_agency_name.field_ds_sub_agency_nid=\'".$view->args[2]."\' ";
}',
      'id' => 'php_2',
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
$path = drupal_get_path_alias($_GET[\'q\']); //get alias of URL
$path = explode(\'/\', $path);
$date =$path[4];
if($date!=\'13\')
$startdate=date(\'F-Y\', mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) - ($date)*30*3600*24);
else if($date==\'13\')
$startdate=date(\'Y\', mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) - 30*3600*24);

if(date(\'m\')==\'3\' && $date==\'1\')
{ $year=date(\'Y\', mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) - ($date)*30*3600*24);
  $startdate=\'February-\'.$year;
}

$agency=$path[3];
//echo "(Datasets Published in $startdate )";
$node=node_load($agency);
drupal_set_title("$node->title ( Datasets Published in $startdate )") ;

	$this_page = $_SERVER[\'REQUEST_URI\'];
	$last =substr($this_page,0,strripos($this_page,\'/\'));
        $slast =substr($last,0,strripos($last,\'/\'));
	$tlast =substr($slast,0,strripos($slast,\'/\'));
	$fourth_last=strripos($tlast,\'/\');
	$argument=substr($this_page,$fourth_last);
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
$arg2 = $view->args[2];
if($arg1<13){
$start=mktime(0,0,0,date(\'m\'),1,date(\'Y\'))-$arg1*30*24*3600;
$end=mktime(0,0,0,date(\'m\'),1,date(\'Y\'))-($arg1-1)*30*24*3600;
}
else {
$start=mktime(0,0,0,date(\'m\'),1,date(\'Y\'))-12*30*24*3600;
$end=mktime(0,0,0,date(\'m\'),1,date(\'Y\'));
}
if(!strlen(strstr($view->args[2], "main_"))>0 )
$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_raw_data\' AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_name_value=\'$arg2\' AND n.status=1 AND wf.stamp between $start AND $end"));
else
$raw=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_raw_data\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

if(!strlen(strstr($view->args[2], "main_"))>0 )
$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_document\' AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_name_value=\'$arg2\' AND wf.stamp between $start AND $end"));
else
$doc=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type=\'catalog_type_document\'  AND n.status=1 AND field_ds_agency_name_nid=$arg0 AND wf.stamp between $start AND $end "));

if(!strlen(strstr($view->args[2], "main_"))>0 )
$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_apps\' ) AND n.status=1  AND field_ds_agency_name_nid=$arg0 AND field_ds_sub_agency_name_value=\'$arg2\' AND wf.stamp between $start AND $end"));
else
$apps=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_apps\') AND field_ds_agency_name_nid=$arg0  AND n.status=1 AND wf.stamp between $start AND $end "));

if(!strlen(strstr($view->args[2], "main_"))>0 )
$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_tools\') AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_name_value=\'$arg2\' AND wf.stamp between $start AND $end"));
else
$tool=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_tools\') AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

if(!strlen(strstr($view->args[2], "main_"))>0 )
$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_service\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND field_ds_sub_agency_name_value=\'$arg2\' AND wf.stamp between $start AND $end"));
else
$ser=db_result(db_query("select count( ds.nid) from content_type_dataset ds Left join workflow_node wf on ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid where wf.sid=10 and field_ds_catlog_type_type IN(\'catalog_type_data_service\' ) AND field_ds_agency_name_nid=$arg0 AND n.status=1 AND wf.stamp between $start AND $end "));

$doc_act=0;
$app_act=0;	
$tool_act=0;
$ser_act=0;
	 print \'<div class="catalog-tabs-menu" style="margin-top:7px;">\';
	 print \'<ul class="catalog-tabs">\';
	if($arg==\'/1\')
  	{ 
            if($raw)
            print \'Catalog Type: Raw Dataset Catalogs\';  
            else if($doc)
            {print \'Catalog Type: Document Catalogs \'; $doc_act=1;}
            else if ($apps)
             {print \'Catalog Type: App Catalogs\'; $app_act=1;}
            else if ($tool)
             {print \'Catalog Type: Tool Catalogs\'; $tool_act=1;}
            else if ($ser)
             {print \'Catalog Type: Service Catalogs\'; $ser_act=1;}
         }

	 if($arg==\'/2\' && $doc  )
  	{ print \'Catalog Type: Document Catalogs\'; }
	
	if($arg==\'/3\' && $apps )
  	{ print \'Catalog Type: App Catalogs\'; }

	if($arg==\'/4\' && $tool )
  	{ print \'Catalog Type: Tool Catalogs\'; }

	if($arg==\'/5\' && $ser )
  	{ print \'Catalog Type: Service Catalogs\'; }

	print\'</ul></div>\';
?>
<div class="page-title-border">&nbsp;</div>

<iframe width="1px" height="1px" style="display: none;" name="download-frame"></iframe>');
  $handler->override_option('header_empty', 1);
  $handler->override_option('footer', '<br>
* Asterisks denote agency-reported high-value datasets. ');
  $handler->override_option('footer_format', '2');
  $handler->override_option('footer_empty', 0);
  $handler->override_option('empty', '<?php
global $base_url;

print \'<div style="font:bold 1.3em arial; padding-top:10px">No matching records found. Please try your search again or <a class="hyperlink"  href="\'.$base_url.\'/suggest_dataset">suggest a dataset.</a></div>\';

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
      'title' => 'title',
      'phpcode' => 'phpcode',
      'stamp' => 'stamp',
      'field_ds_agency_short_name_value' => 'field_ds_agency_short_name_value',
      'field_ds_sector_nid' => 'field_ds_sector_nid',
      'field_ds_description_value' => 'title',
      'field_ds_sub_agency_short_name_value' => 'field_ds_agency_short_name_value',
    ),
    'info' => array(
      'title' => array(
        'sortable' => 0,
        'separator' => '<br>',
      ),
      'phpcode' => array(
        'separator' => '',
      ),
      'stamp' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_ds_agency_short_name_value' => array(
        'sortable' => 0,
        'separator' => '/',
      ),
      'field_ds_sector_nid' => array(
        'separator' => '',
      ),
      'field_ds_description_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
      'field_ds_sub_agency_short_name_value' => array(
        'sortable' => 0,
        'separator' => '',
      ),
    ),
    'default' => '-1',
  ));
  $handler->override_option('path', 'agency-publications/agency-publications-month/pdf/%');
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

  // Exported view: month_wise_agency_report
  $view = new view;
  $view->name = 'month_wise_agency_report';
  $view->description = 'Month Wise Agency Publication';
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
      'label' => 'Agency Name',
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
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'markup' => array(
      'label' => 'Sub Agency Name',
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
      'value' => '',
      'format' => '1',
      'exclude' => 0,
      'id' => 'markup',
      'table' => 'customfield',
      'field' => 'markup',
      'relationship' => 'none',
    ),
    'phpcode_11' => array(
      'label' => 'Dec',
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
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -12*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-11*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_11',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_10' => array(
      'label' => 'Jan',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => 'content/testview2/[nid]/[phpcode_10]',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -11*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-10*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime"));
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_10',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_9' => array(
      'label' => 'Feb',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -10*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-9*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime"));
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_9',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_8' => array(
      'label' => 'Mar',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -9*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-8*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime"));
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_8',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_7' => array(
      'label' => 'Apr ',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -8*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-7*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime"));
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_7',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_6' => array(
      'label' => 'May',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -7*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-6*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime"));
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_6',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_5' => array(
      'label' => 'Jun',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -6*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-5*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime"));
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_5',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_4' => array(
      'label' => 'jul',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -5*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-4*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime"));
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_4',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_3' => array(
      'label' => 'Aug ',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -4*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-3*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime"));
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_3',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_2' => array(
      'label' => 'Sep',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -3*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-2*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime"));
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_2',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_1' => array(
      'label' => 'Oct ',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -2*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime"));
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_1',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode' => array(
      'label' => 'Nov',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'content/agency-publications-month/[nid]/1',
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
      'empty' => '-',
      'hide_empty' => 1,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')); 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime"));

return  $total;


?>',
      'exclude' => 0,
      'id' => 'phpcode',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_13' => array(
      'label' => 'Dec',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'content/agency-publications-month/[nid]/0',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'));    
$endtime = mktime(); 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND wf.stamp BETWEEN $starttime AND $endtime"));
return  $total;

?>',
      'exclude' => 1,
      'id' => 'phpcode_13',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
    ),
    'phpcode_12' => array(
      'label' => 'Total in past 12 months',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'content/agency-publications-month/[nid]/12',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -12*30*3600*24;    
$endtime=mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'));
//$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')); 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid  AND wf.sid=10 AND n.status=1   AND wf.stamp BETWEEN $starttime AND $endtime"));


$result=db_query("SELECT  distinct ds.field_ds_sub_agency_nid as sub,sa.field_sa_subagency_name_value as name FROM content_type_dataset ds LEFT JOIN content_type_sub_agency as sa On sa.nid=ds.field_ds_sub_agency_nid INNER JOIN workflow_node WF on WF.nid=ds.nid where ds.field_ds_agency_name_nid=$data->nid AND WF.sid=10 AND ds.field_ds_catlog_type_type IS NOT NULL  AND WF.stamp BETWEEN $starttime AND $endtime   order by sa.field_sa_subagency_name_value asc ");	

$sub_month=\'</a></td></tr>\';
while ($row = mysql_fetch_object($result)) 
{
     if($row->sub!=null)
	{	  $sub_month.=\'<tr><td class="ds-list-item-new" style="padding-left:20px;">\'.$row->name.\'</td>\';
                         for($i=12;$i>0;$i--){
                          $stime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -$i*30*3600*24;    
                          $etime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-($i-1)*30*3600*24; 
                          $sub=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid =$row->sub  AND wf.stamp BETWEEN $stime AND $etime"));
                            if($sub==0) $sub_month.=\'<td class="ds-list-item-new-center"> -</td>\';
                            else
                            $sub_month.=\'<td class="ds-list-item-new-center"><a title="Month wise report for \'.$row->sub.\'" href="agency-publications-month/\'.$data->nid.\'/\'.$i.\'/\'.$row->sub.\'/1">\'.$sub.\'</a></td>\';
							}
                      $sub_total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid=$row->sub  AND wf.stamp BETWEEN $starttime AND $endtime"));
                            
                  $sub_month.=\'<td class="ds-list-item-new-center"><a title="Past 12 months report for \'.$row->sub.\'" href="agency-publications-month/\'.$data->nid.\'/13/\'.$row->sub.\'/1">\'.$sub_total.\'</a></td></tr>\';


                 }
	else
	{	$null_agency=$data->node_title;
		$short_name=db_result(db_query("Select field_agency_short_name_value from content_type_agency where nid=$data->nid"));
		$short_name=\' (\'. $short_name.\')\';
		$sub_month.=\'<tr><td class="ds-list-item-new" style="padding-left:20px;">\'.$null_agency.\'</td>\';
                         for($i=12;$i>0;$i--){
                          $stime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -$i*30*3600*24;    
                          $etime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-($i-1)*30*3600*24; 
                          $sub=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid IS NULL AND wf.stamp BETWEEN $stime AND $etime"));
                            if($sub==0) $sub_month.=\'<td class="ds-list-item-new-center"> -</td>\';
                            else
                            $sub_month.=\'<td class="ds-list-item-new-center"><a title="Month wise report for \'.$row->sub.\'" href="agency-publications-month/\'.$data->nid.\'/\'.$i.\'/\'.$row->sub.\'/1">\'.$sub.\'</a></td>\';
							}
                      $sub_total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid IS NULL AND wf.stamp BETWEEN $starttime AND $endtime"));
                            
                  $sub_month.=\'<td class="ds-list-item-new-center"><a title="Past 12 months report for \'.$row->sub.\'" href="agency-publications-month/\'.$data->nid.\'/13/\'.$row->sub.\'/1">\'.$sub_total.\'</a></td></tr>\';
	} 
}

$sub_month=substr($sub_month,0,strlen($sub_month)-14);
if($total==0) return \'-\';
else
return  $total.$sub_month  ;

?>
',
      'exclude' => 0,
      'id' => 'phpcode_12',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
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
    'type_1' => array(
      'operator' => 'in',
      'value' => array(
        'agency' => 'agency',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type_1',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'CSV');
  $handler->override_option('header_format', '3');
  $handler->override_option('header_empty', 0);
  $handler->override_option('empty', 'No Datasets published this month.');
  $handler->override_option('empty_format', '1');
  $handler->override_option('items_per_page', 0);
  $handler->override_option('style_plugin', 'table');
  $handler->override_option('style_options', array(
    'grouping' => '',
    'override' => 1,
    'sticky' => 0,
    'order' => 'asc',
    'summary' => '',
    'columns' => array(
      'phpcode' => 'phpcode',
      'phpcode_1' => 'phpcode_1',
    ),
    'info' => array(
      'phpcode' => array(
        'separator' => '',
      ),
      'phpcode_1' => array(
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
    'title' => array(
      'label' => 'Agency Name',
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
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_11' => array(
      'label' => 'Dec \'10',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/12/main_[title]/1',
        'absolute' => 0,
        'link_class' => '',
        'alt' => 'Month wise report for [title]',
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
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -12*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-11*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_11',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_10' => array(
      'label' => 'Jan \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/11/main_[title]/1',
        'absolute' => 0,
        'link_class' => '',
        'alt' => 'Month wise report for [title]',
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
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -11*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-10*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_10',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_9' => array(
      'label' => 'Feb \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/10/main_[title]/1',
        'absolute' => 0,
        'link_class' => '',
        'alt' => 'Month wise report for [title]',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -10*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-9*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_9',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_8' => array(
      'label' => 'Mar \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/9/main_[title] /1',
        'absolute' => 0,
        'link_class' => '',
        'alt' => 'Month wise report for [title]',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -9*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-8*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND  n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_8',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_7' => array(
      'label' => 'Apr \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/8/main_[title]/1',
        'absolute' => 0,
        'link_class' => '',
        'alt' => 'Month wise report for [title]',
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
      'hide_empty' => 1,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -8*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-7*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND  wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_7',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_6' => array(
      'label' => 'May \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/7/main_[title]/1',
        'absolute' => 0,
        'link_class' => '',
        'alt' => 'Month wise report for [title]',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -7*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-6*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_6',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_5' => array(
      'label' => 'Jun \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/6/main_[title]/1',
        'absolute' => 0,
        'link_class' => '',
        'alt' => 'Month wise report for [title]',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -6*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-5*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

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
    'phpcode_4' => array(
      'label' => 'Jul \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/5/main_[title]/1',
        'absolute' => 0,
        'link_class' => 'Month wise report for [title]',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -5*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-4*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_4',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_3' => array(
      'label' => 'Aug \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/4/main_[title]/1',
        'absolute' => 0,
        'link_class' => 'Month wise report for [title]',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -4*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-3*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

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
    'phpcode_2' => array(
      'label' => 'Sep \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/3/main_[title]/1',
        'absolute' => 0,
        'link_class' => '',
        'alt' => 'Month wise report for [title]',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -3*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-2*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

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
    'phpcode_1' => array(
      'label' => 'Oct \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/2/main_[title]/1',
        'absolute' => 0,
        'link_class' => '',
        'alt' => 'Month wise report for [title]',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -2*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

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
    'phpcode' => array(
      'label' => 'Nov \'11',
      'alter' => array(
        'alter_text' => 1,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/1/main_[title]/1',
        'absolute' => 0,
        'link_class' => '',
        'alt' => 'Month wise report for [title]',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')); 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
else
return  $total;

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
    'phpcode_13' => array(
      'label' => 'Dec \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/0/1',
        'absolute' => 0,
        'link_class' => '',
        'alt' => 'Month wise report for [title]',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'));    
$endtime = mktime(); 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
else
return  $total;

?>',
      'exclude' => 1,
      'id' => 'phpcode_13',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_12' => array(
      'label' => ' Total in the past 12 months ',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/13/main_[title]/1',
        'absolute' => 0,
        'link_class' => '',
        'alt' => 'Past 12 months report for [title]',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -12*30*3600*24;    
$endtime=mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'));
//$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')); 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid  AND wf.sid=10 AND n.status=1   AND wf.stamp BETWEEN $starttime AND $endtime"));


$result=db_query("SELECT  distinct ds.field_ds_sub_agency_nid as sub,sa.field_sa_subagency_name_value as name FROM content_type_dataset ds LEFT JOIN content_type_sub_agency as sa On sa.nid=ds.field_ds_sub_agency_nid INNER JOIN workflow_node WF on WF.nid=ds.nid where ds.field_ds_agency_name_nid=$data->nid AND WF.sid=10 AND ds.field_ds_catlog_type_type IS NOT NULL  AND WF.stamp BETWEEN $starttime AND $endtime   order by sa.field_sa_subagency_name_value asc ");	

$sub_month=\'</a></td></tr>\';
while ($row = mysql_fetch_object($result)) 
{
     if($row->sub!=null)
	{	  $sub_month.=\'<tr><td class="ds-list-item-new" style="padding-left:20px;">\'.$row->name.\'</td>\';
                         for($i=12;$i>0;$i--){
                          $stime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -$i*30*3600*24;    
                          $etime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-($i-1)*30*3600*24; 
                          $sub=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid =$row->sub  AND wf.stamp BETWEEN $stime AND $etime"));
                            if($sub==0) $sub_month.=\'<td class="ds-list-item-new-center"> -</td>\';
                            else
                            $sub_month.=\'<td class="ds-list-item-new-center"><a title="Month wise report for \'.$row->name.\'" href="agency-publications-month/\'.$data->nid.\'/\'.$i.\'/\'.$row->sub.\'/1">\'.$sub.\'</a></td>\';
							}
                      $sub_total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid=$row->sub  AND wf.stamp BETWEEN $starttime AND $endtime"));
                            
                  $sub_month.=\'<td class="ds-list-item-new-center"><a title="Past 12 months report for \'.$row->name.\'" href="agency-publications-month/\'.$data->nid.\'/13/\'.$row->sub.\'/1">\'.$sub_total.\'</a></td></tr>\';


                 }
	else
	{	$null_agency=$data->node_title;
		$short_name=db_result(db_query("Select field_agency_short_name_value from content_type_agency where nid=$data->nid"));
		$short_name=\' (\'. $short_name.\')\';
		$sub_month.=\'<tr><td class="ds-list-item-new" style="padding-left:20px;">\'.$null_agency.\'</td>\';
                         for($i=12;$i>0;$i--){
                          $stime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -$i*30*3600*24;    
                          $etime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-($i-1)*30*3600*24; 
                          $sub=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid IS NULL AND wf.stamp BETWEEN $stime AND $etime"));
                            if($sub==0) $sub_month.=\'<td class="ds-list-item-new-center"> -</td>\';
                            else
                            $sub_month.=\'<td class="ds-list-item-new-center"><a title="Month wise report for \'.$null_agency.\'" href="agency-publications-month/\'.$data->nid.\'/\'.$i.\'/-/1">\'.$sub.\'</a></td>\';
							}
                      $sub_total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid IS NULL AND wf.stamp BETWEEN $starttime AND $endtime"));
                            
                  $sub_month.=\'<td class="ds-list-item-new-center"><a title="Past 12 months report for \'.$null_agency.\'" href="agency-publications-month/\'.$data->nid.\'/13/-/1">\'.$sub_total.\'</a></td></tr>\';
	} 
}

$sub_month=substr($sub_month,0,strlen($sub_month)-14);
if($total==0) return \'-\';
else
return  $total.$sub_month  ;

?>
',
      'exclude' => 0,
      'id' => 'phpcode_12',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('title', 'Month Wise');
  $handler->override_option('header', '<?php

global $base_url;

print \'<h1 class="metrics-visitorstats-table-heading fLeft">Month  Wise</h1>\';



?>
');
  $handler->override_option('path', 'agency-publications/month-wise');
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
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'title' => array(
      'label' => 'Agency Name',
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
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'markup' => array(
      'label' => 'Sub Agency Name',
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
    'phpcode_11' => array(
      'label' => 'Dec',
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
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -12*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-11*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_11',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_10' => array(
      'label' => 'Jan',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => 'content/testview2/[nid]/[phpcode_10]',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -11*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-10*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_10',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_9' => array(
      'label' => 'Feb',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -10*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-9*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_9',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_8' => array(
      'label' => 'Mar',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -9*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-8*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND  n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_8',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_7' => array(
      'label' => 'Apr',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -8*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-7*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND  wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_7',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_6' => array(
      'label' => 'May ',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -7*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-6*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_6',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_5' => array(
      'label' => 'Jun ',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -6*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-5*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

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
    'phpcode_4' => array(
      'label' => 'Jul ',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -5*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-4*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_4',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_3' => array(
      'label' => 'Aug ',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -4*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-3*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

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
    'phpcode_2' => array(
      'label' => 'Sep',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -3*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-2*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

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
    'phpcode_1' => array(
      'label' => 'Oct ',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -2*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

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
    'phpcode' => array(
      'label' => 'Nov',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'content/agency-publications-month/[nid]/1',
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
      'empty' => '-',
      'hide_empty' => 1,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')); 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
else
return  $total;

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
    'phpcode_13' => array(
      'label' => 'Dec',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'content/agency-publications-month/[nid]/0',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'));    
$endtime = mktime(); 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
else
return  $total;

?>',
      'exclude' => 1,
      'id' => 'phpcode_13',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_12' => array(
      'label' => 'Total in past 12 months',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'content/agency-publications-month/[nid]/12',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -12*30*3600*24;    
$endtime=mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'));
//$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')); 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1  AND wf.stamp BETWEEN $starttime AND $endtime"));


$result=db_query("SELECT  distinct ds.field_ds_sub_agency_nid as sub,sa.field_sa_subagency_name_value as name FROM content_type_dataset ds LEFT JOIN content_type_sub_agency as sa On sa.nid=ds.field_ds_sub_agency_nid INNER JOIN workflow_node WF on WF.nid=ds.nid where ds.field_ds_agency_name_nid=$data->nid AND WF.sid=10 AND ds.field_ds_catlog_type_type IS NOT NULL  AND WF.stamp BETWEEN $starttime AND $endtime  order by sa.field_sa_subagency_name_value asc ");	

$sub_month=\'\';
while ($row = mysql_fetch_object($result)) 
{
     if($row->sub!=null)
	{	  $sub_month.=\'

,\'.$row->name.\',\';
                         for($i=12;$i>0;$i--){
                          $stime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -$i*30*3600*24;    
                          $etime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-($i-1)*30*3600*24; 
                         $sub=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid =$row->sub  AND wf.stamp BETWEEN $stime AND $etime"));
                            if($sub==0) $sub_month.=\' -,\';
                            else
                             $sub_month.=\'<a href="agency-publications-month/\'.$data->nid.\'/\'.$i.\'/\'.$row->sub.\'/1">\'.$sub.\'</a>,\';
							}
                     $sub_total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid=$row->sub  AND wf.stamp BETWEEN $starttime AND $endtime"));
                             
                  $sub_month.=\'<a href="agency-publications-month/\'.$data->nid.\'/13/\'.$row->sub.\'/1">\'.$sub_total.\'</a>,</tr>\';


                 }
	else
	{	$null_agency=$data->node_title;
		$short_name=db_result(db_query("Select field_agency_short_name_value from content_type_agency where nid=$data->nid"));
		$short_name=\' (\'. $short_name.\')\';
		$sub_month.=\'<tr>,\'.$null_agency.\',\';
                         for($i=12;$i>0;$i--){
                          $stime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -$i*30*3600*24;    
                          $etime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-($i-1)*30*3600*24; 
                          $sub=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid IS NULL AND wf.stamp BETWEEN $stime AND $etime"));
                            if($sub==0) $sub_month.=\' -,\';
                            else
                            $sub_month.=\'<a href="agency-publications-month/\'.$data->nid.\'/\'.$i.\'/\'.$row->sub.\'/1">\'.$sub.\'</a>,\';
							}
                      $sub_total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid IS NULL AND wf.stamp BETWEEN $starttime AND $endtime"));
                            
                  $sub_month.=\'<a href="agency-publications-month/\'.$data->nid.\'/13/\'.$row->sub.\'/1">\'.$sub_total.\'</a>,</tr>\';
	} 
}


if($total==0) return \'--\';
else
return  $total.\'
\'.$sub_month  ;

?>
',
      'exclude' => 0,
      'id' => 'phpcode_12',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
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
    'quote' => 0,
    'trim' => 0,
    'replace_newlines' => 0,
    'newline_replacement' => ', ',
    'header' => 1,
    'encoding' => '',
  ));
  $handler->override_option('row_plugin', '');
  $handler->override_option('path', 'agency-publications/month-wise/csv');
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
    ),
    'title' => array(
      'label' => 'Agency Name',
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
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
    ),
    'markup' => array(
      'label' => 'Sub Agency Name',
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
      'value' => '',
      'format' => '1',
      'exclude' => 0,
      'id' => 'markup',
      'table' => 'customfield',
      'field' => 'markup',
      'relationship' => 'none',
    ),
    'phpcode_11' => array(
      'label' => 'Dec',
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
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -12*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-11*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_11',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_10' => array(
      'label' => 'Jan',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => 'content/testview2/[nid]/[phpcode_10]',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -11*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-10*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_10',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_9' => array(
      'label' => 'Feb',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -10*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-9*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_9',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_8' => array(
      'label' => 'Mar',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -9*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-8*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND  n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_8',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_7' => array(
      'label' => 'Apr ',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -8*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-7*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND  wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_7',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_6' => array(
      'label' => 'May',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -7*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-6*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_6',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_5' => array(
      'label' => 'Jun',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -6*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-5*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

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
    'phpcode_4' => array(
      'label' => 'jul',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -5*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-4*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_4',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_3' => array(
      'label' => 'Aug ',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -4*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-3*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

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
    'phpcode_2' => array(
      'label' => 'Sep',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -3*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-2*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

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
    'phpcode_1' => array(
      'label' => 'Oct ',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -2*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

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
    'phpcode' => array(
      'label' => 'Nov',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'content/agency-publications-month/[nid]/1',
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
      'empty' => '-',
      'hide_empty' => 1,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')); 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
else
return  $total;

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
    'phpcode_13' => array(
      'label' => 'Dec',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'content/agency-publications-month/[nid]/0',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'));    
$endtime = mktime(); 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
else
return  $total;

?>',
      'exclude' => 1,
      'id' => 'phpcode_13',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_12' => array(
      'label' => 'Total in past 12 months',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'content/agency-publications-month/[nid]/12',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -12*30*3600*24;    
$endtime=mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'));
//$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')); 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));

$result=db_query("SELECT  distinct ds.field_ds_sub_agency_nid as sub,sa.field_sa_subagency_name_value as name FROM content_type_dataset ds LEFT JOIN content_type_sub_agency as sa On sa.nid=ds.field_ds_sub_agency_nid INNER JOIN workflow_node WF on WF.nid=ds.nid where ds.field_ds_agency_name_nid=$data->nid AND WF.sid=10 AND ds.field_ds_catlog_type_type IS NOT NULL AND WF.stamp BETWEEN $starttime AND $endtime  order by sa.field_sa_subagency_name_value asc ");	

$sub_month=\'\';
while ($row = mysql_fetch_object($result)) 
{
     if($row->sub!=null)
	{	  $sub_month.=\'</tr><tr><td></td><td class="ds-list-item-new" style="padding-left:20px;">\'.$row->name.\'</td>\';
                         for($i=12;$i>0;$i--){
                          $stime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -$i*30*3600*24;    
                          $etime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-($i-1)*30*3600*24; 
                          $sub=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid =$row->sub  AND wf.stamp BETWEEN $stime AND $etime"));
                              if($sub==0) $sub_month.=\'<td class="ds-list-item-new-center"> -</td>\';
                            else
                            $sub_month.=\'<td class="ds-list-item-new-center"><a href="agency-publications-month/\'.$data->nid.\'/\'.$i.\'/\'.$row->sub.\'/1">\'.$sub.\'</a></td>\';
						}
                   $sub_total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid=$row->sub  AND wf.stamp BETWEEN $starttime AND $endtime"));
                            
                  $sub_month.=\'<td class="ds-list-item-new-center"><a href="agency-publications-month/\'.$data->nid.\'/13/\'.$row->sub.\'/1">\'.$sub_total.\'</a></td></tr>\';


                 }
	else
	{	$null_agency=$data->node_title;
		$short_name=db_result(db_query("Select field_agency_short_name_value from content_type_agency where nid=$data->nid"));
		$short_name=\' (\'. $short_name.\')\';
		$sub_month.=\'</tr><tr><td></td><td class="ds-list-item-new" style="padding-left:20px;">\'.$null_agency.\'</td>\';
                         for($i=12;$i>0;$i--){
                          $stime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -$i*30*3600*24;    
                          $etime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-($i-1)*30*3600*24; 
                          $sub=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid =$row->sub  AND wf.stamp BETWEEN $stime AND $etime"));
                              if($sub==0) $sub_month.=\'<td class="ds-list-item-new-center"> -</td>\';
                            else
                            $sub_month.=\'<td class="ds-list-item-new-center"><a href="agency-publications-month/\'.$data->nid.\'/\'.$i.\'/\'.$row->sub.\'/1">\'.$sub.\'</a></td>\';
						}
                   $sub_total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid=$row->sub  AND wf.stamp BETWEEN $starttime AND $endtime"));
                            
                  $sub_month.=\'<td class="ds-list-item-new-center"><a href="agency-publications-month/\'.$data->nid.\'/13/\'.$row->sub.\'/1">\'.$sub_total.\'</a></td></tr>\';
	} 
}


if($total==0) return \'--\';
else
return  $total.$sub_month  ;

?>
',
      'exclude' => 0,
      'id' => 'phpcode_12',
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
    'filename' => '%view--%timestamp-full.xls',
    'help' => '',
    'parent_sort' => 0,
  ));
  $handler->override_option('row_plugin', '');
  $handler->override_option('path', 'agency-publications/month-wise/xls');
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
  $handler->override_option('displays', array());
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
    'title' => array(
      'label' => 'Agency Name',
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
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_11' => array(
      'label' => 'Dec \'10',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/12/main_[title]/1',
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
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -12*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-11*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_11',
      'table' => 'customfield',
      'field' => 'phpcode',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    ),
    'phpcode_10' => array(
      'label' => 'Jan \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/11/main_[title]/1',
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
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -11*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-10*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_10',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_9' => array(
      'label' => 'Feb \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/10/main_[title]/1',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -10*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-9*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_9',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_8' => array(
      'label' => 'Mar \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/9/main_[title]/1',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -9*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-8*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND  n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_8',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_7' => array(
      'label' => 'Apr \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/8/main_[title]/1',
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
      'hide_empty' => 1,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -8*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-7*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND  wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_7',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_6' => array(
      'label' => 'May \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/7/main_[title]/1',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -7*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-6*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_6',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_5' => array(
      'label' => 'Jun \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/6/main_[title]/1',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -6*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-5*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

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
    'phpcode_4' => array(
      'label' => 'Jul \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/5/main_[title]/1',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -5*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-4*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

?>',
      'exclude' => 0,
      'id' => 'phpcode_4',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_3' => array(
      'label' => 'Aug \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/4/main_[title]/1',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -4*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-3*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

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
    'phpcode_2' => array(
      'label' => 'Sep \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/3/main_[title]/1',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -3*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-2*30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

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
    'phpcode_1' => array(
      'label' => 'Oct \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/2/main_[title]/1',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -2*30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-30*3600*24; 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
return  $total;

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
    'phpcode' => array(
      'label' => 'Nov \'11',
      'alter' => array(
        'alter_text' => 1,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/1/main_[title]/1',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -30*3600*24;    
$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')); 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
else
return  $total;

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
    'phpcode_13' => array(
      'label' => 'Dec \'11',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/0/1',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'));    
$endtime = mktime(); 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10 AND n.status=1 AND wf.stamp BETWEEN $starttime AND $endtime"));
if($total==0) return \'-\';
else
return  $total;

?>',
      'exclude' => 1,
      'id' => 'phpcode_13',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
    'phpcode_12' => array(
      'label' => ' Total in the past 12 months ',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 1,
        'path' => 'agency-publications/agency-publications-month/[nid]/13/main_[title]/1',
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
      'empty' => '-',
      'hide_empty' => 0,
      'empty_zero' => 1,
      'value' => '<?php
$time=strtotime("-1 month");
$starttime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -12*30*3600*24;    
$endtime=mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'));
//$endtime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')); 

$total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid  AND wf.sid=10 AND n.status=1   AND wf.stamp BETWEEN $starttime AND $endtime"));


$result=db_query("SELECT  distinct ds.field_ds_sub_agency_nid as sub,sa.field_sa_subagency_name_value as name FROM content_type_dataset ds LEFT JOIN content_type_sub_agency as sa On sa.nid=ds.field_ds_sub_agency_nid INNER JOIN workflow_node WF on WF.nid=ds.nid where ds.field_ds_agency_name_nid=$data->nid AND WF.sid=10 AND ds.field_ds_catlog_type_type IS NOT NULL  AND WF.stamp BETWEEN $starttime AND $endtime   order by sa.field_sa_subagency_name_value asc ");	

$sub_month=\'</a></td></tr>\';
while ($row = mysql_fetch_object($result)) 
{
     if($row->sub!=null)
	{	  $sub_month.=\'<tr><td class="ds-list-item-new" style="padding-left:20px;">\'.$row->name.\'</td>\';
                         for($i=12;$i>0;$i--){
                          $stime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -$i*30*3600*24;    
                          $etime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-($i-1)*30*3600*24; 
                          $sub=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid =$row->sub  AND wf.stamp BETWEEN $stime AND $etime"));
                            if($sub==0) $sub_month.=\'<td class="ds-list-item-new-center" style="text-align:center;"> -</td>\';
                            else
                            $sub_month.=\'<td class="ds-list-item-new-center" style="text-align:center;"><a title="Month wise report for \'.$row->sub.\'" href="agency-publications-month/\'.$data->nid.\'/\'.$i.\'/\'.$row->sub.\'/1">\'.$sub.\'</a></td>\';
							}
                      $sub_total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid=$row->sub  AND wf.stamp BETWEEN $starttime AND $endtime"));
                            
                  $sub_month.=\'<td class="ds-list-item-new-center" style="text-align:center;"><a title="Past 12 months report for \'.$row->sub.\'" href="agency-publications-month/\'.$data->nid.\'/13/\'.$row->sub.\'/1">\'.$sub_total.\'</a></td></tr>\';


                 }
	else
	{	$null_agency=$data->node_title;
		$short_name=db_result(db_query("Select field_agency_short_name_value from content_type_agency where nid=$data->nid"));
		$short_name=\' (\'. $short_name.\')\';
		$sub_month.=\'<tr><td class="ds-list-item-new" style="padding-left:20px;">\'.$null_agency.\'</td>\';
                         for($i=12;$i>0;$i--){
                          $stime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\')) -$i*30*3600*24;    
                          $etime = mktime(0, 0, 0, date(\'m\'), 1, date(\'Y\'))-($i-1)*30*3600*24; 
                          $sub=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid IS NULL AND wf.stamp BETWEEN $stime AND $etime"));
                            if($sub==0) $sub_month.=\'<td class="ds-list-item-new-center" style="text-align:center;"> -</td>\';
                            else
                            $sub_month.=\'<td class="ds-list-item-new-center" style="text-align:center;"><a title="Month wise report for \'.$null_agency.\'" href="agency-publications-month/\'.$data->nid.\'/\'.$i.\'/-/1">\'.$sub.\'</a></td>\';
							}
                      $sub_total=db_result(db_query("SELECT count(*)FROM content_type_dataset ds INNER JOIN content_type_agency a ON ds.field_ds_agency_name_nid = a.nid  INNER JOIN    workflow_node wf ON ds.nid=wf.nid INNER JOIN node n on ds.nid=n.nid  WHERE  ds.field_ds_agency_name_nid =$data->nid AND wf.sid=10  AND n.status=1  AND ds.field_ds_sub_agency_nid IS NULL AND wf.stamp BETWEEN $starttime AND $endtime"));
                            
                  $sub_month.=\'<td class="ds-list-item-new-center" style="text-align:center;"><a title="Past 12 months report for \'.$null_agency.\'" href="agency-publications-month/\'.$data->nid.\'/13/-/1">\'.$sub_total.\'</a></td></tr>\';
	} 
}

$sub_month=substr($sub_month,0,strlen($sub_month)-14);
if($total==0) return \'-\';
else
return  $total.$sub_month  ;

?>
',
      'exclude' => 0,
      'id' => 'phpcode_12',
      'table' => 'customfield',
      'field' => 'phpcode',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Use default',
      ),
    ),
  ));
  $handler->override_option('title', 'Month Wise');
  $handler->override_option('path', 'agency-publications/month-wise/pdf');
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
