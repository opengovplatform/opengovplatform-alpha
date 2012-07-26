// JavaScript Document
var _GLOBAL_CNT = 0;
var slideTimeIn;
function startscroller() {
    var sObj = $("#scroll-content");
    var inContHeight = $("#scroll-content").find("ul:first").height();
    if (inContHeight > $(sObj).parent().height()) {
        if (Math.abs(_GLOBAL_CNT) >= parseInt($(sObj).height())) {
            _GLOBAL_CNT = 0;
        }
        _GLOBAL_CNT -= 1;
        $(sObj).css("marginTop", _GLOBAL_CNT + "px");
        $("#play").show();
        $("#stop").show();
    } else {
        $(sObj).css("marginTop", "0px");
        $("#play").hide();
        $("#stop").hide();
        _GLOBAL_CNT = 0;
    }
    slideTimeIn = setTimeout("startscroller()", 40);
}
function togglesDiv(class_name) {
    switch (class_name) {
        case 'contactOwner':
            $('#web-contact-owner-form').parent().fadeIn("slow");
            $('#web-contact-owner-form-errors.error').show();
            //$('#clientsidevalidation-web-contact-owner-form-errors').show("fast");
            $('.clear-block .ratings-block').parent().hide();
            $('#ratings-form-errors.error').hide();
            //$('#feedback-comment-form').parent().parent().hide();
            $('#block-vrm_customization-0').hide();
            $('.embed-block').hide();
	        $('#comments').hide();
			$('#comment-form').parent().hide();
		    $('#comment-form-errors.error').hide();
            break;
        case 'ratings':
            //$('#feedback-comment-form').parent().parent().fadeIn("slow");
		$('#ratings-form-errors.error').show();
            	$('#block-vrm_customization-0').fadeIn("slow");
            	$('.clear-block .ratings-block').parent().show();
            	$('#web-contact-owner-form').parent().hide();
		$('#web-contact-owner-form-errors.error').hide();
            	$('.embed-block').hide();
			$('#comments').hide();
			$('#comment-form').parent().hide();
			$('#comment-form-errors.error').hide();
            	break;
    case 'embed':
            	$('.embed-block').fadeIn("slow");
            	$('.clear-block .ratings-block').parent().hide();
		$('#ratings-form-errors.error').hide();
            	$('#web-contact-owner-form').parent().hide();
		$('#web-contact-owner-form-errors.error').hide();
            	//$('#feedback-comment-form').parent().parent().hide();
            	$('#block-vrm_customization-0').hide();
	     	
			$('#comments').hide();
			$('#comment-form').parent().hide();

			$('#comment-form-errors.error').hide();
            	break;
        case 'discuss':		
				$('#comments').fadeIn("slow");
				$('#comment-form').parent().fadeIn("slow");
            	$('.clear-block .ratings-block').parent().hide();
	     	$('#ratings-form-errors.error').hide();
            	$('#web-contact-owner-form').parent().hide();
	     	$('#web-contact-owner-form-errors.error').hide();
            	//$('#feedback-comment-form').parent().parent().hide();
            	$('#block-vrm_customization-0').hide();
	     	$('.embed-block').hide();
             $('#comment-form-errors.error').show();
            	break;
     }
}
function togglesTab(tab_class_name) {
    switch (tab_class_name) {
        case 'recent_catalogs':
            $('#recent_catalogs').show();
            $('#popular_catalogs').hide();
            break;
        case 'popular_catalogs':
            $('#popular_catalogs').show();
            $('#recent_catalogs').hide();
            break;
    }
}
function textCounter(max, textarename, desc) {
    if (document.getElementById(textarename).value.length > parseInt(max)) {
        document.getElementById(textarename).value = document.getElementById(textarename).value.substring(0, max)
    } else {
        var txtlength = document.getElementById(textarename).value.length;
        desc = desc ? desc : 'feedback-textarea-limit-count';
        $('#' + desc).html(parseInt(max) - txtlength);
    }
}
function add_to_favourites() {
    if (document.all) window.external.AddFavorite(location.href, document.title);
    else if (window.sidebar)window.sidebar.addPanel(document.title, location.href, ' ');
    else if (window.opera && window.print) {
        alert("Please use your browser's bookmarking facility to create a bookmark");
    } else if (window.chrome) {
        alert("Please use your browser's bookmarking facility to create a bookmark");
    }
}
function mesgCounters(max, textarename, desc) {
    test = $('#' + textarename).val();
    if (test.length > parseInt(max)) {
        var text = $('#' + textarename).val().substr(0, max);
        $('#' + textarename).val(text);
    }
    else {
        var txtlength = test.length;
        desc = desc ? desc : 'message-textarea-limit-count';
        $('#' + desc).html(parseInt(max) - txtlength);
    }
}

$(document).ready(function () {
    $.ajax({
        url:'//s7.addthis.com/js/250/addthis_widget.js#pubid=xa-4f0d8e4b63d561d0',
        dataType:"script",
        success:function () {
            addthis.init();
        }
    });
    $('.feed-item-body').each(function (index) {
        $(this).html($(this).html().replace(/(&nbsp;)*/g, ""));
        $(this).html($(this).html().replace(/(<br>)*/g, ""));
    });
    if ($(".js-disable-hide").length > 0) {
        $(".js-disable-hide").removeClass('js-disable-hide');
    }
    $('.js-disable-show').each(function (index) {
        $(this).remove();
    });
    $('.block-contact_owner h2').each(function (index) {
        if ($.trim($(this).html()) == 'Contact Dataset Owner') {
            $(this).remove();
        }
    });
    if ($("#node-form").length > 0) {
        var action_url = $("#node-form").attr('action');
        if (action_url.toLowerCase().indexOf("contactus") >= 0) {
            $('#node-form select').each(function (index) {
                $(this).addClass('category-field');
                $(this).wrap('<div class="category-id" />');
            });
        }
    }
    if ($("#web-contact-owner-form").length > 0) {
        $('#web-contact-owner-form select').each(function (index) {
            $(this).addClass('purpose-field');
            $(this).wrap('<div id="contactowner-id" />');
        });
    }
    if ($('.preview-hide').length > 0) {
        $('.preview-hide').removeClass('preview-hide');
    }
    if ($('.imageflow-visible').length > 0) {
        $('.imageflow-visible').removeClass('imageflow-visible');
    }
    $("#context-block-region-text_resize").hide();
    if ($('#web-contact-owner-form').length > 0) {
        var datasetTitle = $('input[name="dataset-title"]').val();
        $('select[name="purpose"]').change(
            function () {
                purpose = $('select[name="purpose"]').val();
                switch (purpose) {
                    case 'Copyright Violation':
                        $('input[name="subject"]').val('Your dataset "' + datasetTitle + '" has been flagged for copyright violation');
                        break;
                    case 'Offensive Content':
                        $('input[name="subject"]').val('Your dataset "' + datasetTitle + '" has been flagged for offensive content');
                        break;
                    case 'Spam or Junk':
                        $('input[name="subject"]').val('Your dataset "' + datasetTitle + '" has been flagged as potential spam');
                        break;
                    case 'Personal Information':
                        $('input[name="subject"]').val('Your dataset "' + datasetTitle + '" has been flagged for containing personal information');
                        break;
                    case 'Other':
                        $('input[name="subject"]').val('A visitor has sent you a message about your "' + datasetTitle + '" dataset');
                        break;
                }
            }).trigger("change");
    }

    /* Search form prefill data*/
    if ($('#views-exposed-form-Catalogs-Search-page-1').length > 0) {
        if ($(".mainHeading h1").html() != "Search") {
            var _fielVal = "Search for " + $(".mainHeading h1").html();
            if ($('input[name="keys"]').val() == "") {
                $('input[name="keys"]').val(_fielVal);
            }
            $('input[name="keys"]').blur(function () {
                if ($(this).val() == "") {
                    $(this).val(_fielVal);
                }
            });

            $('input[name="keys"]').focus(function () {
                if ($(this).val() == _fielVal) {
                    $(this).val("");
                }
            });
        }
    }

    if ($(".metrics-menu").length > 0) {
        var repString = "http://" + window.location.hostname;
        var turl = location.href.replace(repString, '');
        var cmpstring = turl.substring(turl.indexOf('/'), turl.lastIndexOf('/'));
        cmpstring = cmpstring.substring(turl.indexOf('/'), cmpstring.lastIndexOf('/'));


        $(".metrics-menu .menuparent a").each(function () {
            var activemode = ($(this).attr('href').indexOf('top10datasetreport') > -1 && turl.indexOf('top10datasetreport') > -1);
            if (cmpstring == $(this).attr('href') || activemode) {
                $(this).addClass('active');
                $(this).parents(".menuparent").addClass('active-trail');
            }
        });


        if ($(".metrics-menu .menuparent a").hasClass("active")) {
            $(".metrics-menu .menuparent a").parent(".active-trail").find("a").filter(":first").addClass("active");
        }
    }


    if ($(".resize").length > 0) {
        $(".resize ul li a").each(function (index) {
            text = $(this).find('img').attr('alt');
            switch (text) {
                case 'Decrease':
                    $(this).attr('title', 'Decrease Text Size');
                    $(this).find('img').attr('alt', 'Decrease Text Size');
                    break;
                case 'Normal':
                    $(this).attr('title', 'Normal Text Size');
                    $(this).find('img').attr('alt', 'Normal Text Size');
                    break;
                case 'Increase':
                    $(this).attr('title', 'Increase Text Size');
                    $(this).find('img').attr('alt', 'Increase Text Size');
                    break;
            }
        });
    }
    if ($('#mainContent .content .dataset fieldset.group-ds-upload').length > 0) {
        $('#mainContent .content .dataset fieldset.group-ds-upload').find('legend').html('Download');
    }
    var page_full_url = $(location).attr('href');
    page_url_index = page_full_url.indexOf('showrating');
   page_url_index1 = page_full_url.indexOf('showcontact');
if(page_url_index != -1){
    $('.clear-block .ratings-block').parent().show();
    $('#web-contact-owner-form').parent().hide();
    //$('#feedback-comment-form').parent().parent().show();
    $('#block-vrm_customization-0').show();
	$('#comment-form').parent().parent().hide();
	$(".dataset #tabs-block li").each(function(index) {
        $(this).removeClass('active');
        if($(this).hasClass('ratings')){
        $(this).addClass('active');
        }
    });
}else if(page_url_index1 != -1){
    $('.clear-block .ratings-block').parent().hide();
    $('#web-contact-owner-form').parent().show();    
    $('#block-vrm_customization-0').hide();
    $('#comment-form').parent().parent().hide();
	$(".dataset #tabs-block li").each(function(index) {
        $(this).removeClass('active');
        if($(this).hasClass('contactOwner')){
        $(this).addClass('active');
        }
    });
} else {
    if(page_full_url.indexOf('embed=1') != -1 || page_full_url.indexOf('print=1') != -1 ){
		$('#web-contact-owner-form').parent().hide();
    } else {	
		
		 $('#comment-form').parent().parent().show();
    }
    $('.clear-block .ratings-block').parent().hide();
    //$('#feedback-comment-form').parent().parent().hide();
    $('#block-vrm_customization-0').hide();
    $('#web-contact-owner-form').parent().hide();
	}
    $('.embed-block').hide();


    $('#tabs-block li').click(function () {
        $('#tabs-block li').removeClass('active');
        class_name = $(this).attr('class');
        $(this).addClass('active');
        togglesDiv(class_name);
    });

    $(".anchor-links a").click(function () {
        $('#tabs-block li').removeClass('active');
        if ($(this).attr('rel') == "contactOwner") {
            $($('#tabs-block li').get(1)).addClass('active');
        }
        if ($(this).attr('rel') == "ratings") {
            $($('#tabs-block li').get(2)).addClass('active');
        }
        if ($(this).attr('rel') == "embed") {
            $($('#tabs-block li').get(3)).addClass('active');
        }
        if ($(this).attr('rel') == "discuss") {
            $($('#tabs-block li').get(0)).addClass('active');
        }
        togglesDiv($(this).attr('rel'));
    });

//embed code functionality
    if ($('.embed-block').length > 0) {
        var text_area_content = '<div><iframe width="500px" title=":title" height="425px" src=":page_url" frameborder="1" scrolling="auto"></iframe></div>';
        var page_url = $(".hidden-embed-url").val();
        var title = $(this).attr('title');
        text_area_content = text_area_content.replace(':title', title);
        text_area_content = text_area_content.replace(':page_url', page_url);
        $('.embed-block textarea#embed_code').val(text_area_content);
        $('.econf-block #small').addClass('econf-block-selected-color');
    }

    $(".iframe-dimensions").click(function () {
        $(".iframe-dimensions").removeClass("econf-block-selected-color");
        $(this).addClass("econf-block-selected-color");
        var element_id = $(this).attr('id');
        var embed_html = $('.embed-block textarea#embed_code').val();
        var width;
        var height;
        var new_width = 500;
        var new_height = 425;
        var is_width = true;
        var offset_width = embed_html.indexOf('width');
        var offset_height = embed_html.indexOf('height');
        var string_length = embed_html.length;
        var html_1st_part = '';
        var html_2nd_part = '';
        if (offset_width > offset_height) {
            is_width = false;
            html_1st_part = embed_html.substring(0, offset_width);
            html_2nd_part = embed_html.substring(offset_width, string_length);
        } else {
            html_1st_part = embed_html.substring(0, offset_height);
            html_2nd_part = embed_html.substring(offset_height, string_length);
        }
        width = $($('.embed-block textarea#embed_code').val()).find('iframe').attr('width');
        height = $($('.embed-block textarea#embed_code').val()).find('iframe').attr('height');
        if (width.indexOf("px") == -1) {
            width = width + 'px';
        }
        if (height.indexOf("px") == -1) {
            height = height + 'px';
        }
        switch (element_id) {
            case 'large':
                new_width = 950;
                new_height = 808;
                if (is_width) {
                    html_1st_part = html_1st_part.replace(width, new_width + 'px');
                    html_2nd_part = html_2nd_part.replace(height, new_height + 'px');
                } else {
                    html_1st_part = html_1st_part.replace(height, new_height + 'px');
                    html_2nd_part = html_2nd_part.replace(width, new_width + 'px');
                }
                embed_html = html_1st_part + html_2nd_part;
                $('#ewidth').val(new_width);
                $('#eheight').val(new_height);
                $('.embed-block textarea#embed_code').val(embed_html);
                break;
            case 'medium':
                new_width = 760;
                new_height = 646;
                if (is_width) {
                    html_1st_part = html_1st_part.replace(width, new_width + 'px');
                    html_2nd_part = html_2nd_part.replace(height, new_height + 'px');
                } else {
                    html_1st_part = html_1st_part.replace(height, new_height + 'px');
                    html_2nd_part = html_2nd_part.replace(width, new_width + 'px');
                }
                embed_html = html_1st_part + html_2nd_part;
                $('#ewidth').val(new_width);
                $('#eheight').val(new_height);
                $('.embed-block textarea#embed_code').val(embed_html);
                break;
            case 'small':
                new_width = 500;
                new_height = 425;
                if (is_width) {
                    html_1st_part = html_1st_part.replace(width, new_width + 'px');
                    html_2nd_part = html_2nd_part.replace(height, new_height + 'px');
                } else {
                    html_1st_part = html_1st_part.replace(height, new_height + 'px');
                    html_2nd_part = html_2nd_part.replace(width, new_width + 'px');
                }
                embed_html = html_1st_part + html_2nd_part;
                $('#ewidth').val(new_width);
                $('#eheight').val(new_height);
                $('.embed-block textarea#embed_code').val(embed_html);
                break;
        }
        $('.embed-block input#preview').removeClass('disabled');
        $('.embed-block textarea#embed_code').removeAttr('disabled');
        $('.embed-block input#preview').removeAttr('disabled');
    });
    $(".custom-size").keyup(function () {
        var element_id = $(this).attr('id');
        var value = $(this).val();
        var numberRegex = /^[+-]?\d+(\.\d+)?([eE][+-]?\d+)?$/;
        if (!numberRegex.test(value)) {
            var str_len = value.length;
            value = value.slice(0, str_len - 1);
            $(this).val(value);
            return;
        }
        value = value + 'px';
        var input_width = $('#ewidth').val();
        var input_height = $('#eheight').val();
        if (input_width < 425 || input_height < 425) {
            $('.econf-block .block .min-text').addClass('max-size-message');
            $('.embed-block textarea#embed_code').attr('disabled', 'disabled');
            $('.embed-block input#preview').attr('disabled', 'disabled');
            $('.embed-block input#preview').addClass('disabled');
        } else {
            $('.econf-block .block .min-text').removeClass('max-size-message');
            $('.embed-block input#preview').removeClass('disabled');
            $('.embed-block textarea#embed_code').removeAttr('disabled');
            $('.embed-block input#preview').removeAttr('disabled');
        }
        var width;
        var height;
        var embed_html = $('.embed-block textarea#embed_code').val();

        var is_width = true;
        var offset_width = embed_html.indexOf('width');
        var offset_height = embed_html.indexOf('height');
        var string_length = embed_html.length;
        var html_1st_part = '';
        var html_2nd_part = '';
        if (offset_width > offset_height) {
            is_width = false;
            html_1st_part = embed_html.substring(0, offset_width);
            html_2nd_part = embed_html.substring(offset_width, string_length);
        } else {
            html_1st_part = embed_html.substring(0, offset_height);
            html_2nd_part = embed_html.substring(offset_height, string_length);
        }
        switch (element_id) {
            case 'ewidth':
                width = $($('.embed-block textarea#embed_code').val()).find('iframe').attr('width');
                if (width.indexOf("px") == -1) {
                    width = width + 'px';
                }
                if (is_width) {
                    html_1st_part = html_1st_part.replace(width, value);
                } else {
                    html_2nd_part = html_2nd_part.replace(width, value);
                }
                embed_html = html_1st_part + html_2nd_part;
                $('.embed-block textarea#embed_code').val(embed_html);
                $(".iframe-dimensions").removeClass("econf-block-selected-color");
                break;
            case 'eheight':
                height = $($('.embed-block textarea#embed_code').val()).find('iframe').attr('height');
                if (height.indexOf("px") == -1) {
                    height = height + 'px';
                }
                if (is_width) {
                    html_2nd_part = html_2nd_part.replace(height, value);
                } else {
                    html_1st_part = html_1st_part.replace(height, value);
                }
                embed_html = html_1st_part + html_2nd_part;
                $('.embed-block textarea#embed_code').val(embed_html);
                $(".iframe-dimensions").removeClass("econf-block-selected-color");
                break;
        }
        if (input_width == 500 && input_height == 425) {
            $('.econf-block #small').addClass('econf-block-selected-color');
        }
        if (input_width == 760 && input_height == 646) {
            $('.econf-block #medium').addClass('econf-block-selected-color');
        }
        if (input_width == 950 && input_height == 808) {
            $('.econf-block #large').addClass('econf-block-selected-color');
        }
    });
    if ($('.embed-code').length > 0) {
        var container_width = $('.embed-code .containers').width();
        var attr_col = (container_width / 10).toFixed(0);
        var field_item_wt = (container_width * (45 / 100)).toFixed(0);
        $(".embed-code .containers textarea").each(function (index) {
            $(this).attr('cols', attr_col);
        });
        $(".embed-code .dataset .field-items").each(function (index) {
            $(this).attr('style', 'width:69%');
        });
        var page_url_woparam = $(location).attr('href');
        page_url_woparam = page_url_woparam.substring(0, page_url_woparam.indexOf('?'));
        var suggest_dataset_url = Drupal.settings.basePath + 'suggest_dataset';
        $(".embed-code .embed-feature-links .embeded-link").each(function (index) {
            if ($(this).hasClass('suggest-dataset-link')) {
                $(this).attr('href', suggest_dataset_url);
            } else {
                $(this).attr('href', page_url_woparam + '#tabs-block');
                if ($(this).hasClass('rating')) {
                    $(this).attr('href', page_url_woparam + '?showrating#tabs-block');
                }
            }
        });
    }
    $(".embed-feature-links .print").click(function () {
        window.print();
    });

    $(".metrics-menu li").each(function () {
        if ($(this).find('ul').size() > 0) {
            $(this).bind('mouseover',
                function () {
                    $("#submit_btn").focus();
                }
            );
        }
    });
    if ($('#rotating-panes').length > 0) {
        $("#rotating-panes a").each(function () {
            var title_text = $.trim($(this).html());
            $(this).attr('title', title_text);
            if (title_text == 'Pause') {
                $(this).attr('title', 'Pause/Play');
            }
        });
    }


    $('.tabPanel li a').click(function () {
        $('.tabPanel li a').removeClass('active');
        tab_class_name = $(this).attr('class');
        $(this).addClass('active');
        togglesTab(tab_class_name);
    });

});
$(document).ready(function () {
    if ($('#web-tellafriend-form').length > 0) {
        mesgCounters(3000, 'edit-message', 'message-textarea-limit-count');
        $(".messages.error ul li").each(function () {
            if ($(this).find('ul').size() > 0) {
                var cont = $(this).find('ul li').html();
                $(this).find('ul').remove();
                $(this).append(cont);
            }
        });
    }
    if ($('#node-form').length > 0) {
        mesgCounters(3000, 'edit-field-feedback-body-0-value', 'feedback-textarea-limit-count');
        $(".messages.error ul li").each(function () {
            if ($(this).find('ul').size() > 0) {
                var cont = $(this).find('ul li').html();
                $(this).find('ul').remove();
                $(this).append(cont);
            }
        });
    }
    if ($('#web-contact-owner-form').length > 0) {
        mesgCounters(3000, 'edit-message', 'shrt-textarea-limit-count');
        $(".messages.error ul li").each(function () {
            if ($(this).find('ul').size() > 0) {
                var cont = $(this).find('ul li').html();
                $(this).find('ul').remove();
                $(this).append(cont);
            }
        });
    }
    if ($('#contact-mail-page').length > 0) {
        mesgCounters(3000, 'edit-message', 'feedback-textarea-limit-count');
    }
    if($('#comment-form').length > 0){
     mesgCounters(3000,'edit-comment','discuss-textarea-limit-count');
    }
    $("#rss-feed-aggregator").css('overflow', 'hidden');
    $("#stop").click(function () {
        clearTimeout(slideTimeIn);
        $("#scroll-content").css("marginTop", "0px");
        $("#scroll-content").css("marginTop", "0px");
        $("#scroll-content").hide();

        $("#fs2").show();
        $("#fs2").empty();
        $("#fs2").html($("#scroll-content").html());
    });

    $("#play").click(function () {
        clearTimeout(slideTimeIn);
        _GLOBAL_CNT = 0;
        $("#fs2").hide();
        $("#scroll-content").show();
        startscroller();
    });
    startscroller();

});
$(document).ready(function () {
    $(".switch-js-disabled").hide();
    $(".switch-js-enabled").show();
    $("#views-slideshow-imageflow-images-1_previous").attr("title", "Previous");
    $("#views-slideshow-imageflow-images-1_next").attr("title", "Next");
    $(".apachesolr-showhide").attr("title", "Show more");
    if (navigator.userAgent.indexOf('MSIE') < 0 && navigator.userAgent.indexOf('Opera') < 0) {
        $("#contentPanel .site-map-box ul li ul li").attr('style', 'padding:0px 40px 0 7px!important;');
    }

    if ($(".block-vrm_customization form")) {
        var frmaction = $(".block-vrm_customization form").attr('action');
        $(".block-vrm_customization form").attr('action', frmaction + "?showrating");
    }
    if($("#web-contact-owner-form")){
		var frmaction = $("#web-contact-owner-form").attr('action');
		$("#web-contact-owner-form").attr('action',frmaction + "?showcontact#tabs-block");
	}
$("#comments .item-list ul li a").each(function(){
		var frmaction = $(this).attr('href');
		$(this).attr('href',frmaction + "#tabs-block");
	});    
	$("span.ext").after("&nbsp;");
});
$(document).ready(function () {
    if ($("#contact-mail-page").length > 0) {
        var cat_id = $('#contact-mail-page #edit-cid-wrapper #edit-cid').attr('id');
        var cat_class = $('#contact-mail-page #edit-cid-wrapper #edit-cid').attr('class');
        var cat_name = $('#contact-mail-page #edit-cid-wrapper #edit-cid').attr('name');
        var cat_html = $('#contact-mail-page #edit-cid-wrapper #edit-cid').html();
        $('#contact-mail-page #edit-cid-wrapper #edit-cid').remove();
        $('#contact-mail-page #edit-cid-wrapper').append('<div id="category-id"><select id=' + cat_id + ' name=' + cat_name + '>' + cat_html + '</select></div>');
        $('#test #edit-cid').addClass(cat_class);
    }
    if ($(".banner-right .quicktabs_tabs").length > 0) {
        $('.banner-right .quicktabs_tabs li a').each(function (index) {
            var a_text = $(this).html();
            $(this).html('<span>' + a_text + '</span>');
        });
    }
    $("#context-block-region-text_resize").hide();
});
