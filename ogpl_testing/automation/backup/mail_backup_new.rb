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


#system ("test.bat")

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
From: QA Automation <test@nic_automation.com>
To: Gaurav Parrikar <gaurav_parrikar@persistent.co.in>; Priyanka_Khandeparkar<priyanka_khandeparkar@persistent.co.in>;Gautam Wagh<gautam_wagh@persistent.co.in>
Subject: NIC test auatomation Report
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


=begin

begin 
    Net::SMTP.start('relay.jangosmtp.net', 25,'relay.jangosmtp.net',
                    'qa_usamp', 'sampleu09!', :plain) do |smtp|
            smtp.sendmail(mailtext, 'USAMPQA@usamp.com',
                          ['vipul_paikane@persistent.co.in','rahul_halankar@persistent.co.in','nitin_kumar@persistent.co.in','gaurav_parrikar@persistent.co.in','mittal_saglani@persistent.co.in','maria_clemente@persistent.co.in','Akshata_Shanbhag@persistent.co.in','mangesh_naik@persistent.co.in','Rommel_Fernandes@persistent.co.in','suvina_dsouza@persistent.co.in','valencia_fernandes@persistent.co.in','Virej_Salker@persistent.co.in']) 
  end
rescue Exception => e  
  print "Exception occured: " + e 
end  


begin 
    Net::SMTP.start('relay.jangosmtp.net', 25,'relay.jangosmtp.net',
                    'qa_usamp', 'sampleu09!', :plain) do |smtp|
smtp.open_message_stream(from at example.com', ['to at example.com]) do |f|
f.puts 'From: from at example.com'
f.puts 'To: to at example.com'
f.puts 'Subject: test message'
f.puts
f.puts 'This is a test message.'
end
end
define("JANGOMAIL_USERNAME",'qa_usamp');
define("JANGOMAIL_PASSWORD",'sampleu09!');
public $Host        = 'relay.jangosmtp.net';
public $SMTPAuth     = true;
public $Username     = JANGOMAIL_USERNAME;
public $Password     = JANGOMAIL_PASSWORD;

    Net::SMTP.start('your.smtp.server', 25, 'mail.from.domain',
                    'Your Account', 'Your Password', :login)



=end
$em = ["rahul_halankar@persistent.co.in","gaurav_parrikar@persistent.co.in"]
#$server = 'relay.jangosmtp.net'
$server = 'gamail.persistent.co.in'
$port = '25'
$uname = 'gaurav_parrikar@persistent.co.in'
$pass = 'psl!2007'
$uname = ''
$pass = ''

$em.each do|d|
  puts d

		begin 
			Net::SMTP.start("#{$server}", "#{$port}","#{$server}",
							"#{$uname}", "#{$pass}", :plain) do |smtp|
					smtp.sendmail(mailtext, 'USAMPQA@usamp.com',
								  ["#{d}"])
		  end
		rescue Exception => e  
		  print "Exception occured: " + e 
		end
		sleep 3
end





