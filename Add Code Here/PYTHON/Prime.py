def factors(n):
    prime = [1] * (n + 1)
    for i in range(4, n + 1, 2):
        prime[i] = 0
    cnt = 1
    for i in range(3, n + 1, 2):
        if prime[i]:
            for j in range(i ** 2, n + 1, 2 * i):
                prime[j] = 0
            cnt += 1
    return cnt


print(factors(int(input())))
