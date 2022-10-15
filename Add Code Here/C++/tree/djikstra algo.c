#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct MinHeapNode
{
	int v;
	int dist;
} MinHeapNode;

struct MinHeap
{
	int size;	
	int capacity;
	int *pos;
	struct MinHeapNode **arr;
};

struct AdjListNode
{
	int dest;
	int weight;
	struct AdjListNode* next;
};

struct AdjList
{
struct AdjListNode *head;
};

struct Graph
{
	int V;
	struct AdjList* arr;
};

struct AdjListNode* newAdjListNode(int dest, int weight)
{
	struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int V)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;

	graph->arr = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    int i;
	for (i = 0; i < V; ++i)
		graph->arr[i].head = NULL;

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight)
{
	struct AdjListNode* newNode = newAdjListNode(dest, weight);
	newNode->next = graph->arr[src].head;
	graph->arr[src].head = newNode;

	newNode = newAdjListNode(src, weight);
	newNode->next = graph->arr[dest].head;
	graph->arr[dest].head = newNode;
}

struct MinHeapNode* newMinHeapNode(int v, int dist)
{
	struct MinHeapNode* minHeapNode =(struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
	minHeapNode->v = v;
	minHeapNode->dist = dist;
	return minHeapNode;
}

struct MinHeap* createMinHeap(int capacity)
{
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	minHeap->pos = (int *)malloc(capacity * sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->arr =(struct MinHeapNode**)malloc(capacity *sizeof(struct MinHeapNode*));
	return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx)
{
	int smallest, left, right;
	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;

	if (left < minHeap->size &&
		minHeap->arr[left]->dist <
		minHeap->arr[smallest]->dist )
	smallest = left;

	if (right < minHeap->size &&
		minHeap->arr[right]->dist <
		minHeap->arr[smallest]->dist )
	smallest = right;

	if (smallest != idx)
	{
		MinHeapNode *smallestNode = minHeap->arr[smallest];
		MinHeapNode *idxNode = minHeap->arr[idx];

		minHeap->pos[smallestNode->v] = idx;
		minHeap->pos[idxNode->v] = smallest;

		swapMinHeapNode(&minHeap->arr[smallest],
						&minHeap->arr[idx]);

		minHeapify(minHeap, smallest);
	}
}

int isEmpty(struct MinHeap* minHeap)
{
	return minHeap->size == 0;
}

struct MinHeapNode* extractMin(struct MinHeap*minHeap)
{
	if (isEmpty(minHeap))
		return NULL;

	struct MinHeapNode* root =
				minHeap->arr[0];

	struct MinHeapNode* lastNode = minHeap->arr[minHeap->size - 1];
	minHeap->arr[0] = lastNode;

	minHeap->pos[root->v] = minHeap->size-1;
	minHeap->pos[lastNode->v] = 0;

	--minHeap->size;
	minHeapify(minHeap, 0);

	return root;
}

void decreaseKey(struct MinHeap* minHeap, int v, int dist)
{
	int i = minHeap->pos[v];

	minHeap->arr[i]->dist = dist;

	while (i && minHeap->arr[i]->dist < minHeap->arr[(i - 1) / 2]->dist)
	{
		minHeap->pos[minHeap->arr[i]->v] = (i-1)/2;
		minHeap->pos[minHeap->arr[(i-1)/2]->v] = i;
		swapMinHeapNode(&minHeap->arr[i], &minHeap->arr[(i - 1) / 2]);

		i = (i - 1) / 2;
	}
}

bool isInMinHeap(struct MinHeap *minHeap, int v)
{
if (minHeap->pos[v] < minHeap->size)
	return true;
return false;
}

void printPath(int parent[], int destination)
{
    if(parent[destination] == -1) {
        printf("%d ", destination);
        return;
    }
    printPath(parent, parent[destination]);
    printf("%d ", destination);
}

void printArr(int parent[], int dist[], int n)
{
	printf("Vertex   Distance from Source\n");
	int i;
	for (i = 0; i < n; ++i){
		printf("%d \t\t %d \t\t Path:", i, dist[i]);
		printPath(parent, i);
		printf("\n");
	}
}

void dijkstra(struct Graph* graph, int src)
{
	
	int V = graph->V;
	int dist[V];
	int parentVertex[V];
	parentVertex[src] = -1;

	struct MinHeap* minHeap = createMinHeap(V);
    int v;
	for ( v = 0; v < V; ++v)
	{
		dist[v] = INT_MAX;
		minHeap->arr[v] = newMinHeapNode(v, dist[v]);
		minHeap->pos[v] = v;
	}

	minHeap->arr[src] = newMinHeapNode(src, dist[src]);
	minHeap->pos[src] = src;
	dist[src] = 0;
	decreaseKey(minHeap, src, dist[src]);

	minHeap->size = V;

	while (!isEmpty(minHeap))
	{
		struct MinHeapNode* minHeapNode = extractMin(minHeap);
	
		int u = minHeapNode->v;

		struct AdjListNode* pCrawl = graph->arr[u].head;
		while (pCrawl != NULL)
		{
			int v = pCrawl->dest;

			if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX && pCrawl->weight + dist[u] < dist[v])
			{
				dist[v] = dist[u] + pCrawl->weight;
			    parentVertex[v] = u;
				decreaseKey(minHeap, v, dist[v]);
			}
			pCrawl = pCrawl->next;
		}
	}

	printArr(parentVertex, dist, V);
}

int main()
{
	int V = 5;
	struct Graph* graph = createGraph(V);
	addEdge(graph, 0, 1, 10);
	addEdge(graph, 0, 3, 5);
	addEdge(graph, 1, 2, 1);
	addEdge(graph, 1, 3, 2);
	addEdge(graph, 2, 4, 4);
	addEdge(graph, 3, 1, 3);
	addEdge(graph, 3, 2, 9);
	addEdge(graph, 3, 4, 9);
	addEdge(graph, 3, 4, 2);
	addEdge(graph, 4, 0, 7);
	addEdge(graph, 4, 2, 6);


	dijkstra(graph, 0);

	return 0;
}
