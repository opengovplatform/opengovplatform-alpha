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
require 'InputRepository/Mail_Config.rb'


#system ("test.bat")

$wd=Dir.pwd

filepath = $wd+"/report_file_name.txt"
$file_1 = File.open(filepath)
$rep_fl_nm = $file_1.gets
    puts $rep_fl_nm
$file_1.close;
filename = $wd + "/" + $rep_fl_nm.chomp
puts filename

# Read a file and encode it into base64 format
filecontent = File.read(filename)
encodedcontent = [filecontent].pack("m")   # base64

filename = filename.sub(/^.+\//, "")
#filename = filename.sub("/","\\")

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
To: NIC QA Team
Subject: NIC Automation Report
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



$recipient_list.each do|d|
  puts d

		begin
			Net::SMTP.start("#{$mail_server}", "#{$port}","#{$mail_server}",
							"#{$user_name}", "#{$password}", :plain) do |smtp|
					smtp.sendmail(mailtext, "#{$from_alias}",
								  ["#{d}"])
		  end
		rescue Exception => e
		  print "Exception occured: " + e
		end
		sleep 3
end






