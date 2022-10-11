#To calculate factorial

def factorial(x):
    if x == 1:
        return 1
    else:
        return (x * factorial(x-1))


print("Calculate the number of permutations possible (nPr)")

#to get the input

n=int(input("Total number of objects (n): "))
r=int(input("Number of objects selected (r): "))

#to check calculation possible

if n>=r:
  #calculations of permutation
  n_min_r=n-r
  n_fac = factorial(n)
  n_min_r_fac = factorial(n_min_r)
  nPr=int(n_fac/n_min_r_fac)
  print("Number of permutations possible (nPr) is",nPr)
else:
  print("Number of objects selected cannot be more than Total objects")
