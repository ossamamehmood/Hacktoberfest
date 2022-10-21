#include <iostream>
using namespace std;

struct Node
{
	int value;
	struct Node* next;
};

struct Bucket
{
	struct Node *head;
};

struct BucketList
{
	int V;
	struct Bucket * array;
};

struct Node* newNode(int value)
{
	struct Node* newnode = new Node;
	newnode->value = value;
	newnode->next = NULL;
	return newnode;
}

struct BucketList* createBucket(int V)
{
	int i;
	struct BucketList* bl = new BucketList;

	bl->V = V;
	bl->array = new Bucket[V];

	for(i = 0; i < V; i++)
		bl->array[i].head = NULL;

	return bl;
}

void addNode(struct BucketList* bl, int bckt, int value)
{
	struct Node *newnode = newNode(value);
	struct Node *temp = new Node;

	if(bl->array[bckt].head != NULL)
	{
		temp = bl->array[bckt].head;
		if(temp->value > newnode->value)
		{
			newnode->next = bl->array[bckt].head;
			bl->array[bckt].head = newnode;
		}
		else
		{
			while(temp->next != NULL)
			{
				if((temp->next)->value > newnode->value)
					break;

				temp = temp->next;
			}
			newnode->next = temp->next;
			temp->next = newnode;
		}
	}
	else
	{
		bl->array[bckt].head = newnode;
	}
}

void printBuckets(struct BucketList *bl)
{
	int v;
	struct Node* pCrawl = new Node;

	for(v = 0; v < bl->V; v++)
	{
		pCrawl = bl->array[v].head;
		while (pCrawl != NULL)
		{
			cout<<"->"<< pCrawl->value;
			pCrawl = pCrawl->next;
		}
	}
}


int main()
{
	int V = 10, range, NOE, i;
	struct BucketList* mybucket = createBucket(V);


	cout<<"Enter the upper limit in the power of 10 (10 or 100 or 1000 ..) to create Bucket: ";
	cin>>range;
	range = range/10;

	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>NOE;
	int arr[100];

	for(i = 0; i < NOE; i++)
	{
		cout<<"Enter element "<<i+1<<" : ";
		cin>>arr[i];
		addNode(mybucket, arr[i]/range, arr[i]);
	}
	cout<<"\nSorted Data ";
	printBuckets(mybucket);

	return 0;
}
