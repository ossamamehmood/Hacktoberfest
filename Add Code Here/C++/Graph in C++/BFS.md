# BFS for a Graph
## **Breadth First Search**

**Breadth First Search** (BFS) algorithm traverses a graph in a breadthward motion and uses a queue to remember to get the next vertex to start a search, when a dead end occurs in any iteration 

<br>

***

## **Algorithm**

A standard BFS implementation puts each vertex of the graph into one of two categories:

1.Visited
2.Not Visited

The purpose of the algorithm is to mark each vertex as visited while avoiding cycles.

## The algorithm works as follows:

* Start by putting any one of the graph's vertices at the back of a queue.
* Take the front item of the queue and add it to the visited list.
* Create a list of that vertex's adjacent nodes. Add the ones which aren't in the visited list to the back of the queue.
* Keep repeating steps 2 and 3 until the queue is empty.


The graph might have two different disconnected parts so to make sure that we cover every vertex, we can also run the BFS algorithm on every node
<br>

***

## **BFS Example**
<br>


Let's see how the Breadth First Search algorithm works with an example. We use an undirected graph with 5 vertices.

![bfs-sort-algorithm1](https://cdn.programiz.com/sites/tutorial2program/files/graph-bfs-step-0.png)

Next, we visit the element at the front of queue i.e. 1 and go to its adjacent nodes. Since 0 has already been visited, we visit 2 instead.

![bfs-sort-algorithm2](https://cdn.programiz.com/sites/tutorial2program/files/graph-bfs-step-2_2.png)

Vertex 2 has an unvisited adjacent vertex in 4, so we add that to the back of the queue and visit 3, which is at the front of the queue.

![bfs-sort-algorithm3](https://cdn.programiz.com/sites/tutorial2program/files/graph-bfs-step-3.png)

then,

![bfs-sort-algorithm4](https://cdn.programiz.com/sites/tutorial2program/files/graph-bfs-step-4.png)

Only 4 remains in the queue since the only adjacent node of 3 i.e. 0 is already visited. We visit it.

![bfs-sort-algorithm5](https://cdn.programiz.com/sites/tutorial2program/files/graph-bfs-step-5.png)

Since the queue is empty, we have completed the Breadth First Traversal of the graph.

<br>

***

## **SAMPLE**

<br>

The code for the Breadth First Search Algorithm with an example is shown below. The code has been simplified so that we can focus on the algorithm rather than other details.

### **C++ Code**

```cpp
// BFS algorithm in C++

#include <iostream>
#include <list>

using namespace std;

class Graph {
  int numVertices;
  list<int>* adjLists;
  bool* visited;

   public:
  Graph(int vertices);
  void addEdge(int src, int dest);
  void BFS(int startVertex);
};

// Create a graph with given vertices,
// and maintain an adjacency list
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
}

// Add edges to the graph
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_back(dest);
  adjLists[dest].push_back(src);
}

// BFS algorithm
void Graph::BFS(int startVertex) {
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty()) {
    int currVertex = queue.front();
    cout << "Visited " << currVertex << " ";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) {
      int adjVertex = *i;
      if (!visited[adjVertex]) {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  g.BFS(2);

  return 0;
}  
```
<br>

### **Python Code**

```cpp
# BFS algorithm in Python


import collections

# BFS algorithm
def bfs(graph, root):

    visited, queue = set(), collections.deque([root])
    visited.add(root)

    while queue:

        # Dequeue a vertex from queue
        vertex = queue.popleft()
        print(str(vertex) + " ", end="")

        # If not visited, mark it as visited, and
        # enqueue it
        for neighbour in graph[vertex]:
            if neighbour not in visited:
                visited.add(neighbour)
                queue.append(neighbour)


if __name__ == '__main__':
    graph = {0: [1, 2], 1: [2], 2: [3], 3: [1, 2]}
    print("Following is Breadth First Traversal: ")
    bfs(graph, 0)

```

### **BFS Algorithm Complexity**

The time complexity of the BFS algorithm is represented in the form of O(V + E), where V is the number of nodes and E is the number of edges.

The space complexity of the algorithm is O(V).

<br>

***
<br>

## **Resources:**
<br>

* [**JAVAPOINT**](https://www.javatpoint.com/breadth-first-search-algorithm)
* [**GFG**](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/)
