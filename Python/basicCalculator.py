# Program make a simple calculator

# This function adds two numbers
def add(lst):
    ans=0
    for i in range(len(lst)):
        ans = ans + lst[i]
    return ans

# This function subtracts two numbers
def subtract(lst):
    ans=0
    for i in range(len(lst)):
        ans = lst[i] - ans
    return ans

# This function multiplies two numbers
def multiply(lst):
    ans=1
    for i in range(len(lst)):
        ans = ans * lst[i]
    return ans

# This function divides two numbers
def divide(lst):
    ans=1
    for i in range(len(lst)):
        ans = lst[i] / ans
    return ans


print("Select operation.")
print("1.Add")
print("2.Subtract")
print("3.Multiply")
print("4.Divide")

lst=[]
while True:
    # take input from the user
    choice = input("Enter choice(1/2/3/4): ")

    # check if choice is one of the four options
    if choice in ('1', '2', '3', '4'):
        n = int(input("How many numbers for calculation? "))
        for i in range(n):
            ele = float(input("Enter Number: "))
            lst.append(ele) 

        if choice == '1':
            print(add(lst))

        elif choice == '2':
            print(subtract(lst))

        elif choice == '3':
            print(multiply(lst))

        elif choice == '4':
            print(divide(lst))
        
        # check if user wants another calculation
        # break the while loop if answer is no
        next_calculation = input("Let's do next calculation? (yes/no): ")
        if next_calculation == "no":
          break
    
    else:
        print("Invalid Input")
