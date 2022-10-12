# List operations

while True:
    print("Menu :")
    print("1.Display the number of even and odd digits")
    print("2.Display the Reverse Form")
    print("3.Find a specified element in list")
    print("4.Remove a specified element from list")
    print("5.Sort the list in descending order")
    print("6.Accept 2 list and Find common element")
    ch = int(input("Enter your Choice :-"))
    if ch == 1:
        lst1 = []
        n = int(input("Enter number of elements :- "))
        print("Enter Elements in list :- ")
        for i in range(0, n):
            ele1 = input()
            lst1.append(ele1)
        print("Entered List :- ")
        print(lst1)
        for res in lst1:
            if (res):
                res = [int(i) for i in lst1]
                odd_count = len(list(filter(lambda x: (x % 2 != 0), res)))
        print("Number of Odd elements in the list :- ", odd_count)
        print()
        even_count = len(list(filter(lambda x: (x % 2 == 0), res)))
        print("Number of even elements in the list :- ", even_count)
        print()

    elif ch == 2:
        lst1 = []
        n = int(input("Enter number of elements :- "))
        print("Enter Elements in list :- ")
        for i in range(0, n):
            ele1 = input()
            lst1.append(ele1)
        print("Entered List :- ")
        print(lst1)
        lst1.reverse()
        print("Reversed List :-")
        print(lst1)
        print()
    elif ch == 3:
        lst = []
        n = int(input("Enter number of elements :- "))
        for i in range(0, n):
            ele = int(input())
            lst.append(ele)
        print("Entered List is :-")
        print(lst)
        no = int(input("Enter the number to be find :- "))
        if no in lst:
            print("Number Found!")
            print()
        else:
            print("Not Found in the list!!")
            print()
    elif ch == 4:
        lst1 = []
        n = int(input("Enter number of elements :- "))
        print("Enter Elements in list :- ")
        for i in range(0, n):
            ele1 = input()
            lst1.append(ele1)
        print("Entered List :- ")
        print(lst1)
        rem = input("Enter the no. to be removed :- ")
        lst1.remove(rem)
        print(lst1)
    elif ch == 5:
        lst1 = []
        n = int(input("Enter number of elements :- "))
        print("Enter Elements in list :- ")
        for i in range(0, n):
            ele1 = input()
            lst1.append(ele1)
        print("Entered List :- ")
        print(lst1)
        print("List After sorting :- ")
        lst1.sort(reverse=True)
        print(lst1)
    elif ch == 6:
        lst1 = []
        lst2 = []
        n = int(input("Enter number of elements for 1st list :- "))
        print("Enter Elements in list 1 :- ")
        for i in range(0, n):
            ele1 = input()
            lst1.append(ele1)
        print("Entered List 1 is :- ")
        print(lst1)
        n1 = int(input("Enter number of elements for 2nd list :- "))
        print("Enter Elements in List 2 :-")
        for i in range(0, n1):
            ele1 = input()
            lst2.append(ele1)
        print("Entered List 2 is :- ")
        print(lst2)
        common = [value for value in lst1 if value in lst2]
        print("Common Value :- ")
        print(common)
    else:
        break