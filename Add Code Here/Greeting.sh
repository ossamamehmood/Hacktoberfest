#!/bin/bash

myip=$(hostname -I | awk '{print $1}')
os=$(awk -F "=" 'NR==1 {print $2}' /etc/os-release)
echo "Good morning!"
sleep 1
echo "You are lookin great today!"
sleep 1
echo "you are currently logged in as $(whoami)" 
sleep 1
echo "you are using $os"
sleep 1
echo "your ip is $myip" 
sleep 1
echo "do you want to create a new user?(y/n)"
read choice
if [ $choice == "y" ]; then
	echo "enter a new name to create a user"
	read name
	echo "creating a new user $name"
	useradd $name
	sleep 1
	echo "create a password for $name"
	passwd $name
	sleep 1
	echo "adding a home directory to $name"
	mkhomedir_helper $name
	usermod -s /bin/bash $name
	sleep 1
	echo "you are all set!"
elif [ $choice == "n" ]; then
	echo "okay! have a good day"
else
	echo "wrong choice"
fi
