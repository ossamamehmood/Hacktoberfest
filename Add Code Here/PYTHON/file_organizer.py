#!/usr/bin/env python3

#jalebium69
#to run see below:
#python3 filename target_path
#filename -> name of this python script
#target_path ->the directory you want to sort 
#pass the arguments in command line



import sys
import os
import shutil
path=sys.argv[1]
files=os.listdir(path)
for i in files:
    if '.' not in i or i=='.DS_Store':
        continue
    else:
        ext=i.split('.')[-1]
        if os.path.exists(path+'/'+ext):
            shutil.move(path+'/'+i,path+'/'+ext+'/'+i)
        else:
            os.makedirs(path+'/'+ext)
            shutil.move(path+'/'+i,path+'/'+ext+'/'+i)
print("All went well!!!")
