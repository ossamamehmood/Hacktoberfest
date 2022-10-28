def factorial(n):
    if (n==0 or n==1):
        return 1
    else:      
        return n*(factorial(n-1))


num=int(input("enter number : "))



def fibo(n):
    if (n<=1):
        return 1
    else:
        return(fibo(n-2)+fibo(n-1))
for i in range(num):
   print(fibo(i))



'''def multi(n):
    if (n<=1):
        return 1
    else:
        return (n**2) + multi(n)'''



print("factorial : ",factorial(num))
print("fibbonacci : ",fibo(num))
'''print("multiplication : ",multi(num))'''