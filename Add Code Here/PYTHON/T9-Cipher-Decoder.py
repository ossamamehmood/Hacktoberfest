#!/usr/bin/python3

import sys
print('[0] argument is:', sys.argv[1])

def my_f(a, counter):
	a0 = [' ']
	a2 = ['a','b', 'c']
	a3 = ['d','e', 'f']
	a4 = ['g','h', 'i']
	a5 = ['j','k', 'l']
	a6 = ['m','n', 'o']
	a7 = ['p','q', 'r', 's']
	a8 = ['t','u', 'v']
	a9 = ['w','x', 'y', 'z']
	if a == 0:
		print(a0[counter], end='')
	elif a == 2:
		print(a2[counter], end='')
	elif a == 3:
		print(a3[counter], end='')
	elif a == 4:
		print(a4[counter], end='')
	elif a == 5:
		print(a5[counter], end='')
	elif a == 6:
		print(a6[counter], end='')
	elif a ==  7:
		print(a7[counter], end='')
	elif a ==  8:
		print(a8[counter], end='')
	elif a ==  9:
		print(a9[counter], end='')
	
	
f = open(sys.argv[1],"r").read()

i = 0
a = 0

while i < len(f)-1:
	bol = True
	if f[i].isdigit():
		counter = 0
		while bol:
			a = f[i]
			if f[i+1] != a:
				my_f(int(a), counter)
				bol = False
			else:
				counter += 1
			i += 1
	else:
		print(f[i], end='')
		i += 1

print()
print()
		
			
	
	



