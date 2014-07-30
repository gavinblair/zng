(function ($) {
	Drupal.behaviors.youtube = {
	  attach: function (context, settings) {
	    if($('.superhero').length){
			if($(window).width() > 1136 && navigator.appVersion.indexOf("MSIE 9.") == -1 && navigator.appVersion.indexOf("MSIE 8.") == -1 && navigator.appVersion.indexOf("iPad") == -1){
				$('.superhero').css('background-image', 'none').css('background-color', 'black');
				$('body').prepend('<div id="playercontainer" class="movewithhamburger"><div id="player" class="movewithhamburger"></div></div>');
				var tag = document.createElement('script');
				tag.src = "http://www.youtube.com/player_api";
				var firstScriptTag = document.getElementsByTagName('script')[0];
				firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);
			} else {
				if(navigator.appVersion.indexOf("MSIE 8.") == -1 && navigator.appVersion.indexOf("iPad") == -1){
					$('.superhero').css('background-image', 'url('+Drupal.settings.youtube.youtube_gif+')').css('background-size', 'cover');
				}
			}
		}
	  }
	};
})(jQuery);

var player;
function onYouTubePlayerAPIReady() {
	player = new YT.Player('player', {
		playerVars: {
			'autoplay': 1,
			'controls': 0,
			'autohide':1,
			'wmode':'opaque', 
			'loop': 1, 
			'playlist': Drupal.settings.youtube.youtube_videocode,
			'playsinline': 1
		},
		videoId: Drupal.settings.youtube.youtube_videocode,
		events: {
			'onReady': onPlayerReady,
			'onStateChange': onPlayerStateChange
		}
	});
	//video credit
	jQuery('body').prepend('<a class="videocredit" href="http://www.youtube.com/watch?v='+Drupal.settings.youtube.youtube_videocode+'">video credit</a>');
}

// 4. The API will call this function when the video player is ready.
function onPlayerReady(event) {
	event.target.mute();
	jQuery('.superhero').css('background-color', 'transparent');
}
function onPlayerStateChange(event){
	if(event.data === 1) {
		player.seekTo(Drupal.settings.youtube.youtube_startseconds);
	}
}