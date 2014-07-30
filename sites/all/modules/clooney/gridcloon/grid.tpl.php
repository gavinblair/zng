<div class='grid-view'>
	<div class='grid'>
	    <?php
	      $b = module_invoke('views', 'block_view', $block);
	      print str_replace('views-row ', $grid.' ',$b['content']['#markup']);
	    ?>
	</div>
</div>