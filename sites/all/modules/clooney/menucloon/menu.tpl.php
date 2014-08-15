<div class="menu-cloon collapse navbar-collapse navbar-main-collapse <?php echo $style; ?>" data-style="<?php echo $style; ?>">
    <?php if(!in_array($style, array('top', 'menu-cloon-drawer')) || in_array($style, array('collapse-to-hamburger'))) { ?>
        <div id="sidebar-wrapper">
            <?php
                $menu = menu_tree('main-menu'); print drupal_render($menu); 
            ?>
            <?php echo $sidebarcontent; ?>
        </div>
    <?php } ?>
    <nav class="navbar navbar-custom <?php echo $sticky ? 'navbar-fixed-top' : ''; ?>" role="navigation">
        <div class="container">
            <!-- Collect the nav links, forms, and other content for toggling -->
            <?php if(in_array($style, array('top', 'collapse-to-hamburger','menu-cloon-drawer'))) { ?>
                <div class="navbar-navigation collapse navbar-collapse <?php echo $navbar_position; ?> navbar-main-collapse">
                    <?php
                      $menu = menu_tree('main-menu'); print drupal_render($menu); 
                    ?>
                </div>
            <?php } ?>
            <div class="navbar-header page-scroll">
                <?php echo $topcontent; ?>
            </div>
            <?php if($style != 'top' || $style == 'collapse-to-hamburger') { ?>
                <a id="menu-toggle" onclick='togglemenu()' class="<?php echo $sticky ? 'sticky' : ''; ?> btn btn-primary btn-lg toggle"><i class="fa fa-bars"></i></a>
            <?php } ?>
            <!-- /.navbar-collapse -->
        </div>
        <!-- /.container -->
    </nav>
    <?php if(in_array($style, array('menu-cloon-drawer'))) { ?>
        <div class="drawer">
            <?php
                $menu = menu_tree('main-menu'); print drupal_render($menu); 
            ?>
            <?php echo $sidebarcontent; ?>
        </div>
    <?php } ?>
</div>