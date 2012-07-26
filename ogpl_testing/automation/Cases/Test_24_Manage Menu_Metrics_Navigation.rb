# CMS COUNTRY DATA WORKFLOW

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
require 'InputRepository/Test_24_Manage Menu_Metrics_Navigation_input.rb'
require 'InputRepository/Config.rb'
require 'lib/NIC_Lib.rb'

describe "CMS Manage Menu - Metrics Navigation" do

  before(:all) do
      `Taskkill /IM firefox.exe /F`
      $obj = NIC_Lib.new
      @browser1 = $obj.CMS_login($CMS_Admin_User_Email,$CMS_Admin_User_Passwd)
    
  end


#To Login As CMS_Admin 
  it "Validation check to disable Agency Publications in metrics menu " do
        
	@browser1.goto("#{$Site_URL}admin/build/menu")
	@browser1.goto("#{$Site_URL}admin/build/menu-customize/menu-metricsmenu")
  sleep 10
	@browser1.checkbox(:id, "edit-mlid:10894-hidden").clear
  sleep 2
	@browser1.button(:value,"Save configuration").click
  sleep 2
	puts "Disabled metrics link in CMS"
        
end



  it "Verify that Agency Publications link is not seen on frontend site " do
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}agency-publications/agency-wise")
      @browser.text.should_not include("Agency Publications")
      @browser.close
      puts "Checked on front end site"
  end
  


  it "Validation check to enable Agency Publications in metrics menu in CMS " do
        
  @browser1.goto("#{$Site_URL}admin/build/menu-customize/menu-metricsmenu")
  sleep 10
	@browser1.checkbox(:id, "edit-mlid:10894-hidden").set
  sleep 10
	@browser1.button(:value,"Save configuration").click
  sleep 2
	puts "Enabled metrics link in CMS"
        
end


  it "Verify that Agency Publications link is seen on frontend site " do
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}")
      @browser.html.should include("Agency Publications")
      @browser.close
      puts "Checked on front end site"
  end

  it "Validation check to add item in metrics " do
        
      @browser1.goto("#{$Site_URL}admin/build/menu-customize/menu-metricsmenu/add")
      @browser1.text_field(:id, "edit-menu-link-path").set("#{$url}")
      @browser1.text_field(:id, "edit-menu-link-title").set("#{$title1}")
      @browser1.button(:value,"Save").click

end

  it "Verify that newly added link  seen in metrics menu  on frontend site " do
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}agency-publications/agency-wise")
      @browser.html.should include("#{$title1}")
      @browser.close
      puts "Checked on front end site"
  end
  
    it "Verify that newly added link  is clickable " do
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}agency-publications/agency-wise")
      @browser.link(:text,"#{$title1}").click
      sleep 8
     #@browser.window(:url => "#{$url}").use do
      #@browser.html.should include("#{$title1}")
      @browser.close
      puts "Checked on front end site"
      #end
  end
  
 

  after(:all) do
        @browser1.link(:text,"Log Out").click
       
        @browser1.close
        `Taskkill /IM firefox.exe /F`
        puts "Test has completed"
  end
end