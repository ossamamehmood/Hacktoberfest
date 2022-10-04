import time as t
print("Enter you passcode")
for z in range(0,10):
    if(z==0):
        t.sleep(1)
    print("*",end="")

print("\n")
print("Hacking NASA")
for i in range(0,6,1):
    print(20*i,"% Loading...")
    t.sleep(0.5)

print("Extracting data..")
for x in range(1,21,1):
    print(x*5,'% Extracting...')
    t.sleep(0.25)

print("Access denied...")
t.sleep(1)

print("Access denied...")
t.sleep(1)

print("Access granted...")
t.sleep(0.75)

print("Hacked successfully..")
