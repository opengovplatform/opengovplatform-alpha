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
#require 'InputRepository/captcha.rb'
require 'InputRepository/Config.rb'
require 'InputRepository/Test_14_OGPL_Feedback_Form_Input.rb'

#include 'Suite'
#PRE REQUISITES :-
#Login Credentials, Project Creation data

describe "To log in to the OGPL site and Submit the Feedback Form" do
	
  before(:all) do
      `Taskkill /IM firefox.exe /F`
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}")
      $obj = NIC_Lib.new
      @browser1 = $obj.CMS_login($VRM_Admin_User_Email, $VRM_Admin_User_Passwd)
  end
  
	it "To Navigate to the Feedback form" do
		@browser.link(:text, "Feedback").click
		sleep 5
		@browser.text.should include("Feedback")
		@browser.text.should include("Your valuable feedback on Open Government Platform is welcome to serve you better.")
	end
	
	it "To Submit Blank feedback form" do 
		@browser.button(:value, "Submit").click
		sleep 5
		@browser.text.should include("Your Name field is required.")
		@browser.text.should include("Feedback field is required.")
		puts "Validations required"
	end
	
	it "To Submit feedback form with Invalid Email address" do
	
		@browser.text_field(:name, "field_email[0][email]").set("#{$invalid_email}")
		@browser.button(:value, "Submit").click
		sleep 5
		@browser.text.should include("Please enter a valid email id in Your E-mail Address field eg. sam@xyz.com")
	end
	
	it "To Submit feedback form with Valid details" do
		$ext = Time.now
		$ext = $ext.to_s
		$ext = $ext.slice(0..18)
		$ext = $ext.gsub(" ", "_")
		$input_name = "#{$your_name}" + "_" + "#{$ext}"
		@browser.text_field(:name, "field_sender_name[0][value]").set("#{$input_name }")
		@browser.text_field(:name, "field_email[0][email]").set("#{$your_email_address}")
		@browser.text_field(:name, "field_feedback_body[0][value]").set("#{$feedback}")
		@browser.button(:value, "Submit").click
		sleep 8
		@browser.text.should include("Feedback - Acknowledgment")
		@browser.text.should include("Thank you for spending your valuable time in giving the feedback.")
		sleep 5
		puts "Feedback submitted successfully"
	end
	
	it "To login to the VRM site" do
		sleep 10
		@browser1.text.should include("VRM")
		puts "****** VRM Admin logged in successfully"
		@browser1.refresh
		sleep 10
	end
	
	it "To View the feedback sent by the sender" do
			@browser1.link(:id, "quicktabs-tab-vrm_admin_tabs_list-0").click
			sleep 20
			@browser1.text.should include("#{$input_name}")
			puts "******Feedback has been received by VRM Admin"
			sleep 10
	end
	
	it "To log out" do

			@browser1.link(:text, "Log Out").click
			sleep 20
			@browser1.text.should include("User Login")
			puts "******logged out successfully"
			
	end
			
	
 after(:all) do
	@browser.close
	@browser1.close
  `Taskkill /IM firefox.exe /F`
	puts "Test has completed"
end

end


