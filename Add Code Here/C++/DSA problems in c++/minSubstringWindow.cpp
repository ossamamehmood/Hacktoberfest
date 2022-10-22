string minWindow(string s, string t) {
        string res = "";
        if(s.size() < t.size()) return res;
        unordered_map<char, int> umap;
        for(auto it: t) umap[it]++;
        int i=0, j=0;
        int length = INT_MAX, count = umap.size();
        while(j<s.size()){
            if(umap.find(s[j])!=umap.end()){
                umap[s[j]]--;
                if(umap[s[j]]==0) count--;
            }
            if(count > 0) j++;
            else if(count == 0){
                while(count==0){
                    if(umap.find(s[i])!=umap.end()){
                        if(j-i+1 < length){
                            length = j-i+1;
                            res = s.substr(i, j-i+1);
                        }
                        umap[s[i]]++;
                        if(umap[s[i]] > 0) count++;
                    }
                    i++;
                }
                j++;
            }
        }
        return res;
    }
