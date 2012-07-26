File.new("delete.bat", "w")
myfile = File.open("delete.bat","w")
myfile.puts("@REM OFF") 
$path_finder=`echo %cd%`
$Download='\Downloads'
$cases='Cases\*'
$path_finder.chop!
myfile.puts("cd /d "+ $path_finder+$Download)
myfile.puts("del *.csv")
myfile.puts("del *.xls")
myfile.puts("del *.pdf")
myfile.puts("cd /d "+ $path_finder)
myfile.close

myfile = File.open("test.bat","w")
myfile.puts("cd /d "+ $path_finder)
myfile.puts("rspec --format h -o Report.html "+$cases)
myfile.close

myfile = File.open("testrun.bat","w")
myfile.puts("@REM OFF") 
myfile.puts("cd /d "+ $path_finder)
myfile.puts("rspec --format h -o Report.html --tag ~datacreation --tag ~temp --tag ~inprogress "+$cases)
myfile.close


myfile = File.open("testrun_with_mail.bat","w")
myfile.puts("@REM OFF") 
myfile.puts("cd /d "+ $path_finder)
myfile.puts("ruby mail.rb")
myfile.close