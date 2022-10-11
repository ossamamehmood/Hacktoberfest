class MyCalendarThree {
    map<int,int> st,ed;
    
public:
    MyCalendarThree() {
        
        
        
    }
    
    int book(int start, int end) {
        
        st[start]++;
        ed[end]++;
        st[end];
        int c=0;
        int ans=0;
        for(auto it: st){
           
            c+= it.second;
            c-= ed[it.first];
            
            ans= max(c,ans);
            
           
            
            
        }
        
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
