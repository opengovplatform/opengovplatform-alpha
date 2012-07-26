<?php
	global $base_url;
	    global $theme_key;
    $themes = list_themes();
    $theme_object = $themes[$theme_key];
    $theme_name=$theme_object->name;
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language ?>" xml:lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
<head>
<meta http-equiv="X-UA-Compatible" content="IE=8" >
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<?php global $base_url;?>
<title><?php print $head_title ?></title>
<?php print $head ?>
<?php print $styles ?>
<link href="<?php echo $base_url."/".path_to_theme();?>/high.css" rel="alternate stylesheet" type="text/css" media="screen" title="change" />
<?php print $scripts; ?>
</head>

<body class="homePage">
	<span>
		<a class="skipnav" href="#mainNav">Skip to navigation</a>
		<a class="skipnav" href="#mainContent">Skip to main content</a>
	</span>
	<!--top panel start here -->
	<div id="topPanel">
		<div class="mid">
		<!--goi-->
			 <div style="float: left; width: auto;">
              <?php print $header_flag; ?>
			  </div>
            <!--goi -->
				
			<!--accessibility panel start here -->
			<div class="accessPan">
				<ul>
					<!--flags options -->
					<li>OTHER COUNTRY SITES</li>
                    <li class="flags">
						<?php print $header_flags; ?>
                    </li>
                    <!--flags options -->
					<li class="resize">
						<?php print $text_resize; ?>
					</li>
					<!--text resizing option -->
						
					<!--color contrast options -->
					<li class="contrast">
						<a href="javascript:void(0);" class="dark" onclick="chooseStyle('change', 60,'none');"><img src="<?php echo $base_url."/".path_to_theme();?>/images/texthighContrast.gif" alt="High Contrast View"/></a>
						<a href="javascript:void(0);" class="light" onclick="chooseStyle('none', 60,'none');"><img src="<?php echo $base_url."/".path_to_theme();?>/images/textNormal.gif" alt="Standard Contrast View"/></a>
					</li>
					<!--color contrast options -->
					<li class="feedback"><a href="<?php echo $base_url;?>/feedback" title="Feedback">Feedback</a></li>
					<li><a href="<?php echo $base_url;?>/rssfeeds" title="RSS Feeds" class="rss">RSS Feeds</a></li>
					<li class="share">
                    <!-- AddThis Button BEGIN -->
                        <div class="addthis_toolbox addthis_default_style ">
                            <a class="addthis_button_compact add-this-link" href="http://www.addthis.com/bookmark.php" title="Bookmark and Share">Share+</a>
                        </div>
                    <!-- AddThis Button END -->
					</li>
					<li><a href="<?php echo $base_url;?>/sitemap" title="Sitemap" class="sitemap">Sitemap</a></li>
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
	</div>
	<!--top panel end here -->
	<!--logo panel start here -->
	<div id="logoPanel">
		<div class="mid">
			<div class="left">
				<!--logo start here -->
				<div class="logoPan">
					<h1>
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
					
					</h1>
				</div>
				<!--logo start here -->
				
				<!--search form start here -->
				<div class="searchPan">
					<?php print $search_box; ?>
				</div>
				<!--search form end here -->
			</div>
		</div>
	</div>
	<!--logo panel end here -->
    <!--nav panel start here -->
	<div id="navPanel">
		<div class="mid">
			<?php print $banner_links;?>	
			<div class="spacer"></div>
		</div>
	</div>
	<!--nav panel end here -->    
	<!--body panel start here -->
	<div id="bodyPanel">
		<div id="outerContainer">
			<div class="mid">
				<!--header panel start here -->
				<div id="headerPan">
					<div id="rotating-panes">
						<?php print $banner; ?>
					</div>
				</div>
				<!--header panel end here -->
				
				<!--body panel start here -->
				<div id="bodyPan">
					<!--content panel start here -->
					<div class="contentPanel">
						<!--top blocks start here -->
						<div class="topBlocks">
							<?php print $content;?>
						</div>
						<!--top blocks end here -->

						<!--idea panel start here -->
						<!--<div class="ideaPanel">
							<span class="crnr crnrLftTop"></span>
							<span class="crnr crnrRtTop"></span>
							<span class="crnr crnrLftBtm"></span>
							<span class="crnr crnrRtBtm"></span>
							<a href="#"><img src="<?php //echo $base_url."/".path_to_theme();?>/images/idea-banner.jpg" alt="Suggest an Idea!" title="Suggest an Idea!" /></a>
							<div class="container">
								<h2>Recently Suggested Ideas</h2>
								<ul>
									<li><a href="#" title="Browse Function">Browse<br />Function</a></li>
									<li><a href="#" title="Domain Specific Metadata">Domain Specific<br />Metadata</a></li>
									<li><a href="#" title="Maps Datasets">Maps<br />Datasets</a></li>
								</ul>
							</div>
						</div>-->
						<!--idea panel end here -->
					</div>
					<!--content panel end here -->
					
					<!--side panel start here -->
					<div class="sidePanel">
						<!--tab panel -->
						<div class="tabPanel">
							<!--tabs -->
							<div class="tabs">
								<ul>
									<li><a href="javascript:;" title="Recent Catalogs" class="active recent_catalogs" id="cont-1">Recent Catalogs</a></li>
									<li><a href="javascript:;" title="Popular Catalogs" id="cont-2" class="popular_catalogs">Popular Catalogs</a></li>
								</ul>
							</div>
							<!--tabs -->
							
							<!--most used datasets -->
							<div class="content" id="recent_catalogs">
								<?php print $recent_catalogs;?>
							</div>
							<!--most used datasets -->
							
							<!--most used datasets -->
							<div class="content" id="popular_catalogs">
								<?php print $popular_catalogs;?>
							</div>
							<!--most used datasets -->
							
						</div>
						<!--tab panel -->
						
						<!--data sites -->
						<div class="yellowBox">
							<span class="crnr crnrLftTop"></span>
							<span class="crnr crnrRtTop"></span>
							<span class="crnr crnrLftBtm"></span>
							<span class="crnr crnrRtBtm"></span>
							<img src="<?php echo $base_url."/".path_to_theme();?>/images/open-data-sites.png" alt="OPEN DATA SITES" title="OPEN DATA SITES" />
							<ul>
								<li><a href="<?php echo $base_url;?>/wwdatasites">Link to WW Data Sites</a></li>
							</ul>
						</div>
						<!--data sites -->
						
						<!--text box -->
						<div class="txtBox">
							<h2>Major Events</h2>
							<div class="content" id="major_events">
								<?php print $major_events;?>
							</div>
						</div>
						<!--text box -->
					</div>
					<!--side panel end here -->
				</div>
				<!--body panel end here -->
				
				<!--bottom links -->
				<div class="footerLinks">
					<h2>OpenGov:</h2>
					<?php print $footer;?>
				</div>
				<!--bottom links -->
			</div>
		</div>
	</div>
	<!--body panel end here -->
	
	<!--bottom panel start here -->
	<div class="bottomLinks">
		<div class="mid blocks">
			<?php echo theme('site_map'); ?>
		</div>
	</div>
	<!--bottom panel end here -->

	<!--footer start here -->
	<div id="footer">
		<ul class="top">
			<?php print $footer_links;?>
		</ul>
		<div class="footerContent">
                <div class="left"><?php print $site_hosting_details;?></div>
                <div class="right"><?php print $site_ownership_details;?></div>
        </div>
	</div>
	<!--footer end here -->
<?php
print $closure;
?>
</body>
</html>