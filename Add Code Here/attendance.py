#n=int(input("Enter total numbers : "))
from datetime import datetime
l1=list(map(int,input("Enter only Present numbers : ").split()))#[:n]
l=list()
print("\nAbsent numbers are : ")
for i in range(301,373):
	if i in l1:
		continue
	l.append(i)
	print(i,end="\t")
f=open("AbsentNo.csv","a")
v=datetime.now()
f.write("Date : "+str(v.date()))
f.write("\nTime : "+str(v.strftime("%H:%M")))
f.write("\nAbsent Numbers :"+str(l))
f.write("\n\n")
f.close()