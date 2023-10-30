os=$(cat /etc/issue | cut -d " " -f 1)
if [ $os == "arch" ]
then
	app=$(pacman -Qe | grep pip | cut -d " " -f 1)
	
elif [ $os == "ubuntu" ]
then
	app=$(apt list --installed | grep pip | cut -d " " -f 1)
	
fi

module=$(pip freeze | grep python-nmap)
echo $app
if [ $app != "" ] 
then
	echo "pip are installed"
fi

if [ $module != "" ]
then
	echo "python-nmap are installed "
fi

echo "You are using $os"
