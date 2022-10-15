int maxDiff(int num) {
        vector<int> v1,v2; // break number into individual digits and store in vector
        int n = num,rem=0;
        while(n){
            rem = n%10;
            v1.push_back(rem);
            v2.push_back(rem);
            n = n/10;
        }
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        int mx = 0, mn = 0, val, ex;
		// Find and replace digits in vectors and then compose the number
        bool flag = true;
        for(int i=0;i<v1.size();i++){
            if(flag){ // Start index to be replaced not found yet
                if(v1[i]!=9){
                    flag = false;
                    ex = v1[i];
                    v1[i] = 9;
                }
                mx = (mx*10+v1[i]);
                continue;
            }
            if(v1[i]==ex)
                v1[i]=9;
            mx = (mx*10+v1[i]);
        }
        flag = true;
        for(int i=0;i<v2.size();i++){
            if(flag){ // Replacement not found yet
                if(v2[i]>1){
                    flag = false;
                    ex = v2[i];
                    if(v2[0]==v2[i])
                        val = 1;
                    else 
                        val = 0;
                    v2[i]=val;
                }
                mn = (mn*10+v2[i]);
                continue;
            }
            if(v2[i]==ex)
                v2[i]=val;
            mn = (mn*10+v2[i]);
        }
        return mx-mn;
    }
