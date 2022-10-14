class Solution {
public:
    string pushDominoes(string s) {
        
        
        int n = s.length();
        vector<int> R(n,INT_MIN),L(n,INT_MIN);
        
        int c=INT_MIN;
        for(int i=0;i<n;i++){
            
            if(s[i]=='R')
                c=0;
            if(s[i]=='L')
                c= INT_MIN;
            
            R[i]=c;
            if(c!=INT_MIN)
            c--;
           
            
            
        }
        
        c=INT_MIN;
        
         for(int i=n-1;i>=0;i--){
            
           
            if(s[i]=='L')
                c=0;
             if(s[i]=='R')
                c= INT_MIN;
            L[i]=c;
             if(c!=INT_MIN)
             c--;
             
            
        }
     
        string ans="";
        
        
//         for(int x: R)
//             cout<<x<<" ";
//         cout<<endl;
        
//         for(int x: L)
//             cout<<x<<" ";
//         cout<<endl;
        
        
        for(int i=0;i<n;i++){
            
            if(R[i]==L[i])
                ans+='.';
            else 
            if(R[i]>L[i])
                ans+='R';
            else ans+= 'L';
        }
        
        
        
        
        return ans;
        
        
        
        
        
        
        
    }
};
