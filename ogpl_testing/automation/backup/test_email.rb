require 'rubygems'
require 'watir'
require 'firewatir'
require 'Usamp_lib'
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



$em = 'rahul_halankar@persistent.co.in'

$wd=Dir.pwd
$out_fl_path = $wd+"/Output Repository/Non4S_Test_Report.html"
$output_path = $out_fl_path

$myfile = File.open($out_fl_path, 'a');
$myfile.print "</tr></table></center></body></html>";
$myfile.close;


filename = $wd+"/Output Repository/Non4S_Test_Report.html"

ie = Watir::IE.new
#ie = FireWatir::Firefox.new
ie.goto("file:///"+filename)


    html_text = ie.html
    $html_contents=ie.html
    #puts $html_contents
    $html_array = $html_contents.split(/\n/)
    #puts $html_array
	0.upto($html_array.size - 1) { |index|
    if($html_array[index] =~ /TEST [A-Z]+ED/)
    #if($html_array[index].contains_text("TEST"))
    puts "***"
    puts $html_array[index]
    #sleep 1
    #puts $html_array[index-1]
    puts "***"
    $html_array[index].scan(/[A-Za-z]+</){
    if ($html_array[index] =~ /TEST PASSED/)
    $pass=$pass.to_i+1
    puts $pass
    puts "***"
    #sleep 1
    else
    if ($html_array[index] =~ /TEST FAILED/)
    $fail=$fail.to_i+1
    puts $fail
    puts "***"
    #sleep 1
    end
    end
    }
    next
    else
    next
    end
                                                
}
                                          
                                          0.upto($html_array.size - 1) { |index|
                                            if($html_array[index] =~ /NOT COMPLETED [A-Z]+LY/)
                                            #if($html_array[index].contains_text("TEST"))
                                                  puts "***"
                                                  puts $html_array[index]
                                                  #sleep 1
                                                  #puts $html_array[index-1]
                                                  puts "***"
                                                  #$html_array[index].scan(/[A-Za-z]+\{[A-Za-z]+\}/){
                                                  $html_array[index].scan(/NOT COMPLETED SUCCESSFULY/){
                                                  if ($html_array[index] =~ /NOT COMPLETED SUCCESSFULY/)
                                                    $incomplete=$incomplete.to_i+1
                                                    puts $incomplete
                                                    puts "***"
                                                    #sleep 1
                                                    end
                                                  }
                                                  next
                                            else
                                                  next
                                                end
                                                
                                          }
                                          ie.close
                                          puts $pass
                                          puts $fail
                                          puts $incomplete                                          
myfile = File.open($out_fl_path, 'w');
myfile.print "<html>";
myfile.print "<body><center>";
myfile.print "<h1><u>Test Automation Summary</u></h1><br /><center><table border=2 width=\"500px\">";
myfile.print "<tr><td class=\"td2\"><font color=\"green\">Test Cases Passed:</td>"
myfile.print "<td class=\"td3\">"+$pass.to_s+"</td>" 
myfile.print "<tr><td class=\"td2\"><font color=\"Red\">Test Cases Failed:</td>"
myfile.print "<td class=\"td3\">"+$fail.to_s+"</td>" 
myfile.print "<tr><td class=\"td2\"><font color=\"Black\">Test Cases Not Completed:</td>"
myfile.print "<td class=\"td3\">"+$incomplete.to_s+"</td>" 
myfile.print "</tr></table></center></body></html>";
myfile.print "#{html_text}"
myfile.close;


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


# Define the main headers.
part1 =<<EOF
From: USAMP QA Automation <USAMPQA@usamp.com>
To: Vipul Pai Kane <Vipul_PaiKane@persistent.co.in>;Rahul_Halankar <rahul_halankar@persistent.co.in>;Nitin Kumar <nitin_kumar@persistent.co.in>;Gaurav Parrikar <gaurav_parrikar@persistent.co.in>;Mittal Saglani <Mittal_Saglani@persistent.co.in>;Akshata Shanbhag<Akshata_Shanbhag@persistent.co.in>;Mangesh Naik<mangesh_naik@persistent.co.in>;Suvina DSouza<suvina_dsouza@persistent.co.in>;Valencia Fernandes<valencia_fernandes@persistent.co.in>;Virej Salker<Virej_Salker@persistent.co.in>;Maryushka Fernandes<maryushka_fernandes@persistent.co.in>;Sangeeta Pai<sangeeta_pai@persistent.co.in>
Subject: Test Report
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

$em = ["rahul_halankar@persistent.co.in","gaurav_parrikar@persistent.co.in"]
#$server = 'relay.jangosmtp.net'
$server = 'smtp.mailinator.com'
$port = '25'
#$uname = 'qa_usamp'
#$pass = 'sampleu09!'
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