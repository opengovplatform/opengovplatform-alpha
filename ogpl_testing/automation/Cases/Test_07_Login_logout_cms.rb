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
require 'InputRepository/Config.rb'



describe "Verify Login/Logout to CMS site" do
  before(:all) do
      `Taskkill /IM firefox.exe /F`
      driver = Selenium::WebDriver.for :firefox
      @browser = Watir::Browser.new driver
      @browser.goto("#{$CMS_Site_URL}")
      
  end

  it "Successful Login and logout to CMS" do
	  
	  @browser.text_field(:id,"edit-name").set("#{$CMS_Admin_User_Email}")
    @browser.text_field(:id,"edit-pass").set("#{$CMS_Admin_User_Passwd}")
	sleep 2
	  @browser.button(:id,"edit-submit").click
    sleep 20
	  	  
    @browser.link(:text,"Log Out").click
    sleep 10
    
     puts "CMS LOGIN AND LOGOUT SUCCESSFULLY COMPLETED"
	
    end
    

  it "Unsuccessful Login with wrong password to CMS" do
	  @browser.goto("#{$CMS_Site_URL}")
    sleep 3
	  @browser.text_field(:id,"edit-name").set("#{$CMS_Admin_User_Email}")
    @browser.text_field(:id,"edit-pass").set("Priya_admin123")
	sleep 2
	@browser.button(:id,"edit-submit").click
    sleep 20
	  	  
    @browser.text.should include('Sorry, unrecognized username or password')
   
    puts "CMS LOGIN UNSUCCESSFULLY WITH WRONG PASSWORD COMPLETED"
	
    end

    it "Unsuccessful Login with blank username and password to CMS" do
	  @browser.goto("#{$CMS_Site_URL}")
	  @browser.text_field(:id,"edit-name").set("")
    @browser.text_field(:id,"edit-pass").set("")
	sleep 2
@browser.button(:id,"edit-submit").click
    sleep 20
	  	  
    @browser.text.should include('E-mail field is required.')
    @browser.text.should include('Password field is required.')
   
	puts "CMS LOGIN UNSUCCESSFULLY WITH BLANK USER NAME AND PASSWORD COMPLETED"
	
    end


    it "Unsuccessful Login with blank password to CMS" do
	  @browser.goto("#{$CMS_Site_URL}")
	  @browser.text_field(:id,"edit-name").set("#{$CMS_Admin_User_Email}")
    @browser.text_field(:id,"edit-pass").set("")
	sleep 2
@browser.button(:id,"edit-submit").click
    sleep 20
	  	  

    @browser.text.should include('Password field is required.')
    
	puts "CMS LOGIN UNSUCCESSFULLY WITH BLANK PASSWORD COMPLETED"
	
    end

 after(:all) do
        @browser.close
        `Taskkill /IM firefox.exe /F`
        puts "Test has completed"
    end
end