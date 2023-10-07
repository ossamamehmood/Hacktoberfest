class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> vec1;
        int sum1=0,sum2=0,flag=1;
        while(num!=0){
            vec1.push_back(num%10);
            num=num/10;
        }
        int d=vec1.size();
        for(int i=d-1;i>=0;i--){
            if(vec1[i]!=9){
                flag=0;
                for(int j=d-1;j>=0;j--){
                    if(vec1[j]==vec1[i]){
                        sum1=sum1*10+9;
                    }
                    else{
                        sum1=sum1*10+vec1[j];
                    }
                }
                break;
            }
        }
        if(flag==1){
            for(int j=d-1;j>=0;j--){
                sum1=sum1*10+vec1[j];
            }
        }
        int temp=vec1[d-1];
        for(int i=d-1;i>=0;i--){
            if(vec1[i]==temp){
                sum2=sum2*10+0;
            }
            else{
                sum2=sum2*10+vec1[i];
            }
        }
        cout<<sum1<<' '<<sum2;
        return sum1-sum2;
    }
};
