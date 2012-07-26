require 'rubygems'
#require 'watir'
require 'test/unit'
#Load WATIR
require 'fileutils'
# Load WIN32OLE library
require 'win32ole' 
require 'Win32API'
require 'net/smtp'
require 'fileutils'
require 'net/imap' 
require 'net/pop' 


system ("test.bat")

$wd=Dir.pwd
filename = $wd+"/Report.html"

# Read a file and encode it into base64 format
filecontent = File.read(filename)
encodedcontent = [filecontent].pack("m")   # base64

filename = filename.sub(/^.+\//, "")

marker = "AUNIQUEMARKER"

body =<<EOF
Hi All,

The automation suite has completed. Please find attached the results.

Thanks,
Test Automation team
EOF


#body = "Hi All,\n\nThe automation suite has completed. Please find attached the results.\n\nThanks,\nTest Automation team"


# Define the main headers.
part1 =<<EOF
From: QA Automation <test@test.com>
To: Gaurav Parrikar <gaurav_parrikar@persistent.co.in>; Priyanka_Khandeparkar<priyanka_khandeparkar@persistent.co.in>
Subject: SampleMarket Client Application Report
MIME-Version: 1.0
Content-Type: multipart/mixed; boundary=#{marker}
--#{marker}
EOF

# Define the message action
part2 =<<EOF
Content-Type: text/plain
Content-Transfer-Encoding:8bit
#{body}
--#{marker}
EOF

# Define the attachment section
part3 =<<EOF
Content-Type: multipart/mixed; name=\"#{filename}\"
Content-Transfer-Encoding:base64
Content-Disposition: attachment; filename="#{filename}"

#{encodedcontent}
--#{marker}--
EOF





mailtext = part1 + part2 + part3
# Let's put our code in safe area



begin 
    Net::SMTP.start('relay.jangosmtp.net',25,'relay.jangosmtp.net',
                    '','', :plain) do |smtp|
            smtp.sendmail(mailtext, 'test@test.com',
                          ['priyanka_khandeparkar@persistent.co.in'])
end
rescue Exception => e  
  print "Exception occured: " + e 
end  
sleep(2)

# Let's put our code in safe area
begin 
    Net::SMTP.start('relay.jangosmtp.net',25,'relay.jangosmtp.net',
                    '','', :plain) do |smtp|
            smtp.sendmail(mailtext, 'test@test.com',
                          ['gaurav_parrikar@persistent.co.in'])
end
rescue Exception => e  
  print "Exception occured: " + e 
end  
sleep(2)








