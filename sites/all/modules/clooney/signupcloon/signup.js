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
})(jQuery);