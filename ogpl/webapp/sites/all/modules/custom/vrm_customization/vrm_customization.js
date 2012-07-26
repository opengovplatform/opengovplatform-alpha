function textCounter(max,textarename,desc)
{
    if (document.getElementById(textarename).value.length>parseInt(max)){
        document.getElementById(textarename).value=document.getElementById(textarename).value.substring(0,max)
    } else {
        var txtlength = document.getElementById(textarename).value.length;
        desc = desc?desc:'feedback-textarea-limit-count';
        $('#'+desc).html(parseInt(max)-txtlength) ;
    }
}

$(document).ready(function(){
	if($('#edit-description').length>0 )
		textCounter(3000,"edit-description");
	if($('#forward-textarea-limit-count').length>0)
		textCounter(3000,"edit-txt-message",'forward-textarea-limit-count');
	
    $('select#edit-PMO,select#edit-POC').change(function(){

        PMO_emails = $('select#edit-PMO').val() || [];
        POC_emails = $('select#edit-POC').val() || [];

        PMO_emails = PMO_emails.join(",");
        POC_emails = POC_emails.join(",");

        all_emails = PMO_emails + ',' + POC_emails;

        // If first letter is ',' then delete
        if(all_emails.charAt(0) == ',') {
            all_emails = all_emails.substring(1, all_emails.length);
        }
        if(all_emails.charAt(all_emails.length - 1) == ',') {
            all_emails = all_emails.substring(0, all_emails.length-1);
        }
        $('textarea#edit-txt-to-addrs').val(all_emails);
    });
// apply character limit
	$('#edit-txt-message').bind('keyup keydown mouseup mousedown', function() {
		forwardCharLimit('3000','edit-txt-message');
	});
	
	
});

function forwardCharLimit(max,textareaname)
{
	
	if($('#'+textareaname).val().length > parseInt(max))
	{
		var text = $('#'+textareaname).val().substr(0,max);
		$('#'+textareaname).val(text);
	}
	else
	{
		var txtlength = $('#'+textareaname).val().length;
		desc = 'forward-textarea-limit-count';
		$('#'+desc).html(parseInt(max)-txtlength) ;
	}
}

function textCounters(max,textarename,desc)
{	
    if (document.getElementById(textarename).value.length>parseInt(max)){
        document.getElementById(textarename).value=document.getElementById(textarename).value.substring(0,max)
    } else {
        var txtlength = document.getElementById(textarename).value.length;
        desc = desc?desc:'feedback-textarea-limit-count';
        $('#'+desc).html(parseInt(max)-txtlength) ;
    }
}

function textNoteCounters(max,textarename,desc)
{
    if($('#'+textarename).val().length > parseInt(max))
    {
        var text = $('#'+textarename).val().substr(0,max);
        $('#'+textarename).val(text);
    }
    else
    {
        var txtlength = $('#'+textarename).val().length;
        desc = desc?desc:'note-textarea-limit-count';
        $('#'+desc).html(parseInt(max)-txtlength) ;
    }
}

function resetTextNoteCounters(max,desc)
{
    desc = desc?desc:'note-textarea-limit-count';
    $('#'+desc).html(parseInt(max));
}
