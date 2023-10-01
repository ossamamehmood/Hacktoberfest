#!/bin/bash

echo -e '
=======================================
╭━╮╭━┳━╮  ╭━┳━┳╮  ╭━━━┳━━━┳━━━╮  ╭━┳━╮
┃┃╰╯┃┃┃  ┃┃┃┃┃┃  ┃┃┃┃┃┃┃┃┃┃  ┃  ┃┃┃┃
┃╭╮╭╮┃┃  ┃┃┃┃┃┃  ┃┃┃┃┃┃┃┃┃┃  ┃  ┃┃┃┃
┃┃┃┃┃┃┃  ┃╰╯╰╯┃  ┃┃┃┃┃┃┃┃┃┃  ┃  ┃┃┃┃
┃┃┃┃┃┃┃  ┃┃┃┃┃┃  ┃┃┃┃┃┃┃┃┃┃  ┃  ┃┃┃┃
╰╯╰╯╰┻┻━╮┣┻┻┻┻╯  ╰╯╰╯╰╯╰╯╰┻━╮┣┻┻┻┻╯
       ┃┃      |------------|
       ┃┃      | Word Break |
       ┗┛      |------------|
       
 Welcome to the Paragraph to Wordlist
    Text Transformation Tool!
'
echo ' Author: TYehan 
	 https://github.com/TYehan 
    
=======================================  
'

#if ! [ -x "$(command -v sponge)" ]; then
# echo 'Error: sponge is not installed.' >&2
#  echo 'try apt-get install moreutils'
#  exit 1
#fi

echo "  Enter your paragraph here.
---------------------------------------"
read paragraph
echo " "
echo "Enter a name for the outputing file: 
(Example: ParaWordList)
(Hit "Enter" for the Default name: ParaWordList)"
echo " "
read filename
echo " "

# Check if the input is empty
if [ -z "$filename" ]; then
  filename="ParaWordList"
fi

# Check if the file name ends with '.sh' and remove it if present
filename="${filename%.sh}"

touch "$filename.txt"
echo "$paragraph" | tr -d "!-,.\\'" | tr " " "\n" >> "$filename.txt"
echo "======================================="
echo "Your output is saved to $filename.txt in"
pwd
echo "
======================================="

