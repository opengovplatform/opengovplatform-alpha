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
require 'InputRepository/Test_21_Rating_form_Input.rb'
#include 'Suite'
#PRE REQUISITES :-
#Login Credentials, Project Creation data

describe "Submit Ratings form" do
  before(:all) do
      `Taskkill /IM firefox.exe /F`
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}")
      $obj = NIC_Lib.new
      @browser1=$obj.CMS_login($VRM_Admin_User_Email,$VRM_Admin_User_Passwd)
 end
    
    it "To Navigate to Rate a dataset" do
	@browser.goto("#{$Site_URL}catalogs/?filter=catalog_type%3Acatalog_type_raw_data")
	@browser.goto("#{$Site_URL}dataset/parliament-visitor-records-requests")
      sleep 8
      
    end
        
    it "To Navigate to Rating form" do
      @browser.link(:text, "Rate this dataset").click
      sleep 5
    end

 it "Submit a blank Rating form" do
      @browser.button(:id, "edit-submit-1").click
      sleep 5
      @browser.text.should include("Comments field is required.")
    end
    
    
    it "Submit a Rating form with comments" do
		$ext = Time.now
		$ext = $ext.to_s
		$ext = $ext.slice(0..18)
		$ext = $ext.gsub(" ", "_")
		$input_comments = "#{$comments}" + "_" + "#{$ext}"
		@browser.text_field(:id, "edit-field-feedback-body-0-value").set("#{$input_comments}") 
		@browser.button(:id, "edit-submit-1").click
		sleep 5
		@browser.text.should include("Ratings - Acknowledgment")
		puts "Comments submitted"
    end
    
  it "To log in to VRM site" do
		@browser1.refresh
		sleep 15
		@browser1.text.should include("Categories")
		puts "VRM User Logged in Successfully"
		@browser1.link(:text, "All").click
		sleep 10
    end   
    
    it "To go to the Feedback Details_View" do
      
		@browser1.link(:text, "View").click
		sleep 5
		@browser1.text.should include("#{$input_comments}") 
    end   
    
    
     it "To go to the Feedback Details_Notes" do
		@browser1.link(:text, "Notes").click
		sleep 5
		@browser1.text.should include("Add Note") 
         
       end
    
   after(:all) do
        @browser.close
        @browser1.close
        `Taskkill /IM firefox.exe /F`
        puts "Test has completed"
  end
end