require 'rubygems'
#Load WATIR
require 'fileutils'
require 'lib/selenium_support'
# Load WIN32OLE library
#require 'win32ole'
#require 'Win32API'
#Load the win32 library
#require 'win32/clipboard'
#include Win32
require 'lib/NIC_Lib.rb'
require 'InputRepository/Config.rb'
require 'InputRepository/Test_23_VRM_Manage_Action_Workflow_Input.rb'

describe "VRM Manage Action Workflow" do

before(:all) do
    `Taskkill /IM firefox.exe /F`
    $obj=NIC_Lib.new
    @browser = $obj.CMS_login($VRM_Admin_User_Email,$VRM_Admin_User_Passwd)
end

	it "To Validate Action Name field in VRM" do
		sleep 10
		@browser.link(:text, "Manage Actions").click
		@browser.text.should include("Action Status List")
		@browser.link(:text, "Add").click
		@browser.text.should include("Add Action Status")
		@browser.button(:value, "Add").click
		@browser.text.should include("Action Status Name field is required")
		puts "***** Validation done"
	end

	it "To Cancel Action Name field" do
		sleep 10
		@browser.text_field(:name, "name").set("#{$action_name}")
		@browser.button(:value, "Cancel").click
		@browser.text.should include("Action Status List")
		puts "***** Action Name Canceled"
	end


	it "To Add Action field " do
		sleep 10
		@browser.link(:text, "Manage Actions").click
		@browser.text.should include("Action Status List")
		@browser.link(:text, "Add").click
		@browser.text.should include("Add Action Status")
		@browser.text_field(:name, "name").set("#{$action_name}")
		@browser.button(:value, "Add").click
		sleep 10
		@browser.text.should_not include("Action Status Name (Required):")
		@browser.text.should include("#{$action_name}")
		sleep 5
		puts "*****Action field added"
	end
=begin
	it "To verify that newly added action is displayed in the Action status drop down" do
		@browser.link(:id, "quicktabs-tab-vrm_manage_actions-1").click
		sleep 5
		puts " Navigated to list site"
		sleep 5
		@browser.link(:text, "edit").click
		#@browser.goto("#{$Site_URL}node/1354/edit?destination=")
		sleep 3
		@browser.text.should include("Feedback Details Edit")
		puts " Navigated to Edit site"
		@browser.select_list(:id, "edit-field-action-status-value").select("#{$action_name}")
		@browser.text.should include("#{$action_name}")
		puts "Action Name is displayed"
	end
=end
	it "To Edit Action Name" do
    @browser.goto("#{$Site_URL}vrm_dashboard")
		sleep 10
		puts "navigated to Home"
		@browser.link(:text, "Manage Actions").click
		@browser.text.should include("Action Status List")
		puts "Action list"
		@browser.link(:text, "edit").click
		@browser.text.should include("Edit Action Status")
		@browser.text_field(:name, "name").set("#{$edit_action_name}")
		@browser.button(:value, "Save").click
		sleep 10
		#@browser.text.should include("Updated term #{$edit_action_name}")
		@browser.text.should include("#{$edit_action_name} successfully edited")
		sleep 5
		puts "Updated the action name"
	end
=begin	
	it "To verify that edited action name is displayed in the Action status drop down" do
		@browser.link(:id, "quicktabs-tab-vrm_manage_actions-1").click
		sleep 10
		puts " Navigated to list site for edit"
    @browser.link(:text, "edit").click
		#@browser.goto("#{$Site_URL}node/1359/edit?destination=")
		@browser.select_list(:id, "edit-field-action-status-value").select("#{$edit_action_name}")
		@browser.text.should include("#{$edit_action_name}")
	end
=end
	it "To Cancel Delete action" do
		@browser.goto("#{$Site_URL}vrm_dashboard")
    sleep 10
		@browser.link(:text, "Manage Actions").click
		@browser.text.should include("Action Status List")
		@browser.link(:text, "edit").click
    sleep 10
		@browser.text.should include("Edit Action Status")
		@browser.button(:value, "Delete").click
		sleep 3
		@browser.text.should include("Edit Action Status")
		@browser.text.should include("Deleting a term will delete all its children if there are any. This action cannot be undone.")
		@browser.button(:value, "Cancel").click
		sleep 3
		@browser.text.should include("Edit Action Status")
		puts "Not deleted"
	end
	
	it "To Delete Action Name" do
    sleep 10
		@browser.button(:id, "edit-delete").click
		@browser.text.should include("Deleting a term will delete all its children if there are any. This action cannot be undone.")
		@browser.button(:id, "edit-submit").click
    sleep 10
		#@browser.text.should include("Deleted term #{$edit_action_name}")
		@browser.text.should include("#{$edit_action_name} successfully deleted")
		@browser.text.should include("Action Status List")
		puts "Deleted"
		sleep 5
	end
	
	it "To log out" do
    sleep 10
		@browser.link(:text, "Log Out").click
		sleep 10
		@browser.text.should include("Welcome to Open Government Platform")
		
	end
	
			
after(:all) do

	@browser.close
  `Taskkill /IM firefox.exe /F`
	puts "Test has completed"
end

end