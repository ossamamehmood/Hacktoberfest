class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        // here matrix = adjacency matrix
        int V = matrix.size();

        for (int k = 0; k < V; ++k)
        {
            for (int i = 0; i < V; ++i)
            {
                for (int j = 0; j < V; ++j)
                {
                    if (matrix[i][k] == -1 || matrix[k][j] == -1)
                        continue;
                    else if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
};

// O(V^3)