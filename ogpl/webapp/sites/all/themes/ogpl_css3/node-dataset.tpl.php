<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?>">
<?php global $base_url;?>    
    <?php print $picture ?>
    <?php 
	drupal_add_js(drupal_get_path('module', 'clientside_validation') . '/jquery-validate/jquery.validate.js');
	drupal_add_js(drupal_get_path('theme', 'ogpl_css3') . '/js/validation.js');	
	?>	
    <?php
   	global $base_path;
    function embedURL() {
		global $base_path;
		$pageURL = 'http';
        if ($_SERVER["HTTPS"] == "on") {$pageURL .= "s";}
        $pageURL .= "://";
		$pageURL .= $_SERVER["SERVER_NAME"].$base_path;
        $pageURL .= 'embed-preview/';
        return $pageURL;
    }
	function getFileIcon($format)
    {
        if($format=="CSV")
		  return 'csv.png';
		else if($format=="XML") 
		  return 'xml.png';
		else if($format=="XLS") 
		  return 'xls.png'; 
		else if($format=="KML/KMZ") 
		  return 'kml.png';  
        else if($format=="Shapefile") 
		  return 'shp.png';
        else if($format=="Map") 
		  return 'map.png';
		      		  
     }	

	function get_string_between($string, $start, $end){
   	 $string = " ".$string;
   	 $ini = strpos($string,$start);
   	 if ($ini == 0) return "";
   	 $ini += strlen($start);
   	 $len = strpos($string,$end,$ini) - $ini;
   	 return substr($string,$ini,$len);
	}
    ?>
    <?php /*if ($submitted): ?>
    <span class="submitted"><?php print $submitted; //print format_date($node->created, 'custom', "d.m.Y"); ?></span>
    <?php endif;*/ 
	
	/*MARK NODE FOR INDEXING */
	 apachesolr_mark_node($node->nid);
	
	?>
  <div class="add-this-options">
<?php if(empty($_GET['embed'])&& empty($_GET['print'])){ ?>
    <div class="anchor-links fLeft">
        <div class="fLeft"><a href="#tabs-block" rel="discuss" title="Discuss this dataset">Discuss this dataset</a></div>	
		<div class="fLeft"><a href="#tabs-block" rel="contactOwner" title="Contact Dataset Owner">Contact Dataset Owner</a></div>
		<div class="fLeft"><a href="#tabs-block" rel="ratings" title="Rate this dataset">Rate this dataset</a></div>
		<div class="fLeft"><a href="#tabs-block" rel="embed" title="Embed this dataset">Embed this dataset</a></div>
    </div>
<?php } ?>
	<div style="float:right">
     <a class="addthis_button_facebook at300b" title="Send to Facebook" href="#">
     <span class="at300bs at15nc at15t_facebook"></span>
	 </a>
	 <a class="addthis_button_twitter at300b" title="Tweet This" href="#">
     <span class="at300bs at15nc at15t_twitter"></span>
	 </a>
	 <a class="addthis_button_email at300b" title="Email" href="#">
     <span class="at300bs at15nc at15t_email"></span>
	 </a>
	 <?php if(empty($_GET['embed'])&& empty($_GET['print'])){ ?>
	 <a target="_blank" title="Print" href="<?php print $base_url."/print-dataset/".$node->path; ?>">
       <img src="<?php echo $base_url."/".path_to_theme();?>/images/print.png" width="16" height="13" id="print-icon" alt="Print this dataset" title="Print this dataset"  />
	 </a>
	 <?php } ?>
	 </div>
  </div>
  <div class="cBoth"></div>
    <div class="content">
	<div class="dataset">
    <?php

		$pattern = "/\b\w+\@\w+[\.\w+]+\b/";
		preg_match_all($pattern,$content,$matches);
		$matchedArr = array_unique($matches[0]);
		foreach($matchedArr as $key=> $values){
			unset($match_email);
			for($i=0;$i<strlen($values);$i++){
				$match_email.= "&#".ord($values{$i}).";";
			}
			$content = str_replace($values,$match_email,$content);
		}

        $fileicon=getFileIcon($node->field_ds_access_method[0]['value']['field_atd_file_format'][0]['value']);
	      $img='<a href="'.$base_url.'/access-point-download-count?url='.$node->field_ds_access_method[0]['value']['field_atd_access_point'][0]['url'].'&nid='.$node->nid.'"><img alt="'.$node->field_ds_access_method[0]['value']['field_atd_file_format'][0]['value'].'" src="'.$base_url.'/sites/all/themes/ogpl_css3/images/'.$fileicon.'"/></a>';
      $download_count=db_result(db_query("Select download_count from web_download_count where nid=$node->nid"));
      if ($download_count==0) $download_count='<span class="download-stat"> Never Downloaded </span>';
	  else if ($download_count==1) $download_count='<span class="download-stat">Downloaded '.$download_count.' time </span>';
      else $download_count='<span class="download-stat"> Downloaded '.$download_count.' times </span>';

      $access_type_url=$node->field_ds_access_method[0]['value']['field_atd_access_point'][0]['url'];
           
      $search=get_string_between($content,'<div class="field-label">Access point:&nbsp;</div>','</div>');
     
      $search='<div class="field-label">Access point:&nbsp;</div>'.$search;
      $replace='<div class="field-label">Access point:&nbsp;</div> <div class="field-items"> <div class="field-item odd">'.$img. $download_count;
      $content=str_replace($search,$replace,$content);
    
	  print $content;

	?>
	<?php if(empty($_GET['embed'])&& empty($_GET['print'])){ ?>
	<div id="tabs-block" class="js-disable-hide">
		<ul class="list">
		    <li class="discuss active" title="Discuss this dataset">Discuss</li>
			<li class="contactOwner" title="Contact Dataset Owner">Contact Dataset Owner</li>
			<li class="ratings" title="Rate this dataset">Ratings</li>
			<li class="embed" title="Embed this dataset">Embed</li>		           
		</ul>	
	</div>
    <?php } ?>
	</div>
	<div style="clear:both;"></div>
    </div>
    <?php if(empty($_GET['embed'])&& empty($_GET['print'])){ ?>
	<div class="messages error clientside contactOwnerError" id="web-contact-owner-form-errors" style="display: none;"><ul><li style="display:none">No Errors</li></ul></div>
	<div class="messages error clientside ratingsError" id="ratings-form-errors" style="display: none;"><ul><li style="display:none">No Errors</li></ul></div>
	<div class="messages error clientside commentsError" id="comment-form-errors" style="display: none;"><ul><li style="display:none">No Errors</li></ul></div>
	<div class="js-disable-show">Embed</div>
    <form name="embed-form" action="<?php echo $base_url.'/'?>embed_preview" method="post" target="_new">
    <div class="tabs-cont embed-block">
	    <div class="textblock">
		<label for="embed_code" style="display:none">Embed code</label>
        <textarea rows="5" cols="60" class="textbx" name="embed_code" id="embed_code"><div><iframe width="500px" title="<?php echo $node->title; ?>" height="425px" src="<?php echo embedURL(); ?>" frameborder="1" scrolling="auto"></iframe></div></textarea>
    </div>    
    <div class="econf-block">
        <div style="float:right;">
            <div class="head">Size</div>
                <div class="block">    
                    <p class="size-large">950x808</p>
                    <p class="size-medium">760x646</p>
                    <p class="size-small">500x425</p>
                    <p style="clear:both;margin:0px;"></p>
                    <div id="large" class="large iframe-dimensions" title="950x808">&nbsp;</div>
                    <div id="medium" class="medium iframe-dimensions" title="760x646">&nbsp;</div>
                    <div id="small" class="small iframe-dimensions" title="500x425">&nbsp;</div>
                 </div>
             </div>
         <div style="float:left;">
             <div class="head">Custom Size</div>
             <div class="block">    
       			 <label for="ewidth">Width: </label>
                 <input type="text" name="ewidth" value="500" id="ewidth" class="custom-size" />
                 <div style="clear:both">&nbsp;</div>
                 <label for="eheight">Height: </label>
                 <input type="text" name="eheight" value="425" id="eheight" class="custom-size" />
                 <div style="clear:both">&nbsp;</div>
                 <div class="min-text">425x425 is the minimum size</div>
             </div>
         </div>
         <div style="clear:both">&nbsp;</div>
         <input type="submit" class="form-submit" name="preview" value="Preview" id="preview" title="Click here to preview" />
         <input type="hidden" name="embed-url" title="embed-url-hidden" value="<?php print htmlspecialchars($node->path); ?>" />
         <input type="hidden" name="js-embed-url" class="hidden-embed-url" title="embed-url-hidden" value="<?php echo embedURL().$node->path; ?>" />
         <input type="hidden" name="embed-title" title="embed-title-hidden" value="<?php echo $node->title; ?>" />
    </div>
	
	</div>
	</form>
    <div class="clear-block clear" style="clear:both;">
    <div class="meta">
    <?php if ($taxonomy): ?>
    <div class="terms">Tags: <?php print $terms ?></div>
    <?php endif;?>
    </div>
    
    <?php if ($links): ?>
    <div class="js-disable-show element-properties">Rating</div><div class="links ratings-block"><?php print $links; ?></div>
    <?php endif; ?>
    </div>
    <?php } ?>
</div>
<style type="text/css">
#node-form {padding: 15px;}
#node-form label{padding: 0 0 5px;}
#node-form #edit-submit{border: 1px solid #999999;font-size: 1.4em;}
</style>
<script type="text/javascript">
$(".field-item").each(function(){
	if($(this).find('.field').size() > 0){
		var htmlcontent = $(this).html();
		var pObj = $(this).parent().parent();
		$(pObj).removeClass('field');
		$(pObj).attr('innerHTML',htmlcontent);
	}
});

$(".field-item").each(function(){
	if($(this).find('.field').size() > 0){
		var htmlcontent = $(this).html();
		var pObj = $(this).parent().parent();
		$(pObj).removeClass('field');
		$(pObj).attr('innerHTML',htmlcontent);
	}
});


$(".fieldgroup").each(function(){
	$(this).find('.field:last').css('border','none');
	$(this).find('.field:last').css('borderRadius','0 0 7px 7px');
});

$("#print-icon").hover(function(){
	$(this).css('opacity','0.8');
	$(this).css('filter','alpha(opacity=80)');
},function(){
	$(this).css('opacity','1');
	$(this).css('filter','alpha(opacity=100)');
});

<?php if($_GET['print']){ ?>
$(window).bind('load',function(){
	if (typeof(window.print) != 'undefined') {
        window.print();
    }
});
<?php }?>

</script>

