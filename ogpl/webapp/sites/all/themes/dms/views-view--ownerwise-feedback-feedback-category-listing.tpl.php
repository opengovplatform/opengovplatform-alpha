<?php
$from = date('Y-m-d', strtotime($_GET['from'])) == $_GET['from'] ? $_GET['from'] : NULL;
$to = date('Y-m-d', strtotime($_GET['to'])) == $_GET['to'] ? $_GET['to'] : NULL;
drupal_add_js('sites/all/modules/contrib/date/date_popup/lib/jquery.timeentry.pack.js');
drupal_add_js('sites/all/libraries/jquery.ui/ui/minified/ui.datepicker.min.js');
drupal_add_js('sites/all/modules/contrib/date/date_popup/date_popup.js');
?>
<html>
<head>
  <link type="text/css" href="sites/all/modules/contrib/date/date.css" rel="Stylesheet"/>
  <link type="text/css" href="sites/all/modules/contrib/date/date_popup/themes/datepicker.css" rel="Stylesheet"/>
  <link type="text/css" href="sites/all/modules/contrib/date/date_popup/themes/jquery.timeentry.css" rel="Stylesheet"/>
</head>
<body>
<form class='report-form' id='report-submit'>
  <div class="demo">
    <label>From</label><input type="text" id="from_datepicker" name="from">
    <label>To</label><input type="text" id="to_datepicker" name="to">
    <input class="report-submit" type="submit" name="submit" value="Apply">
  </div>
  <!-- End demo -->
</form>
</body>
</html>


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

<script type="text/javascript">
  $(document).ready(function () {
    $("#from_datepicker").val("<?php echo $from; ?>");
    $("#to_datepicker").val("<?php echo $to; ?>");
    $("#from_datepicker").datepicker({ dateFormat:'yy-mm-dd' });
    $("#from_datepicker").focus(function () {
      if ($(this).val() == 'yyyy-mm-dd') {
        $(this).val("").css({'color':'black'});
      }
    });
    $("#from_datepicker").blur(
      function () {
        if ($(this).val() == '') {
          $(this).val("yyyy-mm-dd").css({'color':'gray'});
        } else {
          $(this).css({'color':'black'});
        }
      }).trigger("blur");
    $("#from_datepicker").change(function () {
      if ($(this).val() == 'yyyy-mm-dd') {
        $(this).css({'color':'gray'});
      } else {
        $(this).css({'color':'black'});
      }
    });
    $("#from_datepicker").datepicker({ dateFormat:'yy-mm-dd' });


    $("#to_datepicker").focus(function () {
      if ($(this).val() == 'yyyy-mm-dd') {
        $(this).val("").css({'color':'black'});
      }
    });
    $("#to_datepicker").blur(
      function () {
        if ($(this).val() == '') {
          $(this).val("yyyy-mm-dd").css({'color':'gray'});
        } else {
          $(this).css({'color':'black'});
        }
      }).trigger("blur");
    $("#to_datepicker").change(function () {
      if ($(this).val() == 'yyyy-mm-dd') {
        $(this).css({'color':'gray'});
      } else {
        $(this).css({'color':'black'});
      }
    });
    $("#to_datepicker").datepicker({ dateFormat:'yy-mm-dd' });
    $('#report-submit').submit(function () {

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
      if (!isValid(getDate($("#to_datepicker").val()), $("#to_datepicker").val())) {
        messages += "To date is invalid\n";
      }
      if (!isValid(getDate($("#from_datepicker").val()), $("#from_datepicker").val())) {
        messages += "From date is invalid\n";
      }
      if(getDate($("#from_datepicker").val()) > getDate($("#to_datepicker").val())){
        messages += "From date greater than To date\n";
      }
      if(messages != '') {
        alert(messages);
        return false;
      }
    });
  });
</script>