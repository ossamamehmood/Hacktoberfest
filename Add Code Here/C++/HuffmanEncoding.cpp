#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define deb(x) cout << #x << " " << x << " ";
#define debl(x) cout << #x << " " << x << "\n";



struct Node
{
    char data;
    unsigned count;
    string code;
    Node *left, *right;

    Node(char data, int count)
    {
        this->data = data;
        this->count = count;
        left = right = NULL;
    }
};


struct Compare
{
    bool operator()(Node *l, Node *r)
    {
        return (l->count > r->count);
    }
};


// O(log(n))
void showCodes (Node *root)
{
    if (!root)
        return;

    if (root->data != '#')
        cout << root->data << "\t" << root->count << "\t" << root->code << endl;

    showCodes(root->left);
    showCodes(root->right);
}


// O(log(n))
void encode(Node *root, string code)
{
    if (root->left == NULL && root->left == NULL)
        root->code = code;

    else
    {
        encode(root->left, code + '0');
        encode(root->right, code + '1');
    }
}


// O(n*log(n))
void huffmanEncode (map<char, int> m)
{
    priority_queue<Node *, vector<Node *>, Compare> minHeap;

    for (auto it = m.begin(); it != m.end(); it++)
        minHeap.push(new Node(it->first, it->second));

    while (minHeap.size() > 1)
    {
        Node *l = minHeap.top();
        minHeap.pop();

        Node *r = minHeap.top();
        minHeap.pop();

        Node *new_node = new Node('#', l->count + r->count);
        new_node->left = l;
        new_node->right = r;

        minHeap.push(new_node);
    }

    encode(minHeap.top(), "");
    showCodes(minHeap.top());
}


void SHIV (string file_name)
{
    ifstream file;
    file.open(file_name);

    if (!file)
        cout << file_name << " doesn't exist!\n";

    else
    {
        char c;
        map<char, int> m;

        while (!file.eof())
        {
            file.get(c);
            m[c]++;
        }

        huffmanEncode(m);
    }

    file.close();
}


int main (int argc, char **argv)
{
    ios_base::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);

    if (argc != 2)
        cout << "Usage: ./a.out <file_name.txt>\n";
    else
        SHIV(argv[1]);

    cerr << "Time taken: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}