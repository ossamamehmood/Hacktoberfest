
Me = input('Enter your Name my friend : ')
Target = input('Enter their name friend : ')
calc = 'truelove'
Me = Me.lower()
Target = Target.lower()
myarr = [0,0,0,0,0,0,0,0]
for letter in Me:
    for loveletter in calc:
        if loveletter == letter:
            myarr[calc.index(loveletter)] += 1
            break
for letter in Target:
    for loveletter in calc:
        if loveletter == letter:
            myarr[calc.index(loveletter)] += 1
            break
mynum = 0
for i in range(4):
    mynum += myarr[i]
mynum *= 10
for i in range(4,8):
    mynum += myarr[i]

print(mynum)
