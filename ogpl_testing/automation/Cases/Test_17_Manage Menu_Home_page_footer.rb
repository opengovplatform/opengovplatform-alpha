# CMS MANAGE MENU - HOME PAGE FOOTER

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
require 'InputRepository/Test_17_Manage Menu_Home_page_footer_input.rb'
require 'InputRepository/Config.rb'
require 'lib/NIC_Lib.rb'

describe "CMS manage Menu - Home Page Footer" do

  before(:all) do
      `Taskkill /IM firefox.exe /F`
      $obj = NIC_Lib.new
      @browser1 = $obj.CMS_login($CMS_Admin_User_Email,$CMS_Admin_User_Passwd)
    
  end


#To Login As CMS_Admin

   
  it "Validation check to disable About us in footer menu " do
        
        @browser1.goto("#{$Site_URL}admin/build/menu-customize/menu-frontfooter")
	
	@browser1.checkbox(:id, "edit-mlid:9318-hidden").clear
	@browser1.button(:value,"Save configuration").click
	puts "Disabled About us link in CMS"
        
   end


  it "Verify that Aboust us  link is not seen on frontend site " do
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}")
      @browser.html.should_not include("About Us")
      @browser.close
      puts "Checked on front end site"
  end

  it "Validation check for manage menu in Footer menu: Enable About us " do
        
        @browser1.goto("#{$Site_URL}admin/build/menu-customize/menu-frontfooter")
        @browser1.checkbox(:id, "edit-mlid:9318-hidden").set
        @browser1.button(:value,"Save configuration").click
        puts "Enabled About us link in CMS"
        
end

  it "Verify that About us link is seen on frontend site " do
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}")
      sleep 5
      @browser.html.should include("About Us")
      @browser.close
      puts "Checked on front end site"
  end

  it "Validation check to add item in Footer navigation " do
        
      @browser1.goto("#{$Site_URL}admin/build/menu-customize/menu-frontfooter/add")
      @browser1.text_field(:id, "edit-menu-link-path").set("#{$url}")
      @browser1.text_field(:id, "edit-menu-link-title").set("#{$title}")
      @browser1.button(:value,"Save").click
      sleep 5

end

  it "Verify that newly added link  seen in Footer  on frontend site " do
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}")
      sleep 5
      @browser.html.should include("#{$title}")
      @browser.close
      puts "Checked on front end site"
  end
  
    it "Verify that newly added link  is clickable " do
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}")
      sleep 5
      @browser.link(:text,"#{$title}").click
      sleep 5
     #@browser.window(:url => "#{$url}").use do
      #@browser.html.should include("#{$title}")
      @browser.close
      puts "Checked on front end site"
      #end
  end
 
=begin 
    it "Verify deletion of newly added footer link in CMS " do
        
        @browser1.goto("#{$Site_URL}/admin/build/menu-customize/menu-footerlinks")
	
        @browser1.link(:text => 'delete', :index => 6).click
        #@browser1.link(:xpath,"//*[@id='menu-overview']/tbody/tr[11]/td[6]/a").click # => "click me"

        #@browser1.button(:value,"Confirm").click
	end
=end

  after(:all) do
        @browser1.link(:text,"Log Out").click
        @browser1.close
        `Taskkill /IM firefox.exe /F`
      
        puts "Test has completed"
  end
end