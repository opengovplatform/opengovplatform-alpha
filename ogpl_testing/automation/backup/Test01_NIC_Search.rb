require 'rubygems'
#Load WATIR
require 'fileutils'
require 'lib/selenium_support'
# Load WIN32OLE library
require 'win32ole'
require 'Win32API'
#Load the win32 library
require 'win32/clipboard'
include Win32
require 'InputRepository/Search.rb'
#include 'Suite'
#PRE REQUISITES :-
#Login Credentials, Project Creation data
describe "Google Search" do
  before(:all) do
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto('http://203.199.26.72/dms')
  end
	it "To test google search" do
		#@browser.text_field(:name,"search_theme_form").set("#{$search}")
		puts "*****************************pass1************************"
		#@browser.button(:name,"op").click
		puts "*****************************pass2************************"
		sleep 3
		puts "*****************************pass4************************"
		@browser.link(:id, "quicktabs-tab-catalog_tab-2").click
		@browser.title.should include("Open")
end

	after(:all) do
		#@browser.close
		puts "Test has completed"
    end
end
