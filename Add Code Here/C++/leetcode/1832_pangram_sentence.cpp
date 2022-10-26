#include<iostream>
#include<vector>

using namespace std;

bool checkIfPangram(string word) {
        vector<bool> v(26,false);   //vector to store if an alphabet is present in word or not

        //Updating v vector to true of index corrosponding to that alphabet is present in word
        for(int i=0; i<word.size(); i++){
            if(v[word[i]-'a']==true)
                continue;
            else v[word[i]-'a']=true;
        }

        //Check if all index's value is true or not in v vector
        for(int i=0; i<v.size(); i++){
            if(v[i]==false) //false means an alphabet is missing in word 
                return false;   //so it's not a pangram word and it will return flase
        }

        return true;    //all index's value is true means all 26 alphabets are present in word
                        //means it's a pangram word
    }

int main(){
    string word;   
    cout<<"Check whether a word is pangram or not\n";
    cout<<"Enter the word:\t";
    cin>>word; 
    if(checkIfPangram(word)){
        cout<<"Yes, the given word is a pangram\n";
    }
    else{
        cout<<"No, the given word is not a pangram\n";
    }
    return 0;
}
