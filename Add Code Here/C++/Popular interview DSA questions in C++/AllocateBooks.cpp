// Question Link : https://www.codingninjas.com/codestudio/problems/ayush-gives-ninjatest_1097574

/*
    Time Complexity: O(M * log(K))
    Space complexity: O(1),

    where 'K' is the sum of the time required to study all the chapters 
    and 'M' is the number of chapters.
*/

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{

    long long sum = 0;

    int maxTime = INT_MIN;

    // We will iterate through all the chapters and calculate the sum.
    for (int i = 0; i < m; i++)
    {
        sum += time[i];
        maxTime = max(maxTime , time[i]);
    }

    // We will initialize the lower limit of binary search l with maxTime and the upper limit of binary search with sum.
    long long l = maxTime, r = sum, answer = sum;

    while (l <= r)
    {
        
        long long mid = (l + r) / 2;
        long days = 1;
        long long currentTime = 0;

        for (int i = 0; i < m; i++)
        {
            currentTime += time[i];
            if (currentTime > mid)
            {
                days++;
                currentTime = time[i];
            }

        }

        /*
            If the days required to study all the chaptes is greater than n than answer is not possible
            and we want more time to study in a given day so we will compress the range to the right hand side.
            Else we can study all the chapters and we will update the answer with mid.
        */
        if (days <= n)
        {
            answer = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }

    }

    // We will return the final answer.
    return answer;
}
