def bubble_sort(arr):
    x = len(arr)
    for i in range(x):
        swapped = False
        for j in range(0, x - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break

arr = []

for i in range(1, 6):
    n = int(input(f"Enter Number between 10 and 20 {i}:"))
    if n > 10 and n < 20:
        arr.append(n)
    else:
        print("Enter a valid number between 10 and 20.")
        n = int(input(f"Enter Number between 10 and 20 {i}:"))
    i += 1

bubble_sort(arr)

print("Sorted array:", arr)
