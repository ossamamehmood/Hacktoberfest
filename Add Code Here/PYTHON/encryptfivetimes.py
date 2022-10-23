import string
poop = string.ascii_lowercase
letters = list(poop)
original = list(poop)
from random import randint
import time

for i in range(0, len(letters)):
    if i == 22:
        letters[i] = "a"
        letters[i+1] = "b"
        letters[i+2] = "c"
        letters[i+3] = "d"
        break;
    else:
        letters[i] = letters[i+4]
nani = str(input("Enter Sentence without characters: "))
nani = nani.lower()
ask = list(nani)
length = len(ask)
count = 0
for i in range(0, length):
    if ask[i] == " ":
        count += 1
for i in range(0, count):
    for i in range(0, length):
        if ask[i] == " ":
          ask.pop(i)
          break;
for i in range(0, len(ask)):
    for j in range(0, len(original)):
        if ask[i] == original[j]:
            ask[i] = letters[j]
            break;
s = ""
s = s.join(ask)
nani = list(nani)
s = list(s)
print()
for i in range(0, len(nani)):
    if nani[i] == " ":
        s.insert(i, " ")
for j in range(1, 10):
    for i in range(1, 80):
        a = randint(1, 9)
        print (a, end = "")
print ()
print()
time.sleep(2)
print ("Done...")
time.sleep(2)
print()
ending = ""
ending = ending.join(s)
print ("Encrypted sentence: " + ending)

    

