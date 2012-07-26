<?php
    global $base_url;
	global $user;
	$access_denied = 0;	
	$admin_page_urls = variable_get('admin_pages_list', '');
  
 
	if(in_array(drupal_get_path_alias($_GET['q']), explode("\r\n", $admin_page_urls)) && in_array('anonymous user', $user->roles)){
		$access_denied = 1;
		$head_title = "Access Denied";
	}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language; ?>" xml:lang="<?php print $language->language; ?>">
<head>
<meta http-equiv="X-UA-Compatible" content="IE=8" />
<meta http-equiv="content-language" content="<?php echo $language->language;?>" />
<title><?php print $head_title ?></title>
<?php print $head ?>
<?php print $styles ?>
<?php print $scripts; ?>
<!--[if gte IE 9]>
  <style type="text/css">
    .gradient {
       filter: none;
    }
  </style>
<![endif]-->
</head>
<?php if(empty($_GET['embed'])&& empty($_GET['print'])){ ?>
<body class="innerPages" role="application">
	<span>
		<a class="skipnav" accesskey="1" href="#mainNav">Skip to navigation</a>
		<a class="skipnav" accesskey="2" href="#mainContent">Skip to main content</a>
	</span>
<div id="outerContainer">	
	<div id="mainContainer">
    	<!--top panel start here -->
        <div id="topPanel">
           <!--goi-->
			 <div style="float: left; width: auto;">
              <?php print $header_flag; ?>
			  </div>
            <!--goi -->
        <?php
          $url_page = drupal_get_path_alias(request_uri());
          $last_occ = strrpos($url_page, '/');
          $page_uri_alias = substr($url_page, $last_occ+1);
         ?>      
            <!--accessibility panel start here -->
            <div class="accessPan">
            	<ul>
                	<!--color options -->
                	<!--<li><a href="#content" title="Skip to Main Content">Skip to Main Content</a></li> -->
					<li class="colorOptions">
						<?php print $color_options; ?>
					</li>

                	<!--color options -->
                    <li class="resize">
						<?php print $text_resize; ?>
					</li>
                                        
                    <!--color contrast options -->
					
                    <li class="contrast">												
							<?php print $contrast_options; ?>
					</li>

                    <!--color contrast options -->
                    
					<li class="feedback"><a href="<?php echo $base_url;?>/feedback" title="Feedback">Feedback</a></li>
					
                	<li class="rssfeeds">
					  <a href="<?php echo $base_url;?>/rssfeeds" title="RSS Feeds" class="rss">
						<img src="<?php echo $base_url."/".path_to_theme();?>/images/icon-rss.png" alt="RSS Feed" title="RSS Feed" />
					  </a>
					</li>
                	
                    <li class="share">
                    <!-- AddThis Button BEGIN -->
                        <div class="addthis_toolbox addthis_default_style ">
                            <a class="addthis_button_compact add-this-link" href="http://www.addthis.com/bookmark.php" title="Bookmark and Share">Share+</a>
                        </div>
                    <!-- AddThis Button END -->
                    <?php //print $header_options; ?>
					</li>
                    <!--flags options -->
                    <li class="flags">
						<?php print $header_flags; ?>
                    </li>
                    <!--flags options -->
					<?php 
					global $user;
					if ($user->uid) {
					echo "<li><a href='$base_url/logout'>Log out</a></li>";
					}
					?>
                </ul>
            </div>
            <!--accessibility panel end here -->
        </div>
    	<!--top panel end here -->
         <script type="text/javascript">
			$(".colorOptions a, .contrast a").attr('href','#switch');
		</script>
        <!--logo panel start here -->
        <div id="logoPanel">
			<!--logo start here -->
			<div class="logo">
		    <?php
	        // Prepare header
	        $site_fields = array();
	        if ($site_name) {
	        	$site_fields[] = check_plain($site_name);
	        }
	        if ($site_slogan) {
	        	$site_fields[] = check_plain($site_slogan);
	        }
	        $site_title = implode(' ', $site_fields);
	        if ($site_fields) {
	        	$site_fields[0] = '<span>'. $site_fields[0] .'</span>';
	        }
	        $site_html = implode(' ', $site_fields);
	        
	        if ($logo || $site_title) {
	        	print '<a href="'. check_url($front_page) .'" title="'. $site_title .'">';
	        if ($logo) {
	        	print '<img src="'. check_url($logo) .'" alt="'. $site_title .'" id="logo-image" />';
	        }
	        print '</a>';
	        }
	        ?>
			</div>
			<!--logo end here -->

            <!--search panel start here -->
            <div class="searchPan" role="search">
            	<?php print $search_box; ?>
            </div>
            <!--search panel end here -->
        </div>
        <!--logo panel end here -->
        
        <!--header panel start here -->
        <div id="headerPanel">
        	<!--header start here -->
            <div id="header">
				<?php print $banner;?>
				<?php print $banner_left;?>
				<?php print $banner_right;?>
			</div>
        	<!--header end here -->
            
            <!--navigation start here -->
            <div id="mainNav" role="navigation">
				<?php print $banner_links;?>
            </div>
            <!--navigation end here -->
        </div>
        <!--header panel end here -->
        
        <!--blocks panel start here -->
		<div id="mainContent" role="main">
			<div id="contentPanel">	
				<?php
			if($access_denied == 1) {
				echo '<div class="containers"><h1 class="page-title">'.t('Access denied').'</h1><div class="page-title-border"></div>'
					.'<div class="access-denied-error">'.t('You are not authorized to access this page.').'</div></div>';
			} else {
			?>
            	<div class="containers">
				<?php if ($metrics_menu){ print '<div class="metrics-menu">'. $metrics_menu .'<div class="page-title-border"></div></div>';}else{ ?>
				<?php if ($title){ 
				switch(strtolower($title)) {
					case 'contact':
						$title = "Contact Us"; break;
					default: break;
				}
				print '<h1'. ($tabs ? ' class="page-title"' : '') .'>'. $title .'</h1>';
				$uri1 = strrpos($_SERVER["REQUEST_URI"], "datasets-agency");
				$uri2 = strrpos($_SERVER["REQUEST_URI"], "agency-publications-month");
				$uri3 = strrpos($_SERVER["REQUEST_URI"], "datasets-per-month-year");
				
				if($uri1===false && $uri2===false && $uri3===false)
				print '<div class="page-title-border">&nbsp;</div>';} }?>
				<?php //if ($tabs): print '<ul class="tabs primary">'. $tabs .'</ul>'; endif; ?>
          		<?php //if ($tabs2): print '<ul class="tabs secondary">'. $tabs2 .'</ul>'; endif; ?>
				<?php if ($show_messages && $messages): print $messages; endif; ?>
				<?php if ($search_filter){ print'<div class="small-catalog-panel">'.$search_filter.'</div>';}?>
				<?php print $content;?>
				<?php
                if($node->type=='dataset')  {
                    print '<div id="suggest-cp-block"><div style="text-align:center;margin-right:20px;" class="suggest-cp">';	  
                    print '<div class="suggest-label">Didn`t find what you are looking for? Would like to inform/suggest?  <a href="'.$base_url.'/suggest_dataset?nid='.$node->nid.'" title="Click here to suggest dataset" >Suggest</a></div></div></div>';
                }
                ?>
				</div>
				<?php } ?>
			</div>
        </div>
        <!--blocks panel end here -->
        
        <!--footer link start here -->
        <div class="footerLinks" role="contentinfo">
			<?php print $footer;?>
        </div>
        <!--footer link end here -->
    </div>
        
        <!--footer container start here-->
        <div class="footerSeparator">&nbsp;</div>
        <div class="footerContainer">
        	<!--footer links -->
        	<!-- code from this section is removed -->
        	<!--footer links -->
            
            <!--footer sub links -->
            <div class="footerSubLinks">
				<?php print $footer_links;?>
            </div>
            <!--footer sub links -->
            
			<div class="footerContent">
                <div class="left"><?php print $site_hosting_details;?></div>
                <div class="right"><?php print $site_ownership_details;?></div>
            </div>
        </div>
        <!--footer container end here-->
</div>
<script type="text/javascript">
<!--//--><![CDATA[//><!--
userAgentLowerCase = navigator.userAgent.toLowerCase();
 
function resizeTextarea(t) {
	
  if ( !t.initialRows ) t.initialRows = t.rows;
  a = t.value.split('\n');
  b=0;
  for (x=0; x < a.length; x++) {
	if (a[x].length >= t.cols) b+= Math.floor(a[x].length / t.cols);
  }
  b += a.length;
  if (userAgentLowerCase.indexOf('opera') != -1) b += 2;
 
  if (b > t.rows || b < t.rows)
	t.rows = (b < t.initialRows ? t.initialRows : b);
	
}

$("#edit-recipients").attr('rows',3);
$("#edit-recipients").keyup(function(){
		resizeTextarea(document.getElementById('edit-recipients'));

});

$("#edit-recipients").mouseout(function(){
		resizeTextarea(document.getElementById('edit-recipients'));

});
//--><!]]>
</script>


</body>
<?php
print $closure;
?>

    <?php } else { ?>
<body class="innerPages embed-code">
    <div id="mainContent">
        <div id="contentPanel">
            <div class="containers">
            <?php if ($metrics_menu){ print '<div class="metrics-menu">'. $metrics_menu .'<div class="page-title-border"></div></div>';}else{ ?>
            <?php if ($title){ 
            switch(strtolower($title)) {
                case 'contact':
                    $title = "Contact Us"; break;
                    default: break;
                }
            print '<h1'. ($tabs ? ' class="page-title"' : '') .'>'. $title .'</h1><div class="page-title-border">&nbsp;</div>';} }?>
            <?php if ($show_messages && $messages): print $messages; endif; ?>
            <?php if ($search_filter){ print'<div class="small-catalog-panel">'.$search_filter.'</div>';}?>
            <?php print $content;?>
            <?php
				if(empty($_GET['print'])){
					print '<div class="embed-feature-links">';
					print '<div class="fLeft"><a class="embeded-link discuss" target="_blank" href="">Contact Dataset Owner</a></div>';
					print '<div class="fLeft"><a class="embeded-link rating" target="_blank" href="">Rating</a></div>';
					print '<div class="fLeft"><a class="embeded-link suggest-dataset-link" target="_blank" href="">Suggest Dataset</a></div>';
					print '<div class="fLeft print"><a>Print</a></div>';
					print '<div class="cBoth"></div></div>';
				}	
            ?>
            </div>
        </div>
    </div>
</body>
<?php } ?>
</html>