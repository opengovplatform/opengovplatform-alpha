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
describe "Search for India on NIC site" do
  before(:all) do
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto('http://203.199.26.72/dms/')
  end
      it "To test open data sites for India " do
	
	@browser.link(:text,"Open Data Sites").click
	@browser.link(:text,"India").click
	@browser.link(:text,"West Bengal").click
	#sleep 3
	@browser.title.should include("India")
end

   after(:all) do
        @browser.close
        puts "Test has completed"
    end
end
