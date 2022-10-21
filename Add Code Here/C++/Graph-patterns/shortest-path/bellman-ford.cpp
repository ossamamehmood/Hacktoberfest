// SINGLE SOURCE SHORTEST PATH
// SLOWER THAN DIJKSTRA'S
// O(V^3) WORST TIME
// DOES NOT WORK FOR NEGATIVE EDGE WEIGHT CYCLES
// BUT CAN DETECT NEGATIVE EDGE WEIGHT CYCLES

// DIRECTED GRAPHS => WORKS FOR +VE EDGES AND -VE EDGES
// UNDIRECTED GRAPHS => WORKS FOR +VE EDGES ONLY

// RELAX N - 1 TIMES
// THEN RELAX 1 MORE TIME

// CONCEPT -> 'N-1' IS THE MAX NUMBER OF RELAXATIONS REQUIRED TO GET SHORTEST DISTANCES

class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        int dis[n];
        for (int i = 0; i < n; ++i)
            dis[i] = INT_MAX;

        dis[0] = 0;
        bool updated; // flag

        // relax n - 1 times
        for (int i = 0; i < n - 1; ++i)
        {
            updated = false;

            for (auto &e : edges)
            {
                int from = e[0], to = e[1], wt = e[2];

                if (dis[from] != INT_MAX && dis[from] + wt < dis[to])
                {
                    dis[to] = dis[from] + wt;
                    updated = true;
                }
            }

            if (updated == false)
                break;
        }

        // relax nth time
        if (updated == true)
            for (auto &e : edges)
            {
                int from = e[0], to = e[1], wt = e[2];

                if (dis[from] != INT_MAX && dis[from] + wt < dis[to])
                    return true; // negative cycle
            }

        return false; // no negative cycle
    }
};