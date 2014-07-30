<div class='casestudies'>
    <?php
      $block = module_invoke('views', 'block_view', 'case_studies-block');
      print $block['content']['#markup'];
    ?>
</div>