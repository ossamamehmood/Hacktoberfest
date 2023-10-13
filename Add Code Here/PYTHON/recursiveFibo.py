def fibo(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibo(n - 1) + fibo(n - 2)

def main():
    n = int(input())
    total = fibo(n)
    print(total)

if __name__ == "__main__":
    main()
