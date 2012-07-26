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
require 'InputRepository/Input_Year.rb'



describe "Navigate to Metrics Menu" do
  before(:all) do
      driver = Selenium::WebDriver.for :firefox
      @browser = Watir::Browser.new driver
      @browser.goto('http://203.199.26.72/dms/')
  end

  it "Successful navigation to Agency Publication" do
	  
	  @browser.link(:text, "Metrics").click
	  @browser.text.should include('Agency Wise')
	  	  
	puts "AGENCY PUBLICATION NAVIGATION COMPLETED"
	
    end
    
    
  
  it "Successful navigation to Agency Publication Month Wise" do
	  
	@browser.goto('http://203.199.26.72/dms/agency-publications/month-wise')
	@browser.text.should include('Month Wise')
	@browser.text.should include('Total in the past 12 months')
	
	@browser.select_list(:id, "datasets-per-year").select("#{$year}")
	@browser.button(:value,"Submit").click
	@browser.text.should include("Total in #{$year}")
	
	puts "AGENCY PUBLICATION NAVIGATION TO MONTH WISE COMPLETED"
	
 end

		
	
 it "Successful Navigation to Agency Publication Category Wise" do
	 
	@browser.goto('http://203.199.26.72/dms/agency-publications/category-wise')
	
	@browser.select_list(:id, "selectyear").select("#{$current_year}")
	@browser.button(:value,"Submit").click
	
	@browser.select_list(:id, "selectyear").select("#{$year}")
	@browser.button(:value,"Submit").click
	@browser.text.should include('by Category')
	
	puts "AGENCY PUBLICATION NAVIGATION TO CATEGORY WISE COMPLETED"
end

it "Successful Navigation To High Value Dataset" do
	 
	@browser.goto('http://203.199.26.72/dms/agency-publications/high-value-dataset')
	
	@browser.text.should include('High Value Raw Datasets')
	@browser.text.should include('High Value Documents')
	@browser.text.should include('High Value Apps')
	@browser.text.should include('High Value Tools')
	@browser.text.should include('High Value Services')
	
	@browser.select_list(:id, "selectyear").select("#{$current_year}")
	@browser.select_list(:id, "agency").select(/Forests and Mining/)
	
	@browser.select_list(:id, "cat").select(/Births, Deaths, Marriages, and Divorces/)
	
	@browser.button(:value,"Submit").click
	@browser.text.should include('High Value Raw Datasets')
	
	
	@browser.select_list(:id, "selectyear").select("#{$year}")
	@browser.select_list(:id, "agency").select(/Commerce Department/)
	
	@browser.select_list(:id, "cat").select(/Health and Nutrition/)
	
	@browser.button(:value,"Submit").click
	@browser.text.should include('High Value Documents')
	
	puts "AGENCY PUBLICATION NAVIGATION TO HIGH VALUE DATASET COMPLETED"
	
end

it "Successful Navigation To Suggested Datasets" do
	@browser.goto('http://203.199.26.72/dms/suggesteddatasets')
	@browser.text.should include('Agency Determinations Of Site Suggestion')
	
	@browser.goto('http://203.199.26.72/dms/suggested-datasets-list')
	@browser.text.should include('Valuable Suggestions/Ideas')
	
	puts "NAVIGATION TO SUGGESTED DATASETS COMPLETED"
	
end

it "Successful Navigation To Visitor Statistics" do
	@browser.goto('http://203.199.26.72/dms/visitorstats/daily-visitor-statistics')
	@browser.text.should include('Daily Visitor Statistics')
	
	@browser.goto('http://203.199.26.72/dms/visitorstats/monthly-visitor-statistics')
	@browser.text.should include('Monthly Visitor Statistics')
	
	puts "NAVIGATION TO VISITOR STATISTICS COMPLETED"

end

 after(:all) do
        @browser.close
        puts "Test has completed"
    end
end