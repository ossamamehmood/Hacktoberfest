class LUPrefix {
public:
    set<int> s;
    LUPrefix(int n) {
        for(int i=1; i<=n+1; i++) s.insert(i);
    }
    
    void upload(int video) {
        s.erase(video);
    }
    
    int longest() {
        return *s.begin()-1;
    }
};
