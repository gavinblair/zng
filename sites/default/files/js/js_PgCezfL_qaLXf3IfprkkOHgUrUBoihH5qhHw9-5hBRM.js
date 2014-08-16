jQuery(function($) {

});
;
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
};
(function ($) {
	Drupal.behaviors.signup = {
	  attach: function (context, settings) {
	    if($('.signup').length){
			$('.signup').each(function(){
				
				var action = $('form', this).attr('action');
				var thankyou = $(this).attr('data-thankyou');
				var already_check = $(this).attr('data-already-check');
				var invalid_check = $(this).attr('data-invalid-check');
				//console.log(already_check);
				var form = $('form', $(this));
				form.append('<input type="hidden" name="action" value="'+action+'" />');
				form.append('<input type="hidden" name="already_check" value="'+already_check+'" />');
				form.append('<input type="hidden" name="invalid_check" value="'+invalid_check+'" />');
				form.bind('submit', function(event){
					var datastring = form.serialize();
					$.ajax({
						type: "POST",
						url: "/signup/submit",
						data: datastring,
						dataType: "text",
						success: function(data) {
							//var obj = jQuery.parseJSON(data); if the dataType is not specified as json uncomment this
							// do what ever you want with the server response
							if(data === "success") {
								form.addClass('thanks');
								form.html(thankyou);
							} else {
								form.addClass('error');
								$.data(form, 'form', form.html());
								form.attr('data-form', form.html());
								if(data === "already"){
									form.html('Good news! You have already signed up for this newsletter. <a onclick="var form = jQuery(this).parent(); form.removeClass(\'error\'); form.html(form.attr(\'data-form\'));">Try another address?</a>');
								} else if(data === "invalid") {
									form.html('Sorry, it looks like you entered an invalid email address. <a onclick="var form = jQuery(this).parent(); form.removeClass(\'error\'); form.html(form.attr(\'data-form\'));">Try again?</a>');
								}
							}
						},
						error: function(){
							$.data(form, 'form', form.html());
							form.attr('data-form', form.html());
							form.html('An error occurred :O <a onclick="var form = jQuery(this).parent(); form.removeClass(\'error\'); form.html(form.attr(\'data-form\'));">Try again?</a>');
						}
					});
					event.preventDefault();
				});
			});
		}
	  }
	};
})(jQuery);;
/*
	--------------------------------------------------------------------------
	(c) 2007 Lawrence Akka
	 - jquery version of the spamspan code (c) 2006 SpamSpan (www.spamspan.com)

	This program is distributed under the terms of the GNU General Public
	Licence version 2, available at http://www.gnu.org/licenses/gpl.txt
	--------------------------------------------------------------------------
*/

(function ($) { //Standard drupal jQuery wrapper.  See http://drupal.org/update/modules/6/7#javascript_compatibility
// load SpamSpan
Drupal.behaviors.spamspan = {
  attach: function(context, settings) {
// get each span with class spamspan
       $("span.spamspan", context).each(function (index) {
// for each such span, set mail to the relevant value, removing spaces
	    var _mail = ($("span.u", this).text() +
	    	"@" +
	    	$("span.d", this).text())
	    	.replace(/\s+/g, '')
	    	.replace(/\[dot\]/g, '.');
// Find the header text, and remove the round brackets from the start and end
	    var _headerText = $("span.h", this).text().replace(/^ ?\((.*)\) ?$/, "$1");
	    // split into individual headers, and return as an array of header=value pairs
	    var _headers = $.map(_headerText.split(/, /), function(n, i){
            return (n.replace(/: /,"="));
          });
// Find the anchor text, and remove the round brackets from the start and end
	    var _anchorText = $("span.t", this).text().replace(/^ \((.*)\)$/, "$1");
// Build the mailto URI
  var _mailto = "mailto:" + encodeURIComponent(_mail);
  var _headerstring = _headers.join('&');
  _mailto += _headerstring ? ("?" + _headerstring) : '';
// create the <a> element, and replace the original span contents
   	    $(this).after(
		$("<a></a>")
		.attr("href", _mailto)
		.html(_anchorText ? _anchorText : _mail)
		.addClass("spamspan")
		).remove();
	} );
}
};
}) (jQuery);;
