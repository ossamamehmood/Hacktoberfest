import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Solution {
    public String intToRoman(int num) {
        String str="";
        int n=num;
        while((n/1000)>0){
            str= str+"M";
            n=n-1000;
        }
        while(n/100 > 0){
            if(n/100==9){
                str=str+"C"+"M";
                n=n-900;
            }
            else if(n/100 >=5){
                str=str+"D";
                n=n-500;
            }
            else if(n/100==4){
                str=str+"C"+"D";
                n=n-400;
            }
            else{
                str=str+"C";
                n=n-100;
            }
        }
        while(n/10 > 0){
            if(n/10==9){
                str=str+"X"+"C";
                n=n-90;
            }
            else if(n/10 >=5){
                str=str+"L";
                n=n-50;
            }
            else if(n/10 ==4){
                str=str+"X"+"L";
                n=n-40;
            }
            else{
                str=str+"X";
                n=n-10;
            }
        }
        while(n > 0){
            if (n==9){
                str=str+"I"+"X";
                n=n-9;
            }
            else if(n>=5){
                str=str+"V";
                n=n-5;
            }
            else if(n ==4){
                str=str+"I"+"V";
                n=n-40;
            }
            else{
                str=str+"I";
                n=n-1;
            }
        }
        return str;
    }
}
