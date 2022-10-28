for _ in range(int(input("Enter no of string: "))):
    s = input("Enter String: ")
    
    if(s==s[::-1]):
        print(-1)
    else:
        print(''.join(sorted(s)))
