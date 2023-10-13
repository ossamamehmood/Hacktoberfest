
def fib(n: int) -> list[int]:
    fibonacci_sequence = []
    a, b = 0, 1

    while len(fibonacci_sequence) < n:
        fibonacci_sequence.append(a)
        a, b = b, a + b

    return fibonacci_sequence

def recursive_fib(n: int) -> list[int]:
    if n <= 0:
        return []
    if n == 1:
        return [0]
    if n == 2:
        return [0, 1]
    fib_sequence = recursive_fib(n - 1)
    fib_sequence.append(fib_sequence[-1] + fib_sequence[-2])
    return fib_sequence
    
def fib_generator():
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b

    
if __name__ == "__main__":
    fib_gen = fib_generator()

    n = input("Number of elements of the sequence:\n")
    n = int(n)

    print(fib(n))
    print(recursive_fib(n))

    for _ in range(n):
        print(next(fib_gen))