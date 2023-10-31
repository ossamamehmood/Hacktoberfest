package main

import (
	"fmt"
	"sync"
	"time"
)

const (
	numWorkers = 5
	numTasks   = 20
)

func worker(id int, tasks <-chan int, results chan<- int, wg *sync.WaitGroup) {
	defer wg.Done()
	for task := range tasks {
		// Simulate some processing time
		time.Sleep(time.Millisecond * time.Duration(task))
		// Send the result back to the main goroutine
		results <- task * 2
	}
}

func main() {
	// Create channels for tasks and results
	tasks := make(chan int, numTasks)
	results := make(chan int, numTasks)

	// Create a WaitGroup to wait for all goroutines to finish
	var wg sync.WaitGroup

	// Start worker goroutines
	for i := 1; i <= numWorkers; i++ {
		wg.Add(1)
		go worker(i, tasks, results, &wg)
	}

	// Send tasks to the workers
	for i := 1; i <= numTasks; i++ {
		tasks <- i
	}
	close(tasks)

	// Close the results channel when all workers are done
	go func() {
		wg.Wait()
		close(results)
	}()

	// Collect results from the workers
	var collectedResults []int
	for result := range results {
		collectedResults = append(collectedResults, result)
	}

	// Print the collected results
	fmt.Println("Collected Results:", collectedResults)
}
