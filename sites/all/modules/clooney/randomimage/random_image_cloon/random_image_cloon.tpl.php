<?php if($bgimage) $imgpath = file_load($bgimage)->uri; ?>
<div class="random-image-cloon <?php echo isset($cssclass) ? $cssclass : ''; ?> <?php echo isset($bgfixed) && $bgfixed ? 'bgfixed' : '' ;?> <?php echo $fullheight ? 'header' : 'intro'; ?>" style='color: <?php echo $textcolor ;?>; background-color: <?php echo $bgcolor; ?>; <?php if($bgimage) { ?>background-image: url(<?php print file_create_url($imgpath); ?>)<?php } ?>; <?php echo $height? 'height: '. $height : ''; ?>;'>
    <div class="<?php echo $fullheight ? 'vert-text' : 'container'; ?>">
        <?php if(!$fullheight) { ?><div class="row"><?php } ?>
            <?php $h = $fullheight ? '1' : '2'; ?>
            <h<?php echo $h; ?>><?php echo $title; ?></h<?php echo $h; ?>>
            <?php echo $body; ?>
        	<?php if($scrolldown) { ?>
        		<span class='scrolldown'>
        			<span class="fa-stack fa-lg">
					  <i class="fa fa-circle fa-stack-2x"></i>
					  <i class="fa fa-angle-double-down fa-stack-1x fa-inverse"></i>
					</span>
        		</span>
        	<?php } ?>
        <?php if(!$fullheight) { ?></div><?php } ?>
    </div>
</div>