#include<bist.std++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int arr[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string code[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string s="";
        for(int i=0;i<13;i++){
            while(num>=arr[i]){
                s += code[i];
                num -= arr[i];
            }
        }
        return s;
    }
};


int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int roman = ob.intToRoman(N);
        cout << roman << endl;
    }
  return 0;
}
