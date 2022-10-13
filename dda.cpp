#include <bits/stdc++.h>
using namespace std;
 
void DDALine(int x0, int y0, int x1, int y1)
{

    int dx = x1 - x0;
    int dy = y1 - y0;
 
    int step;

    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);
 
    
    float x_incr = (float)dx /step;
    float y_incr = (float)dy /step; 

    float x = x0;
    float y = y0;
 
    for (int i = 0; i < step; i++) {

        x+= x_incr;
        y+=y_incr;

        cout<<round(x)<<" "<<round(y)<<endl;
    }
}
 
int main()
{
 
    int x0,y0,x1,y1;
    cin>>x0>>y0>>x1>>y1;
    DDALine(x0, y0, x1, y1);
 
    return 0;
}