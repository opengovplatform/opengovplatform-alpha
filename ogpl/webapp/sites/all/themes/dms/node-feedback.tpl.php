<?php
global $base_url;
$notes_url = request_uri();
?>
<style>
.print-feedback{
	margin-top:-40px;
}
.feedback .even.field {
    background: none repeat scroll 0 0 #DDDDDD;
}
.feedback .field {
    margin: 0;
    padding: 5px;
	clear:both;
}
.feedback {
    border: 1px solid #CDCDCD;
}

.field-label {font-weight:bold;}
</style>
<script>
    var url = window.location.href;
    var arr1 = url.split('/');
	$(document).ready(function() {
	    $('.feedback').append($('.click-here'));
        $('.feedback > div:even').addClass('even');
    });
</script>
<?php
if(strpos($notes_url, '/type/note') || strpos($notes_url, '/comment/reply')) {
    ?>
<style>
.node-type-feedback.node.full-node .inner{display:none;}
#comments,#comment-form{display:block;}
#comment-form .resizable-textarea{width: 99.75%;}
h2.title{display:none;}
</style>
<script>
    $(document).ready(function() {
        $('#comments').show();
        //$('#node-'+ arr1[5]).hide();
        $('#comment-form').show();
        $("#content-tabs-inner .primary li:first-child").removeClass("active");
        $("#content-tabs-inner .primary li:eq(1)").addClass("active");
        $("#content-tabs-inner .primary li:eq(1) a").addClass("active");
		$("h1.title").html("Notes");
    });
</script>
<?php
} else if((strpos($notes_url, '/print') === FALSE)){
    ?>
<style>
#comments,#comment-form{display:none;}
</style>
<script>
    $(document).ready(function() {
        $('#node-'+arr1[5]).show();
    });
</script>
<?php
}
?>
<div id="node-<?php print $node->nid; ?>" class="node <?php print $node_classes; ?>">
    <div class="inner">
        <?php print $picture ?>

        <?php if ($page == 0): ?>
        <h2 class="title"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
        <?php endif; ?>

        <?php if ($submitted): ?>
        <div class="meta">
            <span class="submitted"><?php //print $submitted ?></span>
        </div>
        <?php endif; ?>
        <div class="print-feedback">
            <?php
            global $user;
            if ($user->uid && $node->type == "feedback") { ?>
                  <?php $url=$base_url.'/print/'.$node->nid; ?>
                <iframe style="display:none;" name="printable-content" id="printable-content"></iframe>			 
                <img src="<?php print $base_url; ?>/sites/all/themes/dms/printer_icon.png" width="20px" height="30px" title="Print" onclick="feedback_print('<?php print $url; ?>');" />
                <?php } ?>
            <!--a href="#notes" onclick="showNotes(<?php print $node->nid ?>);">Notes</a-->
        </div>
        <?php if ($node_top && !$teaser): ?>
        <div id="node-top" class="node-top row nested">
            <div id="node-top-inner" class="node-top-inner inner">
                <?php print $node_top; ?>
            </div><!-- /node-top-inner -->
        </div><!-- /node-top -->
        <?php endif; ?>
		
		<div class="content clearfix">
            <div class="feedback">
				<?php print $field_sender_name_rendered; ?>
				<?php print $field_email_rendered; ?>
				<?php print $field_feedback_subject_rendered; ?>
				<?php print $field_category_rendered; ?>
                <?php echo str_replace($field_feedback_body[0]['safe'], nl2br($field_feedback_body[0]['safe']), $field_feedback_body_rendered); ?>
				<?php print $field_action_status_rendered; ?>
				<?php print $field_feedback_type_rendered; ?>
				<?php print $field_assigned_to_rendered; ?>
				<?php print $field_forwarded_to_rendered; ?>
				<?php print $field_forwarded_to_nonmembers_rendered; ?>
				<?php print $field_source_rendered; ?>
				<?php print str_replace('Delay Time:', 'Delay Time (in hrs):', $field_delay_time_rendered); ?>
				<?php print $current_workflow_state; ?>
                <?php print $field_refer_nodeid_rendered; ?>
                <?php
                if (count($reply_review) > 0)
                {
                    echo '<h2>Reply / Review</h2>';
                    foreach($reply_review as $rr)
                    {
                        echo $rr . '<br>';
                    }
                }

                print $comments;
                ?>
			</div>
        </div>
		</div><!-- /inner -->

    <?php if ($node_bottom && !$teaser): ?>
    <div id="node-bottom" class="node-bottom row nested">
        <div id="node-bottom-inner" class="node-bottom-inner inner">
            <?php print $node_bottom; ?>
        </div><!-- /node-bottom-inner -->
    </div><!-- /node-bottom -->
    <?php endif; ?>

</div><!-- /node-<?php print $node->nid; ?> -->
<?php
if(!strpos($notes_url, '/comment/reply')) {
?>
<div class="feedback-comment">
    <?php
    module_load_include('inc', 'comment','comment.admin');
    print drupal_get_form('comment_form', array('nid' => $node->nid));
    ?>
</div>
<?php } ?>