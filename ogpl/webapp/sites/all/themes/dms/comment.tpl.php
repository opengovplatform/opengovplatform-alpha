<?php
$notes_url = request_uri();

if ($node->type == "feedback" && (strpos($notes_url, '/print/') === FALSE)) {
    $date = str_replace(".", "", str_replace(" on ", "", strstr($submitted, ' on ')));

    $username = explode(" ", str_replace("Submitted by", "", $submitted));
    $username = explode(">", $username[5]);
    $username = $username[1];
    $max_name = variable_get('realname_max_username', 20);
    if (drupal_strlen($username) > $max_name) {
        $username = drupal_substr($username, 0, $max_name - 3) .'...';
    }
    ?>
<tr class="<?php print $comment_classes;?>">
    <td><?php print filter_xss(nl2br($content)) ?></td>
    <td><?php echo $username; ?></td>
    <td><?php print $date ?></td>
</tr>
<?php } else { ?>
<div class="comment <?php print $comment_classes;?> clear-block">
    <?php print $picture ?>

    <div class="submitted">
        <?php print $submitted ?>
    </div>

    <div class="content">
        <span style="font-weight: bold;">Comments: </span>
        <div class="field">
            <?php print nl2br($content) ?>
        </div>

        <?php if ($signature): ?>
        <div class="signature">
            <?php print $signature ?>
        </div>
        <?php endif; ?>
    </div>

    <?php if ($links): ?>
    <div class="links">
        <?php print $links ?>
    </div>
    <?php endif; ?>

</div><!-- /comment -->
<?php } ?>
