#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

// Pair to store snake's tail coordinates
typedef pair<int, int> Point;

// Construct maximum length snake sequence from the given tail and `L[]` matrix
vector<Point> constructPath(vector<vector<int>> const &L,
				vector<vector<int>> const &grid, Point tail)
{
	vector<Point> path;
	path.push_back(tail);

	int i = tail.first;
	int j = tail.second;

	// start from snake's tail till snake's head
	while (L[i][j])
	{
		if (i - 1 >= 0 && L[i][j] - L[i - 1][j] == 1 &&
			abs(grid[i - 1][j] - grid[i][j]) == 1)
		{
			path.push_back(make_pair(i - 1, j));
			i--;
		}
		// note that there can be multiple paths – hence we have placed 'else' block
		else if (j - 1 >= 0 && (L[i][j] - L[i][j - 1] == 1) &&
			abs(grid[i][j - 1] - grid[i][j]) == 1)
		{
			path.push_back(make_pair(i, j - 1));
			j--;
		}
	}

	// return vector containing the path
	return path;
}

// Function to find the maximum length of snake sequence in a given matrix
vector<Point> findMaxLengthSnakeSequence(vector<vector<int>> const &grid)
{
	// `N × N` matrix
	int N = grid.size();

	// base case
	if (N == 0) {
		return {};
	}

	// `L[i][j]` stores the maximum length of the snake sequence
	// ending at cell (i, j)
	vector<vector<int>> L(N, vector<int>(N));

	// stores the maximum length of the snake sequence
	int max_so_far = 0;

	// Pair to store coordinates of a snake's tail
	Point tail;

	// process the matrix in a bottom-up fashion
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// initialize each element by 0
			L[i][j] = 0;

			// compare the current cell with the top cell and check the
			// absolute difference
			if (i - 1 >= 0 && abs(grid[i - 1][j] - grid[i][j]) == 1)
			{
				L[i][j] = L[i - 1][j] + 1;
				if (max_so_far < L[i][j])
				{
					max_so_far = L[i][j];
					tail = make_pair(i, j);
				}
			}

			// compare the current cell with the left cell and check the
			// absolute difference
			if (j - 1 >= 0 && abs(grid[i][j - 1] - grid[i][j]) == 1)
			{
				// `L[i][j]` can be non-zero at this point, hence take the maximum
				L[i][j] = max(L[i][j], L[i][j - 1] + 1);

				if (max_so_far < L[i][j])
				{
					max_so_far = L[i][j];
					tail = make_pair(i, j);
				}
			}
		}
	}

	// construct the maximum length snake sequence
	return constructPath(L, grid, tail);
}

void printSnakeSequence(vector<vector<int>> const &grid, vector<Point> const &path)
{
	// base case
	if (path.size() == 0) {
		return;
	}

	cout << "The maximum length snake sequence is ";

	// use reverse iterator to print the vector (from snake's head to tail)
	auto it = path.rbegin();
	while (it != path.rend()) {
		cout << grid[it->first][it->second];
		if (++it != path.rend()) {
			cout << " — ";
		}
	}

	cout << endl << "The length is " << path.size() - 1;
}

int main()
{
	vector<vector<int>> grid =
	{
		{ 7, 5, 2, 3, 1 },
		{ 3, 4, 1, 4, 4 },
		{ 1, 5, 6, 7, 8 },
		{ 3, 4, 5, 8, 9 },
		{ 3, 2, 2, 7, 6 }
	};

	vector<Point> path = findMaxLengthSnakeSequence(grid);
	printSnakeSequence(grid, path);

	return 0;
}