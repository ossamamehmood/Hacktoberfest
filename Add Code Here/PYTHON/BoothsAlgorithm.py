##Taking decimal inputs from user
int_m=int(input("Enter first number: "))
int_q=int(input("Enter second number: "))
##Converting decimal numbers to binary numbers
m_neg=0
q_neg=0
bin_m=bin(int_m)
if int_m>=0:
    m=bin_m[2:]
else:
    m=bin_m[3:]
    m_neg=1
bin_q=bin(int_q)
if int_q>=0:
    q=bin_q[2:]
else:
    q=bin_q[3:]
    q_neg=1

##Adding zeros at start of the number to equate their length
max_len=max(len(m),len(q)) 
m=m.zfill(max_len)
q=q.zfill(max_len)

##Adding one zero to each number for signed numbers
m='0'+m
q='0'+q


##Carrying out one's complement of the numbers
onesm=""
twosm=""
carry=0
for i in range(len(m)):
    if m[i]=='0':
        onesm+='1'
    else:
        onesm+='0'


##Carrying out two's complement of the numbers
onesml=list(onesm.strip(""))
twosml=list(onesm)
for i in range(len(onesm)-1,-1,-1):
    if onesml[i]=='1':
        twosml[i]='0'
    else:
        twosml[i]='1'
        break
m=list(m.strip(""))
if m_neg==1:
    twosml,m=m,twosml


    
if q_neg==1:
    onesq=""
    twosq=""
    carry=0
    for i in range(len(q)):
        if q[i]=='0':
            onesq+='1'
        else:
            onesq+='0'


    onesql=list(onesq.strip(""))
    twosql=list(onesq)
    for i in range(len(onesq)-1,-1,-1):
        if onesql[i]=='1':
            twosql[i]='0'
        else:
            twosql[i]='1'
            break
    q=""
    q=q.join(twosql)

##Performing the operations till count is not equal to zero
a='0'*len(m)
q1='0'
count=len(m)
a=list(a.strip(""))
q=list(q.strip(""))
while(count!=0):
    carry=0
    ##Performing addition operation(A=A+M)
    if q[-1]=='0' and q1=='1':
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
    ##Performing subtraction operation(A=A+(-M))
    elif q[-1]=='1' and q1=='0':
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
            else:
                if carry==1:
                    a[i]='1'
                else:
                    a[i]='0'
                    carry=1       
    ##Performing Arithmetic shift right
    q[1:]=q[0:]
    q[0]=a[-1]
    a[1:]=a[0:]
    q1=q[-1]
    a=a[0:-1]
    q=q[0:-1]
    ##Subtracting 1 from count
    count-=1

##Obtaining final answer
neg_flag=0
final_ans=a+q
if m_neg+q_neg==1:
    neg_flag=1
    for i in range(len(final_ans)-1,-1,-1):
        if final_ans[i]=='1':
            final_ans[i]='0'
            break
        else:
            final_ans[i]='1'
    for i in range(len(final_ans)):
        if final_ans[i]=='1':
            final_ans[i]='0'
        else:
            final_ans[i]='1'
result=""
result=result.join(final_ans)
if neg_flag==1:
    print("The product of the given two numbers is:","-"+str(int(result,2)))
else:
    print("The product of the given two numbers is:",int(result,2))