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
<?php
$from = date('Y-m-d', strtotime($_REQUEST['date_filter']['min']['date'])) == $_REQUEST['date_filter']['min']['date'] ? $_REQUEST['date_filter']['min']['date'] : NULL;
$to = date('Y-m-d', strtotime($_REQUEST['date_filter']['max']['date'])) == $_REQUEST['date_filter']['max']['date'] ? $_REQUEST['date_filter']['max']['date'] : NULL;
drupal_add_js('sites/all/modules/contrib/date/date_popup/lib/jquery.timeentry.pack.js');
drupal_add_js('sites/all/libraries/jquery.ui/ui/minified/ui.datepicker.min.js');
drupal_add_js('sites/all/modules/contrib/date/date_popup/date_popup.js');
?>
<html>
<head>
  <link type="text/css" href="sites/all/modules/contrib/date/date.css" rel="Stylesheet"/>
  <link type="text/css" href="sites/all/modules/contrib/date/date_popup/themes/datepicker.css" rel="Stylesheet"/>
  <link type="text/css" href="sites/all/modules/contrib/date/date_popup/themes/jquery.timeentry.css" rel="Stylesheet"/>


<div class="<?php print $classes; ?>">
  <?php if ($admin_links): ?>
  <div class="views-admin-links views-hide">
    <?php print $admin_links; ?>
  </div>
  <?php endif; ?>
  <?php if ($header): ?>
  <div class="view-header">
    <?php print $header; ?>
  </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
  <div class="view-filters metric-filters">
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

<script type="text/javascript">
  $(document).ready(function () {
    var view_filter = $(this).find('.view-filters').find('form');
    $(view_filter).find("optgroup").each(function (index) {
      var contents = $(this).html();
      $(this).parent().append(contents);
      $(this).remove();
    })

    $("#edit-sid optgroup").each(function () {
      if ($(this).children().size() == 0) {
        $(this).remove();
      }
    });
    $("#edit-sid optgroup:first").find('option:first').remove();

    $("#edit-date-filter-min-date").val("<?php echo $from; ?>");
    $("#edit-date-filter-max-date").val("<?php echo $to; ?>");
    $("#edit-date-filter-min-date").datepicker({ dateFormat:'yy-mm-dd' });
    $("#edit-date-filter-min-date").focus(function () {
      if ($(this).val() == 'yyyy-mm-dd') {
        $(this).val("").css({'color':'black'});
      }
    });
    $("#edit-date-filter-min-date").blur(
      function () {
        if ($(this).val() == '') {
          $(this).val("yyyy-mm-dd").css({'color':'gray'});
        } else {
          $(this).css({'color':'black'});
        }
      }).trigger("blur");
    $("#edit-date-filter-min-date").change(function () {
      if ($(this).val() == 'yyyy-mm-dd') {
        $(this).css({'color':'gray'});
      } else {
        $(this).css({'color':'black'});
      }
    });
    $("#edit-date-filter-min-date").datepicker({ dateFormat:'yy-mm-dd' });


    $("#edit-date-filter-max-date").focus(function () {
      if ($(this).val() == 'yyyy-mm-dd') {
        $(this).val("").css({'color':'black'});
      }
    });
    $("#edit-date-filter-max-date").blur(
      function () {
        if ($(this).val() == '') {
          $(this).val("yyyy-mm-dd").css({'color':'gray'});
        } else {
          $(this).css({'color':'black'});
        }
      }).trigger("blur");
    $("#edit-date-filter-max-date").change(function () {
      if ($(this).val() == 'yyyy-mm-dd') {
        $(this).css({'color':'gray'});
      } else {
        $(this).css({'color':'black'});
      }
    });
    $("#edit-date-filter-max-date").datepicker({ dateFormat:'yy-mm-dd' });
    $('<?php echo $field_name; ?>').submit(function () {

    var getDate = function(dateStr) {
		var matches = /^(\d{4})[-\/](\d{2})[-\/](\d{2})$/.exec(dateStr);
		//alert(matches);
        if (matches == null) return new Date(1971,1,1);
        var d = matches[3];
        var m = matches[2] - 1;
        var y = matches[1];
        return new Date(y, m, d);
      };

      var isValid = function (date, dateStr) {
        if (date == 'yyyy-mm-dd') return false;
		//alert(dateStr);
        var composedDate = getDate(dateStr);
        return composedDate.getFullYear() + '-' + (composedDate.getMonth()+1).zeroFill(2) + '-' + composedDate.getDate().zeroFill(2) == dateStr;
      };

	Number.prototype.zeroFill = function (width) {
		var fillZeroes = "00000000000000000000";  // max number of zero fill ever asked for in global
		var input = this + "";  // make sure it's a string
		return(fillZeroes.slice(0, width - input.length) + input);
}

      var messages = '';
      if (!isValid(getDate($("#edit-date-filter-max-date").val()), $("#edit-date-filter-max-date").val())) {
        messages += "To date is invalid\n";
      }
      if (!isValid(getDate($("#edit-date-filter-min-date").val()), $("#edit-date-filter-min-date").val())) {
        messages += "From date is invalid\n";
      }
      if(getDate($("#edit-date-filter-min-date").val()) > getDate($("#edit-date-filter-max-date").val())){
        messages += "From date greater than To date\n";
      }
      if(messages != '') {
        alert(messages);
        return false;
      }
    });
  });

</script>