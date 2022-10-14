#!usr/bin/python
import sys

def rot13(st):
    res = []
    for i in range(len(st)):
        stack = ord(st[i])
        result = chr(stack+1)
        res.append(result)
    return res

arr = str(input("Enter a string \n"))
result = rot13(arr)
print("".join(result))