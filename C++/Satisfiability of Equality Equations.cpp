class Solution {
    
    vector<char> par;
    
    char getPar(char a){
        if(par[a]==a)
            return a;
        return getPar(par[a]);
    }
    void un(char a,char b){
      
        char x= getPar(a);
        char y= getPar(b);
        
        if(x==y)
            return ;
      
        par[y]=a;
        
        
    }
    
public:
    bool equationsPossible(vector<string>& eq) {
        
        par.resize(300,-1);
        
        for(int i=0;i<300;i++)
        {
            par[i]=(char)i;     
        }
        
        
        for(auto it: eq){
            if(it[1]=='!')
                continue;
            
            un(it[0],it[3]);
            
        }
        
        
        for(auto it: eq){
            if(it[1]=='=')
                continue;
            
           if(getPar(it[0])== getPar(it[3]))
               return 0;
            
        }
        
        return 1;
        
        
  
    }
};
