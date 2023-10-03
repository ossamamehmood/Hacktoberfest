import pywhatkit as pktwhat

def sendMsg(no,msg,hrs,min):
    pktwhat.sendwhatmsg(no,msg,hrs,min)


num = int(input("Enter the number"))
msg = input("Enter the message")
hrs =int(input("Enter Hrs:"))
mins = int(input("Enter mins:"))
sendMsg(num,msg,hrs,mins)