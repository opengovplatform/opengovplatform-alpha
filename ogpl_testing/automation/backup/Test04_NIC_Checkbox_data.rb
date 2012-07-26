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
      driver = Selenium::WebDriver.for :firefox
      @browser = Watir::Browser.new driver
      @browser.goto('http://203.199.26.72/dms/')
  end
      it "To Search by checking Retain current filters" do
		@browser.link(:text,"Raw Datasets").click  
		puts "*****************************pass1************************"
		@browser.text_field(:name,"keys").set("#{$search}")
		puts "*****************************pass2************************"
		@browser.checkbox(:name,"apachesolr_search[retain-filters]").set  
		puts "*****************************pass3************************"
		@browser.button(:id, "edit-submit").click
		puts "*****************************pass4************************"
		sleep 10
		#puts "*****************************pass5************************"
		#@browser.body.should include("2008 Home Mortgage Disclosure Act (HMDA) Loan")
		
end

   after(:all) do
        #@browser.close
        puts "Test has completed"
    end
end
