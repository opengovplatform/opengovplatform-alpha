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
require 'lib/NIC_Lib.rb'
require 'InputRepository/Config.rb'
require 'InputRepository/Test_26_VRM_Mange_delaytime_Input.rb'



describe "Manage Delay Time in VRM" do

	before(:all) do
      `Taskkill /IM firefox.exe /F`
			$obj=NIC_Lib.new
			@browser=$obj.CMS_login($VRM_Admin_User_Email,$VRM_Admin_User_Passwd)
	end
	
		it "To navigate to Manage Delay Time tab" do
			@browser.link(:text, "Manage Delay Time").click
			sleep 10
			@browser.text.should include("Manage Delay Time")
		end

		it "To enter Default Delay time" do
			@browser.text_field(:name, "default_delay_time").set("#{$delay_time}")
			@browser.button(:value, "Update").click
			sleep 15
			@browser.text.should include("Manage Delay Time")
		end	

	after(:all) do
		@browser.close
		`Taskkill /IM firefox.exe /F`
		puts "Test has completed"
	end

end