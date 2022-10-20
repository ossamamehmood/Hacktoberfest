#reverse binary search python program
def binarysearch():
    for i in range(len(arr)):
        if arr[i]==K:
            print(i)

N=int(input())
arr=list(map(int,input().split()))
K=int(input())

binarysearch()
