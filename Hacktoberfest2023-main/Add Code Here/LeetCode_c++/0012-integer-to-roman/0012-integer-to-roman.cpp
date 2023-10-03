class Solution {
public:
    string intToRoman(int num) 
    {
        /*
          M 1000
          CM 900
          D 500
          CD 400
          C 100
          XC 90
          L 50
          XL 40
          X 10
          IX 9
          V 5
          IV 4
          I 1
        */
        vector<pair< string,int>>roman ;
         roman = {{"M",1000},{"CM",900},{"D",500},{"CD",400},{"C",100}
                  ,{"XC",90},{"L",50},{"XL",40},{"X",10},{"IX",9},{"V",5},
                   {"IV",4},{"I",1}};
        
        string ans="";
        for( int i = 0; i<roman.size();i++)
        {
            while( num >= roman[i].second )
            {
              ans+=roman[i].first;
              num-=roman[i].second;
            }
        }           
        return ans;
    }
};