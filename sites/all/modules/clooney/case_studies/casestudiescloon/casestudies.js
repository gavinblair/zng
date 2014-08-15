var caseslider;
jQuery(function($) {
    if($('.caseslider').length) {
      $('.caseslider .holder').each(function(){
        var title = $(this).children('.cont').children('h1').children('a').text();
        var id = $(this).attr('data-slide-index');
        $('.casectrl a[data-slide-index='+id+']').text(title);
      });
      if($(window).width() > 970){
          var css = navigator.appVersion.indexOf("Trident") == -1 && navigator.appVersion.indexOf("MSIE") == -1 ? true : false;
          caseslider = $('.caseslider').bxSlider({
              'controls': false,
              'pagerCustom': '.casectrl',
              'easing': 'linear',
              'adaptiveHeight': false,
              'infiniteLoop': false,
              'responsive': false,
              'useCSS': css
          });
      }
      $(window).bind('orientationchange', resizeWrapper);
      $(window).bind('resize', resizeWrapper);
  }
});

function resizeWrapper(){
  //alert(jQuery(window).width());
  jQuery('.caseslider li, .caseslider li section').css('width', jQuery(window).width()+'px');
  if(typeof caseslider !== 'undefined' && typeof caseslider.destroySlider !== 'undefined'){
      caseslider.destroySlider();
  }
  if(jQuery(window).width() > 970){
     var css = navigator.appVersion.indexOf("Trident") == -1 && navigator.appVersion.indexOf("MSIE") == -1 ? true : false;
     caseslider = jQuery('.caseslider').bxSlider({
         'controls': false,
         'pagerCustom': '.casectrl',
         'easing': 'linear',
         'adaptiveHeight': false,
         'infiniteLoop': false,
         'responsive': false,
         'useCSS': css
     });
  }
}