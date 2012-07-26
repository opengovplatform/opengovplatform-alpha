<div class="comment<?php print ($comment->new) ? ' comment-new' : ''; print ($comment->status == COMMENT_NOT_PUBLISHED) ? ' comment-unpublished' : ''; print ' '. $zebra; ?>">

  <div class="clear-block">
  <?php if ($submitted): ?>
     <div class="author"><span class="author_name"><?php print t('!username',array('!username' => theme('username', $comment)));?></span>
    </div>
  <?php endif; ?>



  <?php if ($comment->new) : ?>
    <a id="new"></a>
    <span class="new"><?php print drupal_ucfirst($new) ?></span>
  <?php endif; ?>

  <?php print $picture ?>

    <h3><?php print $title ?></h3>

    <div class="content">
      <?php print $content ?>
    </div>

  </div>

  <?php if ($links): ?>
    <div class="links"><?php print $links ?></div>
	<div class="time-elapsed"><span class="submitted"><?php print format_interval(time()-$comment->timestamp, $granularity = 1, $langcode = NULL) .' ago'; ?></span></div>
  <?php endif; ?>
</div>
