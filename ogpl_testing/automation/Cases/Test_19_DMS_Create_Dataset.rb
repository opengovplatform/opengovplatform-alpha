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
require 'InputRepository/Test_19_DMS_Create_Dataset_Input.rb'

describe "DMS Dataset Creation" do
	
  before(:all) do
      `Taskkill /IM firefox.exe /F`
	$obj = NIC_Lib.new
	@browser = $obj.CMS_login($DMS_Admin_Email, $DMS_Admin_Passwd)
	driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
		@browser1 = Watir::Browser.new driver
		@browser1.goto("#{$Site_URL}")
      sleep 10
  end
  
	it "To Navigate to the Create Content Dataset" do
		@browser.goto("#{$Site_URL}node/add/dataset")
		sleep 20
		@browser.text.should include("Dataset Workflow")
		@browser.text.should include("Create Dataset")
	end
	
	it "To Validate Save Blank Dataset form" do 
		@browser.button(:value, "Save Progress").click
		sleep 5
		@browser.text.should include("Title field is required.")
		@browser.text.should include("Description field is required.")
		@browser.text.should include("Contact Person (Name) field is required.")
		@browser.text.should include("Contact Person Title field is required.")
		@browser.text.should include("Contact Person Office Address field is required.")
		@browser.text.should include("Contact Person Phone Number field is required.")
		@browser.text.should include("Contact Person Email Address field is required.")
		@browser.text.should include("Sector field is required.")
		#@browser.text.should include("Sub-Sector field is required.")
		@browser.text.should include("Keywords field is required.")
		@browser.text.should include("URL field is required.")
		@browser.text.should include("URL field is required.")
		puts "*******Validations done"
	end
	
	
	it "To Submit Dataset form with Required details only" do
		$ext = Time.now
		$ext = $ext.to_s
		$ext = $ext.slice(0..18)
		$ext = $ext.gsub(" ", "_")
		$input_title = "#{$dataset_title}" + "_" + "#{$ext}"
		@browser.text_field(:id, "edit-field-ds-title-0-value").set("#{$input_title}")
		#@browser.frame(:title => 'Rich Text AreaPress ALT-F10 for toolbar. Press ALT-0 for help').send_keys("#{$description}")
		@browser.textarea(:id, "edit-field-ds-description-0-value").set("#{$description}")
		puts "description added"
		#~ @browser.select_list(:id, "edit-field-ds-sub-agency-nid-nid").set("general services")
		#~ puts "agency_name added"
		@browser.text_field(:id, "edit-field-ds-contact-name-0-value").set("#{$contact_person_name}")
		puts "contact_person_name"
		@browser.text_field(:id, "edit-field-ds-contact-title-0-value").set("#{$contact_person_title}")
		puts "contact_person_title"
		@browser.text_field(:id, "edit-field-ds-office-address-0-value").set("#{$contact_person_office_address}")
		puts "contact_person_office"
		@browser.text_field(:id, "edit-field-ds-contact-phone-number-0-value").set("#{$contact_person_phone}")
		puts "contact_person_phone"
		@browser.text_field(:id, "edit-field-ds-email-address-0-email").set("#{$contact_person_email}")
		puts "contact_person_email"
		@browser.select_list(:name, "field_ds_sector[nid][nid][]").select("#{$sector}")
		puts "sector added"
		#~ @browser.text_field(:name, "field_ds_sub_sector[0][value]").set("#{$sub_sector}")
		#~ puts "sub-sector added"
		@browser.text_field(:name, "field_ds_keywords[0][value]").set("#{$keywords}")
		puts "keywords added"
		@browser.text_field(:name, "field_ds_date_released[0][value][date]").set("#{$date}")
		puts "date added"
		@browser.text_field(:name, "field_ds_access_url[0][url]").set("#{$access_url}")
		puts "access url added"
		@browser.text_field(:name, "field_ds_reference_url[0][url]").set("#{$ref_url}")
		puts "ref-url added"
		@browser.select_list(:name, "field_ds_dataset_license[value]").select("#{$license_value}")
		puts "license added"
		@browser.button(:value, "Save and Continue >").click
		sleep 5
		#@browser.text.should include("Dataset" + "#{$input_title}" + "_" + "has been created.")
		@browser.text.should include("#{$input_title}")		
		puts "******Dataset created successfully"
	end
	
	
	#~ #it "To Submit form with Invalid Email address" do
	
		#~ @browser.text_field(:name, "field_ds_email_address[0][email]").set("#{$invalid_email}")
		#~ @browser.button(:value, "Save and Continue").click
		#~ @browser.text.should include("The value in Contact Person Email Address is not a valid email address.")
		#~ sleep 5
	#~ end
	
	it "To publish the dataset created" do
		sleep 10
		@browser.link(:id, "multistep-dataset-5").click
		@browser.radio(:id, "edit-workflow-10").set
		@browser.button(:value, "Finish").click
		@browser.text.should include("#{$input_title}")
		puts "******Dataset Published"
		sleep 10
		
	end
	
	it "To log out from DMS site" do
		@browser.link(:text, "Log Out").click
		sleep 10
		@browser.text.should include("User Login")
		puts "logged out successfully"
	end
	
	it "To View newly added Dataset in the Metrics Report" do
		#@browser1.refresh
		sleep 20
		@browser1.goto("#{$Site_URL}visitorstats/daily-visitor-statistics")
		sleep 10
		@browser1.text.should include("Daily Visitor Statistics")
		@browser1.goto("#{$Site_URL}visitorstats/top10datasetreport/MostdownloadedAllTime")
		sleep 5
		@browser1.text.should include("Most Downloaded 10 Datasets")
		@browser1.select_list(:id, "Top10DatasetReportType").select(/Most Recently Added 10 Datasets/)
		@browser1.button(:id, "submit_btn").click
		sleep 5
		@browser1.text.should include("Most Recently Added 10 Datasets")
		@browser1.text.should include("#{$input_title}")
		puts "******Dataset has been added "
		sleep 5
	end
	
	it "To View newly added Dataset on What's New tab" do
		@browser1.link(:text, "What's New").click
		sleep 10
		@browser1.text.should include("What's New")
		@browser1.goto("#{$Site_URL}new/7")
		sleep 10
		@browser1.text.should include("Latest Datasets In Last 7 Days")
		@browser1.text.should include("#{$input_title}")
		puts "*****Dataset added on What's new tab"
		sleep 5
	end
		
 after(:all) do
	@browser.close
	@browser1.close
  `Taskkill /IM firefox.exe /F`
	puts "Test has completed"
end

end


