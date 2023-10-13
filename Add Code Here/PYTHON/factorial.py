def factorial(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

def main():
    n = int(input())
    total = factorial(n)
    print(total)

if __name__ == "__main__":
    main()
