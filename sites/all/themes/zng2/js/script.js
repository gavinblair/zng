jQuery(document).ready(function($){
	setTimeout(function(){
		$('.panel-display').addClass('here');
	}, 500);
	if($('.toolbar-drawer').length == 0) {
		$('a').click(function(){
			$('.panel-display').addClass('going');
		});
	}
});

window.addEventListener('load', function() {
    FastClick.attach(document.body);
}, false);