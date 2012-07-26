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
require 'InputRepository/Test_06_Metrics_sites_input.rb'
require 'InputRepository/Config.rb'



describe "Verify Navigation to Metrics Menu" do
  before(:all) do
      `Taskkill /IM firefox.exe /F`
      driver = Selenium::WebDriver.for :firefox
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}")
  end

  it "Successful navigation to Agency Publication" do
	  
	  @browser.link(:text, "Metrics").click
    sleep 3
	  @browser.text.should include('Agency Wise')
	  	  
    puts "AGENCY PUBLICATION NAVIGATION COMPLETED"
	
    end
    
    
  
  it "Successful navigation to Agency Publication Month Wise" do
	  
	@browser.goto("#{$Site_URL}agency-publications/month-wise")
	@browser.text.should include('Month Wise')
	@browser.text.should include('Total in the past 12 months')
	
	@browser.select_list(:id, "datasets-per-year").select("#{$year}")
	@browser.button(:value,"Submit").click
	@browser.text.should include("Total in #{$year}")
	
	puts "AGENCY PUBLICATION NAVIGATION TO MONTH WISE COMPLETED"
	
 end

		
	
 it "Successful Navigation to Agency Publication Category Wise" do
	 
	@browser.goto("#{$Site_URL}agency-publications/category-wise")
	
	@browser.select_list(:id, "selectyear").select("#{$current_year}")
	@browser.button(:value,"Submit").click
	
	@browser.select_list(:id, "selectyear").select("#{$year}")
	@browser.button(:value,"Submit").click
	@browser.text.should include('by Category')
	
	puts "AGENCY PUBLICATION NAVIGATION TO CATEGORY WISE COMPLETED"
end

it "Successful Navigation To High Value Dataset" do
	 
	@browser.goto("#{$Site_URL}agency-publications/high-value-dataset")
	
	@browser.text.should include('High Value Raw Datasets')
	@browser.text.should include('High Value Documents')
	@browser.text.should include('High Value Apps')
	@browser.text.should include('High Value Tools')
	@browser.text.should include('High Value Services')
	
	@browser.select_list(:id, "selectyear").select("#{$current_year}")
	@browser.select_list(:id, "agency").select(/General Services Department /)
	@browser.select_list(:id, "cat").select(/Geography and Environment /)
	
	@browser.button(:value,"Submit").click
	@browser.text.should include('High Value Raw Datasets')
	
	
	@browser.select_list(:id, "selectyear").select("#{$year}")
	@browser.select_list(:id, "agency").select(/Commerce Department /)
	@browser.select_list(:id, "cat").select(/Health and Nutrition /)
	
	@browser.button(:value,"Submit").click
	@browser.text.should include('High Value Documents')
	
	puts "AGENCY PUBLICATION NAVIGATION TO HIGH VALUE DATASET COMPLETED"
	
end

it "Successful Navigation To Suggested Datasets" do
	@browser.goto("#{$Site_URL}suggesteddatasets")
	@browser.text.should include('Agency Determination on Suggestions')
	
	@browser.goto("#{$Site_URL}suggested-datasets-list")
  sleep 3
	#@browser.body.should include('')
	
	puts "NAVIGATION TO SUGGESTED DATASETS COMPLETED"
	
end

it "Successful Navigation To Visitor Statistics" do
	@browser.goto("#{$Site_URL}visitorstats/daily-visitor-statistics")
	@browser.text.should include('Daily Visitor Statistics')
	
	@browser.goto("#{$Site_URL}visitorstats/monthly-visitor-statistics")
	@browser.text.should include('Monthly Visitor Statistics')
	
	puts "NAVIGATION TO VISITOR STATISTICS COMPLETED"

end

 after(:all) do
        @browser.close
        `Taskkill /IM firefox.exe /F`
        puts "Test has completed"
    end
end