def emptyCells(N, K, tasks):

	matrix = [[-1 for i in range(N)]for j in range(N)]
	output = []

	for _ in tasks:
		x,y = _ 

		for i in range(N):
			matrix[x][i] = 0

		for i in range(N):
			matrix[i][y] = 0

		count = 0
		for arr in matrix:
			for i in arr:
				if i == -1:
					count += 1
		output.append(count)

	return output

test_cases = int(input())

while test_cases:

	N, K = map(int, input().split())
	tasks = []

	for t in range(K):
		i,j = map(int,input().split())
		X = i,j
		tasks.append(X)

	output = emptyCells(N, K, tasks)

	for emptyCell in output:
		print(emptyCell, end=' ')

	print()
	test_cases -= 1