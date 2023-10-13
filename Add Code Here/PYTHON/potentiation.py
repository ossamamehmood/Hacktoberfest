def pot(a, b):
    if b == 0 and a != 0:
        return 1
    if b >= 1:
        return a * pot(a, b - 1)
    if b <= -1:
        return 1.0 / a * pot(a, b + 1)
    return 0

def main():
    a, b = map(int, input().split())
    total = 0

    if a == 0 and b <= 0:
        print("undefined")
    else:
        total = pot(a, b)
        print(total)

if __name__ == "__main__":
    main()
