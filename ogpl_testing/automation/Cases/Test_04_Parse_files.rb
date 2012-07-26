require 'rubygems'
#Load WATIR
require 'fileutils'
require 'lib/selenium_support'
# Load WIN32OLE library
require 'win32ole'
#require 'Win32API'
#Load the win32 library
#require 'win32/clipboard'
#include Win32
require 'InputRepository/Config.rb'
#include 'Suite'
#PRE REQUISITES :-
#Login Credentials, Project Creation data

describe "Parse downloaded metrics files" do
  before(:all) do
      #driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      #@browser = Watir::Browser.new driver
      #@browser.goto('http://203.199.26.72/dms/')
  end

  it "To Parse CSV file" do
	puts "To parse CSV file"
	#puts Dir.pwd
	$fl_nm = "#{Dir.pwd}/Downloads/"
	#puts $fl_nm
	$fl_nm = $fl_nm.gsub("/", "\\")
	#puts $fl_nm
	$contains = Dir.new($fl_nm).entries
	p $contains
	$fl_csv = $contains[3].to_s
	p $fl_csv
	$fl_csv = $fl_nm + $fl_csv
	p $fl_csv

      excel= WIN32OLE::new('excel.Application')
      workbook=excel.Workbooks.Open("#{$fl_csv}")
      worksheet=workbook.Worksheets(1)
      $col1 =worksheet.Range('a1') ['Value']
      $col2 =worksheet.Range('e1') ['Value']
      $col3 =worksheet.Range('k1') ['Value']
      $row1 =worksheet.Range('a2') ['Value']
      #$row2 =worksheet.Range('a20') ['Value']
      
      #excel.ActiveWorkbook.Save
      excel.Workbooks.Close
      excel.quit

      $col1.should == "Agency"
      $col2.should == "Raw Datasets (high-value)"
      $col3.should == "Date Of last Submission"
      $row1.should == "Commerce Department"
      #$row2.should == "Forests and Mining"
      
  end

  it "To parse EXCEL file" do
      puts "To parse EXCEL file"
	  #puts Dir.pwd
      $fl_nm = "#{Dir.pwd}/Downloads/"
      #puts $fl_nm
      $fl_nm = $fl_nm.gsub("/", "\\")
      #puts $fl_nm
      $contains = Dir.new($fl_nm).entries
      p $contains
      $fl_csv = $contains[4].to_s
	  puts "EXCEL"
	  puts $fl_csv
      $fl_csv = $fl_nm + $fl_csv
      puts $fl_csv

      excel= WIN32OLE::new('excel.Application')
      workbook=excel.Workbooks.Open("#{$fl_csv}")
      worksheet=workbook.Worksheets(1)
      $col1 =worksheet.Range('a1') ['Value']
      $col2 =worksheet.Range('e1') ['Value']
      $col3 =worksheet.Range('k1') ['Value']
      $row1 =worksheet.Range('a2') ['Value']
      #$row2 =worksheet.Range('a22') ['Value']
      
      #excel.ActiveWorkbook.Save
      excel.Workbooks.Close
      excel.quit

      $col1.should == "Agency"
      $col2.should == "Raw Datasets (high-value)"
      $col3.should == "Date Of Last Submission"
      $row1.should == "Commerce Department"
      #$row2.should == "Forests and Mining"
  end

  after(:all) do
        #@browser.close
        #system("delete.bat")
        puts "Test has completed"
  end

end
