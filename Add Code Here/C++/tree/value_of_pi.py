# The formula to calculate the value of pi is X = 4 - 4/3 + 4/5 - 4/7 + 4/9 .....
# This code is an implementation of the same formula

# Initialize denominator as integer
k = 1

# Initialize sum as integer
s = 0

for i in range(10000):
# Loop ends at a very big number as pi is never ending

	if i % 2 == 0:
		s + = 4/k
	else:

		# odd index elements are negative
		s -= 4/k

	# denominator is odd
	k += 2

print(s)
