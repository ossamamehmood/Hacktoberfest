package main

import (
	"fmt"
	"math/rand"

	"./linkedlist"
)

func main() {

	head := &linkedlist.LinkedList{}
	for i := 0; i < 20; i++ {
		head.Append(rand.Intn(100))
	}

	head.Print()
	fmt.Println(DetectCycle(head.Head))

	head.Append(10)
	head.Print()
	fmt.Println(DetectCycle(head.Head))

	head.Append(10)
	head.Print()
	fmt.Println(DetectCycle(head.Head))

	head.Append(10)
	head.Print()
	fmt.Println(DetectCycle(head.Head))
}

// DetectCycle is a function that detect cycle in a linked list and return the starting node if any.
func DetectCycle(head *linkedlist.Node) *linkedlist.Node {
	slowPtr, fastPtr := head, head

	for fastPtr}
