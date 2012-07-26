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
require 'lib/NIC_Lib'
require 'InputRepository/Test_22_ContactUS_Form_Workflow_Input.rb'
require 'InputRepository/Config.rb'
#include 'Suite'
#PRE REQUISITES :-
#Login Credentials, Project Creation data

describe "Submit Contact us form and VRM workflow" do
  
  before(:all) do
      `Taskkill /IM firefox.exe /F`
      driver = Selenium::WebDriver.for :firefox, :profile => "Selenium"
      @browser = Watir::Browser.new driver
      @browser.goto("#{$Site_URL}contactus")
      $obj = NIC_Lib.new
      @browser1 = $obj.CMS_login($VRM_Admin_User_Email, $VRM_Admin_User_Passwd)
      $obj = NIC_Lib.new
      @browser2 = $obj.CMS_login($VRM_PMO_User_Email, $VRM_PMO_User_Passwd)
      $obj = NIC_Lib.new
      @browser3 = $obj.CMS_login($VRM_POC_User_Email, $VRM_POC_User_Passwd)
      
    end


    it "Submit a blank form" do
      @browser.button(:value,"Submit").click
      sleep 10
      @browser.text.should include('Your Name field is required.')
      @browser.text.should include('Subject field is required.')
      @browser.text.should include('Message field is required.')
    end
    
    it "Submit form with Invalid E-mail ID" do
      $ext = Time.now
      $ext = $ext.to_s
      $ext = $ext.slice(0..18)
      $ext = $ext.gsub(" ", "_")
      $Name_title = "#{$Name}" + "_" + "#{$ext}"


      @browser.text_field(:id, "edit-field-sender-name-0-value").set("#{$Name_title}") 
      @browser.text_field(:id, "edit-field-email-0-email").set("#{$Invaild_E_Mail}") 
      @browser.text_field(:id, "edit-field-feedback-subject-0-value").set("#{$Subject}")
      @browser.text_field(:id, "edit-field-feedback-body-0-value").set("#{$Message}") 
      @browser.button(:value,"Submit").click
      sleep 10
      @browser.text.should include("Please enter a valid email id in Your E-mail Address field eg. sam@xyz.com")
            
      @browser.text_field(:id, "edit-field-email-0-email").clear
      end
    
    it "Submit form with Valid Data" do
      @browser.text_field(:id, "edit-field-email-0-email").set("#{$Vaild_E_Mail}") 
      @browser.select_list(:id, "edit-field-category-value").select("Tools") 
      @browser.button(:value,"Submit").click
      sleep 8
      @browser.text.should include('Thank you for your comment/question on OGPL')
    end
 

#LOGIN TO VRM AS ADMIN AND ASSIGN THE DETILAS TO PMO
    
    it "To go to all page and check if details are available" do
      @browser1.text.should include("VRM")
      puts "VRM User Logged in Successfully"
      @browser1.refresh
      @browser1.link(:text, "All").click
      sleep 10
      @browser1.text.should include("#{$Name_title}") 
    end 

  
    it "To go to the Feedback Details_View" do
      
      @browser1.link(:text, "View").click
      sleep 10
      #@browser1.text.should include("#{$Name_title}") 
      #@browser1.text.should include("Opened")
    end   
    
           
       
      it "To click on Move to assign with out adding details" do
      @browser1.link(:text, "Edit").click
      sleep 5
      @browser1.button(:value,"Move to \"Assigned\"").click
      sleep 5
      @browser1.text.should include('Please choose an option for field Assign To')
    end
    
    
    it "To edit details" do
        @browser1.select_list(:id, "edit-field-category-value").select("Apps")
        #@browser1.select_list(:id, "edit-field-action-status-value").select("*")
        @browser1.checkbox(:id, "edit-field-feedback-type-value-16").set
        @browser1.select_list(:id, "edit-field-assigned-to-uid-uid").select("#{$VRM_PMO_User_Email}")
        @browser1.text_field(:id, "edit-field-delay-time-0-value").set("15")
        @browser1.button(:value,"Move to \"Assigned\"").click
           sleep 10
           @browser1.text.should include("#{$Name_title}") 
           @browser1.text.should include("Assigned") 
                     
    end
                   
    it "To check if the details are assigned to PMO" do
      #@browser2.text.should include("Welcome to Open Government Platform (OGPL)")
      puts "VRM_PMO User Logged in Successfully"
      @browser2.refresh
      @browser2.link(:text, "VRM").click
      sleep 10
      @browser2.link(:text, "View").click
      sleep 10
      #@browser2.text.should include("Feedback Details") 
    end 
    
    
    
       it "To add a note to feed back" do
         @browser2.link(:text, "Notes").click
         sleep 10
         #@browser2.text.should include("Feedback Details") 
         @browser2.button(:value,"Submit").click
         sleep 10
          @browser2.text.should include("Add Note: field is required.") 
          @browser2.text_field(:id,"edit-comment").set("#{$Add_Note}")
          @browser2.button(:value,"Clear").click
          @browser2.text_field(:id,"edit-comment").set("#{$Add_Note}")
          @browser2.button(:value,"Submit").click
          sleep 10
          #@browser2.text.should include("#{$Add_Note}") 
        end
    
    it "To Forward the details"do 
      @browser2.link(:text, "Edit").click
      sleep 10 
      @browser2.link(:text, "Forward").click
      sleep 10
      @browser2.select_list(:id, "edit-POC").select("#{$VRM_POC_User_Email}")
      @browser2.text_field(:id, "edit-and-emails").set("#{$User_Defined_Email}")
      @browser2.text_field(:id, "edit-fld-subject").set("#{$Subject}")
      @browser2.text_field(:id, "edit-txt-message").set("#{$Comment}")
      @browser2.button(:value,"Submit").click
      sleep 10
      #@browser2.text.should include("Feedback Details Edit") 
    end
    
    
    #NEED TO ADD A BLOCK TO VERIFY IF THE MAIL IS FORWAREDED TO CONCERN PERSON
    
     it "To reply to the details"do 
      @browser2.link(:text, "Reply").click
      sleep 10
      @browser2.text_field(:id, "edit-title").set("#{$Subject}")
      @browser2.select_list(:id, "pre_configured_text_select").select("Apps")
      @browser2.text_field(:id, "edit-field-feedback-reply-body-0-value").clear
      @browser2.text_field(:id, "edit-field-feedback-reply-body-0-value").set("#{$Comment}")
      @browser2.button(:value,"Submit").click
      sleep 10
    end
    
    #NEED TO ADD A BLOCK TO VERIFY IF THE E-MAIL IS REPLIED TO CONCERN PERSON
    
          
     #TO ARCHIVE AND ASSIGN BACK THE FEEDBACK
       
      it "To Archive the feedback" do
      @browser1.refresh  
      @browser1.link(:text, "Edit").click
      sleep 5
      @browser1.text.should include("Assigned")
      @browser1.button(:text,"Move to \"Archived\"").click
      sleep 15
      #@browser1.text.should include("#{$Name_title}") 
      
      
    end
    
         it "To Assign back to PMO" do
        @browser1.refresh 
        @browser1.link(:text, "Edit").click  
        sleep 10
        @browser1.select_list(:id, "edit-field-assigned-to-uid-uid").select("#{$VRM_PMO_User_Email}")
        @browser1.button(:text,"Move to \"Assigned\"").click
        sleep 10
        @browser1.text.should include("#{$Name_title}") 
        @browser1.text.should include("Assigned")        
                     
    end
         
         it "To revert back to VRM Admin" do
           @browser2.refresh
           @browser2.link(:text, "Edit").click 
           sleep 10
           @browser2.button(:text,'Move to "Reverted"').click
           sleep 5
          
         end
         
         
         it "To edit details and assign to POC" do
        @browser1.refresh  
        @browser1.link(:text, "Edit").click
        sleep 5
        @browser1.select_list(:id, "edit-field-assigned-to-uid-uid").select("#{$VRM_POC_User_Email}")
        @browser1.button(:text,"Move to \"Assigned\"").click
           sleep 8
           @browser1.text.should include("#{$Name_title}") 
           @browser1.text.should include("Assigned") 
                     
    end
                           
    it "To check if the details are assigned to POC" do
      #@browser3.text.should include("Welcome to Open Government Platform (OGPL)")
      puts "VRM_POC User Logged in Successfully"
      @browser3.refresh
      @browser3.link(:text, "VRM").click
      sleep 10
      @browser3.link(:text, "View").click
      sleep 15
      
      @browser3.text.should include("Assigned") 
    end 
    
    
       it "To add a note to feed back" do
         @browser3.link(:text, "Notes").click
         sleep 5
         @browser3.button(:value,"Submit").click
         sleep 5
          @browser3.text.should include("Add Note: field is required.") 
          @browser3.text_field(:id,"edit-comment").set("#{$Add_Note}")
          @browser3.button(:value,"Clear").click
          @browser3.text_field(:id,"edit-comment").set("#{$Add_Note}")
          @browser3.button(:value,"Submit").click
          sleep 10
          #@browser3.text.should include("#{$Add_Note}") 
        end
        
        
    it "To Forward the details"do 
      @browser3.link(:text, "Edit").click
      sleep 10 
      @browser3.link(:text, "Forward").click
      sleep 10
      @browser3.select_list(:id, "edit-PMO").select("#{$VRM_PMO_User_Email}")
      @browser3.text_field(:id, "edit-and-emails").set("#{$User_Defined_Email}")
      @browser3.text_field(:id, "edit-fld-subject").set("#{$Subject}")
      @browser3.text_field(:id, "edit-txt-message").set("#{$Comment}")
      @browser3.button(:value,"Submit").click
      sleep 10
      #@browser3.text.should include("Feedback Details Edit") 
    end
    
    
    #NEED TO ADD A BLOCK TO VERIFY IF THE MAIL IS FORWAREDED TO CONCERN PERSON
    
     it "To reply to the details"do 
      @browser3.link(:text, "Reply").click
      sleep 10
      @browser3.text_field(:id, "edit-title").set("#{$Subject}")
      @browser3.select_list(:id, "pre_configured_text_select").select("Apps")
      @browser3.text_field(:id, "edit-field-feedback-reply-body-0-value").clear
      @browser3.text_field(:id, "edit-field-feedback-reply-body-0-value").set("#{$Comment}")
      @browser3.button(:value,"Submit").click
      sleep 10
      #@browser3.text.should include("#{$Name_title}") 
      #@browser3.text.should include("Replied")
    end
    
    #NEED TO ADD A BLOCK TO VERIFY IF THE E-MAIL IS REPLIED TO CONCERN PERSON
    
          
     #TO ARCHIVE AND ASSIGN BACK THE FEEDBACK
       
      it "To Archive the feedback" do
      @browser1.refresh  
      @browser1.link(:text, "Edit").click
      sleep 5
      @browser1.button(:text,"Move to \"Archived\"").click
      sleep 5 
      #@browser1.text.should include("#{$Name_title}") 
      #@browser1.text.should include("Archived")
    end
    
         it "To Assign back to POC" do
        @browser1.link(:text, "Edit").click  
        sleep 10
        @browser1.button(:text,"Move to \"Assigned\"").click
        sleep 15
        @browser1.text.should include("#{$Name_title}") 
        @browser1.text.should include("Assigned") 
                     
    end
         
         it "To revert back to VRM Admin" do
           @browser3.refresh
           @browser3.link(:text, "Edit").click 
           sleep 10
           @browser3.button(:text,'Move to "Reverted"').click
           sleep 10
                     
         end
         
         
       it "To Assign the feedback" do
      @browser1.refresh  
      @browser1.link(:text, "Edit").click
      sleep 5
      @browser1.text.should include("Assigned") 
      @browser1.select_list(:id, "edit-field-assigned-to-uid-uid").select("#{$VRM_POC_User_Email}")
      @browser1.button(:text,"Move to \"Assigned\"").click
      sleep 5 
      #@browser1.text.should include("#{$Name_title}") 
      #@browser1.text.should include("Assigned") 
        
      end
      
       
         
     it "To reply to the details"do 
      @browser3.refresh  
      @browser3.link(:text, "Edit").click
      sleep 5
      @browser3.link(:text, "Reply").click
      sleep 5
      @browser3.text_field(:id, "edit-title").set("#{$Subject}")
      @browser3.select_list(:id, "pre_configured_text_select").select("Apps")
      @browser3.text_field(:id, "edit-field-feedback-reply-body-0-value").clear
      @browser3.text_field(:id, "edit-field-feedback-reply-body-0-value").set("#{$Comment}")
      @browser3.button(:value,"Submit").click
      sleep 10
      #@browser3.text.should include("#{$Name_title}") 
    end
    
                   
         it "To Close the feedback" do
      @browser1.refresh  
      @browser1.link(:text, "Edit").click
      sleep 5
      @browser1.button(:text,"Move to \"Closed\"").click
      sleep 5 
      end
    #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
      
   
    it "Submit a Contact US form without Email for PMO Review" do
      @browser.goto("#{$Site_URL}/contactus")
      sleep 10
      $ext = Time.now
      $ext = $ext.to_s
      $ext = $ext.slice(0..18)
      $ext = $ext.gsub(" ", "_")
      $Name_title = "#{$Name}" + "_" + "#{$ext}"


      @browser.text_field(:id, "edit-field-sender-name-0-value").set("#{$Name_title}") 
      @browser.text_field(:id, "edit-field-feedback-subject-0-value").set("#{$Subject}")
      @browser.text_field(:id, "edit-field-feedback-body-0-value").set("#{$Message}") 
      @browser.button(:value,"Submit").click
      sleep 5
      #@browser.text.should include('Thank you for your comment/question on OGPL,India.')
   
      ###########################################################
      @browser1.refresh
      @browser1.link(:text, "Home").click
   sleep 5
      @browser1.link(:text, "All").click
   sleep 5
      @browser1.text.should include("#{$Name_title}") 
      @browser1.link(:text, "Edit").click
   sleep 5
      @browser1.select_list(:id, "edit-field-category-value").select("Apps")
      #@browser1.select_list(:id, "edit-field-action-status-value").select("Actionable")
      @browser1.checkbox(:id, "edit-field-feedback-type-value-16").set
      @browser1.select_list(:id, "edit-field-assigned-to-uid-uid").select("#{$VRM_PMO_User_Email}")
      @browser1.text_field(:id, "edit-field-delay-time-0-value").set("15")
      @browser1.button(:value,'Move to "Assigned"').click
      sleep 10
      #@browser1.text.should include("#{$Name_title}") 
      ############################################################
       puts "VRM_PMO User Logged in Successfully"
      @browser2.refresh
      @browser2.link(:text, "VRM").click
   sleep 5
      @browser2.link(:text, "View").click
   sleep 5
      @browser2.link(:text, "Edit").click
      #@browser2.text.should include("#{$Name_title}") 
   sleep 5
      @browser2.link(:text, "Review").click
   sleep 5
      @browser2.text_field(:name, "field_feedback_review_body[0][value]").set("#{$Comment}")
      @browser2.button(:value,"Submit").click
   sleep 5
      #@browser2.text.should include("#{$Name_title}") 
      #@browser2.text.should include("Reviewed") 
      #######################################################
      
      end
    
     
    it "Submit a Contact US form without Email for POC Review" do
      @browser.goto("#{$Site_URL}/contactus")
   sleep 5
      $ext = Time.now
      $ext = $ext.to_s
      $ext = $ext.slice(0..18)
      $ext = $ext.gsub(" ", "_")
      $Name_title = "#{$Name}" + "_" + "#{$ext}"


      @browser.text_field(:id, "edit-field-sender-name-0-value").set("#{$Name_title}") 
      @browser.text_field(:id, "edit-field-feedback-subject-0-value").set("#{$Subject}")
      @browser.text_field(:id, "edit-field-feedback-body-0-value").set("#{$Message}") 
      @browser.button(:value,"Submit").click
      sleep 10
      @browser.text.should include('Thank you for your comment/question on OGPL')
   sleep 5
      ###########################################################
      @browser1.refresh
      @browser1.link(:text, "Home").click
   sleep 5
      @browser1.link(:text, "All").click
   sleep 5
     @browser1.link(:text, "Edit").click
     #@browser1.text.should include("#{$Name_title}")  
   sleep 5
      @browser1.select_list(:id, "edit-field-category-value").select("Apps")
      #@browser1.select_list(:id, "edit-field-action-status-value").select("Actionable")
      @browser1.checkbox(:id, "edit-field-feedback-type-value-16").set
      @browser1.select_list(:id, "edit-field-assigned-to-uid-uid").select("#{$VRM_POC_User_Email}")
      @browser1.text_field(:id, "edit-field-delay-time-0-value").set("15")
      @browser1.button(:value,'Move to "Assigned"').click
      sleep 10
      #@browser1.text.should include("#{$Name_title}") 
      ############################################################
      @browser3.text.should include("VRM")
      puts "VRM_POC User Logged in Successfully"
      @browser3.refresh
      @browser3.link(:text, "VRM").click
      sleep 5
      @browser3.link(:text, "View").click
      sleep 10
      @browser3.link(:text, "Edit").click
      sleep 5
      @browser3.link(:text, "Review").click
      sleep 5
      @browser3.text_field(:name, "field_feedback_review_body[0][value]").set("#{$Comment}")
      @browser3.button(:value,"Submit").click
      sleep 5
      #@browser3.text.should include("#{$Name_title}") 
      #@browser3.text.should include("Reviewed") 
      #######################################################
      end
    
    
     it "To move to Irrelevant state" do
      @browser.goto("#{$Site_URL}/contactus")
      $ext = Time.now
      $ext = $ext.to_s
      $ext = $ext.slice(0..18)
      $ext = $ext.gsub(" ", "_")
      $Name_title = "#{$Name}" + "_" + "#{$ext}"


      @browser.text_field(:id, "edit-field-sender-name-0-value").set("#{$Name_title}") 
      @browser.text_field(:id, "edit-field-email-0-email").set("#{$Invaild_E_Mail}") 
      @browser.text_field(:id, "edit-field-feedback-subject-0-value").set("#{$Subject}")
      @browser.text_field(:id, "edit-field-feedback-body-0-value").set("#{$Message}") 
      @browser.button(:value,"Submit").click
      sleep 10
      @browser.text.should include('Please enter a valid email id in Your E-mail Address field eg. sam@xyz.com')
            
      @browser.text_field(:id, "edit-field-email-0-email").clear
     
    
      @browser.text_field(:id, "edit-field-email-0-email").set("#{$Vaild_E_Mail}") 
      @browser.select_list(:id, "edit-field-category-value").select("Tools") 
      @browser.button(:value,"Submit").click
      sleep 8
      @browser.text.should include('Thank you for your comment/question on OGPL')
     

#LOGIN TO VRM AS ADMIN AND ASSIGN THE DETILAS TO PMO
    
   
   
      puts "VRM User Logged in Successfully"
      @browser1.refresh
      @browser1.link(:text, "Home").click
      sleep 10
      @browser1.link(:text, "All").click
      sleep 10
      @browser1.text.should include("#{$Name_title}") 
          
      @browser1.link(:text, "View").click
      sleep 10
      @browser1.text.should include("#{$Name_title}") 
      @browser1.text.should include("Opened")
    
      @browser1.link(:text, "Edit").click
      sleep 5
      @browser1.button(:value,'Move to "Irrelevant"').click
      #@browser1.text.should include("Irrelevant")
     @browser1.refresh
      @browser1.link(:text, "Home").click
   sleep 5
      @browser1.link(:text, "All").click
   sleep 5
            @browser1.link(:text, "Irrelevant").click
            end
    #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


 after(:all) do
	@browser.close
	@browser1.close
  @browser2.close
  @browser3.close
  `Taskkill /IM firefox.exe /F`
	puts "Test has completed"
end


end