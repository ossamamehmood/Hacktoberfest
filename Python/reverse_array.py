def reverseArray(a):
  arr = []
  for i in range(len(a)-1, -1, -1):
    arr.append(a[i])
  return arr

myArr = [1,2,3,4,5,6]
reversedArray = reverseArray(myArr)
print(reversedArray)
