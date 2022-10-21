#program to print 1 to 10 numbers
import os
from colorama import *
import time
os.system("cls")
i=1
while(i<=10):
 time.sleep(2)
 print(Fore.RED,i)
 i=i+1
print(Style.RESET_ALL)