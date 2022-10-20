
// You are given N number of words.
// You are given M puzzles in the form of M strings.
// For a given puzzle, a word is valid if both the following conditions are confirmed - 
//     Condition 1 -> Word contains the first letter of puzzle.
//     Condition 2 -> For each letter in word, that letter should be present in puzzle.
// You have to print the number of valid words corresponding to a puzzle.

#include<bits/stdc++.h>
using namespace std;
int wordMask(string &word){
    int mask = 0;
    for(auto c:word){
        mask = mask | 1<<(c-'a');
    }
    return mask;
}
vector<int> solution(vector<string> &words,vector<string> &puzzles){
    unordered_map<int,int> mpp;
    for(auto word:words){
        mpp[wordMask(word)]++;
    }
    vector<int> ans;
    for(auto p:puzzles){
        int mask = wordMask(p);
        int submask=mask;
        int first = (1<<(p[0]-'a'));
        int curr = 0;
        while(submask){
            if(submask & first){
                curr+=mpp[submask];
            }
            submask = (submask-1) & mask;
        }
        ans.push_back(curr);
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n;
    vector<string> words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    cin>>m;
    vector<string> puzzles(m);
    for(int i=0;i<m;i++){
        cin>>puzzles[i];
    }
    vector<int> ans=solution(words,puzzles);
    for(int i=0;i<m;i++){
        cout<<puzzles[i]<<"->"<<ans[i]<<endl;
    }
    return 0;
}

// input...
// 7
// aaaa asas able ability actt actor access 
// 6
// aboveyz abrodyz abslute absoryz actresz gaswxyz

// output
// aboveyz -> 1
// abrodyz -> 1
// abslute -> 3
// absoryz -> 2
// actresz -> 4
// gaswxyz -> 0
