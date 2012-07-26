<?php
    global $base_url;
     
?>   
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language; ?>" xml:lang="<?php print $language->language; ?>">
<head>
<meta http-equiv="X-UA-Compatible" content="IE=8" />
<meta http-equiv="content-language" content="<?php echo $language->language;?>" />
<title>Home | Welcome to ODP</title>
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

<body role="application">
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
            
            <!--accessibility panel start here -->
            <div class="accessPan">
            	<ul>
					<li class="colorOptions">

                	<!--color options -->
                	<!--<li><a href="#content" title="Skip to Main Content">Skip to Main Content</a></li> -->
					<?php print $color_options; ?>
					</li>
					<!--color options -->
                    <li class="resize">
						<?php print $text_resize; ?>
					</li>
                    <li class="contrast">
                   <!--color contrast options -->
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
					echo "<li><a href='logout'>Log out</a></li>";
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
                <?php if($banner) { ?>
                <div class="rotating-banner"><?php print $banner;?></div>
                <?php } ?>
                <div class="rotating-banner banner-left"><?php print $banner_left;?></div>
                <?php if($banner_right) { ?>
                <div class="banner-right"><?php print $banner_right;?></div>
                <?php } ?>
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
			<?php print $home_content;?>
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
        	<div class="blocksPanel">
				<?php //print $footer_sitemap;?>		
				<?php echo theme('site_map'); ?>
            </div>
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
</body>
<?php
print $closure;
?>
</html>
