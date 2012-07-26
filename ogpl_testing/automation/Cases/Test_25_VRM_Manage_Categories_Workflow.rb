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
require 'InputRepository/Test_25_VRM_Manage_Categories_Workflow_Input.rb'

describe "Manage Categories Workflow in the VRM site" do

	before(:all) do
      `Taskkill /IM firefox.exe /F`
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
			@browser1 = Watir::Browser.new driver
			@browser1.goto("#{$Site_URL}contactus")
			$obj=NIC_Lib.new
			@browser=$obj.CMS_login($VRM_Admin_User_Email,$VRM_Admin_User_Passwd)
	end
	
		it "To navigate to Manage Categories tab" do
			@browser.link(:text, "Manage Categories").click
			@browser.text.should include("Category List")
		end
		
		it "To Validate adding blank Category" do
			@browser.link(:id, "quicktabs-tab-vrm_manage_categories-1").click
			@browser.text.should include("Add Category")
			sleep 5
			puts "navigate to add category screen"
			@browser.button(:id, "edit-submit-1").click
			@browser.text.should include("Category Name field is required.")
			sleep 5
		end
			
		it "To Verify Cancel action" do
			@browser.text_field(:id, "edit-name-1").set("#{$add_category}")
			puts "Input Category "
			@browser.text_field(:id, "edit-description").set("#{$description}")
			puts "Input description "
			@browser.checkbox(:name, "is_contact_cat").set
			puts "checkbox checked "
			@browser.button(:id, "edit-cancel-1").click
			sleep 5
			@browser.text.should include("Category List")
		end
		
		it "To Add new Category and verify in the workflow" do
			@browser.link(:id, "quicktabs-tab-vrm_manage_categories-1").click
			sleep 5
			@browser.text.should include("Add Category")
			@browser.text_field(:id, "edit-name-1").set("#{$add_category}")
			@browser.text_field(:id, "edit-description").set("#{$description}")
			@browser.checkbox(:name, "is_contact_cat").set
			@browser.button(:id, "edit-submit-1").click
			#~ sleep 10
			#~ @browser.text.should include("Category Saved")
			sleep 15
			puts "category added"
			@browser.link(:id, "quicktabs-tab-vrm_admin_tabs-0").click
			sleep 10
			puts "Navigated to list page"
			#@browser.div(:id, "view-id-VRM_all_feedback_list-page_7").link(:text,"Edit").click 
			#@browser.link(:xpath, "//*[@id='quicktabs_tabpage_vrm_admin_tabs_list_0']/div/div[2]/table/tbody/tr[1]/td[10]/a[1]").click
			@browser.link(:xpath, "//*[@id='quicktabs_tabpage_vrm_admin_tabs_list_1']/div/div[2]/table/tbody/tr[1]/td[10]/a[1]").click
			puts "Navigated to Edit page"
			sleep 10
			@browser.text.should include("Feedback Details Edit")
			puts "Navigated to Feedback Details Edit page"
			@browser.select_list(:id, "edit-field-category-value").select("#{$add_category}")
			@browser.text.should include("#{$add_category}")
			puts "Category displayed in the workflow"
		end

		#~ it "Verify Contact Category in the workflow when checked" do
			#~ @browser1.refresh
			#~ sleep 5
			#~ @browser1.select_list(:id, "edit-field-category-value").select("#{$add_category}")
			#~ @browser1.text.should include("#{$add_category}")
			#~ puts "Contact Category added in the workflow"
			
		#~ end
					
		it "To verify that two categories cannot have same name" do
			@browser.goto("#{$Site_URL}vrm_dashboard")
			@browser.link(:id, "quicktabs-tab-vrm_admin_tabs-2").click
			@browser.text.should include("Category List")
			@browser.link(:id, "quicktabs-tab-vrm_manage_categories-1").click
			@browser.text_field(:id, "edit-name-1").set("#{$add_category}")
			@browser.button(:id, "edit-submit-1").click
			@browser.text.should include("Two categories can not have same name")
			@browser.button(:id, "edit-cancel-1").click
			sleep 15
			puts "Category list screen"
		end
			
		it "To Edit Category" do
			@browser.link(:text, "Manage Categories").click
			sleep 5
			@browser.text.should include("Category List")
			#@browser.link(:text, "edit").click
			@browser.link(:xpath, "//*[@id='quicktabs_tabpage_vrm_manage_categories_0']/div/div[2]/table/tbody/tr[2]/td[2]/a").click
			sleep 10
			#@browser.div(:id, "view-id-vrm_category_view-page_1").link(:text,"edit").click   # :href=> /admin\/content\/taxonomy\/edit\/term/).click
			@browser.text.should include("Edit Category")
			@browser.text_field(:id, "edit-name").set("#{$edit_category}")
			@browser.text_field(:id, "edit-description").set("#{$edit_description}")
			@browser.checkbox(:name, "is_contact_cat").clear
			@browser.button(:id, "edit-submit").click
			sleep 10
			#@browser.text.should include("Updated term #{$edit_category}")
			@browser.text.should include("#{$edit_category} successfully edited.")
			puts "Updated the category name"
		 end
	
	
		#~ it "To Verify that Contact Category is not displayed when unchecked" do
			#~ @browser1.refresh
			#~ sleep 5
			#~ #@browser1.select_list(:id, "edit-field-category-value").select("#{$add_category}")
			#~ @browser1.select_list(:id, "edit-field-category-value")
			#~ @browser1.text.should_not include("#{$add_category}")
			#~ puts "category not added"
		#~ end

		it "Send a feedback to be used in next cases" do
			@browser1.link(:text, "Feedback").click
			sleep 3
			@browser1.text_field(:id, "edit-field-sender-name-0-value").set("TestName")
			@browser1.text_field(:id, "edit-field-email-0-email").set("Name@testemail.com")
			@browser1.textarea(:id, "edit-field-feedback-body-0-value").set("Feedback text sent from Feedback form")
			@browser1.button(:value,"Submit").click
			sleep 5
			@browser1.text.should include("WHAT HAPPENS TO YOUR FEEDBACK NOW?")
		end

		it "To verify that edited category and Predefined format text is displayed in the workflow" do
			sleep 5
			@browser.refresh
			sleep 15
			#@browser.div(:id, "quicktabs-tab-vrm_admin_tabs-0").click
			@browser.link(:id, "quicktabs-tab-vrm_admin_tabs-0").click
			sleep 10
			@browser.link(:id, "quicktabs-tab-vrm_admin_tabs_list-0").click
			sleep 2
			puts "Navigated to list site for edit"
			#@browser.div(:id, "view-id-VRM_all_feedback_list-page_7").link(:text,"Edit").click
			@browser.link(:xpath, "//*[@id='quicktabs_tabpage_vrm_admin_tabs_list_0']/div/div[2]/table/tbody/tr[1]/td[10]/a[1]").click
			sleep 15
			puts "Navigated to edit status"
			@browser.select_list(:id, "edit-field-category-value").select("#{$edit_category}")
			@browser.text.should include("#{$edit_category}")
			puts "Edited Category displayed in the workflow"
			@browser.select_list(:id, "edit-field-assigned-to-uid-uid").select("#{$assignee}")
			@browser.button(:value, "Submit").click
			sleep 10
			@browser.text.should include("Feedback details has been updated.")
			@browser.link(:text, "Edit").click
			sleep 10
			@browser.text.should include("Feedback Details Edit")
			@browser.link(:text, "Reply").click
			sleep 10
			@browser.text.should include("Create Feedback Reply")
			@browser.select_list(:id, "pre_configured_text_select").select("#{$edit_category}")
			puts "selected edited category"
			#@browser.text.should include("#{$edit_description}")
			puts "Preformatted text displayed in comments"
			sleep 10
		end
		
		it "To Remove Category associated with the feedback" do
			@browser.goto("#{$Site_URL}vrm_dashboard")
			sleep 10
			@browser.link(:text, "Manage Categories").click
			sleep 10
			@browser.text.should include("Category List")
			#@browser.div(:id, "view-id-vrm_category_view-page_1").link(:text,"edit").click   # :href=> /admin\/content\/taxonomy\/edit\/term/).click
			#@browser.link(:text, "edit").click
			@browser.link(:xpath, "//*[@id='quicktabs_tabpage_vrm_manage_categories_0']/div/div[2]/table/tbody/tr[2]/td[2]/a").click
			sleep 5
			@browser.text.should include("Edit Category")
			@browser.button(:id, "edit-delete").click
			sleep 10
			@browser.text.should include("Unable to delete, category selected is associated with a feedback.")
			puts "Unable to delete category"
			@browser.goto("#{$Site_URL}vrm_dashboard")
			sleep 15
			#@browser.div(:id, "view-id-VRM_all_feedback_list-page_7").link(:text,"Edit").click
			@browser.link(:xpath, "//*[@id='quicktabs_tabpage_vrm_admin_tabs_list_1']/div/div[2]/table/tbody/tr[1]/td[10]/a[1]").click
			sleep 10
			@browser.select_list(:id, "edit-field-category-value").clear
			@browser.select_list(:id, "edit-field-category-value").select("Tools")
			@browser.button(:id, "edit-submit").click
			sleep 10
			@browser.text.should include("Feedback details has been updated.")
			puts "Feedback details updated"
			sleep 5
		end
			
		it "To delete a newly added category" do
			@browser.goto("#{$Site_URL}vrm_dashboard")
			sleep 10
			@browser.link(:text, "Manage Categories").click
			sleep 10
			#@browser.text.should include("Category List")
			#@browser.link(:id, "quicktabs-tab-vrm_manage_categories-1").click
			#@browser.text.should include("Add Category")
			#sleep 5
			#@browser.text_field(:id, "edit-name-1").set("#{$addnew_category}")
			#@browser.text_field(:id, "edit-description").set("#{$description}")
			#@browser.checkbox(:name, "is_contact_cat").set
			#@browser.button(:id, "edit-submit-1").click
			#sleep 5
			#@browser.text.should include("Category Saved")
			#sleep 15
			#puts "category added"
			#@browser.div(:id, "view-id-vrm_category_view-page_1").link(:text,"edit").click   
			#@browser.link(:text, "edit").click
			@browser.link(:xpath, "//*[@id='quicktabs_tabpage_vrm_manage_categories_0']/div/div[2]/table/tbody/tr[2]/td[2]/a").click
			sleep 5
			@browser.text.should include("Edit Category")
			@browser.button(:id, "edit-delete").click
			sleep 5
			@browser.text.should include("Deleting a term will delete all its children if there are any. This action cannot be undone.")
			@browser.button(:id, "edit-submit").click
			sleep 25
			#@browser.text.should include("Deleted term #{$edit_category}")
			@browser.text.should include("#{$edit_category} successfully deleted")
		         puts "Category Deleted"
			sleep 10
		end

	after(:all) do
		
		@browser.close
		@browser1.close
		`Taskkill /IM firefox.exe /F`
		puts "Test has completed"
		sleep 3
	end
			
end