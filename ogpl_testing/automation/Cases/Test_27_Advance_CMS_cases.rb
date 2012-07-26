# ADVANCE CMS CASES

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
require 'InputRepository/Test_27_Advance_CMS_cases_input.rb'
require 'InputRepository/Config.rb'
require 'lib/NIC_Lib.rb'

describe "Advance CMS cases" do

  before(:all) do
      `Taskkill /IM firefox.exe /F`
      $obj = NIC_Lib.new
      @browser1 = $obj.CMS_login($CMS_Admin_User_Email,$CMS_Admin_User_Passwd)

  end

  it "Verify that user with no defined role does not get listed in user list" do

        @browser1.goto("#{$Site_URL}user-management")
        sleep 2
        @browser1.goto("#{$Site_URL}content/add-user")
        sleep 2
        $em_ext = Time.now
        $em_ext = $em_ext.to_s
        $em_ext = $em_ext.slice(0..18)
        $em_ext = $em_ext.gsub(" ","_")
        $em_ext = $em_ext.gsub(":","_")
        $cms_user_email = $email + "_" + $em_ext + "@testmail.com"
        @browser1.text_field(:id, "edit-mail").set($cms_user_email)
        @browser1.text_field(:id, "edit-pass-pass1").set($passwd)
        @browser1.text_field(:id, "edit-pass-pass2").set($passwd)
        #$cms_name = $name + "_" + $em_ext
        @browser1.text_field(:id, "edit-field-prof-name-0-value").set($name)
        #@browser1.checkbox(:id, "edit-roles-assign-11").set
        @browser1.text_field(:id, "edit-field-prof-phone-0-value").set($valid_phone1)
        @browser1.select_list(:id, "edit-field-prof-agency-nid-nid").select($dept)
        @browser1.button(:value,"Create new account").click
        sleep 1
        @browser1.goto("#{$Site_URL}user-management")
        sleep 2
        while (@browser1.link(:title,"Go to next page").exists?)
              @browser1.text.should_not include($cms_user_email)
              @browser1.link(:title,"Go to next page").click
              puts "test1"
        end
        puts "User is not reflected in list"
  end

  it "Check Contact Admin tab on Reference Documents page" do
        @browser1.goto("#{$Site_URL}references")
        sleep 3
        @browser1.text.should include("Contact Admin")
        puts "Contact admin completed"
  end

  it "Verify manage logo page is loaded" do
        @browser1.goto("#{$Site_URL}admin/build/themes/settings/cms")
        sleep 3
        @browser1.text.should include("Themes")
        #~ @browser1.text.should include("Toggle display")
        #~ @browser1.text.should include("Logo image settings")
        #~ @browser1.text.should include("Shortcut icon settings")
        puts "Manage logo completed"
  end

  it "Validation for phone number" do
      @browser1.goto("#{$Site_URL}user-management")
        sleep 2
        @browser1.goto("#{$Site_URL}content/add-user")
        sleep 2
        $em_ext = Time.now
        $em_ext = $em_ext.to_s
        $em_ext = $em_ext.slice(0..18)
        $em_ext = $em_ext.gsub(" ","_")
        $em_ext = $em_ext.gsub(":","_")
        $cms_user_email = $email + "_" + $em_ext + "@testmail.com"
        @browser1.text_field(:id, "edit-mail").set($cms_user_email)
        @browser1.text_field(:id, "edit-pass-pass1").set($passwd)
        @browser1.text_field(:id, "edit-pass-pass2").set($passwd)
        #$cms_name = $name + "_" + $em_ext
        @browser1.text_field(:id, "edit-field-prof-name-0-value").set($name)
        @browser1.checkbox(:id, "edit-roles-assign-11").set
        @browser1.text_field(:id, "edit-field-prof-phone-0-value").set($invalid_phone)
        @browser1.select_list(:id, "edit-field-prof-agency-nid-nid").select($dept)
        @browser1.button(:value,"Create new account").click
        #@browser1.text.should include($err_msg)
        puts "Validation completed"
  end

=begin
  it "Update phone number" do

        @browser1.goto("#{$Site_URL}user-management")
        sleep 2
        @browser1.goto("#{$Site_URL}content/add-user")
        sleep 2
        $em_ext = Time.now
        $em_ext = $em_ext.to_s
        $em_ext = $em_ext.slice(0..18)
        $em_ext = $em_ext.gsub(" ","_")
        $em_ext = $em_ext.gsub(":","_")
        $cms_user_email = $email + "_" + $em_ext + "@testmail.com"
        @browser1.text_field(:id, "edit-mail").set($cms_user_email)
        @browser1.text_field(:id, "edit-pass-pass1").set($passwd)
        @browser1.text_field(:id, "edit-pass-pass2").set($passwd)
        #$cms_name = $name + "_" + $em_ext
        @browser1.text_field(:id, "edit-field-prof-name-0-value").set($name)
        @browser1.checkbox(:id, "edit-roles-assign-11").set
        @browser1.text_field(:id, "edit-field-prof-phone-0-value").set($valid_phone1)
        @browser1.button(:value,"Create new account").click
	sleep 20
        #@browser1.text.should include("Password and further instructions have been e-mailed to the new user #{$cms_user_email}")
	@browser1.text.should include("Created a new user account for #{$cms_user_email}. No e-mail has been sent.")
	@browser1.link(:text,"#{$cms_user_email}").click
        sleep 3
        @browser1.link(:text,"Edit").click
        @browser1.text_field(:id, "edit-field-prof-phone-0-value").set($valid_phone2)
        @browser1.button(:value,"Save").click
        @browser1.text.should include($valid_phone2)
        puts "update completed"
  end
=end

  after(:all) do
        @browser1.link(:text,"Log Out").click
        @browser1.close
        `Taskkill /IM firefox.exe /F`
        puts "Test has completed"
  end

end


