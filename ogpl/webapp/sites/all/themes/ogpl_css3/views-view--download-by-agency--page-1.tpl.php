<?php
/**
 * @file views-view.tpl.php
 * Main view template
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 * - $admin_links: A rendered list of administrative links
 * - $admin_links_raw: A list of administrative links suitable for theme('links')
 *
 * @ingroup views_templates
 */
?>
<script type="text/javascript">
<!--//--><![CDATA[//><!--
function getAbsolutePath() {
    var loc = window.location;
    var pathName = loc.pathname.substring(0, loc.pathname.lastIndexOf('/') + 1);
    return loc.href.substring(0, loc.href.length - ((loc.pathname + loc.search + loc.hash).length - pathName.length));
}
function getCompletePath() {
    var loc = window.location;
	var pathName;
	if(window.location.href.lastIndexOf('&itemcount')==-1)
     return window.location.href;
     else
	 return window.location.href.substring(0,window.location.href.lastIndexOf('&itemcount'));
}
function itemsperpage(itemcount)
{
var selObj = document.getElementById('itemcount');
$('#'+itemcount).attr('selected',true);
window.location=getAbsolutePath()+'downloadbyagency' +'?&itemcount='+itemcount;
}
//--><!]]>
</script>

<div class="<?php print $classes; ?>">
  <?php if ($admin_links): ?>
    <div class="views-admin-links views-hide">
      <?php print $admin_links; ?>
    </div>
  <?php endif; ?>

<?php
global $base_url;
$this_page = drupal_get_path_alias($_GET['q']);
print '<div class="catalog-tabs-menu">';
  print '<ul class="catalog-tabs catalog-adjust">';
 if($this_page=='visitorstats/downloadbycategory')
    print '<li><a class="active" href="'.$base_url.'/'.$this_page.'" title="Category">Category</a></li>';
 else
   print '<li><a href="'.$base_url.'/visitorstats/downloadbycategory" title="Category">Category</a></li>';

  if($this_page=='visitorstats/downloadbyagency')
    print '<li><a class="active" href="'.$base_url.'/'.$this_page.'" title="Agency">Agency</a></li>';
 else
   print '<li><a href="'.$base_url.'/visitorstats/downloadbyagency" title="Agency">Agency</a></li>';
print'</ul>';
print'</div>';
?>
<?php if ($header): ?>
<div class="view-header">
  <?php print $header; ?>
</div>
<?php endif; ?>
<?php
print'<div class="metrics-category-report-border">';
print'<h1 class="view-header metrics-visitorstats-table-heading">';
print'Downloads by Agency</h1>';
print'<div><p>These numbers represent the number of times a user has clicked on the "XML" or "CSV" (for example) links in the Raw Data Catalogs to download datasets and user downloads of tools in the Tool Catalog available in these categories. </p></div>';

$select_options=array('10'=>'10','25'=>'25','50'=>'50','100'=>'100');
$selected_count=$_GET['itemcount'];



print '<div style="display:none;" class="metrics-result-per-page-dropdown cBoth switch-js-enabled">';
print '<label for="itemcount">Results per page: </label>';
print '<select id="itemcount" name="itemcount" onchange="itemsperpage(this.options[this.options.selectedIndex].value);">';
foreach($select_options as $key=>$value)
	{ 
		if($selected_count == $select_options[$value]) {
		print '<option value="'.$select_options[$value].'" selected = "selected" onclick="itemsperpage('.$select_options[$value].')">'.$select_options[$value].'&nbsp;</option>';
		}
		else{ 
		print '<option value="'.$select_options[$value].'" onclick="itemsperpage('.$select_options[$value].')">'.$select_options[$value].'&nbsp;</option>';

		}
	}
print '</select>';
print '</div>';

$count=10;
$count=$_GET['itemcount'];
if($count==0) $count=10;
print '<div  class="metrics-result-per-page-links cBoth switch-js-disabled"> Results Per Page: ';
if($count=='10')
print ' 10 |';
else
print '<a title="Show 10 results per page" href="'.$base_url.'/visitorstats/downloadbyagency?&amp;itemcount=10"> 10 </a>|';
if($count=='25') print ' 25 |';
else
print '<a title="Show 25 results per page" href="'.$base_url.'/visitorstats/downloadbyagency?&amp;itemcount=25"> 25 </a>|';
if($count=='50') print ' 50 |';
else
print '<a title="Show 50 results per page" href="'.$base_url.'/visitorstats/downloadbyagency?&amp;itemcount=50"> 50 </a>|';

if($count=='100') print ' 100 ';
else
print '<a title="Show 100 results per page" href="'.$base_url.'/visitorstats/downloadbyagency?&amp;itemcount=100"> 100 </a>';

print '</div>';
?>
<?php 
    $view = views_get_current_view();
	global $pager_total;
	$total_pages = $pager_total['0'];
	if(!$total_pages)
	$total_pages=1;
	$pno=$_GET['page'];
	$fpage=0;
	if(!$pno)
	{ $fpage=1;}
	
	$pno=$pno+1;
    if($fpage) 
	print '<div class="metrics-page-records cBoth">Page '.$fpage.' of '.$total_pages.' ('.$view->total_rows.' Records)</div>';
    else
	print '<div class="metrics-page-records cBoth">Page '.$pno.' of '.$total_pages.' ('.$view->total_rows.' Records)</div>';
 
  ?>
  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <?php if ($rows): ?>
    <div class="view-content">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon">
      <?php print $feed_icon; ?>
    </div>
  <?php endif; ?>

</div>
</div>
<?php /* class view */ ?>