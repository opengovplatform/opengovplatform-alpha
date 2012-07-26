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
      @browser.goto('http://www.google.com')
  end
      it "To test google search" do
	@browser.text_field(:name,"q").set("search")
	@browser.button(:name,"btnG").click
	sleep 3
	@browser.title.should include("search")
end

   after(:all) do
        @browser.close
        puts "Test has completed"
    end
end
