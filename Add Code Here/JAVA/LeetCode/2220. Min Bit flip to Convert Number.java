class Solution {
    public int minBitFlips(int start, int goal) {
        //using RSB
        
    //     int temp = start ^ goal;
    //     int ans=0;
    //     while(temp!=0){
    //         int rsb= temp & -temp;
    //         temp-=rsb;
    //         ans++;
    //     }
    //     return ans;
    // 
    
int cnt=0;
int num = start^goal;
while(num!=0){
if((num&1)==1){
cnt++;
num=num>>1;
}else{
num=num>>1;
}
}
return cnt;
    }
}