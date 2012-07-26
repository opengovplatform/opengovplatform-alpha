# ADVANCE WEBSITE CASES

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
require 'InputRepository/Test_28_Advance_website_cases_input.rb'
require 'InputRepository/Config.rb'
require 'lib/NIC_Lib.rb'
require 'yaml'

describe "Advance Website cases (Frontend)" do

  before(:all) do
      `Taskkill /IM firefox.exe /F`
      driver = Selenium::WebDriver.for :firefox
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}")

  end


  it "Verify that Site Development and hosting details logo exists" do
    sleep 10
      @browser.html.should include("#{$Site_URL}sites/all/themes/ogpl_css3/images/nic-footer-dummy.png")
      #@browser.html.should include("Site Development and hosting details")
      puts "Site Development and hosting details logo check completed"

  end

  it "Verify that Site ownership details comes here logo exists" do
    sleep 10
      @browser.html.should include("#{$Site_URL}sites/all/themes/ogpl_css3/images/nic-footer-dummy.png")
      #@browser.html.should include("Site ownership details comes here")
      puts "Site ownership details comes here logo check completed"

  end

  it "Verify Dataset and Apps Section on Home page" do
      @browser.text.should include("Interested #{$for} latest or most viewed Datasets?")
      @browser.text.should include("Interested #{$in} latest or most viewed Apps?")
      @browser.text.should_not include("Interested #{$in} latest or most viewed Datasets?")
      @browser.text.should_not include("Interested #{$for} latest or most viewed Apps?")
  end

  it "Check Recent Ideas section on home page" do
      #@browser.goto("#{$Site_URL}node/1532")
      @browser.link(:id, "stop").click
      sleep 3
      #@browser.link(:title, 'feedabck feedbacvk').click
      #@browser.div(:id, "fs2").link(:text,"feedabck feedbacvk").click   
	@browser.link(:xpath,"//*[@id='fs2']/ul/li[1]/a").click
	sleep 2
    @browser.title.should include("Feedback Details | Open Government Platform (OGPL)")
    @browser.text.should include("Feedback Details")
  end

=begin #this case is no longer valid
    it "Verify the count of input string in Tell a friend section" do
      sleep 5
      @browser.goto("#{$Site_URL}")
      @browser.link(:text, "Tell a Friend").click
      sleep 5
      @browser.text.should include("Tell A Friend")
      @browser.title.should include("Tell A Friend | Open Government Platform (OGPL)")
      @browser.text.should include("3000")
      @browser.text_field(:id, "edit-message").set("1")
      @browser.text.should include("2999")
      @browser.refresh
      @browser.text.should include("3000")
    end
=end

    it "Verify Image panel links on home page" do
      @browser.goto("#{$Site_URL}")
      @browser.image(:src=>"#{$Site_URL}sites/all/themes/ogpl_css3/images/img-learn.png").click
      sleep 5
      @browser.text.should include("Learn")
      @browser.title.should include("Learn | Open Government Platform (OGPL)")
    end

    it "Verify about us links on home page" do
      @browser.goto("#{$Site_URL}")
      @browser.link(:text, "About Us").click
      sleep 5
      @browser.title.should include("About Us | Open Government Platform (OGPL)")
      @browser.text.should include("About Us")
    end

    it "Verify Enable/Disable Read more links on home page" do
      @browser.goto("#{$Site_URL}")
      @browser.link(:text, "What's New").click
      sleep 5
      @browser.title.should include("What's New | Open Government Platform (OGPL)")
      @browser.text.should_not include("Warrning")
      @browser.text.should_not include("warrning")
      @browser.text.should include("Read More")
      end

    it "Verify Search and navigation to Contact data set" do
      @browser.goto("#{$Site_URL}")
      @browser.text_field(:name, "search_theme_form").set("test")
      #@browser.button(:id,"edit-submit-2").click
      @browser.button(:value,"Search").click
      sleep 5
      #@browser.title.should include("Search | Open Government Platform (OGPL)")
      project_name = File.open("InputRepository/projectname.yml"){|file| YAML::load(file)}
      project_name['project']
      @browser.link(:text, "#{$page_title}").click
      sleep 5
      @browser.title.should include("#{$page_title} | Open Government Platform (OGPL)")
      #@browser.text.should include("Contact Dataset Owner")
      #@browser.text.should include("3000")
    end

    

     it "Verify navigation to suggested apps link" do
       @browser.goto("#{$Site_URL}")
       sleep 5
       @browser.link(:text, "Suggested APPs...").click
       sleep 2
       @browser.title.should include("Suggested Apps | Open Government Platform (OGPL)")
       @browser.text.should include("Suggested Apps")
     end

     it "Verify Navigation to Suggested Datasets link" do
       @browser.goto("#{$Site_URL}")
       sleep 5
       @browser.link(:text, "Suggested Datasets...").click
       sleep 2
       @browser.title.should include("Suggested Datasets | Open Government Platform (OGPL)")
       @browser.text.should include("Suggested Datasets")
     end

=begin #skipped as this was no longer a requirement
     it "Verify Dataset and Apps Section" do
       @browser.goto("#{$Site_URL}")
       sleep 5
       @browser.text.should_not include("0 Raw Datasets")
       @browser.text.should_not include("0 High Value Datasets")
       @browser.text.should_not include("0 Agencies/Organizations Participating")
       @browser.text.should_not include("0 Apps")
       @browser.text.should_not include("0 Mobile Apps")
       @browser.text.should_not include("0 Agencies/Organizations participating ")
     end
=end

      it "Verify Open Data site" do
	@browser.goto("#{$Site_URL}")
	sleep 5
	@browser.link(:text, "WW Data Sites").click
       sleep 45
       @browser.title.should include("World Wide Data Sites | Open Government Platform (OGPL)")
       @browser.text.should include("World Wide Data Sites")
     end

      it "Verify navigations to all links on home page" do
        @browser.goto("#{$Site_URL}")
        @browser.link(:text, "Help").click
        sleep 5
       @browser.title.should include("Help | Open Government Platform (OGPL)")
       @browser.text.should include("Help")
       @browser.link(:text, "Sections of this Portal").click
       sleep 5
       @browser.title.should include("Help on Sections of this Portal | Open Government Platform (OGPL)")
       #@browser.text.should include("Help on Sections of this Portal")
	end
	
=begin # These are not links
	@browser.goto("#{$Site_URL}help")
       sleep 5
	@browser.link(:text, "Using the Search Facility").click
       sleep 5
       @browser.title.should include("Using the Search Facility | Open Government Platform (OGPL)")
       @browser.text.should include("Using the Search Facility")
       @browser.goto("#{$Site_URL}help")
       sleep 5
       @browser.link(:text, "Viewing Information in Various File Formats").click
       sleep 5
       @browser.title.should include("Viewing Information in Various File Formats | Open Government Platform (OGPL)")
       @browser.text.should include("Viewing Information in Various File Formats")
       @browser.goto("#{$Site_URL}help")
       sleep 5
       @browser.link(:text, "Screen Reader Access").click
       sleep 5
       @browser.title.should include("Screen Reader Access | Open Government Platform (OGPL)")
       @browser.text.should include("Screen Reader Access")
       
       @browser.goto("#{$Site_URL}help")
       sleep 5
       @browser.link(:text, "Provide Feedbacks").click
       sleep 5
       @browser.title.should include("Provide Feedbacks | Open Government Platform (OGPL)")
       @browser.text.should include("Provide Feedbacks")
       
       @browser.goto("#{$Site_URL}help")
       sleep 5
       @browser.link(:text, "Navigation Bar").click
       sleep 5
       @browser.title.should include("Navigation Bar | Open Government Platform (OGPL)")
       @browser.text.should include("Navigation Bar")
       
       @browser.goto("#{$Site_URL}help")
       sleep 5
       @browser.link(:text, "Viewing Information in Various File Formats").click
       sleep 5
       @browser.title.should include("Viewing Information in Various File Formats | Open Government Platform (OGPL)")
       @browser.text.should include("Viewing Information in Various File Formats")
       
       @browser.goto("#{$Site_URL}help")
       sleep 5
       @browser.link(:text, "Blocks on the Front Page").click
       sleep 5
       @browser.title.should include("Blocks on the Front Page | Open Government Platform (OGPL)")
       @browser.text.should include("Blocks on the Front Page")
       
        @browser.goto("#{$Site_URL}help")
       sleep 5
       @browser.link(:text, "Footer").click
       sleep 5
       @browser.title.should include("Footer | Open Government Platform (OGPL)")
       @browser.text.should include("Footer")
       end
=end


    it "Verify that Global Search result shouldn't display anything without entering any key in the search box." do
      @browser.goto("#{$Site_URL}")
      sleep 5
      @browser.button(:value,"Search").click
      #@browser.text.should_not include("#{$error_msg}")
      @browser.text_field(:id, "edit-keys").set("")
      sleep 5
      @browser.button(:id,"edit-submit").click
      @browser.text.should include("#{$error_msg}")
    end

=begin #This case is no longer required
    it "Verify navigation to Communities section" do
      @browser.goto("#{$Site_URL}")
      sleep 5
      @browser.button(:title,"Community - 1").click
      sleep 5
      @browser.title.should include("Community | Open Government Platform (OGPL)")
    end
=end    

  it "Verify the existence of Rotating panel on site" do
      @browser.goto("#{$Site_URL}")
      sleep 10
      #@browser.link(:id, "views_slideshow_singleframe_playpause_Rotating_Panel_Half-block_1").click
      @browser.link(:id, "views_slideshow_singleframe_playpause_Rotating_Panel-block_1").click
      sleep 5
      #@browser.image(:src=>"#{$Site_URL}system/files/imagecache/rotating_images_home_half/national-transport.png").click 
      @browser.image(:src=>"#{$Site_URL}system/files/imagecache/rotating_images_home/national-transport_0.png").click 
      sleep 10
      @browser.window(:title => "Federal Fleet Data | Open Government Platform (OGPL)").use 
      @browser.text.should include("Core metadata")
      @browser.text.should include("Access Type")
      @browser.text.should include("Catalog Type")
  end


  after(:all) do
        @browser.link(:text,"Log Out").click
        @browser.close
        `Taskkill /IM firefox.exe /F`
        puts "Test has completed"
end
end
