$(document).ready(function(){

//$("input[type='checkbox']").unbind("click");
//$("input[type='checkbox']").unbind("change");

	$('.qt_tab').click(bulk_reset);
	$('.vrm-bulk-replied #edit-submit').unbind('click').click(bulk_validate1);
	$('.vrm-bulk-reviewed #edit-submit').unbind('click').click(bulk_validate2);
	$('.vrm-bulk-replied #edit-objects-selector-wrapper').html('<input type="checkbox" id="bulk-operation-select-all-1"></input>');
	$('.vrm-bulk-reviewed #edit-objects-selector-wrapper').html('<input type="checkbox" id="bulk-operation-select-all-2"></input>');
	$('#bulk-operation-select-all-1').click(select_all_1);
	$('#bulk-operation-select-all-2').click(select_all_2);
	function select_all_1(){
		if($('#bulk-operation-select-all-1').attr('checked')==true)
			{
				$('.vrm-bulk-replied input[type=checkbox]').each(function(){
					$(this).attr('checked',true);
				});
			}
		else
			{
				$('.vrm-bulk-replied input[type=checkbox]').each(function(){
					$(this).attr('checked',false);
				});
			}	
	}
	function select_all_2()
	{
	if($('#bulk-operation-select-all-2').attr('checked')==true)
		{
			$('.vrm-bulk-reviewed input[type=checkbox]').each(function(){
				$(this).attr('checked',true);
			});
		}
	else
		{
			$('.vrm-bulk-reviewed input[type=checkbox]').each(function(){
				$(this).attr('checked',false);
			});
		}
	}
	
	//$('.qt_tab').click(bulk_reset);
	/*$('.item-list .pager a').unbind('click').click(function()
			{
				$('.views-bulk-operations-table #edit-objects-selector').val('None');
			});*/
	function bulk_validate1()
		{
			var selected = false; 
			$('.vrm-bulk-replied .form-checkbox').each(function(){
				if($(this).attr('checked'))
					selected=true;
			});
			if(selected == false)
			{
				alert ("No rows selected, Please select a row.");
				return false;
			}
			else
			{
					ans=confirm("Are you sure you want to change the status?");
					if(ans)
					{
						return true;
					}
					else
					{
						return false;
					}
			}
			
		}
		//.vrm-bulk-reviewed .vbo-select
	function bulk_validate2()
		{
			var selected = false; 
			$('.vrm-bulk-reviewed .form-checkbox').each(function(){
				if($(this).attr('checked'))
					selected=true;
			});
			if(selected == false)
			{
				alert ("No rows selected, Please select a row.");
				return false;
			}
			else
			{
					ans=confirm("Are you sure you want to change the status?");
					if(ans)
					{
						return true;
					}
					else
					{
						return false;
					}
			}
			
		}
	$('.item-list .pager a').click(bulk_reset);
	function bulk_reset()
		{
			$('.vrm-bulk-replied input[type=checkbox]').each(function(){
				if($(this).attr('checked'))
				{
					$(this).attr('checked',false);
				}
			});
			$('.vrm-bulk-reviewed input[type=checkbox]').each(function(){
				if($(this).attr('checked'))
				{
					$(this).attr('checked',false);
				}
			});
			
		}
	$('#quicktabs_container_vrm_admin_tabs_list').ajaxComplete(function(){$('.item-list .pager a').click(bulk_reset);
	$('.vrm-bulk-replied #edit-submit').unbind('click').click(bulk_validate1);
	$('.vrm-bulk-reviewed #edit-submit').unbind('click').click(bulk_validate2);
	$('.vrm-bulk-replied #edit-objects-selector-wrapper').html('<input type="checkbox" id="bulk-operation-select-all-1"></input>');
	$('.vrm-bulk-reviewed #edit-objects-selector-wrapper').html('<input type="checkbox" id="bulk-operation-select-all-2"></input>');
	$('.vrm-bulk-replied #bulk-operation-select-all-1').click(select_all_1);
	$('.vrm-bulk-reviewed #bulk-operation-select-all-2').click(select_all_2);
	});
	
});
