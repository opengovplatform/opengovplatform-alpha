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
require 'InputRepository/Config.rb'
#include 'Suite'
#PRE REQUISITES :-
#Login Credentials, Project Creation data
describe "Download Metrics files" do
  before(:all) do
      `Taskkill /IM firefox.exe /F`
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}")
  end

  it "To download CSV file" do
      system("delete.bat")
      @browser.goto("#{$Site_URL}agency-publications/agency-wise")
      @browser.image(:src=>"#{$Site_URL}sites/all/themes/ogpl_css3/images/csv.png").click
      sleep 40
      puts "Waiting for CSV.."
      sleep 5
            
  end
  
  it "Check existence of downloaded CSV file" do
      puts Dir.pwd
      $fl_nm = "#{Dir.pwd}/Downloads/"
      puts $fl_nm
      $fl_nm = $fl_nm.gsub("/", "\\")
      puts $fl_nm
      $contains = Dir.new($fl_nm).entries
      #sleep 3
      #p $contains
      if ($contains[2] == ".svn")
			$contains[3].should include("agency_wise_report")
			$contains[3].should include(".csv")
	  else
			$contains[2].should include("agency_wise_report")
			$contains[2].should include(".csv")
	  end
	  
      
  end

  it "To download EXCEL file" do
      @browser.goto("#{$Site_URL}agency-publications/agency-wise")
      @browser.image(:src=>"#{$Site_URL}sites/all/themes/ogpl_css3/images/xls.png").click
      sleep 40
      puts "Waiting for XLS.."
      sleep 5
      
  end
  
  it "Check existence of downloaded EXCEL file" do
      puts Dir.pwd
      $fl_nm = "#{Dir.pwd}/Downloads/"
      puts $fl_nm
      $fl_nm = $fl_nm.gsub("/", "\\")
      puts $fl_nm
      $contains = Dir.new($fl_nm).entries
      #sleep 3
      #p $contains
	  if ($contains[2] == ".svn")
			$contains[4].should include("agency_wise_report")
			$contains[4].should include(".xls")
	  else
			$contains[3].should include("agency_wise_report")
			$contains[3].should include(".xls")
	  end
      
  end

  it "To download PDF file" do
      @browser.goto("#{$Site_URL}agency-publications/agency-wise")
      @browser.image(:src=>"#{$Site_URL}sites/all/themes/ogpl_css3/images/pdf.png").click
      sleep 40
      puts "Waiting for PDF.."
      sleep 5
      
  end

  it "Check existence of downloaded PDF file" do
      puts Dir.pwd
      $fl_nm = "#{Dir.pwd}/Downloads/"
      puts $fl_nm
      $fl_nm = $fl_nm.gsub("/", "\\")
      puts $fl_nm
      $contains = Dir.new($fl_nm).entries
      p $contains
      if ($contains[2] == ".svn")
			$contains[3].should include("agency-publications_agency-wise")
			$contains[3].should include(".pdf")
	  else
			$contains[2].should include("agency-publications_agency-wise")
			$contains[2].should include(".pdf")
	  end
	  
  end

  after(:all) do
        @browser.close
        #system("delete.bat")
        `Taskkill /IM firefox.exe /F`
        puts "Test has completed"
  end
end