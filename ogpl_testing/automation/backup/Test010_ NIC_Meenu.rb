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
describe "nic_menu" do
  before(:all) do
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto('http://203.199.26.72/dms/')
  end
      it "To test menu click" do
	@browser.link(:text, "Raw Datasets").click
	
	sleep 3
	
end

   after(:all) do
       # @browser.close
        puts "Test has completed"
    end
end
