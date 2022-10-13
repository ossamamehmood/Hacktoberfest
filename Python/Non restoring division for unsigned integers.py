#############q=DIVIDEND###################m=DIVISOR###################################
int_q=int(input("Enter dividend: "))
int_m=int(input("Enter divisor: "))
bin_m=bin(int_m)
bin_q=bin(int_q)
m=bin_m[2:]
q=bin_q[2:]


max_len=max(len(m),len(q)) 
m=m.zfill(max_len)
q=q.zfill(max_len)
m='0'+m
a='0'*len(m)
count=len(q)


onesm=""
twosm=""
carry=0
for i in range(len(m)):
    if m[i]=='0':
        onesm+='1'
    else:
        onesm+='0'

onesml=list(onesm.strip(""))
twosml=list(onesm)

for i in range(len(onesm)-1,-1,-1):
    if onesml[i]=='1':
        twosml[i]='0'
    else:
        twosml[i]='1'
        break

a=list(a.strip(""))
q=list(q.strip(""))


while(count):
    carry=0
    #SL
    a[0:]=a[1:]
    a.append(q[0])
    q[0:]=q[1:]
    if a[0]=='1':
        for i in range(len(a)-1,-1,-1):
            if a[i]=='0' and m[i]=='0':
                if carry==0:
                    a[i]='0'
                else:
                    a[i]='1'
                    carry=0
            elif (a[i]=='0' and m[i]=='1') or (a[i]=='1' and m[i]=='0'):
                if carry==0:
                    a[i]='1'
                else:
                    a[i]='0'
            else:
                if carry==1:
                    a[i]='1'
                else:
                    a[i]='0'
                    carry=1
    else:
        for i in range(len(a)-1,-1,-1):
            if a[i]=='0' and twosml[i]=='0':
                if carry==0:
                    a[i]='0'
                else:
                    a[i]='1'
                    carry=0
            elif (a[i]=='0' and twosml[i]=='1') or (a[i]=='1' and twosml[i]=='0'):
                if carry==0:
                    a[i]='1'
                else:
                    a[i]='0'
                    carry=1
            else:
                if carry==1:
                    a[i]='1'
                else:
                    a[i]='0'
                    carry=1 
    if a[0]=='0':
        q.append('1')
        # print(a,q)
    else:
        q.append('0')
        # print(a,q)
    count=count-1

if a[0]=='1':
    a=a+m


qs=""
ast=""
qs=qs.join(q)
ast=ast.join(a)
quotient=int(qs, 2)
remainder=int(ast, 2)
print(f"Quotient = {quotient}    Remainder = {remainder}")