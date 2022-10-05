#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
#define endl '\n'
using namespace std;
struct Node{
	Node *links[26];
	bool k = false;
	
	// Check if the key is present in the node
	bool containsKey(char ch){
		return links[ch-'a']!=NULL;
	}
	// put function
	void put(char ch,Node *node){
		links[ch-'a']=node;
	}
	
	// get function
	Node *get(char ch){
		return links[ch-'a'];
	}
	
	// set finishing of a word
	void setf(){
		k = true;
	}
	
	// check finishing of a word
	bool finish(){
		return k;
	}
};

class Trie{
//	private:
		Node *root;
	public:
		// Constructor
		Trie(){
			root = new Node();
		}
		
		// Insert a word into the trie
		void insert(string word){
			Node *node = root;
			for(int i=0;i<word.size();i++){
				// Checking if the character is present
				// else we'll simply create and put address
				// by making a reference trie to it
				if(!node->containsKey(word[i])){
					node->put(word[i],new Node());
				}
				// we'll simply move our node to reference trie
				// if we get the characters we want to insert
				node = node->get(word[i]);
			}
			
			// Lastly set the flag value to true indicating finishing
			// of the word
			node->setf();
		}
		
		// Searching operation
		bool search(string word){
			Node *node = root;
			for(int i=0;i<word.size();i++){
				// Searching each character of the word
				if(!node->containsKey(word[i])){
					return false;
				}
				// move to reference node
				node = node->get(word[i]);
			}
			return node->finish();
		}
		
		 /** Returns if there is any word in the trie
		  that starts with the given prefix. */
	   	bool startsWith(string prefix) {
			Node *node=root;
			for(int i=0;i<prefix.size();i++){
				// Searching each character of the word
				if(!node->containsKey(prefix[i])){
					return false;
				}
				// move to reference node
				node = node->get(prefix[i]);
			}
			return true;
    	}
};
int main(){
	int n;
	cin>>n;
	Trie *obj = new Trie();
	while(n!=-1){
		string s;
		cin>>s;
		switch(n){
			case 1:obj->insert(s);break;
			case 2:obj->search(s)?printf("True\n"):printf("False\n");break;
			case 3:obj->startsWith(s)?printf("True\n"):printf("False\n");break;
			default:printf("Invalid Choice\n");break;
		}
		cin>>n;
	}
}