class Solution {
public:
    string reverseVowels(string s) {
        int n=s.length()-1;
        for(int i=0;i<=n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                while(i<=n && !(s[n]=='a' || s[n]=='e' || s[n]=='i' || s[n]=='o' || s[n]=='u' || s[n]=='A' || s[n]=='E' || s[n]=='I' || s[n]=='O' || s[n]=='U')){
                    n--;
                }
                if(i<=n)
                {
                    char temp=s[i];
                    s[i]=s[n];
                    s[n]=temp;
                    n--;
                }
            }
        }
        return s;
        
    }
};

