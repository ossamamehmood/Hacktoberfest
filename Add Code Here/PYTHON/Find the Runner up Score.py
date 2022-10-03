Largest = arr[n-1]
secondlargest = min(arr)
for i in range(0,n):
    if arr[i]>Largest:
        Largest = arr[i]
for x in range(0,n):
    if arr[x]>secondlargest and arr[x]!=Largest:
        secondlargest=arr[x]
print(secondlargest)

# Need to find runner-up score
# --> Must find the winner score first
# --> Compare all scores with winner score to find runner-up  score
# Note - No input commands added since console already has input commands

# For eg, 5=n, arr = [1,-1,-2,1,-3]
# --> Currently, largest = arr[n-1] = arr[4] = -3
# --> Currently, secondlargest = min(arr) = -3
# --> 'for' loop initiated, largest calculated as '1'
# --> second 'for' loop initiated, since -1 > -3 and -1 != 1, therefore, secondlargest = -1
# --> print(secondlargest) --> print(-1) --> -1