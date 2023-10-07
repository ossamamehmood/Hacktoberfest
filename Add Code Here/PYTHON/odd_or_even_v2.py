import sys

def is_odd(n: int):
    return "eovdedn☝✌️"[n % 2 :: 2]

def main():
    try:
        if len(sys.argv) >= 1: print(is_odd(int(sys.argv[1])))
        else: print("invalid input")
    except Exception as e:
        print("error", e)

if __name__ == "__main__":
    main()
