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
require 'InputRepository/Test_02_Search_input.rb'
require 'InputRepository/Config.rb'
#include 'Suite'
#PRE REQUISITES :-
#Login Credentials, Project Creation data

describe "Search on NIC OGPL site" do
  before(:all) do
      `Taskkill /IM firefox.exe /F`
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}")
  end

  it "To Search by checking Retain current filters" do
		@browser.goto("#{$Site_URL}catalogs/?filter=catalog_type%3Acatalog_type_raw_data")
		puts "*****************************pass1************************"
		@browser.text_field(:name,"keys").set("#{$search}")
		puts "*****************************pass2************************"
		@browser.checkbox(:name,"retain_filters").set  
		puts "*****************************pass3************************"
		@browser.button(:id, "edit-submit-Catalogs-Search").click
		puts "*****************************pass4************************"
		sleep 10
		puts "*****************************pass5************************"
		@browser.text.should include("Parliament Visitor Records Requests")
		
  end

  it "To check search operation in Documents section on NIC site" do
puts "debug*****************************pass5************************"
    @browser.goto("#{$Site_URL}catalogs/?filter=catalog_type%3Acatalog_type_document")
    puts "debug*****************************pass5************************"
    @browser.text_field(:name,"keys").set("#{$document_search_key}")
		@browser.checkbox(:name,"retain_filters").set
		@browser.button(:id, "edit-submit-Catalogs-Search").click
		sleep 15
		@browser.text.should include("#{$document_search_key}")
    puts "DOC SEARCH COMPLETED"
  end

  it "To verify global search opeartion on NIC site" do
    @browser.text_field(:id, "edit-search-theme-form-1").set("#{$document_search_key}")
    @browser.button(:value,"Search").click
    sleep 10
    @browser.text.should include("#{$document_search_key}")
    puts "GLOBAL SEARCH COMPLETED"
  end

  after(:all) do
        @browser.close
        `Taskkill /IM firefox.exe /F`
        puts "Test has completed"
    end
end
