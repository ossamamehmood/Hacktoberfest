class Solution {
public:
    string intToRoman(int num) {
        int normal[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res;
        for(int i=0;i<13;i++){
            while(num>=normal[i]){
                res.append(roman[i]);
                num-=normal[i];
            }
        }
        return res;
    }
};
