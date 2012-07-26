$(document).ready(
function() {
$("#edit-field-feedback-subject-0-value").hover(
  function () {
    $(this).attr('title', $(this).val());
});
setTimeout( function(){
    $('.resizable-textarea #edit-body').css('height','200px');
    $('.defaultSkin #edit-body_tbl').css('height','200px');
    $('.defaultSkin #edit-body_ifr').css('height','155px');
 }, 3000);
 
if($(".view-display-id-page_19 table th:first").length >0){$(".view-display-id-page_19 table th:first").html("<input id='bulk_print_select_all' type='checkbox' onclick='bulk_print_select_all();' />  "); }
 
 
/*if($('#block-quicktabs-vrm_pmo_tabs_list').length > 0){
    $("#block-quicktabs-vrm_pmo_tabs_list .view-filters").each(function(index) {
        var html_text = $(this).html();
        $(this).parent().prepend('<fieldset class="menu-item-form collapsible collapsed fieldset-vrm"><legend class="collapse-processed"><a href="#">Filters</a></legend><div class="view-filters">'+html_text+'</div></fieldset>');
        $(this).remove();
    });
}
if($('#block-quicktabs-vrm_poc_tabs_list').length > 0){
    $("#block-quicktabs-vrm_poc_tabs_list .view-filters").each(function(index) {
        var html_text = $(this).html();
        $(this).parent().prepend('<fieldset class="menu-item-form collapsible collapsed fieldset-vrm"><legend class="collapse-processed"><a href="#">Filters</a></legend><div class="view-filters">'+html_text+'</div></fieldset>');
        $(this).remove();
    });
}
if($('#block-quicktabs-vrm_admin_tabs').length > 0){
    $("#block-quicktabs-vrm_admin_tabs .view-filters").each(function(index) {
        var html_text = $(this).html();
        $(this).parent().prepend('<fieldset class="menu-item-form collapsible collapsed fieldset-vrm"><legend class="collapse-processed"><a href="#">Filters</a></legend><div class="view-filters">'+html_text+'</div></fieldset>');
        $(this).remove();
    });
}
$('.fieldset-vrm legend').click(function() {
    if($(this).parent().hasClass('collapsed')){
        $(this).parent().removeClass('collapsed');
    } else {
        $(this).parent().addClass('collapsed');
    }
});*/
    $('.quicktabs_tabpage .view-filters').each(function(index) {
        var view_filter = $(this).find('form');
            if($(view_filter).find('legend').attr('class') == undefined || $(view_filter).find('legend').attr('class') == ''){
                var html_content = $(view_filter).html();
                $(view_filter).empty();
                $(view_filter).html('<fieldset class="menu-item-form collapsible collapsed fieldset-vrm"><legend class="collapse-processed"><a href="javascript:void(0)" id="filters">Filters</a></legend>'+html_content+'</fieldset>');

                $(view_filter).find("optgroup").each(function(index) {
                    var contents = $(this).html();
                    $(this).parent().append(contents);
                    $(this).remove();
                })
                
                $(view_filter).find('legend').click(function() {
                    if($(this).parent().hasClass('collapsed')){
                        $(this).parent().removeClass('collapsed');
                    } else {
                        $(this).parent().addClass('collapsed');
                    }
                });
            }
			$(".views-field-field-category-value > div").each(function(){
					$(this).wrap('<li />');
			})
			$(".views-field-phpcode > div").each(function(){
					$(this).wrap('<li />');
			})
			$(".views-field-field-category-value:has(li)").each(function(){
			if($(this).find('ul').size() == 0){
				var htmlCont = $(this).html();
				$(this).empty();
				$(this).html("<ul>"+ htmlCont+ "</ul>");
			}
		});
		$(".views-field-field-category-value").each(function(){
			if($(this).find('span').size() == 0){
			
			var htmlCont = $(this).html();
			$(this).empty();
			$(this).html('<span><p>'+ htmlCont+ '</p></span>');
			}
		});
		$(".views-field-phpcode").each(function(){
			if($(this).find('span').size() == 0){
			
			var htmlCont = $(this).html();
			$(this).empty();
			$(this).html('<span><p>'+ htmlCont+ '</p></span>');
			}
		});
		$(".views-field-phpcode:has(li)").each(function(){
			if($(this).find('ul').size() == 0){
				var htmlCont = $(this).html();
				$(this).empty();
				$(this).html("<ul>"+ htmlCont+ "</ul>");
			}
		});
	});

if($("#field_state_data_values").length > 0){
    $('#edit-field-country-longitude-0-value-wrapper').after('<div class="clear-both"></div>');

    $("#field_state_data_values").find('.link-field-subrow').each(function(index) {
        $(this).removeClass('clear-block');
    });
    $("#edit-field-country-portal-url-0-url-wrapper").parent().parent().removeClass('clear-block');
    $(document).find('.filefield-element').each(function(index) {
        $(this).addClass('country_data_widget');
    });
    var node_id=$('#edit-country-data-nid').val();
    var state_data = $.cookie(node_id+'-state-data');
    var agency_data = $.cookie(node_id+'-agency-data');
    if (state_data == null){
        state_data = '';
    }
    if (agency_data == null){
        agency_data = '';
    }
    state_data = state_data.replace('+',' ');
    agency_data = agency_data.replace('+',' ');
    var states_array = state_data.split('|');
    var agency_array = agency_data.split('|');

    $("#field_state_data_values").find("select").each(function(index) {
        var element_id = $(this).attr('id');
        var auto_element_id = '';
        var sub_region_element_id = '';
        if (element_id.indexOf("value-field-region-type-value") >= 0){
            var element_value = $('#'+element_id).val().toLowerCase();
            auto_element_id = element_id.replace('value-field-region-type-value','value-field-state-name-0-value');
            sub_region_element_id = element_id.replace('value-field-region-type-value','value-field-sub-region-0-value');
            $('#'+auto_element_id).attr('autocomplete','off');
                
            switch(element_value){
                case 'state':
                  var obj23 = new actb(document.getElementById(auto_element_id),states_array);
                  $('#'+sub_region_element_id).val('');
                  $('#'+sub_region_element_id).attr('disabled', true);
                  break;
                case 'city':
                  var obj23 = new actb(document.getElementById(auto_element_id),states_array);
                  $('#'+sub_region_element_id).removeAttr('disabled');
                  break;
                case 'municipality':
                  var obj23 = new actb(document.getElementById(auto_element_id),states_array);
                  $('#'+sub_region_element_id).removeAttr('disabled');
                  break;
                case 'agency':
                  var obj23 = new actb(document.getElementById(auto_element_id),agency_array);
                  $('#'+sub_region_element_id).val('');
                  $('#'+sub_region_element_id).attr('disabled', true);
                  break;
                case 'sub-agency':
                  var obj23 = new actb(document.getElementById(auto_element_id),agency_array);
                  $('#'+sub_region_element_id).removeAttr('disabled');
                  break;
                default:
                  var obj23 = new actb(document.getElementById(auto_element_id),states_array);
                  $('#'+sub_region_element_id).val('');
                  $('#'+sub_region_element_id).attr('disabled', true);
            }

            $('#'+element_id).unbind('change');
            $('#'+element_id).change(function() {
                var current_value = $(this).val().toLowerCase();
                var current_id = $(this).attr('id');
                var current_auto_id = current_id.replace('value-field-region-type-value','value-field-state-name-0-value');
                var current_sub_region_id = element_id.replace('value-field-region-type-value','value-field-sub-region-0-value');
                switch(current_value){
                    case 'state':
                      $('#'+current_auto_id).unbind();
                      var obj23 = new actb(document.getElementById(current_auto_id),states_array);
                      $('#'+current_sub_region_id).val('');
                      $('#'+current_sub_region_id).attr('disabled', true);
                      break;
                    case 'city':
                      $('#'+current_auto_id).unbind();
                      var obj23 = new actb(document.getElementById(current_auto_id),states_array);
                      $('#'+current_sub_region_id).removeAttr('disabled');
                      break;
                    case 'municipality':
                      $('#'+current_auto_id).unbind();
                      var obj23 = new actb(document.getElementById(current_auto_id),states_array);
                      $('#'+current_sub_region_id).removeAttr('disabled');
                      break;
                    case 'agency':
                      $('#'+current_auto_id).unbind();
                      var obj23 = new actb(document.getElementById(current_auto_id),agency_array);
                      $('#'+current_sub_region_id).val('');
                      $('#'+current_sub_region_id).attr('disabled', true);
                      break;
                    case 'sub-agency':
                      $('#'+current_auto_id).unbind();
                      var obj23 = new actb(document.getElementById(current_auto_id),agency_array);
                      $('#'+current_sub_region_id).removeAttr('disabled');
                      break;
                    default:
                      $('#'+current_auto_id).unbind();
                      var obj23 = new actb(document.getElementById(current_auto_id),states_array);
                      $('#'+current_sub_region_id).val('');
                      $('#'+current_sub_region_id).attr('disabled', true);
                }
            });
        }
    });
}
$('#node-form').ajaxComplete(state_data_site_eventbind);
    $('.quicktabs_tabpage').ajaxComplete(function() {
        var view_filter = $(this).find('.view-filters').find('form');
        if($(view_filter).find('legend').attr('class') == undefined || $(view_filter).find('legend').attr('class') == ''){
            var html_content = $(view_filter).html();
            $(view_filter).empty();
            $(view_filter).html('<fieldset class="menu-item-form collapsible fieldset-vrm"><legend class="collapse-processed"><a href="javascript:void(0)" id="filters">Filters</a></legend>'+html_content+'</fieldset>');

            $(view_filter).find("optgroup").each(function(index) {
                var contents = $(this).html();
                $(this).parent().append(contents);
                $(this).remove();
            })
            
            $(view_filter).find('legend').click(function() {
                if($(this).parent().hasClass('collapsed')){
                    $(this).parent().removeClass('collapsed');
                } else {
                    $(this).parent().addClass('collapsed');
                }
            });
        }
		$(".views-field-field-category-value > div").each(function(){
			$(this).wrap('<li />');
		})
		$(".views-field-phpcode > div").each(function(){
				$(this).wrap('<li />');
		})
		$(".views-field-field-category-value:has(li)").each(function(){
			if($(this).find('ul').size() == 0){
				var htmlCont = $(this).html();
				$(this).empty();
				$(this).html("<ul>"+ htmlCont+ "</ul>");
			}
		});
		$(".views-field-field-category-value").each(function(){
			if($(this).find('span').size() == 0){
			var htmlCont = $(this).html();
			$(this).empty();
			$(this).html('<span><p>'+ htmlCont+ '</p></span>');
			}
		});
		$(".views-field-phpcode").each(function(){
			if($(this).find('span').size() == 0){
			var htmlCont = $(this).html();
			$(this).empty();
			$(this).html('<span><p>'+ htmlCont+ '</p></span>');
			}
		});
		$(".views-field-phpcode:has(li)").each(function(){
			if($(this).find('ul').size() == 0){
				var htmlCont = $(this).html();
				$(this).empty();
				$(this).html("<ul>"+ htmlCont+ "</ul>");
			};
		});
		$("select option").attr( "title", "" );
		$("select option").each(function(i){
		  this.title = this.text;
		})
	
		try {
        $( "#edit-date-filter-min-date" ).attr('class','form-text');
		$( "#edit-date-filter-max-date" ).attr('class','form-text');
		$( "#edit-date-filter-min-date" ).datepicker({ dateFormat: 'yy-mm-dd' });
        $( "#edit-date-filter-max-date" ).datepicker({ dateFormat: 'yy-mm-dd' });
		for(i=1;i<=19;i++){
		  $( "#min-date-page-"+i).attr('class','form-text');
		  $( "#max-date-page-"+i).attr('class','form-text');
          $("#min-date-page-"+i).datepicker({ dateFormat: 'yy-mm-dd' });
          $("#max-date-page-"+i).datepicker({ dateFormat: 'yy-mm-dd' });
		}
        }catch (e)
        {}
});


    $("#edit-sid optgroup").each(function(){
        if($(this).children().size() ==0 ){
            $(this).remove();
        }
    });
	$(".grippie").width('100%');
	var cont = $(".field-field-instructions .field-item").html();
	if(cont){
		var regX = /\n/gi ;
		cont= cont.replace(cont.charAt(0),"");
		cont = cont.replace(regX, "<br/>");
		$(".field-field-instructions .field-item").empty();
		$(".field-field-instructions .field-item").append(cont);
	}	

	$("#edit-site-country").change(function(){
		$("#edit-site-slogan").val($(this).find("option:selected").html());
	});

	if($('#content-inner-inner .title').text()=="Edit mini panel home_panel") {
		$('#edit-display-title-title-wrapper .description').after(
		"<div style=\"margin-bottom:-10px;margin-top:5px;font-weight:bold;\">Below classes are to be used for resizing the blocks</div><table style=\"margin-top:10px\";><tr><th>css classname</th><th> purpose</th></tr><tr><td>blocks-100</td><td>For making a specific block 100%</td></tr><tr><td>blocks-50</td><td>For making a specific block 50%</td></tr><tr><td>blocks-33</td><td>For making a specific block 33%</td></tr><tr><td>blocks-66</td><td>For making a specific block 66%</td></tr><tr><td>blocks-top-margin</td><td>For keeping distance between blocks when they come on two rows.</td></tr><tr><td>alpha</td><td>To be added only for the first block on each row.</td></tr></table>");
	}
	
	$("#field_ds_sub_sector_values tr").find('th:eq(0)').find('span').text("(Required)");
	var text=$("#field_ds_sub_sector_values tr").find('th:eq(0)').html();
	if(text){
	   text=text.replace(":", " ");
	   text=text+":";
	   $("#field_ds_sub_sector_values tr").find('th:eq(0)').html(text);
	} 
		
	$("#field_ds_reference_url_values tr").find('th:eq(0)').find('span').text("(Required)");
	text=$("#field_ds_reference_url_values tr").find('th:eq(0)').html();
	if(text){   
	   text=text.replace(":", " ");
	   text=text+":";
		$("#field_ds_reference_url_values tr").find('th:eq(0)').html(text);
	}
	
	$(".cms-workflow-view .views-widget #edit-type-wrapper select").attr('size',7);
	$(".cms-workflow-view .views-widget #edit-sid-wrapper select").attr('size',7);
	$("select option").attr( "title", "" );
    $("select option").each(function(i){
      this.title = this.text;
    })
	show_para_hostip_para($("#edit-host-ip-config").val());

    $(".messages.error ul li").each(function(){
        if($(this).find('ul').size() > 0){
            var cont = $(this).find('ul li').html();
            $(this).find('ul').remove();
            $(this).append(cont);
        }
    });
});


function isNumberKey(evt){
	var charCode = (evt.which) ? evt.which : event.keyCode
	if (charCode > 31 && (charCode < 48 || charCode > 57))
	return false;

	return true;
}


function state_data_site_eventbind() {
    if($("#field_state_data_values").length > 0){
        $(this).find('.link-field-subrow').each(function(index) {
            $(this).removeClass('clear-block');
        });
        var node_id=$('#edit-country-data-nid').val();
        var state_data = $.cookie(node_id+'-state-data');
        var agency_data = $.cookie(node_id+'-agency-data');
        if (state_data == null){
            state_data = '';
        }
        if (agency_data == null){
            agency_data = '';
        }
        state_data = state_data.replace(/\+/g,' ');
        agency_data = agency_data.replace(/\+/g,' ');
        var states_array = state_data.split('|');
        var agency_array = agency_data.split('|');
        
        $("#field_state_data_values").find('tbody tr').each(function(index) {
            $(this).find('select').each(function(index) {
                var element_id = $(this).attr('id');
                var auto_element_id = '';
                var sub_region_element_id = '';
                
                if (element_id.indexOf("value-field-region-type-value") >= 0){
                    var element_value = $('#'+element_id).val().toLowerCase();
                    auto_element_id = element_id.replace('value-field-region-type-value','value-field-state-name-0-value');
                    sub_region_element_id = element_id.replace('value-field-region-type-value','value-field-sub-region-0-value');
                    $('#'+auto_element_id).attr('autocomplete','off');
                    
                    switch(element_value){
                        case 'state':
                          var obj23 = new actb(document.getElementById(auto_element_id),states_array);
                          $('#'+sub_region_element_id).val('');
                          $('#'+sub_region_element_id).attr('disabled', true);
                          break;
                        case 'city':
                          var obj23 = new actb(document.getElementById(auto_element_id),states_array);
                          $('#'+sub_region_element_id).removeAttr('disabled');
                          break;
                        case 'municipality':
                          var obj23 = new actb(document.getElementById(auto_element_id),states_array);
                          $('#'+sub_region_element_id).removeAttr('disabled');
                          break;
                        case 'agency':
                          var obj23 = new actb(document.getElementById(auto_element_id),agency_array);
                          $('#'+sub_region_element_id).val('');
                          $('#'+sub_region_element_id).attr('disabled', true);
                          break;
                        case 'sub-agency':
                          var obj23 = new actb(document.getElementById(auto_element_id),agency_array);
                          $('#'+sub_region_element_id).removeAttr('disabled');
                          break;
                        default:
                          var obj23 = new actb(document.getElementById(auto_element_id),states_array);
                          $('#'+sub_region_element_id).val('');
                          $('#'+sub_region_element_id).attr('disabled', true);
                    }
                    
                    $('#'+element_id).unbind('change');
                    $('#'+element_id).change(function() {
                        var current_value = $(this).val().toLowerCase();
                        var current_id = $(this).attr('id');
                        var current_auto_id = current_id.replace('value-field-region-type-value','value-field-state-name-0-value');
                        var current_sub_region_id = element_id.replace('value-field-region-type-value','value-field-sub-region-0-value');
                        switch(current_value){
                            case 'state':
                              $('#'+current_auto_id).unbind();
                              var obj23 = new actb(document.getElementById(current_auto_id),states_array);
                              $('#'+current_sub_region_id).val('');
                              $('#'+current_sub_region_id).attr('disabled', true);
                              break;
                            case 'city':
                              $('#'+current_auto_id).unbind();
                              var obj23 = new actb(document.getElementById(current_auto_id),states_array);
                              $('#'+current_sub_region_id).removeAttr('disabled');
                              break;
                            case 'municipality':
                              $('#'+current_auto_id).unbind();
                              var obj23 = new actb(document.getElementById(current_auto_id),states_array);
                              $('#'+current_sub_region_id).removeAttr('disabled');
                              break;
                            case 'agency':
                              $('#'+current_auto_id).unbind();
                              var obj23 = new actb(document.getElementById(current_auto_id),agency_array);
                              $('#'+current_sub_region_id).val('');
                              $('#'+current_sub_region_id).attr('disabled', true);
                              break;
                            case 'sub-agency':
                              $('#'+current_auto_id).unbind();
                              var obj23 = new actb(document.getElementById(current_auto_id),agency_array);
                              $('#'+current_sub_region_id).removeAttr('disabled');
                              break;
                            default:
                              $('#'+current_auto_id).unbind();
                              var obj23 = new actb(document.getElementById(current_auto_id),states_array);
                              $('#'+current_sub_region_id).val('');
                              $('#'+current_sub_region_id).attr('disabled', true);
                        }
                    });
                }
            });
        });
    }
}

function show_para_hostip_para(val){
	$("#edit-webservice-url-wrapper").hide();
	$("#edit-hostip-database-name-wrapper").hide();
	switch(val){
		case "web_service":
			$("#edit-webservice-url-wrapper").show();
		break;
		case "local_db":
			$("#edit-hostip-database-name-wrapper").show();
		break;
	}	
}


function printSelectedFeedback(sitename) {

    var selected = $("input[id^=bulk-print]:checked");
    counter = selected.length;
    var separator = '<p style="page-break-after: always">&nbsp;</p>';
    var print_button = '<button id="print" class="noprint" onclick="window.print();">Print</button>'; 
    var print_css='<style type="text/css" media="all">@media print {.noprint {display:none;}}</style>';
    if (selected.length == 0) alert("Please select one or more feedbacks to print.");
    else{
	$("#print-waiting").show();
   $("#printable-content").contents().find("head").html('');
   $("#printable-content").contents().find("head").append(print_css);

    $("#printable-content").contents().find("body").html('');
   
  $("#printable-content").contents().find("body").append(print_button);
    $.each(selected, function (index, element) {
        $.get(sitename + '/print/' + element.value, function (html) {
             if(counter==1)
             $("#printable-content").contents().find("body").append(html);
             else 
             $("#printable-content").contents().find("body").append(html + '<br>' + separator);

             counter--;

            if (counter == 0) {
	       $("#printable-content").contents().find("body").append(print_button);
		$("#print-waiting").hide();
            $("#printable-content").contents().find(".print-feedback").remove();
			$("#printable-content").contents().find(".print-logo").remove();
			var new_window=window.open('','bulk_print') ;
			new_window.document.title="Processing Bulk Print...";
			var print_window =  window.open('','bulk_print','toolbar=0,scrollbars=yes,width=600,height=600');
     
			var html = $("#printable-content").contents().find("html").html();
                     
			print_window.document.open();
			print_window.document.write(html);
			print_window.document.close();
			print_window.focus();
	
			//print_window.print();
			//print_window.close();
          }
        } ,"html");
      } );
    
}		
}

function bulk_print_select_all()
{
 if($("#bulk_print_select_all").is(':checked')){
  $("[id^=bulk-print]").each(function(){   
      $(this).attr('checked',true);
   });
  }
 else
 {
   $("[id^=bulk-print]").each(function(){   
      $(this).attr('checked',false);
   });
 }
}

function feedback_print(url)
{      $("#printable-content").contents().find("body").html('');
        var new_window=window.open('','feedback_print') ;
		new_window.document.title="Feedback Details";
	 $.get(url, function (html) { 	
	           var printWin = window.open('','feedback_print','toolbar=0,scrollbars=yes,width=auto,height=auto');
			   $("#printable-content").contents().find("body").append(html);
			   $("#printable-content").contents().find(".print-feedback").remove();
			   $("#printable-content").contents().find(".print-logo").remove();
			   $("#printable-content").contents().find(".print-hr").remove();
			   printWin.document.write($("#printable-content").contents().find("html").html());
			   printWin.document.close();
			   printWin.focus();
			   printWin.print();
			   printWin.close();
             });
}