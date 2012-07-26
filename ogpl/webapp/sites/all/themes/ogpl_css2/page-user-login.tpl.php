<?php global $base_url, $site_name;
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language; ?>" xml:lang="<?php print $language->language; ?>">

<head>
  <style type="text/css" media="all">
  @import "<?php echo $base_url.'/'.drupal_get_path('module', 'views_slideshow');?>/contrib/views_slideshow_singleframe/views_slideshow.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('module', 'views_slideshow');?>/contrib/views_slideshow_thumbnailhover/views_slideshow.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('module', 'extlink');?>/extlink.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('module', 'views');?>/css/views.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('module', 'context');?>/plugins/context_reaction_block.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('module', 'views_bulk_operations');?>/js/views_bulk_operations.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/css/style.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/css/typography.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/css/superfish.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/css/superfish-navbar.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/css/superfish-vertical.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/css/dms-style.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/css/multistep.css?i";

  </style>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <link href="<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/css/dms-style.css" rel="alternate stylesheet" type="text/css" />
  <link href="<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/css/multistep.css" rel="alternate stylesheet" type="text/css" />
  	
  <?php //print $styles; ?>
  <link type="text/css" rel="stylesheet" media="all" href="<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/fusion_core/css/grid16-fluid.css?i"/>
  <!--[if IE 8]>
  <link type="text/css" rel="stylesheet" media="all" href="<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/fusion_core/css/ie8-fixes.css?i" />
  <![endif]-->
  <!--[if IE 7]>
  <link type="text/css" rel="stylesheet" media="all" href="<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/fusion_core/css/ie7-fixes.css?i" />
  <![endif]-->
  <!--[if lte IE 6]>
  <link type="text/css" rel="stylesheet" media="all" href="<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/css/ie6-fixes.css?i"/>
  <![endif]-->  
  <?php print $scripts; ?>
</head>

<body id="<?php print $body_id; ?>" class="<?php print $body_classes; ?>">
  <div id="page" class="page">
    <div id="page-inner" class="page-inner">
      <div id="skip">
        <a href="#main-content-area"><?php print t('Skip to Main Content Area'); ?></a>
      </div>

      <!-- header-top row: width = grid_width -->
      <div id="header-top-wrapper" class="header-top-wrapper full-width">
	<div id="header-top" class="header-top row grid16-16">
	<div id="header-top-inner" class="header-top-inner inner clearfix">
  
	<div id="block-blockify-blockify-logo" class="block block-blockify odd first last grid16-3 logo-block">
  	<div class="inner clearfix">
            <div class="content clearfix">
      		<a href="<?php echo $base_url; ?>" id="logo" rel="home" title="Return to the OpenGov Platform DMS home page" class="active"><img src="<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/images/dms/logo.png" alt="OpenGov Platform DMS logo" title="" width="150" height="124" /></a>    </div>
  		</div><!-- /block-inner -->
	</div><!-- /block -->
	</div><!-- /header-top-inner -->
	</div><!-- /header-top -->
	</div><!-- /header-top-wrapper -->

      <!-- header-group row: width = grid_width -->             

      <!-- preface-top row: width = grid_width -->
        <?php print theme('grid_row', $preface_top, 'preface-top', 'full-width', $grid_width); ?>
        <?php print theme('grid_row', $preface_bottom, 'preface-bottom', 'full-width', $grid_width); ?>
      <!-- main row: width = grid_width -->
      <div id="main-wrapper" class="main-wrapper full-width">
        <div id="main" class="main row <?php print $grid_width; ?>">
          <div id="main-inner" class="main-inner inner clearfix"> 
            <!-- main group: width = grid_width - sidebar_first_width -->
            <div id="main-group" class="main-group row nested <?php print $main_group_width; ?>">
              <div id="main-group-inner" class="main-group-inner inner">
                <div id="main-content" class="main-content row nested">
                  <div id="main-content-inner" class="main-content-inner inner">
                    <!-- content group: width = grid_width - (sidebar_first_width + sidebar_last_width) -->
                    <div id="content-group" class="content-group row nested <?php print $content_group_width; ?>">
                      <div id="content-group-inner" class="content-group-inner inner">
                        <h1 class="title">Welcome to <?php echo variable_get('site_name', array()); ?> Control Panel</h1>     
                        <div id="content-region" class="content-region row nested">
                          <div id="content-region-inner" class="content-region-inner inner">
                            <div id="content-inner" class="content-inner block">
                              <div id="content-inner-inner" class="content-inner-inner inner">
                                <?php if ($title): ?>
                                <h1 class="title">User Login</h1>
                                <?php endif; ?>
					<?php if ($show_messages && $messages): print $messages; endif; ?>
                                <?php if ($content): ?>
                                <div id="content-content" class="content-content">
                                  <?php print $content; ?>                                 
                                </div><!-- /content-content -->
                                <?php endif; ?>
                              </div><!-- /content-inner-inner -->
                            </div><!-- /content-inner -->
                          </div><!-- /content-region-inner -->
                        </div><!-- /content-region -->

                        <?php print theme('grid_row', $content_bottom, 'content-bottom', 'nested'); ?>
                      </div><!-- /content-group-inner -->
                    </div><!-- /content-group -->

                    <?php print theme('grid_row', $sidebar_last, 'sidebar-last', 'nested', $sidebar_last_width); ?>
                  </div><!-- /main-content-inner -->
                </div><!-- /main-content -->

                <?php print theme('grid_row', $postscript_top, 'postscript-top', 'nested'); ?>
              </div><!-- /main-group-inner -->
            </div><!-- /main-group -->
          </div><!-- /main-inner -->
        </div><!-- /main -->
      </div><!-- /main-wrapper -->
     
    </div><!-- /page-inner -->
  </div><!-- /page -->
  <?php print $closure; ?>
</body>
</html>