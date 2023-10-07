package main

import (
	"container/heap"
	"fmt"
	"math"
)

type Edge struct {
	To     int
	Weight int
}

type Graph map[int][]Edge

type Item struct {
	Node     int
	Priority int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].Priority < pq[j].Priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(*Item)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

// Dijkstra finds the shortest path from start to all nodes in the graph.
func Dijkstra(graph Graph, start int) map[int]int {
	dist := make(map[int]int)
	for node := range graph {
		dist[node] = math.MaxInt
	}
	dist[start] = 0

	pq := make(PriorityQueue, 0)
	heap.Push(&pq, &Item{Node: start, Priority: 0})

	for len(pq) > 0 {
		node := heap.Pop(&pq).(*Item).Node

		for _, edge := range graph[node] {
			alt := dist[node] + edge.Weight
			if alt < dist[edge.To] {
				dist[edge.To] = alt
				heap.Push(&pq, &Item{Node: edge.To, Priority: alt})
			}
		}
	}

	return dist
}

func main() {
	graph := make(Graph)
	graph[0] = []Edge{{1, 4}, {2, 1}}
	graph[1] = []Edge{{3, 1}}
	graph[2] = []Edge{{1, 2}, {3, 5}}
	graph[3] = []Edge{{4, 3}}
	graph[4] = []Edge{}

	startNode := 0
	distances := Dijkstra(graph, startNode)

	fmt.Println("Shortest distances from node", startNode, "to all other nodes:")
	for node, distance := range distances {
		fmt.Printf("Node %d: %d\n", node, distance)
	}
}
