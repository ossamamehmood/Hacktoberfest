#include<iostream>
#include<vector>
using namespace std;

void insertion_sort_reverse(vector<int> &v){

    for(int i = 1 ; i < v.size() ; i++){
        /// one solution
        /*
        int key = v[i];
        int j = i-1;
        while( j >= 0 && v[j] < key){
          v[j+1] = v[j];
          j--;
        }
        v[j+1] = key;
        */
        /// another
        for(int j = i ; j-1 >=0 && v[j-1] < v[j] ; j--){
            swap(v[j],v[j-1]);
        }
        
    }
}

void print(vector<int> &v){
    
    for(auto val : v){
        cout << val << " ";
    }
    cout << endl;
}

int main(){

    vector<int> insertion_v = {40,23,0,-40,-30,100,-15,99};
    
    insertion_sort_reverse(insertion_v);

    cout<<"insertion sort (Descending Order): \n";
    print(insertion_v);

    cout <<"\nNo Run Time Error!\n";
}   