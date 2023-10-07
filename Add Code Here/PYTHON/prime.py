def is_prime(num):
  for i in range(2,num):
      if (num % i) == 0:
          return False
  return True
 
def all_primes(num):
  primes = []
  for n in range(2,num+1):
      if is_prime(n) is True:
          primes.append(n)
  return primes
 
num = int(input("Enter upper limit: "))
primes = all_primes(num)
print(primes)
