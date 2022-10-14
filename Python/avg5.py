def avgcondition(arr):
    sum =0
    for i in range(len(arr)):
        if arr[i]>2 and arr[i]<10:
            sum = sum + arr[i]
        else:
            return False
    return sum/5

arr = []

for i in range(5):
    a = float(input())
    arr.append(a)
print(arr)
print(avgcondition(arr))