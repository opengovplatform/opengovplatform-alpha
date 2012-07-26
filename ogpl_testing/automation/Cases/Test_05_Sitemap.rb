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
#require 'InputRepository/Search.rb'
require 'InputRepository/Config.rb'
#include 'Suite'
#PRE REQUISITES :-
#Login Credentials, Project Creation data

describe "Verify Site map on NIC OGPL site" do
  before(:all) do
      `Taskkill /IM firefox.exe /F`
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}")
  end

  it "To Check Sitemap  existence " do
		@browser.goto"#{$Site_URL}agency-publications/agency-wise"
		puts "*****************************pass5************************"
		@browser.link(:text, "Site Map").click
		sleep 10
		@browser.text.should include("Site Map")
		
	end
	
it "To Check Presence of links in sitemap " do
		@browser.html.should include("div id=\"contentPanel\"")
		
		
  end

  
  after(:all) do
        @browser.close
        `Taskkill /IM firefox.exe /F`
        puts "Test has completed"
    end
end
