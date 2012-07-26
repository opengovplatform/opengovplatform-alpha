# VRM REPORTS

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
#require 'InputRepository/Test_20_CMS_Block_workflow_input.rb'
require 'InputRepository/Config.rb'
require 'lib/NIC_Lib.rb'

describe "Checking VRM reports" do

  before(:all) do
      `Taskkill /IM firefox.exe /F`
      $obj = NIC_Lib.new
      @browser1 = $obj.CMS_login($VRM_Admin_User_Email,$VRM_Admin_User_Passwd)
      @browser2 = $obj.CMS_login($VRM_PMO_User_Email,$VRM_PMO_User_Passwd)
      @browser3 = $obj.CMS_login($VRM_POC_User_Email,$VRM_POC_User_Passwd)

  end


#To Login As CMS_Admin
  it "Check reports for VRM admin" do
      @browser1.goto("#{$Site_URL}action-metrics")
      sleep 5
      @browser1.text.should include("VRM Action Metrics")
      puts "Reports for VRM admin completed"

   end

    it "Check reports for VRM PMO" do
      @browser2.goto("#{$Site_URL}action-metrics")
      sleep 5
      @browser2.text.should include("VRM Action Metrics")
      puts "Reports for VRM PMO completed"

   end

     it "Check reports for VRM POC" do
      @browser3.goto("#{$Site_URL}action-metrics")
      sleep 5
      @browser3.text.should include("VRM Action Metrics")
      puts "Reports for VRM POC completed"

   end


  after(:all) do
        @browser1.link(:text,"Log Out").click
        @browser2.link(:text,"Log Out").click
        @browser3.link(:text,"Log Out").click
        @browser1.close
        @browser2.close
        @browser3.close
        `Taskkill /IM firefox.exe /F`
        puts "Test has completed"
  end

end
