import timeit
import time

def long_function():
    print('function start')
    num = 84684168461654343484687
    flag = False

    if num > 1:
        for i in range(2, num):
            if (num % i) == 0:
                flag = True
                break

    if flag:
        print(num, "is not a prime number")
    else:
        print(num, "is a prime number")
    print('function end')
    
print(timeit.Timer(long_function).timeit(number=1))