jQuery(function($) {
    $('a[href*=#]:not([href=#])').click(function() {
        if (location.pathname.replace(/^\//, '') == this.pathname.replace(/^\//, '') || location.hostname == this.hostname) {

            var target = $(this.hash);
            target = target.length ? target : $('[name=' + this.hash.slice(1) + ']');
            if (target.length) {
                $('html,body').animate({
                    scrollTop: target.offset().top
                }, 1000);
                return false;
            }
        }
    });

    if ($('.navbar').length) {
        $(window).scroll(function() {
            if ($(".navbar").offset().top > 50) {
                $(".navbar-fixed-top").addClass("top-nav-collapse");
            } else {
                $(".navbar-fixed-top").removeClass("top-nav-collapse");
            }
        });
    }
});


function togglemenu() {
    var menu_style = jQuery('.menu-cloon:first').attr('data-style');
    switch (menu_style) {
        case 'menu-cloon-drawer':
            toggleDrawerMenu();
            break;
        default:
            toggleSidebarMenu();
            break;
    }

    return false;
}

function toggleSidebarMenu() {
    jQuery("#sidebar-wrapper").toggleClass("active");
    jQuery(".panel-cloon").toggleClass('menuopen');
    if (jQuery(".panel-cloon").hasClass("menuopen")) {
        if (jQuery(".navbar-fixed-top").length) {
            jQuery(".navbar-fixed-top").animate({'marginRight': jQuery("#sidebar-wrapper").width()}, 400);
            //jQuery("#menu-toggle").animate({'right': jQuery("#sidebar-wrapper").width()}, 400);
        } else {
            jQuery(".navbar").animate({'marginLeft': -1 * jQuery("#sidebar-wrapper").width()}, 400);
        }
        jQuery(".movewithhamburger").animate({'marginLeft': -1 * jQuery("#sidebar-wrapper").width()}, 400);
        jQuery(".panel-cloon").animate({'left': -1 * jQuery("#sidebar-wrapper").width()}, 400);
        jQuery("#sidebar-wrapper").animate({'marginRight': 0}, 400, function() {
            jQuery('#sidebar-wrapper').css('z-index', '0');
        });
    } else {
        if (jQuery(".navbar-fixed-top").length) {
            jQuery(".navbar-fixed-top").animate({'marginRight': 0}, {
                duration: 400,
                complete: function() {
                    jQuery(this).removeAttr('style');
                }});
            //jQuery("#menu-toggle").animate({'right': 0}, 400);
        } else {
            jQuery(".navbar").animate({'marginLeft': 0}, {
                duration: 400,
                complete: function() {
                    jQuery(this).removeAttr('style');
                }});
        }
        jQuery(".movewithhamburger").animate({'marginLeft': 0}, 400);
        jQuery(".panel-cloon").animate({'left': 0}, 400);
        jQuery('#sidebar-wrapper').css('z-index', '-3');
        jQuery("#sidebar-wrapper").animate({'marginRight': jQuery("#sidebar-wrapper").width()}, 400, function() {
        });
    }
    jQuery('#menu-toggle .fa').toggleClass('fa-bars');
    jQuery('#menu-toggle .fa').toggleClass('fa-times');
}

function toggleDrawerMenu(){
    jQuery(".panel-cloon").toggleClass('menuopen');
}