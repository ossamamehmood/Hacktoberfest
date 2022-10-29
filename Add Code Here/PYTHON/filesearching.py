

# This program will help us implement concepts such as binary searching, operating system.
# P.S: Dont run this on root. That is dont give the DIRECTORY path as root else the program might
# consume all your resources and your system might get crashed

import os
from pathlib import Path

DIRECTORY = '#enter your dircetory'

# List all the directories in the DIRECTORY
dirs = [name for name in os.listdir(DIRECTORY) if os.path.isdir(os.path.join(DIRECTORY, name))]

# List all the files in the DIRECTORY
# files = [name for name in os.listdir(DIRECTORY) if os.path.isfile(os.path.join(DIRECTORY, name))]
files = []

for root, dirs, files in os.walk(DIRECTORY):
    for File in files:
        files.append(root + File)

dirs.sort()
files.sort()

def binarySearch(target, List):
    '''This function performs a binary search on a sorted list and returns the position if successful else returns -1'''
    left = 0 #First position of the list
    right = len(List) - 1 #Last position of the list
    global iterations
    iterations = 0

    while left <= right: #U can also write while True condition
        iterations += 1
        mid = (left + right) // 2
        if target == List[mid]:
            return mid, List[mid]
        elif target < List[mid]:
            right =  mid - 1
        else:
            left = mid + 1
    return -1

print(dirs)
print(files)

try:
    result, filePath = binarySearch('server.py', files)
    print(os.path.abspath(filePath))
except:
    print('File not found')
