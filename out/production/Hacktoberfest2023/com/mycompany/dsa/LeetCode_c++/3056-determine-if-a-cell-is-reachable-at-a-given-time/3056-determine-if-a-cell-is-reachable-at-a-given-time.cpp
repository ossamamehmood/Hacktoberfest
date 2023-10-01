class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
    {
       int x=abs(fx-sx);
       int y=abs(fy-sy);

       int dis = max(x,y);

       if(t<dis)
        return false;
       if( dis==0 )
        return t!=1;

       return true;     
    }
};