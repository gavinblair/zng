<?php
/**
 * @file
 * Template for a 3 column panel layout.
 *
 * This template provides a very simple "one column" panel display layout.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   $content['middle']: The only panel in the layout.
 */
?>
<div <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
	<div class="panel-display panel-cloon panel-head clearfix">
	  <div class="panel-panel panel-col">
	    <div><?php print $content['header']; ?></div>
	  </div>
	</div>
	<div class="panel-display panel-cloon panel-middle clearfix">
	  <div class="panel-panel panel-col">
	    <div><?php print $content['middle']; ?></div>
	  </div>
	</div>
	<div class="panel-display panel-cloon panel-foot clearfix">
	  <div class="panel-panel panel-col">
	    <div><?php print $content['footer']; ?></div>
	  </div>
	</div>
</div>