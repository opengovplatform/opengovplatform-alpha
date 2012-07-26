<?php global $base_url, $site_name, $user;
$user_name=$user->name;
$user_name=str_replace('@','[at]',$user_name);
$user_name=str_replace('.','[dot]',$user_name);
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language; ?>" xml:lang="<?php print $language->language; ?>">

<head>
  <style type="text/css" media="all">
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/admin_menu/admin_menu.css?i";
  @import "<?php echo $base_url;?>/modules/block/block.css?i";
  @import "<?php echo $base_url;?>/modules/aggregator/aggregator.css?i";
  @import "<?php echo $base_url;?>/modules/node/node.css?i";
  @import "<?php echo $base_url;?>/modules/system/admin.css?i";
  @import "<?php echo $base_url;?>/modules/system/defaults.css?i";
  @import "<?php echo $base_url;?>/modules/system/system.css?i";
  @import "<?php echo $base_url;?>/modules/system/system-menus.css?i";
  @import "<?php echo $base_url;?>/modules/user/user.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/apachesolr_autocomplete/apachesolr_autocomplete.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/apachesolr_autocomplete/jquery-autocomplete/jquery.autocomplete.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/fivestar/css/fivestar.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/nice_menus/nice_menus.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/nice_menus/nice_menus_default.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/panels/css/panels.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/rate/rate.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/textsize/textsize.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/video/css/video.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/views_table_highlighter/views_table_highlighter.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/calendar/calendar_multiday/calendar_multiday.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/cck/theme/content-module.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/ctools/css/ctools.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/date/date.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/date/date_popup/themes/datepicker.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/date/date_popup/themes/jquery.timeentry.css?i";
  @import "<?php echo $base_url;?>/sites/default/files/fivestar/basic/basic.css?i";
  </style>

<style type="text/css" media="all">
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/filefield/filefield.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/logintoboggan/logintoboggan.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/views_slideshow/contrib/views_slideshow_singleframe/views_slideshow.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/views_slideshow/contrib/views_slideshow_thumbnailhover/views_slideshow.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/extlink/extlink.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/cck/modules/fieldgroup/fieldgroup.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/views/css/views.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/contrib/context/plugins/context_reaction_block.css?i";
  @import "<?php echo $base_url;?>/sites/all/modules/CMS/custom_search/custom_search.css?i";
 @import "<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/fusion_core/css/style.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/fusion_core/css/typography.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/fusion_core/css/superfish.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/fusion_core/css/superfish-navbar.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/fusion_core/css/superfish-vertical.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('theme', 'ogpl_css2');?>/fusion_core/css/grid16-fluid.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('theme', 'dms');?>/css/dms-style.css?i";
  @import "<?php echo $base_url.'/'.drupal_get_path('theme', 'dms');?>/css/multistep.css?i";
  @import "<?php echo $base_url; ?>/sites/all/libraries/jquery.ui/themes/default/ui.all.css?f";
</style>
  <title><?php print $head_title; ?></title>
  <?php print $head; ?>
  <link href="<?php echo $base_url.'/'.drupal_get_path('theme', 'dms');?>/css/dms-style.css" rel="alternate stylesheet" type="text/css" />
  <link href="<?php echo $base_url.'/'.drupal_get_path('theme', 'dms');?>/css/multistep.css" rel="alternate stylesheet" type="text/css" />
 
	
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
      <?php //print theme('grid_row', $header_top, 'header-top', 'full-width', $grid_width); ?>
	<div id="header-top-wrapper" class="header-top-wrapper full-width">
		<div id="header-top" class="header-top row grid16-16">
			<div id="header-top-inner" class="header-top-inner inner clearfix">  
				<div id="block-blockify-blockify-logo" class="block block-blockify odd first last grid16-3 logo-block">
					<div class="inner clearfix">
						<div class="content clearfix">
						<a href="<?php echo $base_url; ?>" id="logo" rel="home" title="Return to the OpenGov Platform DMS home page" class="active"><img src="<?php echo $base_url.'/'.drupal_get_path('theme', 'dms');?>/logo.png" alt="OpenGov Platform DMS logo" title="" width="150" height="124" /></a>    
						</div>
					</div><!-- /block-inner -->
				</div><!-- /block -->
				<div class="block block-search even  grid16-4 fusion-right fusion-right-content add-10px-margintop user-navigation" id="block-search-0">
				  <div class="inner clearfix">
						<div class="fusion-edit">
							<a class="fusion-block-config" title="configure this Search block (in header top)" href="<?php echo $base_url;?>/admin/build/block/configure/search/0?destination=node%2F441">configure block</a>
						</div>            
						<div class="content clearfix">
							<form class="search-form" id="search-block-form" method="post" accept-charset="UTF-8" action="home" target="_self" novalidate="novalidate">
							<div>
								<div id="edit-search-block-form-1-wrapper" class="form-item">
								<label for="edit-search-block-form-1"></label>
								<input type="text" class="form-text apachesolr-autocomplete unprocessed custom-search-default-value custom-search-box  form-autocomplete" title="Enter the terms you wish to search for." value="" size="15" id="edit-search-block-form-1" name="search_block_form" maxlength="128" autocomplete="off">
								</div>
								<input type="submit" class="form-submit" value="Search" id="edit-submit" name="op">
								<input type="hidden" value="form-be0aa57d03957027c47cfcaa44406fe9" id="form-be0aa57d03957027c47cfcaa44406fe9" name="form_build_id">
								<input type="hidden" value="90788149027b6c19f43fb35e0114c328" id="edit-search-block-form-form-token" name="form_token">
								<input type="hidden" value="search_block_form" id="edit-search-block-form" name="form_id">
								<input type="hidden" class="default-text" value="" id="edit-default-text" name="default_text">
							</div>
							</form>
						</div>
				  </div><!-- /block-inner -->
				</div>
				<div class="block block-block odd  grid16-8 fusion-right fusion-right-content fusion-inline-menu fusion-list-vertical-spacing ul-2-menu add-10px-margintop user-navigation" id="block-block-4">
				  <div class="inner clearfix">
						<div class="fusion-edit"><a class="fusion-block-edit" title="edit the content of this Custom block (in header top)" href="/dms/admin/build/block/configure/block/4?destination=node%2F441">edit block</a></div>            
						<div class="content clearfix">
					  <ul>
						<li>Welcome <?php print l($user_name,'user/'.$user->uid); ?></li>
						<li><a title="Help" onclick="window.open('<?php echo $base_url;?>/sites/default/files/WebHelp/ogpl_admin_guide.htm', 'help_window', 'menubar=1,resizable=1,width=900,height=900')" href="javascript:void(0);">Help</a></li>
				<li><a title="Log Out" href="<?php echo $base_url;?>/logout">Log Out</a></li>
				</ul>    </div>
				  </div><!-- /block-inner -->
				</div>
				<div class="block block-superfish even  grid16-13 primary-navigation">
				<?php print $dms_header_primary; ?>
				</div>
				<?php if($dms_header_dataset!=''){ ?>
				<div class="block block-block odd  grid16-2 fusion-right fusion-center-content create-dataset">
				<?php print $dms_header_dataset; ?>
				</div>
				<?php } ?>
				<div class="block block-views even  last grid16-7 sidebar-title-underline whats-new-ticker">
				<?php print $dms_header_whatsnew; ?>
				</div>
				<?php //print theme('grid_row', $header_top, 'header-top', 'full-width', $grid_width); ?>
			</div><!-- /header-top-inner -->
		</div><!-- /header-top -->
	</div><!-- /header-top-wrapper -->
      <!-- header-group row: width = grid_width -->

        <?php if ($header): ?>
        <div id="header-group-wrapper" class="header-group-wrapper full-width">
        <div id="header-group" class="header-group row <?php print $grid_width; ?>">
          <div id="header-group-inner" class="header-group-inner inner clearfix">
            <?php print $header; ?>
          </div><!-- /header-group-inner -->
        </div><!-- /header-group -->
      </div><!-- /header-group-wrapper -->
        <?php endif; ?>

      <!-- preface-top row: width = grid_width -->
        <?php print theme('grid_row', $preface_top, 'preface-top', 'full-width', $grid_width); ?>
        <?php print theme('grid_row', $preface_bottom, 'preface-bottom', 'full-width', $grid_width); ?>
      <!-- main row: width = grid_width -->
      <div id="main-wrapper" class="main-wrapper full-width">
        <div id="main" class="main row <?php print $grid_width; ?>">
          <div id="main-inner" class="main-inner inner clearfix">
            <?php print theme('grid_row', $sidebar_first, 'sidebar-first', 'nested', $sidebar_first_width); ?>

            <!-- main group: width = grid_width - sidebar_first_width -->
            <div id="main-group" class="main-group row nested <?php print $main_group_width; ?>">
              <div id="main-group-inner" class="main-group-inner inner">
                <div id="main-content" class="main-content row nested">
                  <div id="main-content-inner" class="main-content-inner inner">
                    <!-- content group: width = grid_width - (sidebar_first_width + sidebar_last_width) -->
                    <div id="content-group" class="content-group row nested <?php print $content_group_width; ?>">
                      <div id="content-group-inner" class="content-group-inner inner">
                        <?php if (drupal_lookup_path('alias',$_GET['q']) != "home") print theme('grid_block', htmlspecialchars_decode($breadcrumb), 'breadcrumbs'); ?>
                      
                      <?php print $header_center; ?>

                        <?php if ($content_top || $help || $messages): ?>
                        <div id="content-top" class="content-top row nested">
                          <div id="content-top-inner" class="content-top-inner inner">
                            <?php print theme('grid_block', $help, 'content-help'); ?>
                            <?php print theme('grid_block', $messages, 'content-messages'); ?>
                            <?php print $content_top; ?>
                          </div><!-- /content-top-inner -->
                        </div><!-- /content-top -->
                        <?php endif; ?>

                        <div id="content-region" class="content-region row nested">
                          <div id="content-region-inner" class="content-region-inner inner">
                            <a name="main-content-area" id="main-content-area"></a>
                           
                            <?php if(trim($tabs) and !in_array(drupal_lookup_path('alias',$_GET['q']), array("home", "user-management"))){print theme('grid_block', $tabs, 'content-tabs');} ?>
							
                            <div id="content-inner" class="content-inner block">
                              <div id="content-inner-inner" class="content-inner-inner inner">
                                <?php if ($title): ?>
                                <h1 class="title"><?php print $title; ?></h1>
                                <?php endif; ?>
                                <?php if ($content): ?>
                                <div id="content-content" class="content-content">
                                  <?php print $content; ?>
                                  <?php print $feed_icons; ?>
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

      <!-- postscript-bottom row: width = grid_width -->
      <?php print theme('grid_row', $postscript_bottom, 'postscript-bottom', 'full-width', $grid_width); ?>

      <!-- footer row: width = grid_width -->
      <?php //print theme('grid_row', $footer, 'footer', 'full-width', $grid_width); ?>

      <!-- footer-message row: width = grid_width -->
      <div id="footer-message-wrapper" class="footer-message-wrapper full-width">
        <div id="footer-message" class="footer-message row <?php print $grid_width; ?>">
          <div id="footer-message-inner" class="footer-message-inner inner clearfix">
            <?php print theme('grid_block', $footer_message, 'footer-message-text'); ?>
          </div><!-- /footer-message-inner -->
        </div><!-- /footer-message -->
      </div><!-- /footer-message-wrapper -->

    </div><!-- /page-inner -->
  </div><!-- /page -->
  <?php print $closure; ?>
  <script>
  $("#block-superfish-1").removeClass("clear-block block block-superfish");
  $("#block-block-2").removeClass("clear-block block block-block");
  $("#block-views-whats_new-block_2").removeClass("clear-block block block-views");
  $("#context-block-region-dms_header_dataset").remove();
  </script>
</body>
</html>
