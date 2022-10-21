#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// first try
//i able to aproach the problem but not coded
int bagOfTokensScore(vector<int> &tokens, int power)
{

    sort(tokens.begin(), tokens.end());
    // [26,48,87]

    int score = 0;
    int n = tokens.size(); // 3
    if (n == 0)
        return 0;
    // 26 < 81
    if (tokens[0] < power)
    {
        // face up
        power = power - tokens[0]; // 55
        score = 1;
    }
    else
    {
        return score;
    }

    if (n == 1)
        return score;
    // face down
    if (n - 1 != 1)
    {
        power = power + tokens[n - 1]; // 250
        score = 0;
    }

    int i = 1;
    while (i < n - 1 && tokens[i] <= power)
    {
        power = power - tokens[i];
        score++;
        i++;
    }

    return score;
}

// second try with see the solution
int bagOfTokensScore(vector<int> &tokens, int power)
{

    sort(tokens.begin(), tokens.end());
    // [26,48,87]

    int score = 0;
    int n = tokens.size(); // 3
    if (n == 0)
        return 0;
    // 26 < 81
    if (tokens[0] < power)
    {
        // face up
        power = power - tokens[0]; // 55
        score = 1;
    }
    else
    {
        return score;
    }

    if (n == 1)
        return score;
    // face down
    if (n - 1 != 1)
    {
        power = power + tokens[n - 1]; // 250
        score = 0;
    }

    int i = 1;
    while (i < n - 1 && tokens[i] <= power)
    {
        power = power - tokens[i];
        score++;
        i++;
    }

    return score;
}
int main()
{
    cout << "Bag of tokens" << endl;

    // https://leetcode.com/problems/bag-of-tokens/

    return 0;
}
