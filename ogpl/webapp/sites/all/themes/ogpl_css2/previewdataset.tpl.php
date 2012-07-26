<?php
$name = variable_get('theme_default', NULL);
$path = drupal_get_path("theme", $name);

$title = ($data['mode']!='print') ? "Embed" : "Print";
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
                      "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<title><?php echo $title." - ".$data['headline'];?></title>
<script type="text/javascript" src="<?php global $base_path; echo $base_path.drupal_get_path('module', 'jquery_update')."/replace/jquery.min.js"; ?>"></script>
<script type="text/javascript" src="<?php echo $base_path.$path."/js/script.js"; ?>"></script>
<link href="<?php echo $base_path.$path;?>/dataset-preview.css" rel="stylesheet" type="text/css" />
</head>
<body>
<div id="content">
<?php
	echo "<h1>".$data['headline']."</h1>";
	echo "<div class=\"page-title-border\"></div>";
	echo "<div class=\"dataset\">";
	echo $data['body'];
	echo "</div>";
	
	if($data['mode']!='print'){
	?>
	<div class="embed-feature-links">
		<div class="fLeft"><a href="<?php echo $base_path.$data['path']."#tabs-block";?>" target="_blank" class="embeded-link discuss">Discuss</a></div>
		<div class="fLeft"><a href="<?php echo $base_path.$data['path']."?showcontact#tabs-block";?>" target="_blank" class="embeded-link discuss">Contact Dataset Owner</a></div>
		<div class="fLeft"><a href="<?php echo $base_path.$data['path']."?showrating#tabs-block";?>" target="_blank" class="embeded-link rating">Rating</a></div>
		<div class="fLeft"><a href="<?php echo $base_path."suggest_dataset/";?>" target="_blank" class="embeded-link suggest-dataset-link">Suggest Dataset</a></div>
		<div class="fLeft"><a href="<?php echo $base_path."print-dataset/".$data['path'];?>" target="_blank">Print</a></div>
		<div class="cBoth"></div>
	</div>
	<?php } ?>
</div>
</body>
</html>