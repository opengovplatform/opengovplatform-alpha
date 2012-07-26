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
describe "Facebook_login" do
  before(:all) do
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto('http://www.facebook.com')
  end
      it "To test facebook login" do
	@browser.text_field(:id,"email").set("1@mailop.com")
  @browser.text_field(:id,"pass").set("1@mailop.com")
	@browser.button(:value,"Log In").click
	sleep 3
	
end

   after(:all) do
       # @browser.close
        puts "Test has completed"
    end
end
