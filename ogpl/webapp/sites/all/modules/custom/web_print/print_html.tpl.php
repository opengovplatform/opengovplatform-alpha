<?php

/**
 * @file
 * Default print module template
 *
 * @ingroup print
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $print['language']; ?>" xml:lang="<?php print $print['language']; ?>">
<head>
    
    <?php print $print['head']; ?>
    <?php print $print['base_href']; ?>
    <title>Feedback Details</title>
    <?php global $base_url;
	 print '<script type="text/javascript" src="'.$base_url.'/misc/jquery.js?Q"></script>';?>
    <?php print $print['sendtoprinter']; ?>
    <?php print $print['robots_meta']; ?>
    <?php print $print['favicon']; ?>
    <?php //print $print['css']; ?>
</head>
<body>
<?php if (!empty($print['message'])) {
    print '<div class="print-message">'. $print['message'] .'</div><p />';
} ?>

<div class="print-logo"><?php print $print['logo']; ?></div>
<p />
<hr class="print-hr" />
<!-- div class="print-breadcrumb"><?php print $print['breadcrumb']; ?></div-->
<div id="print-feedback-content">
    <h1 class="print-title">Feedback Details<!--?php print $print['title']; ?--></h1>
    <div class="print-content"><?php print $print['content']; ?></div>
    <div class="print-footer"><?php print $print['footer_message']; ?></div>
    <hr class="print-hr" />
</div>
</body>
</html>
