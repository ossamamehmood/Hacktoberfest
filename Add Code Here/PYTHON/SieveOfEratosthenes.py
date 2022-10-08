# Python Program To Print All Prime Numbers Using Sieve Of Eratosthenes


def SieveOfEratosthenes(num):
    prime = [True for i in range(num+1)]
    p = 2
    while (p * p <= num):
        # If prime[p] is not changed, then it is a prime
        if (prime[p] == True):
            # Updating all multiples of p
            for i in range(p * p, num+1, p):
                prime[i] = False
        p += 1

    # Print all prime numbers
    for p in range(2, num+1):
        if prime[p]:
            print(p, end=' ')

num = int(input('Number upto which prime nos. are found:'))
print('Prime numbers smaller than or equal to', num)
SieveOfEratosthenes(num)
