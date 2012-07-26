require 'rubygems'
require 'fileutils'
#require 'win32ole'
#require 'Win32API'
#require 'win32/clipboard'
#include Win32

$wd = Dir.pwd
$fl_path = $wd + "/report_file_name.txt"

$ext = Time.now
$ext = $ext.to_s
$ext = $ext.slice(0..18)
$ext = $ext.gsub(" ", "_")
$ext = $ext.gsub(":", "_")

$fl_nm = "Report_" + $ext + ".html"
puts $fl_nm
#file = File.open($fl_path,w)

    #file.puts $fl_nm
#file.close

File.open($fl_path, 'w') do |f1| 
				  f1.puts $fl_nm
end

