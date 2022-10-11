#!/bin/bash

url=$1
echo ""
echo ""
echo ""
echo "This Tools Name is Osintool"
echo "---------------------------------------------------------------------------------"
echo "---------------------------------------------------------------------------------"
echo "This is your OSINT tool for gathering domain information and emails! Happy Hunting"


if [ ! -d "/home/kali/Desktop/Engagement-$url" ];then
	mkdir "/home/kali/Desktop/Engagement-$url" 
fi

echo "Directory Permissions setting..."
chmod 777 /home/kali/Desktop/Engagement-$url
cd /home/kali/Desktop/Engagement-$url
echo "Directory Permissions Done..."

echo "[+] NSLOOKUP is running....."
nslookup $url >> /home/kali/Desktop/Engagement-$url/NSLOOKUP.txt
echo "NSLOOKUP is Done..."

echo "[+] Assetfinder is running....."
assetfinder $url >> /home/kali/Desktop/Engagement-$url/assetFinderOutput.txt
echo "Assetfinder is Done..."

#Amass Finds all Subdomains and IP addresses, not unique and is grepped out later
echo "[+] Amass is running, take a breather ;)....."
amass enum -active -d $url -src -ip -dir /home/kali/Desktop/Engagement-$url -o /home/kali/Desktop/Engagement-$url/AmassSubDomains.txt
rm /home/kali/Desktop/Engagement-$url/amass.log
rm /home/kali/Desktop/Engagement-$url/amass.json
rm /home/kali/Desktop/Engagement-$url/indexes.bolt
echo "Amass is Done..."

#Second look at subdomains with this tool
echo "[+] Sublist3r is running....."
sublist3r -d $url >> /home/kali/Desktop/Engagement-$url/sublist3rOutput.txt
echo "Sublist3r is Done..."

#Nikto Vulnerability Scan
echo "[+]Nikto is running....."
nikto -h $url >> /home/kali/Desktop/Engagement-$url/niktoOutput.txt
echo "Nikto is Done..."

# NMAP will now grep out IPs from amass and export them to a file, that file will then be uploaded for a port scan in NMAP"
echo " The enumeration is done! Now the port scanning begins"
grep -E -o "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)" AmassSubDomains.txt | sort -u >>ips.txt
echo "NMAP is scanning  0...0   "
nmap -T4 -A -sV -iL /home/kali/Desktop/Engagement-$url/ips.txt >> /home/kali/Desktop/Engagement-$url/NMAP Results
echo "Port Scanning is Done..."

#CRT.SH searching for interesting subdomain Locations, I would like to take the outputs of Amass and play here more as an input.
curl -s https://crt.sh/?q=$url > /home/kali/Desktop/Engagement-$url/crtfirst.txt
cat /home/kali/Desktop/Engagement-$url/crtfirst.txt | grep $TARGET | grep TD | sed -e 's/<//g' | sed -e 's/>//g' | sed -e 's/TD//g' | sed -e 's/\///g' | sed -e 's/ //g' | sed -n '1!p' | sort -u > /home/kali/Desktop/Engagement-$url/$TARGET-crt.txt
curl -s https://crt.sh/?q=*.$url > /home/kali/Desktop/Engagement-$url/crtsecond.txt
cat /home/kali/Desktop/Engagement-$url/crtsecond.txt | grep $TARGET | grep TD | sed -e 's/<//g' | sed -e 's/>//g' | sed -e 's/TD//g' | sed -e 's/\///g' | sed -e 's/ //g' | sed -n '1!p' | sort -u > /home/kali/Desktop/Engagement-$url/$TARGET-crt2.txt

#Can I copy all file data and place into 1 file and then delete the file left over to have 1 file?
rm /home/kali/Desktop/Engagement-$url/crtfirst.txt 
rm /home/kali/Desktop/Engagement-$url/crtsecond.txt 


#THIS ISNT WORKING EVEN AS ROOT
sudo chmod 777 home/kali/Desktop/Engagement-$url
