#include <bits/stdc++.h>

using namespace std;

/// Time complexity: O(n^2)
/// Space complexity: O(1);
void insertion_sort(vector<int> &v){

    for(int i = 1 ; i < v.size();  i++){

        int key = v[i] ;
        int j = i-1;

        while(j >= 0 && v[j] > key){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
    
}

/// Time complexity: O(n^2)
/// Space complexity: O(1);
void selection_sort(vector<int> &v){

    for(int i  = 0 ; i < v.size()-1 ; i++){

        int minimum_val_indx = i ;
        for(int j = i +1 ; j < v.size() ; j++){
            
            if(v[j] < v[minimum_val_indx]) minimum_val_indx = j;
        }
        swap(v[i],v[minimum_val_indx]);
    }
}

/// Time complexity: O(n)
/// Space complexity: O(n);

void count_sort(vector<int> &v){

    int maxVal = *max_element(v.begin() , v.end());
    int minVal= *min_element(v.begin(), v.end());
    
    vector<int> count(maxVal - minVal +1);

    for( int i = 0 ; i < v.size() ; i++){
        count[v[i] - minVal]++;
    }

    int idx {0};
    for(int i = 0 ; i < count.size() ; i++){

        while(count[i]){
            v[idx++] = i + minVal;
            count[i]--;
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
    vector<int> selection_v = {40,23,0,-40,-30,100,-15,99};
    vector<int> count_v     = {40,23,0,-40,-30,100,-15,99};
    
    insertion_sort(insertion_v);
    selection_sort(selection_v);
    count_sort(count_v);

    cout<<"insertion sort: \n";
    print(insertion_v);
    cout<<"selection sort: \n";
    print(selection_v);
    cout<<"count sort: \n";
    print(count_v);

}