import os
f=open("data.csv","w")
f.write("Name,High,Low,Open,Close\n")
f.close()

def insert():
    f=open("data.csv","r+")
    n=int(input("Enter no. of records to enter: "))
    for i in range (n):
        f.write(input("Enter stock data: ")+"\n")
    f.close()

def display():
    with open("data.csv","r") as f:
        print(f.read())

def count():
    lc,wc,char=0,0,0
    with open("data.csv","r") as f:
        for l in f:
            lc += 1
            wc += len(l.split(","))
            char += len(l)
    print("Line Count: ",lc,"\nWord Count: ",wc,"\nCharacters: ",char)

#_main()_
ch=-1
while ch!=0:
    print("-"*10,"MENU","-"*10)
    print("1.Insert\n2.Display\n3.Count\n4.Exit")
    ch=int(input("Enter choice: "))
    if ch==1:
        insert()
    elif ch==2:
        display()
    elif ch==3:
        count()
    elif ch==4:
        exit()
    else:
        print("INVALID OPTION!")
        ch=-1
