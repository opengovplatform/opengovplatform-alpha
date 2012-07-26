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
      it "To Navigate and NIC search" do
		@browser.link(:text,"Raw Datasets").click  
		puts "*****************************pass1************************"
		@browser.text_field(:name,"keys").set("#{$search}")
		puts "*****************************pass2************************"
		@browser.button(:name,"op").click
		puts "*****************************pass3************************"
		sleep 3
		puts "*****************************pass4************************"
		@browser.title.should include("Open")
  end

   after(:all) do
        @browser.close
	
	puts "*****************************complete************************"
	sleep 3
        puts "Test has completed"
    end
end
