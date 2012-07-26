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
#require 'InputRepository/Search.rb'

describe "Navigate to foreign sites" do
  before(:all) do
      driver = Selenium::WebDriver.for :firefox
      @browser = Watir::Browser.new driver
      @browser.goto('http://203.199.26.72/dms/')
  end

  it "Successful navigation to USA site" do
		@browser.image(:src=>"http://203.199.26.72/dms/system/files/flag-usa_1.png?1327217961").click
    @browser.window(:title => "Data.gov").use do
      @browser.text.should include('Data.gov')
    end
    
    puts "USA NAVIGATION COMPLETED"

  end

  it "Successful navigation to SPANISH site" do
		@browser.image(:src=>"http://203.199.26.72/dms/system/files/flag-3_0_0.png?1326913394").click
    @browser.window(:title => "Proyecto Aporta - Buscador de catálogos").use do
      @browser.text.should include('Catálogo de información pública en Internet')
  end

    puts "SPANISH NAVIGATION COMPLETED"

  end

  it "Successful navigation to CANADA site" do
		@browser.image(:src=>"http://203.199.26.72/dms/system/files/flag-canada_0.png?1326913314").click
    @browser.window(:title => /Open Data/).use do
      @browser.text.should include('canada.gc.ca')
  end

    puts "CANADA NAVIGATION COMPLETED"

  end
  
  it "Successful navigation to GREEK site" do
		@browser.image(:src=>"http://203.199.26.72/dms/system/files/flag-5_1.png?1326914195").click
    @browser.window(:title => /Hellenic Ministry of Foreign Affairs/).use do
      @browser.text.should include('The Ministry')
  end

    puts "GREEK NAVIGATION COMPLETED"

  end

  it "Successful navigation to IRISH site" do
		@browser.image(:src=>"http://203.199.26.72/dms/system/files/flag-2_2.png?1326914069").click
    @browser.window(:title => "www.gov.ie | Information on Government services").use do
      @browser.text.should include('When looking for Irish Government information')
  end

    puts "IRISH NAVIGATION COMPLETED"

  end

   it "Successful navigation to CZECH site" do
		@browser.image(:src=>"http://203.199.26.72/dms/system/files/flag-check_0.png?1326913819").click
    @browser.window(:title => "Home | Government of the Czech Republic").use do
    @browser.text.should include('Government of the Czech Republic')
  end

    puts "CZECH NAVIGATION COMPLETED"

  end

  after(:all) do
        @browser.close
        puts "Test has completed"
    end
end