#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {

        int n = ratings.size();
        vector<int> candies(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        for (int i = n - 1; i > 0; i--)
        {
            if (ratings[i - 1] > ratings[i] && candies[i - 1] <= candies[i])
            {
                candies[i - 1] = candies[i] + 1;
            }
        }

        int total = 0;
        for (int candy : candies)
        {
            total += candy;
        }

        return total;
    }
};

int main()
{

    // call the fn here
    return 0;
}