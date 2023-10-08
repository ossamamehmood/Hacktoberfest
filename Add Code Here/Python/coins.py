# A Dynamic Programming based Python3 program to
# find minimum of coins to make a given change V
import sys

# m is size of coins array (number of
# different coins)
def minCoins(coins, m, V):
	
	# table[i] will be storing the minimum
	# number of coins required for i value.
	# So table[V] will have result
	table = [0 for i in range(V + 1)]

	# Base case (If given value V is 0)
	table[0] = 0

	# Initialize all table values as Infinite
	for i in range(1, V + 1):
		table[i] = sys.maxsize

	# Compute minimum coins required
	# for all values from 1 to V
	for i in range(1, V + 1):
		
		# Go through all coins smaller than i
		for j in range(m):
			if (coins[j] <= i):
				sub_res = table[i - coins[j]]
				if (sub_res != sys.maxsize and
					sub_res + 1 < table[i]):
					table[i] = sub_res + 1
	
	if table[V] == sys.maxsize:
		return -1
	
	return table[V]

# Driver Code
if __name__ == "__main__":

	coins = [1,5,7,9,11]
	m = len(coins)
	V = 25
	print("Minimum coins required is ",
				minCoins(coins, m, V))

