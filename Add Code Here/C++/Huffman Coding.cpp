/ Enter the number of elements
// 5
// Enter the characters
// A B C D F
// Enter the frequencies of characters
// 5 1 2 4 10

// Huffman Codes are :
// F : 0
// A : 10
// B : 1100
// C : 1101
// D : 111
//  ------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct Node {

	char data;
	int freq;
	Node *left, *right;

	Node(char data, int freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare{

	bool operator()(Node* l, Node* r)
	{
		return (l->freq > r->freq);
	}
};

void print(struct Node* root, string str)
{
	if (!root)
		return;

	if (root->data != '$')
		cout <<root->data<<" : "<<str<<"\n";

	print(root->left,str+"0");
	print(root->right,str+"1");
}

void HuffmanCoding(char data[], int freq[], int n)
{
	Node *left, *right, *top;
	priority_queue<Node*, vector<Node*>, compare> minHeap;

	for (int i = 0; i < n; ++i)
		minHeap.push(new Node(data[i], freq[i]));

	while (minHeap.size() != 1) {

		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new Node('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);

	}
	cout<<endl;
	cout<<"Huffman Codes are : "<<endl;
	print(minHeap.top(), "");
}

int main()
{
    cout<<"Enter the number of elements"<<endl;
	int n;
    cin>>n;

    cout<<"Enter the characters"<<endl;
    char arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Enter the frequencies of characters"<<endl;
    int freq[n];
    for(int i=0;i<n;i++)
        cin>>freq[i];

	HuffmanCoding(arr, freq, n);

	return 0;
}
