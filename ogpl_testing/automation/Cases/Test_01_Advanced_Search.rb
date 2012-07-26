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
require 'InputRepository/Test_01_Advanced_search_Input.rb'

describe "To Verify Advanced Search on OGPL site" do
	
	before(:all) do
		driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
		@browser = Watir::Browser.new driver
		@browser.goto("#{$Site_URL}search/advancedsearch")
		sleep 10
	end
			it "To Search All of the words in Any part in the Page" do
				@browser.text_field(:id, "edit-all-words").set("#{$search_word}")
				#@browser.select_list(:id, "edit-all-words-options").select("in the title of the page")
				@browser.button(:id, "edit-submit").click
				sleep 20
				@browser.text.should include("#{$search_word}")
				
				sleep 10
				puts "Search done in any part in the page"
			end
			
			it "To search a word in the Title of the Page" do
				@browser.goto("#{$Site_URL}search/advancedsearch")
				sleep 14
				@browser.text_field(:id, "edit-all-words").set("#{$search_title}")
				@browser.select_list(:id, "edit-all-words-options").select("in the title of the page")
				@browser.button(:id, "edit-submit").click
				sleep 5
				@browser.text.should include("#{$search_title}")
				puts "Search title displayed"
				
				sleep 10
			end
			
			it "To search for Exact Phrase" do
				@browser.goto("#{$Site_URL}search/advancedsearch")
				sleep 10
				@browser.text_field(:id, "edit-exact-phrase").set("#{$search_phrase}")
				@browser.button(:id, "edit-submit").click
				sleep 10
				@browser.text.should include("#{$search_phrase}")
				
				puts "Exact Phrase in the page"
			end
				
				
			it "To search for Exact Phrase in the title of the Page" do
				
				@browser.goto("#{$Site_URL}search/advancedsearch")
				sleep 10
				@browser.text_field(:id, "edit-exact-phrase").set("#{$phrase_title}")
				@browser.select_list(:id, "edit-exact-phrase-options").select("in the title of the page")
				@browser.button(:id, "edit-submit").click
				sleep 10
				@browser.text.should include("#{$phrase_title}")
				
				puts "Exact Phrase in the title found"
			end
			
			it "To search Any Of These Words in any part of the page" do
				
				@browser.goto("#{$Site_URL}search/advancedsearch")
				sleep 10
				@browser.text_field(:id, "edit-any-words").set("#{$search_any_words}")
				@browser.button(:id, "edit-submit").click
				sleep 10
				@browser.text.should include("#{$search_any_words}")
				
				puts "Any of these words found"
			end
			
			it "To search Any Of These Words in title of the page" do
				
				@browser.goto("#{$Site_URL}search/advancedsearch")
				sleep 10
				@browser.text_field(:id, "edit-any-words").set("#{$search_word_title}")
				@browser.select_list(:id, "edit-any-words-options").select("in the title of the page")
				@browser.button(:id, "edit-submit").click
				sleep 10
				@browser.text.should include("#{$search_word_title}")
				
				puts "Any of these words found"
			end

			#~ it "To search none of these words in the Page" do
				#~ @browser.text_field(:id, "edit-all-words").set("#{$word1}")
				#~ @browser.text_field(:id, "edit-none-words").set("#{$word2}")
				#~ @browser.button(:id, "edit-submit").click
				#~ sleep 5
				#~ @browser.text.should_not include("#{$word2}")
				#~ #@browser.text.should include("#{$search_word}")
				#~ @browser.goto("#{$Site_URL}search/advancedsearch")
				#~ sleep 5
				#~ puts "None of these words found"
			#~ end
			
			#~ it "To search none of these words in the title" do
				#~ @browser.text_field(:id, "edit-all-words").set("#{$word1}")
				#~ @browser.text_field(:id, "edit-none-words").set("#{$word2}")
				#~ @browser.select_list(:id, "edit-none-words-options").select("in the title of the page")
				#~ @browser.button(:id, "edit-submit").click
				#~ @browser.text.should_not include("#{$word2}")
				#~ #@browser.text.should include("#{$search_word}")
				#~ @browser.goto("#{$Site_URL}search/advancedsearch")
				#~ sleep 5
				#~ puts "None of these words found"
			#~ end
			
			it "To search Results per page in any file" do
				@browser.goto("#{$Site_URL}search/advancedsearch")
				sleep 10
				@browser.text_field(:name, "any_words").set("#{$search_any_words}")
				#@browser.select_list(:name, "file_type").select("#{$file_type}")
				@browser.select_list(:id, "edit-results-per-page").select("#{$results_per_page}")
				@browser.button(:id, "edit-submit").click
				sleep 10
				@browser.text.should include("#{$search_any_words}")
				puts "Results found"
			end


		after(:all) do
			@browser.close
			`Taskkill /IM firefox.exe /F`
			puts "Test has completed"
			
		end
end