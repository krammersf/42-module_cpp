#!/bin/bash

# Clear the terminal
clear

#creating TEST FILE
cat > 9_input.txt << EOF
date | value
2012-01-03 | 1
2012-01-03 |2		 
2012-01-03 |  3
2012-01-03 |	 4
2012-01-03 | 	5
2012-12-01 |6.00	

 
	
2012-01-03 |	7
2012-01-09 | 1.0.
2012-01-09 | 1.a
2012-01-09 | 1. 9
2012-01-03 | 1.2
2012-01-11 | -1
2012-01-11 | f
2001-42-42
2012-01-11 | 1000
2012-01-11 | 1001
2012-01-11 | &
2012-01-11 | ' '
2023-12-31 | 0.2
20120111 | 5
2012-02-30 | 5
2012-04-31 | 5
2024-12-31 | 3.2
0000-12-31 | 3.2
2012-00-31 | 3.2
2012-12-00 | 3.2
2012-12-01 | 2.5
2012-12-01 |.
2012-12-01 |..
2012-12-01 |...
2012-12-01 | 9.5
2012-12-01 |....
2012-12-01 | 2.5 		''
2012-12-01 | 2.5 		""
2012-12-01 | 33.5
2012-12-01 |.5
2012-12-01 |.&5
2012-12-01 |*5
2012-12-01 | 100.54   
2012-12-01 | 100.5.44   
2012-12-01 | 100.544  5 
2012-12-01 | 100.001  &  
2012-12-01 | 100.1234567890 
2012/12/01 | 100.9 
2012-12~01 | 100.8 
2012~12-01 | 100.7 
2012-12-01 | 9.1 
2012-12-01 |  
2012-12-01 |
2012-12-01 | 	 	 	 
EOF

#exporting output from de prgram
#./btc 9_input.txt 2>&1 | sed -e :a -e '/^\n*$/{$d;N;};/\n$/ba' > program_output.txt
#printf "\n\033[93m ==> Please enter the executable name: \033[0m"
#read executable_name

# Use the entered executable name
#./"$executable_name" 9_input.txt 2>&1 | sed -e :a -e '/^\n*$/{$d;N;};/\n$/ba' > program_output.txt
./btc 9_input.txt 2>&1 | sed -e :a -e '/^\n*$/{$d;N;};/\n$/ba' > program_output.txt 2>/dev/null


# Making EXPECTED OUTPUT
cat <<EOF > expected_output.txt
2012-01-03 => 1 = 5.45
2012-01-03 => 2 = 10.9
2012-01-03 => 3 = 16.35
2012-01-03 => 4 = 21.8
2012-01-03 => 5 = 27.25
2012-12-01 => 6.00 = 75.96
Error: bad input => 
Error: bad input =>  
Error: bad input => 	
2012-01-03 => 7 = 38.15
Error: more than one '.'
Error: not a number.
Error: not a number.
2012-01-03 => 1.2 = 6.54
Error: not a number.
Error: not a number.
Error: bad input => 2001-42-42
2012-01-11 => 1000 = 7100
Error: too large a number.
Error: not a number.
Error: not a number.
2023-12-31 => 0.2 = 9423.19
Error: bad date => 20120111
Error: bad date => 2012-02-30
Error: bad date => 2012-04-31
2024-12-31 => 3.2 = 150771
Error: bad date => 0000-12-31
Error: bad date => 2012-00-31
Error: bad date => 2012-12-00
2012-12-01 => 2.5 = 31.65
Error: not a number.
Error: not a number.
Error: not a number.
2012-12-01 => 9.5 = 120.27
Error: not a number.
Error: not a number.
Error: not a number.
2012-12-01 => 33.5 = 424.11
Error: not a number.
Error: not a number.
Error: not a number.
2012-12-01 => 100.54 = 1272.84
Error: more than one '.'
Error: not a number.
Error: not a number.
2012-12-01 => 100.1234567890 = 1267.56
Error: bad date => 2012/12/01
Error: bad date => 2012-12~01
Error: bad date => 2012~12-01
2012-12-01 => 9.1 = 115.206
Error: input is empty
Error: bad input => 2012-12-01 |
Error: input is empty
EOF

# Finding desired line in progrma_output.txt and getting its line number
line=$(grep -n "2012-01-03 => 1 = 5.45" program_output.txt | cut -d ":" -f1)

# If the line was found, start the comparison
if [ -n "$line" ]; then
	#echo "Line '2012-01-03 => 1 = 5.45' found at line $line."
	printf "\n     \033[1;93mStarting comparison between your output and the expected ... \n\033[0m\n"
	
	# Comparing from the found line
	tail -n +"$line" program_output.txt | awk '/Error/ {print "Error"} !/Error/ {print $0}' | awk '{if (NR > 1 && length($0) == 0) {next} else if (NR > 1) {print last} last=$0} END {if (length(last) != 0) print last}' > temp.txt
	# Creating temp2.txt with modified lines from 'expected_output.txt'
	awk '/Error/ {print "Error"} !/Error/ {print $0}' expected_output.txt > temp2.txt

	# Check all 53 lines
	for i in $(seq 1 53); do
		line=$(sed -n "${i}p" temp.txt)
		expected_line=$(sed -n "${i}p" temp2.txt)
		expected_line2=$(sed -n "$((${i}-0))p" expected_output.txt)
	expected_line3=$(sed -n "$((${i}+1))p" 9_input.txt)
	expected_line4=$(sed -n "$((${i}-0))p" program_output.txt)
	if [ "$line" = "$expected_line" ]; then
		printf "\033[44m\033[0;37m  Line %02d ==> \033[1;32m✔ OK    \033[0m\033[0m" $i
		printf "\033[46m\033[1;30m~> INPUT   :\033[0m '$expected_line3'\n\033[0m"
	else
		printf " \033[44m\033[0;37m Line %02d ==> \033[1;31m✖ ERROR \033[0m\033[0m" $i
		printf "\033[46m\033[1;30m~> INPUT   :\033[0m '%s'\n\033[0m" "$expected_line3"
		printf "                      \033[44m\033[1;31m~> YOU     :\033[0m '$expected_line4'\n\033[0m"
		printf "                      \033[44m\033[1;32m~> EXPECTED:\033[0m '$expected_line2'\n\033[0m"
	fi
	sleep 0.2
	done

else
			   printf "mal na primeira linha\n" $i

fi

rm expected_output.txt program_output.txt 9_input.txt temp.txt temp2.txt

# Add credits
printf "\n     Credits: \033[1;5;33mfde-carv\033[0m <fde-carv@student.42porto.com>\n\n     Thanks for using this test!!! 😊\n\n"

