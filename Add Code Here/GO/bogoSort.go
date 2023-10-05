package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

func BogoSort() {
	unsortedList := generateRandomList(10)

	sortedList := bogoSort(unsortedList)

	fmt.Println("Sorted List:", sortedList)
}

func bogoSort(list []int) []int {
	for !isSorted(list) {
		shuffleList(list)
	}
	return list
}

func isSorted(list []int) bool {
	for i := 1; i < len(list); i++ {
		if list[i] < list[i-1] {
			return false
		}
	}
	return true
}

func shuffleList(list []int) {
	rand.Seed(time.Now().UnixNano())
	n := len(list)
	for i := n - 1; i > 0; i-- {
		j := rand.Intn(i + 1)
		list[i], list[j] = list[j], list[i]
	}
}

func generateRandomList(size int) []int {
	list := make([]int, size)
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < size; i++ {
		list[i] = rand.Intn(100)
	}
	return list
}