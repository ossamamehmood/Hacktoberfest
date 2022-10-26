# Recursive Python3 program for
# coin change problem.

# Returns the count of ways we can sum
# coins[0...n-1] coins to get sum "sum"


def count(coins, n, sum):

	# If sum is 0 then there is 1
	# solution (do not include any coin)
	if (sum == 0):
		return 1

	# If sum is less than 0 then no
	# solution exists
	if (sum < 0):
		return 0

	# If there are no coins and sum
	# is greater than 0, then no
	# solution exist
	if (n <= 0):
		return 0

	# count is sum of solutions (i)
	# including coins[n-1] (ii) excluding coins[n-1]
	return count(coins, n - 1, sum) + count(coins, n, sum-coins[n-1])


# Driver program to test above function
coins = [1, 2, 3]
n = len(coins)
print(count(coins, n, 4))

# This code is contributed by Smitha Dinesh Semwal
