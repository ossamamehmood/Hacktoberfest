#!/usr/bin/env python
from pip._internal.operations.freeze import freeze
import __future__
import platform, subprocess

#os = platform.linux_distribution()
#print(os[0])

check_os = subprocess.check_output("cat /etc/issue", shell=True)
print(check_os)

for requirement in freeze(local_only=True): 
	req = requirement.split("==") 
	if req[0] == "python-nmap": 
		print("module python-nmap exist")


check_pip = subprocess.check_output("pacman -S ", shell=True)
print(check_pip)
