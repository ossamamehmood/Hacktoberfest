#!/bin/zsh

if [[ "$1" == "-u" ]]
then
    if [[ ${#2} > 0 ]]
    then
        if [[ -f "$(pwd)/$2" ]]
        then
            command="curl -s -F'file=@$(pwd)/$2' https://0x0.st"
            echo "Executing: $command"

            url=$(eval $command)
            echo "URL: $url"

            printf "$url" | xclip -sel clip
            notify-send "File Uploaded" "URL: $url \ncopied to clipboard" -t 5000 -i "$HOME/.program/icon.png"

            entry="$(date '+%d-%m-%y-%H:%M:%S')    $url    $(echo $2 | awk -F'/' '{print $(NF)}')"
            echo $entry >> $HOME/.0x0_list
            echo "Uploaded"
        else
            echo "File doesnt exist"
        fi
    else
        echo "Please give a file name"
    fi

elif [[ "$1" == "-l" ]]
then
    if [[ ${#2} > 0 ]]
    then
        if [[ $2 =~ ^[0-9]+$ ]]
        then
            cat ~/.0x0_list | tail -$2
        else
            echo "Enter a valid integer"
        fi
    else
        cat ~/.0x0_list | less
    fi

elif [[ "$1" == "-e" ]]
then
    $EDITOR ~/.0x0_list

elif [[ "$1" == "-h" ]] || [[ "$1" == "--help" ]]
then
    echo "Usage: upload [OPTION]... [FILE]...

Uploads file to 0x0 server(no login needed), copies the URL for file to 
clipboard and also stores the URLs in ~/.0x0_list

OPTIONS:
    -h, --help      Prints the help
    -u [File]       specify the file to be uploaded, filename in cwd or absolute/relative path works
    -l [number]     List the last n uploads with their URL, if number not specified it will all the URLS
    -e              Opens the ~/.0x0_list file for editing

EXAMPLE:
    upload -u hello.txt
    upload -u dir/hello.txt
    upload -u /home/user/dir/hello.txt
    upload -l
    upload -l 10
    upload -e
"

else
    echo "Invalid argument, run: upload --help"
fi    
