<?php

/**
 * @file search-results.tpl.php
 * Default theme implementation for displaying search results.
 *
 * This template collects each invocation of theme_search_result(). This and
 * the child template are dependant to one another sharing the markup for
 * definition lists.
 *
 * Note that modules may implement their own search type and theme function
 * completely bypassing this template.
 *
 * Available variables:
 * - $search_results: All results as it is rendered through
 *   search-result.tpl.php
 * - $type: The type of search, e.g., "node" or "user".
 *
 *
 * @see template_preprocess_search_results()
 */
?>

<div id="big-catalog-panel" class="fRight">

<?php  
	global $base_url;
	$this_page = $_SERVER['REQUEST_URI'];
		
 if(!strlen(strstr($this_page,"filters"))>0)
	 {
			$_SESSION['rows']=10;
	  }
	  
     $page = $_SERVER['REQUEST_URI'];
	$options=array(' '=>'Most Relevant','sis_popularity desc'=>'Most Accessed','sis_ratings desc'=>'Most Rated','comment_count desc'=>'Most Commented','sort_title asc'=>'Alphabetical','created desc'=>'Newest','created asc'=>'Oldest');
	$results_page=array('10'=>'10','25'=>'25','50'=>'50','100'=>'100');
	if($_GET['selectop']=='1')
	{
	  $pos=strpos($page,'&selectop');
	  $page=substr($page,0,$pos);
	  $_SESSION['rows']=10;
	  
	}
	$form['solrsort']=array(
	'#type' => 'select',
	'#title' => t(''),
	'#options' =>  $options,
	'#value'=>$_GET['solrsort'],
	'#attributes' => array('onChange' => ' 
	 window.open("'.$page.'&selectop=1&solrsort="+this.options[this.options.selectedIndex].value,"_self")'),
	);
	$form['page-results']=array(
	
	'#type' => 'select',
	'#id'=>'selectpage',
	'#title' => t('Results Per Page'),
	'#options' =>  $results_page,
	'#value'=>$_GET['results'],
	'#attributes' => array('onchange' => 'window.open("'.$this_page.'&pageop=1&results="+this.options[this.options.selectedIndex].value,"_self")'),
	
	
	);
	$form['page-results1']=array(
	'#type' => 'select',
	'#title' => t(''),
	'#options' =>  $results_page,
	'#value'=>$_GET['results'],
	'#attributes' => array('onChange' => 'window.open("'.$this_page.'&pageop=1&results="+this.options[this.options.selectedIndex].value,"_self")'),
	
	
	);

	/*SET TITLE FOR SEARCH PAGE */
	
	$search_title='Browse Datasets';
	if (strlen(strstr($this_page,"filters=type%3Adataset"))>0) 
	{
		drupal_set_title('Datasets'); 
		if(strlen(strstr($this_page,"ss_cck_field_ds_catlog_type%3A"))>0)
		{
			drupal_set_title('Datasets'); 
			if(strlen(strstr($this_page,"catalog_type_data_apps"))>0)
			{
				drupal_set_title('Apps'); 
				$search_title='Browse Apps';
			}
			else if(strstr($this_page,"catalog_type_raw_data"))
			{
				drupal_set_title('Raw Data'); 
				$search_title='Browse Raw Data';
			}
			else if(strstr($this_page,"catalog_type_document"))
			{
				drupal_set_title('Documents');
				$search_title='Browse Documents';					
			}
			else if(strstr($this_page,"catalog_type_data_tools"))
			{
				drupal_set_title('Tools');
				$search_title='Browse Tools';					
			}
			else if(strstr($this_page,"catalog_type_data_service"))
			{
				drupal_set_title('Services');
				$search_title='Browse Services';					
			}
	}			
	  
	print '<div class="heading">'.$search_title;
	print '<div  style="display:none;" class="sort-select-box switch-js-enabled ">';
	print drupal_render($form['page-results']).'</div>';
	$count=10;
	$count=$_GET['results'];
	if($count==0) $count=10;
	$page_uri = $_SERVER['REQUEST_URI'];
	if($_GET['pageop']=='1')
	{
	  $page_uri=substr($page_uri,0,strpos($page_uri,"&pageop=1"));
    }
       $page_uri=str_replace("&","&amp;",$page_uri);
	print '<div  class="sort-select-box cBoth switch-js-disabled"> Results Per Page: ';
	if($count=='10')
	print ' 10 |';
	else
	print '<a title="Show 10 results per page" href="'.$page_uri.'?&amp;pageop=1&amp;results=10"> 10 </a>|';
	if($count=='25') print ' 25 |';
	else
	print '<a title="Show 25 results per page" href="'.$page_uri.'&amp;pageop=1&amp;results=25"> 25 </a>|';
	if($count=='50') print ' 50 |';
	else
	print '<a title="Show 50 results per page" href="'.$page_uri.'&amp;pageop=1&amp;results=50"> 50 </a>|';

	if($count=='100') print ' 100 ';
	else
	print '<a title="Show 100 results per page" href="'.$page_uri.'&amp;pageop=1&amp;results=100"> 100 </a>';

	print '</div>';

	//print '<div class="sort-select-box">';
	//print drupal_render($form['solrsort']);
	//print '<span style="width: 200px; font: 14px Arial ! important;">(Search found 27 items)</span>';
    print'</div>';
	
	print '<div class="ds-list" >';
	global $pager_page_array, $pager_total;
		$total_pages = $pager_total['0'];
		$total_page_count = $total_pages - 1;
		
		$page_number = $pager_page_array['0'];
		$page_res=(int)$_SESSION['rows'];
		$start_result = $page_number * $page_res  + 1;
		print '<div class="ds-list-head " >';		
		print '<div class="title" style="width:40px;">Sr.No.</div>  <div class="title" style="width:300px;">Name/Title </div> <div class="title" style="width:80px;"> Popularity </div> <div class="title" style="width:90px;">Rating </div> <div class="title" style="width:85px;">File Format </div></div> ';
		$i=$start_result;
		
	
		foreach( $results as $result)
		  { 
			print '<div class="ds-list-item">';
				$thisNode = node_load($result['node']->nid);
			//SI
			print '<div class="item" style="width:40px; height:50px;"  >'.$i++.'</div>';
			//Name
			$name=check_plain($result['title']);
			$title_lim=7;
			
			if (str_word_count($name, 0) > $title_lim) {
			$numwords = str_word_count($name, 2);
			$pos = array_keys($numwords);
			$name = substr($name, 0, $pos[$title_lim]).'...' ;
			}
			print '<div class="item" style="width:300px;">';	print '<h3 style="width:100%;"><a title="'.check_plain($result['title']).'" href="'. check_url($result['link']) .'">'.$result['title'].'</a></h3><div>';
			
			if(strlen(strstr($this_page,"search/apachesolr_search/?filters"))>0 || strlen(strstr($this_page,"search/apachesolr_search?"))>0)
			{
				$text=$thisNode->field_ds_description[0][value];
			}
			else
			{	$text=$result[snippet];
			
			}
			$limit=40;
			
			if (str_word_count($text, 0) > $limit) {
			$numwords = str_word_count($text, 2);
			$pos = array_keys($numwords);
			$text = substr($text, 0, $pos[$limit]).'...' ;
			}
			print strip_tags($text).'<br/></div></div>';
			
		
			/* */
			$teaser = FALSE;
			$page = TRUE;
			$thisNode = node_build_content($thisNode, $teaser, $page);
			$statistics = statistics_get($thisNode->nid);
			if($statistics==null)
			$total_count=0;
			else
			$total_count=$statistics['totalcount'];
			//Popularity
			print '<div class="item" style="width:80px;">'.$result['fields']['sis_popularity'].' views</div>';
			/*Ratings */
			 $a=0;
			 $q=0;
			 $u=0;
			 $acc=votingapi_select_results(array('content_id' => $thisNode->nid, 'tag' =>'voteaccessibility', 'function' => 'average'));
			 $qual=votingapi_select_results(array('content_id' => $thisNode->nid, 'tag' =>'votequality', 'function' => 'average'));
			 $usab=votingapi_select_results(array('content_id' => $thisNode->nid, 'tag' =>'voteusability', 'function' => 'average'));
			 $oldrange=(25-0);
			 $newrange=(40-20);
			 
			 	$a=(int)$acc[0]['value'];		
			    $q=(int)$qual[0]['value'];
				$u=(int)$usab[0]['value'];
				
				
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
			
        $vote1= rate_get_results('node', $thisNode->nid, 1);
        $vote2 = rate_get_results('node', $thisNode->nid, 2);
        $vote3=rate_get_results('node', $thisNode->nid, 3);
        $vote=$vote1['count'];
        if($vote2['count']>$vote) $vote=$vote2['count'];
        if($vote3['count']>$vote)$vote=$vote3['count'];                 
           if($result['fields']['sis_ratings']=='0') $vote=0;   		           
            $votes='<span style="margin-left: 20px;">('.$vote.' votes)</span>'; 
                $vote=0;
			 print '<div class="item" style="width:90px;">'.theme('fivestar_static',$result['fields']['sis_ratings']).$votes.'</div>';
			
			//FileFormat
			$file=$thisNode->field_ds_file[0][filemime];
			$fileformat='Unknown';
			  if($file == 'text/csv') $fileformat='CSV';
			  if($file == 'text/plain') $fileformat='TXT'; 
			  if($file == 'application/vnd.google-earth.kml') $fileformat='KML';
			  if($file == 'application/octec-stream') $fileformat='SHP';
			  if($file == 'text/xml' || $file == 'application/xml')$fileformat='XML' ;
			  if($file == 'text/html') $fileformat='HTML';
			  if($file== 'application/pdf')$fileformat='PDF';
			  if($file== 'application/zip') $fileformat='ZIP';
			  if($file == 'application/vnd.ms-powerpoint') $fileformat='PPT';
			  if($file=='application/vnd.openxmlformats-officedocument.wordprocessingml.document' || $file=='application/vnd.ms-word')  $fileformat='DOC';
			  if($file=='application/vnd.openxmlformats-officedocument.spreadsheetml.sheet')   $fileformat='XLSX';
                       if($file=='application/vnd.ms-excel') $fileformat='XLS';

		  //print_r($thisNode);
		  $filename=substr($thisNode->field_ds_file[0][filepath],strrpos($thisNode->field_ds_file[0][filepath],"/")+1);
		  if($fileformat=='CSV')
				 print '<div class="item" style="width:85px;"><a  title="CSV Download" href="'.$base_url.'/system/files/'.$filename.'"><img alt="CSV" src="'.$base_url.'/sites/all/themes/ogpl_css3/images/csv.png"/></a></div></div>';
		   else if ($fileformat=='XLS')
				 print '<div class="item" style="width:85px;"><a  title="XLS Download" href="'.$base_url.'/system/files/'.$filename.'"><img alt="XLS" src="'.$base_url.'/sites/all/themes/ogpl_css3/images/xls.png"/></a></div></div>';
                 else if ($fileformat=='XLSX')
				 print '<div class="item" style="width:85px;"><a  title="XLSX Download" href="'.$base_url.'/system/files/'.$filename.'"><img alt="XLSX" src="'.$base_url.'/sites/all/themes/ogpl_css3/images/xlsx.png"/></a></div></div>';
		   else if ($fileformat=='PDF')
				 print '<div class="item" style="width:85px;"><a  title="PDF Download" href="'.$base_url.'/system/files/'.$filename.'"><img alt="PDF" src="'.$base_url.'/sites/all/themes/ogpl_css3/images/pdf.png"/></a></div></div>';	 
		  else if ($fileformat=='XML')
				 print '<div class="item" style="width:85px;"><a  title="XML Download" href="'.$base_url.'/system/files/'.$filename.'"><img alt="XML" src="'.$base_url.'/sites/all/themes/ogpl_css3/images/xml.png"/></a></div></div>';
                else if ($fileformat=='KML')
				 print '<div class="item" style="width:85px;"><a  title="KML Download" href="'.$base_url.'/system/files/'.$filename.'"><img alt="KML" src="'.$base_url.'/sites/all/themes/ogpl_css3/images/kml.png"/></a></div></div>';
                 else if ($fileformat=='SHP')
				 print '<div class="item" style="width:85px;"><a  title="SHP Download" href="'.$base_url.'/system/files/'.$filename.'"><img alt="SHP" src="'.$base_url.'/sites/all/themes/ogpl_css3/images/shp.png"/></a></div></div>';				 
		   else if($file)
				 print '<div class="item" style="width:85px;"><a title="Download" href="'.$base_url.'/system/files/'.$filename.'">'.$fileformat.'</a></div></div>';
			else  print '<div class="item" style="width:85px;"></div></div>';
			   // print_r($thisNode->field_ds_file[0]);

		  }
	 // print '<br/><br/>';
	  print '<div class="paging" > '.$pager;
	 // print '<div class="bottom-page-results">Results Per Page:';
	//  print drupal_render($form['page-results1']).'</div>
	  print '</div></div>';
	  $pagenum=$page_number+1;
	  $recs = $GLOBALS['pager_total_items'][0];
	  if($pager)
	  {
			//print '<div class="showing-pager">Showing '.$pagenum.' of '. $total_pages .' pages (out of '.$recs.' records ) </div>';	
	  }
	  
	  //suggest Dataset
	  print '<div style="text-align:center;margin-right:20px;">';
	  
	  print '<div class="fLeft suggest-label">Didn`t find what you are looking for? Would like to inform/suggest?<a title="Suggest Dataset"  href="'.$base_url.'/suggest_dataset" >Suggest</a></div></div></div> ';

	
	
}
else 
    {
print '<div class="heading">'.$GLOBALS['pager_total_items'][0].' Search Results</div>';
	print '<div class="ds-list" >';
	global $pager_page_array, $pager_total;
		$total_pages = $pager_total['0'];
		$total_page_count = $total_pages - 1;
		
		$page_number = $pager_page_array['0'];
		$page_res=(int)$_SESSION['rows'];
		$start_result = $page_number * $page_res  + 1;
		//print '<div class="ds-list-head " >';		
		//print '<div class="title" style="width:50px;">SI </div>  <div class="title" style="width:210px;">Name </div> <div class="title" style="width:100px;"> Type </div> <div class="title" style="width:100px;">Rating </div> <div class="title" style="width:105px;">Description </div></div> ';
		$i=$start_result;
		
	
	foreach( $results as $result)
	  { //print_r($result);
		print '<div class="ds-list-item">';
     	$thisNode = node_load($result['node']->nid);
		//print '<div style="width:50px;"  >'.$i++.'</div>';
		
	     print '<div class="item" style="width:30px;" >';		
         if($result[type]=='Page')
		 print '<img src="'.$base_url.'/sites/all/themes/ogpl_css3/images/page.png" alt="Page"/>';
		 else if($result[type]=='Dataset')
         print '<img src="'.$base_url.'/sites/all/themes/ogpl_css3/images/dataset.png" alt="Dataset"/>';
		 else if($result[type]=='Upload Documents')
		 print '<img src="'.$base_url.'/sites/all/themes/ogpl_css3/images/uploads.png" alt="Documents"/>';
		 else if($result[type]=='FAQ')
		 print '<img src="'.$base_url.'/sites/all/themes/ogpl_css3/images/faq.png" alt="FAQ"/>';
 		 print'</div>';

	    //Name
		$type=$result[type];
		if($result[type]=='Upload Documents')
		    $type='Document';
		  $name=$result['title'];
			$title_lim=6;
			
			if (str_word_count($name, 0) > $title_lim) {
			$numwords = str_word_count($name, 2);
			$pos = array_keys($numwords);
			$name = substr($name, 0, $pos[$title_lim]).'...' ;
			}	
		print '<div class="item" style="width:610px; min-height:42px; ">';	print '<h3><a title="'.check_plain($result['title']).'" href="'. check_url($result['link']) .'">'.$name .'</a></h3><div class="type">'.$result[type].'</div>';
		$limit=40;
		
		if(strlen(strstr($this_page,"search/apachesolr_search/?filters"))>0 || strlen(strstr($this_page,"search/apachesolr_search?"))>0)
			{
				$text=$thisNode->field_ds_description[0][value];
			}
			else
			{	$text=$result[snippet];
			
			}
			
		if (str_word_count($text, 0) > $limit) {
        $numwords = str_word_count($text, 2);
        $pos = array_keys($numwords);
        $text = substr($text, 0, $pos[$limit]).'...' ;
		}
		/*Ratings */
		     $a=0;
			 $q=0;
			 $u=0;
			 $acc=votingapi_select_results(array('content_id' => $thisNode->nid, 'tag' =>'voteaccessibility', 'function' => 'average'));
			 $qual=votingapi_select_results(array('content_id' => $thisNode->nid, 'tag' =>'votequality', 'function' => 'average'));
			 $usab=votingapi_select_results(array('content_id' => $thisNode->nid, 'tag' =>'voteusability', 'function' => 'average'));
			 
			 $oldrange=(25-0);
			 $newrange=(40-20);
			 	$a=(int)$acc[0]['value'];		
			    $q=(int)$qual[0]['value'];
				$u=(int)$usab[0]['value'];
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
	
        $vote1= rate_get_results('node', $thisNode->nid, 1);
        $vote2 = rate_get_results('node', $thisNode->nid, 2);
        $vote3=rate_get_results('node', $thisNode->nid, 3);
        $vote=$vote1['count'];
        if($vote2['count']>$vote) $vote=$vote2['count'];
        if($vote3['count']>$vote)$vote=$vote3['count'];             
        if($result['fields']['sis_ratings']=='0') $vote=0;   		
        $votes='<span style="margin-left: 20px;">('.$vote.' votes)</span>'; 
		$vote=0;
		if($result[type]=='Dataset' && $value!=0)
		print '<div style="width:100px; float:right;">'.theme('fivestar_static', $result['fields']['sis_ratings']).$votes.'</div>';
		print '<div style="width:580px; float:left ">'.strip_tags($text).'<br/></div>';
		
		
		/* */
		$teaser = FALSE;
		$page = TRUE;
		$thisNode = node_build_content($thisNode, $teaser, $page);
		$statistics = statistics_get($thisNode->nid);
		if($statistics==null)
		$total_count=0;
		else
		$total_count=$statistics['totalcount'];
		//Popularity
		
	//	print '<div  class="item list-bullet" style="width:65px; margin-left: 55px;">'..'</div>';
	   		
			
		if($result[type]=='Dataset')
		print '<div class="item list-bullet" style="width:220px; font-size:1em; padding-bottom:0px; "><a title="'.$thisNode->field_ds_agency_name[0][safe][title].'" href="'.$base_url.'/search/apachesolr_search/?filters=is_cck_field_ds_agency_name%3A'.$thisNode->field_ds_agency_name[0][safe][nid].'">'.$thisNode->field_ds_agency_name[0][safe][title].'</a></div>';

		//FileFormat
		//print_r($thisNode);
		
		print '</div></div>';
	  }
	 // print '<br/><br/>';
	  print '<div class="paging" > '.$pager.'</div></div></div>';
	  
	}
	
	if(!empty($_GET['filters'])){
		?>	
		<script type="text/javascript">
			$("#block-apachesolr-sort .item-list li:first").hide();
		</script>
		<?php
	}
  ?>

<?php// print $pager; ?>
