$(document).ready(function(){
	var container1 = $('div.ratingsError.messages.error');
	$("#node-form").validate(
		{
			errorContainer: container1,
			errorLabelContainer: $("ul", container1),
			wrapper: 'li',
			meta: "validate",

			rules: {
				"field_feedback_body[0][value]":"required",
				"captcha_response":"required",

			},
			messages: {
				"field_feedback_body[0][value]": {
					required: "Comments field is required."
				},
				"captcha_response":{
					required: "Verification field is required."	
				}
			},
			invalidHandler: function(form, validator) {
				if (validator.errorList.length > 0) {
				var x = $(validator.errorList[0].element).offset().top - $(validator.errorList[0].element).height() - 250;
					$('html, body').animate({scrollTop: x}, 1000);
					$('.wysiwyg-toggle-wrapper a').each(function() {
						$(this).click();
						$(this).click();
					});
				}
			}
		}
	);
	
	var container2 = $('div.contactOwnerError.messages.error');
	$("#web-contact-owner-form").validate(
		{
			errorContainer: container2,
			errorLabelContainer: $("ul", container2),
			wrapper: 'li',
			meta: "validate",

			rules: {
				"purpose":"required",
				"subject":"required",
				"message":"required",
				"emailid":{required:true,email: true},
				"captcha_response":"required",

			},
			messages: {
				"purpose": {
					required: "Purpose field is required."
				},
				"subject": {
					required: "Subject field is required."
				},
				"message": {
					required: "Short Message field is required."
				},
				"emailid": {
					email: "Please enter a valid email id in Your E-mail Address field eg. sam@xyz.com",
					required: "Your E-mail Address field is required."
				}
			},
			invalidHandler: function(form, validator) {
				if (validator.errorList.length > 0) {
				var x = $(validator.errorList[0].element).offset().top - $(validator.errorList[0].element).height() - 200;
					$('html, body').animate({scrollTop: x}, 1000);
					$('.wysiwyg-toggle-wrapper a').each(function() {
						$(this).click();
						$(this).click();
					});
				}
			}
		}
	);
	
	var container3 = $('div.commentsError.messages.error');
	$("#comment-form").validate(
		{
			errorContainer: container3,
			errorLabelContainer: $("ul", container3),
			wrapper: 'li',
			meta: "validate",

			rules: {
				"name":"required",
				"comment":"required",
				"mail":{required:true,email: true},
				"captcha_response":"required",

			},
			messages: {
				"name": {
					required: "Your Name field is required."
				},
				"comment": {
					required: "Comment field is required."
				},
				"mail": {
					email: "Please enter a valid email id in E-mail field eg. sam@xyz.com",
					required: "E-mail field is required."
				},
				"captcha_response":{
					required: "Verification field is required."	
				}
			},
			invalidHandler: function(form, validator) {
				if (validator.errorList.length > 0) {
				var x = $(validator.errorList[0].element).offset().top - $(validator.errorList[0].element).height() - 200;
					$('html, body').animate({scrollTop: x}, 1000);
					$('.wysiwyg-toggle-wrapper a').each(function() {
						$(this).click();
						$(this).click();
					});
				}
			}
		}
	);
});