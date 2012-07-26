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
#include 'Suite'
#PRE REQUISITES :-
#Login Credentials, Project Creation data
describe "Download metrics file" do
  before(:all) do
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto("$Site_URL")
  end

  it "To download CSV file" do
      @browser.goto("$Site_URLagency-publications/agency-wise")
      @browser.image(:src=>"$Site_URLsites/all/themes/cms/images/csv.png").click
      sleep 20
            
  end

  it "To download EXCEL file" do
      @browser.goto("$Site_URLagency-publications/agency-wise")
      @browser.image(:src=>"$Site_URLsites/all/themes/cms/images/xls.png").click
      sleep 20
      
  end

  it "To download PDF file" do
      @browser.goto("$Site_URLagency-publications/agency-wise")
      @browser.image(:src=>"$Site_URLsites/all/themes/cms/images/pdf.png").click
      sleep 20
      
  end

  it "Check existence of downloaded files" do
      puts Dir.pwd
      $fl_nm = "#{Dir.pwd}/Downloads/"
      puts $fl_nm
      $fl_nm = $fl_nm.gsub("/", "\\")
      puts $fl_nm
      $contains = Dir.new($fl_nm).entries
      p $contains
      $contains[2].should include("agency-publications")
      $contains[2].should include(".pdf")
      $contains[3].should include("agency_wise_report")
      $contains[3].should include(".csv")
      $contains[4].should include("agency_wise_report")
      $contains[4].should include(".xls")
    
      #$contains.matches?(/agency*\.csv/)

  end

  after(:all) do
        @browser.close
        system("delete.bat")
        puts "Test has completed"
  end
end