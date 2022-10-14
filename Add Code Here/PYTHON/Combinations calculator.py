#To calculate factorial

def factorial(x):
    if x == 1:
        return 1
    else:
        return (x * factorial(x-1))

print("Calculate the number of combinations possible (nCr)")

#to get the input

n=int(input("Total number of objects (n): "))
r=int(input("Number of objects selected (r): "))

#to check if calculation possible

if n>=r:
  #calculations of combination
  n_min_r=n-r
  n_fac = factorial(n)
  r_fac = factorial(r)
  n_min_r_fac = factorial(n_min_r)
  nCr=int(n_fac/(r_fac*n_min_r_fac))
  print("Number of combinations possible (nCr) is",nCr)
else:
  print("Number of objects selected cannot be more than Total objects")
