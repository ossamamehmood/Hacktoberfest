from sys import stdin

def pushZerosAtEnd(arr, n) :
    counter=0
    i=0
    while counter!=n:
        if arr[i]==0:
            arr.pop(i)
            arr.append(0)
        else:
            i=i+1
        counter=counter+1


#Taking Input Using Fast I/O
def takeInput() :
    n = int(stdin.readline().rstrip())

    if n == 0:
        return list(), 0
    
    arr = list(map(int, stdin.readline().rstrip().split()))
    return arr, n
  

#to print the array/list
def printList(arr, n) : 
    for i in range(n) :
        print(arr[i], end = " ")

    print()


#main
t = int(stdin.readline().strip())

while t > 0 :

    arr, n = takeInput()

    pushZerosAtEnd(arr, n)
    printList(arr, n)

    t -= 1
