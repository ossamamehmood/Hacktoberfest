#include <bits/stdc++.h>
using namespace std;

const int N = 20;    // maximum number of cities
int dist[N][N];      // distance matrix
int memo[1 << N][N]; // memoization array
int n;               // number of cities

// function to calculate the distance between two cities
int calc_dist(int i, int j)
{
    // code to calculate distance between city i and city j
}

// function to solve the TSP using dynamic programming
int tsp(int mask, int pos)
{
    if (mask == (1 << n) - 1)
    {                        // all cities have been visited
        return dist[pos][0]; // return distance from last city to starting city
    }
    if (memo[mask][pos] != -1)
    { // if already calculated, return memoized value
        return memo[mask][pos];
    }
    int ans = INT_MAX; // initialize answer to maximum value
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {                                                        // if city has not been visited
            int new_mask = mask | (1 << city);                   // mark city as visited
            int new_ans = dist[pos][city] + tsp(new_mask, city); // calculate new answer
            ans = min(ans, new_ans);                             // update answer with minimum value
        }
    }
    memo[mask][pos] = ans; // memoize answer
    return ans;
}

int main()
{
    // code to input number of cities and distance matrix
    memset(memo, -1, sizeof(memo));              // initialize memoization array to -1
    int ans = tsp(1, 0);                         // solve TSP starting from city 0
    cout << "Minimum distance: " << ans << endl; // output minimum distance
    return 0;
}
