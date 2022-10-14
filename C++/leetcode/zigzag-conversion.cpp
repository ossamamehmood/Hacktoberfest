class Solution {
public:
    string convert(string s, int numRows) {
        string result="";
        if(numRows==1)
      return s;
        int step1,step2;
        int len=s.size();
        for(int i=0;i<numRows;++i){
            step1=(numRows-i-1)*2;
            step2=(i)*2;
            int pos=i;
            if(pos<len)
                result+=s.at(pos);
            while(1){
                pos+=step1;
                if(pos>=len)
                    break;
        if(step1)
          result+=s.at(pos);
                pos+=step2;
                if(pos>=len)
                    break;
        if(step2)
          result+=s.at(pos);
            }
        }
        return result;
    }
};
