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
require 'InputRepository/Test_15_OGPL_Suggested_Dataset_Form_Input.rb'

#include 'Suite'
#PRE REQUISITES :-
#Login Credentials, Project Creation data

describe "Submit the Dataset Form on NIC OGPL site" do
	
  before(:all) do
      `Taskkill /IM firefox.exe /F`
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}")
      $obj = NIC_Lib.new
      @browser1 = $obj.CMS_login($VRM_Admin_User_Email, $VRM_Admin_User_Passwd)
      
  end
  
	it"To Navigate to the Suggested Dataset form" do
		
		@browser.goto("#{$Site_URL}suggesteddatasets")
		@browser.text.should include("Suggested Datasets are suggestions/ideas from public to government on publishing newer datasets or information on this site.")
		@browser.link(:text, "click here").click
		sleep 5
		@browser.text.should include("Suggest Dataset")
		puts "Navigated to Suggested Dataset form successfully"
		
	end
	
	it"To Submit Blank Suggestion form" do 
		@browser.button(:value, "Submit").click
		sleep 5
		@browser.text.should include("Your Name field is required.")
		@browser.text.should include("Suggestion field is required.")
	end
	
	it"To Submit Suggestion form with invalid Email address" do
		@browser.text_field(:name, "field_email[0][email]").set("#{$invalid_email}")
		@browser.button(:value, "Submit").click
		sleep 5
		@browser.text.should include("Please enter a valid email id in Your E-mail Address field eg. sam@xyz.com")
		puts "User needs to enter valid Email address"
	end
	
	it"To submit Suggestion form with valid details" do
		$ext = Time.now
		$ext = $ext.to_s
		$ext = $ext.slice(0..18)
		$ext = $ext.gsub(" ", "_")
		$input_name = "#{$your_name}" + "_" + "#{$ext}"
		@browser.text_field(:name, "field_sender_name[0][value]").set("#{$input_name}")
		@browser.text_field(:name, "field_email[0][email]").set("#{$your_email_address}")
		@browser.text_field(:name, "field_feedback_body[0][value]").set("#{$suggestion}")
		@browser.button(:value, "Submit").click
		sleep 5
		@browser.text.should include("Suggest Dataset - Acknowledgment")
		@browser.text.should include("Thank you for spending your valuable time in suggesting and giving your idea for government datasets or apps that does not exist yet, but should.")
		puts "Suggestion form submitted successfully"
	end
	
	
	it "To login to the VRM site" do
		@browser1.text.should include("VRM")
		puts "****** VRM Admin logged in successfully"
		@browser1.refresh
		sleep 10
	end
	
	
	it "To View the Suggestions sent by the sender" do
			@browser1.link(:id, "quicktabs-tab-vrm_admin_tabs_list-0").click
			sleep 20
			@browser1.text.should include("#{$input_name}")
			puts "******Feedback has been received by VRM Admin"
	end
	
	it "To log out" do

			@browser1.link(:text, "Log Out").click
			sleep 10
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


