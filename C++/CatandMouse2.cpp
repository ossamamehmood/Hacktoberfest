#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int memo[75][8][8][8][8];
    vector<string> v;
    int cj, mj;
    int R, C;
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, 1, -1};

    bool dp(int nturn, int cx, int cy, int mx, int my)
    {
        if (nturn % 2 == 1)
        {
            // mouse turn
            if (mx == cx && my == cy)
                return false; // mouse is caught by the cat, losing position for the mouse
            if (nturn >= 75)
                return false; // mouse can't win, it used many moves and it couldnt get the food
            if (v[mx][my] == 'F')
                return true; // winner position, mouse got the food
            if (v[cx][cy] == 'F')
                return false; // losing position, cat got the food
        }
        else
        {
            // cat turn
            if (mx == cx && my == cy)
                return true; // cat captured the mouse, winner position
            if (nturn >= 75)
                return true; // winner position for the cat, nice block ;)
            if (v[mx][my] == 'F')
                return false; // losing position, mouse got the food
            if (v[cx][cy] == 'F')
                return true; // winner position, cat got the food
        }

        if (memo[nturn][cx][cy][mx][my] != -1)
            return memo[nturn][cx][cy][mx][my];
        bool win = false;

        if (nturn % 2 == 1)
        {
            // mouse turn
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j <= mj; j++)
                {
                    int Mx = mx + j * di[i];
                    int My = my + j * dj[i];
                    if (Mx >= 0 && Mx < R && My >= 0 && My < C && v[Mx][My] != '#')
                    {
                        if (dp(nturn + 1, cx, cy, Mx, My) == 0)
                        { // If there is any move that causes the next player to lose then I am in a winning position.
                            win = true;
                            break;
                        }
                    }
                    else
                        break;
                }
                if (win)
                    break;
            }
        }
        else
        {
            // cat turn
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j <= cj; j++)
                {
                    int Cx = cx + j * di[i];
                    int Cy = cy + j * dj[i];
                    if (Cx >= 0 && Cx < R && Cy >= 0 && Cy < C && v[Cx][Cy] != '#')
                    {
                        if (dp(nturn + 1, Cx, Cy, mx, my) == 0)
                        { // If there is any move that causes the next player to lose then I am in a winning position.
                            win = true;
                            break;
                        }
                    }
                    else
                        break;
                }
                if (win)
                    break;
            }
        }

        memo[nturn][cx][cy][mx][my] = win;
        return win;
    }

    bool canMouseWin(vector<string> &_v, int _cj, int _mj)
    {
        memset(memo, -1, sizeof(memo));
        v = _v;
        cj = _cj;
        mj = _mj;
        int cx, cy, mx, my;
        R = v.size();
        C = v[0].size();

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
            {
                if (v[i][j] == 'C')
                {
                    cx = i;
                    cy = j;
                }

                if (v[i][j] == 'M')
                {
                    mx = i;
                    my = j;
                }
            }
        return dp(1, cx, cy, mx, my);
    }
};