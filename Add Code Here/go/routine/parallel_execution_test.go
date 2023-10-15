package main

import (
	"bytes"
	"io"
	"os"
	"strings"
	"sync"
	"testing"
)

func TestWorker(t *testing.T) {
	// Create channels for tasks and results
	tasks := make(chan int)
	results := make(chan int)

	// Create a WaitGroup to wait for the worker goroutine to finish
	var wg sync.WaitGroup

	// Start the worker goroutine
	wg.Add(1)
	go worker(1, tasks, results, &wg)

	// Send a task to the worker
	tasks <- 10
	close(tasks) // Close the tasks channel

	// Wait for the worker to finish
	wg.Wait()

	// Close the results channel and collect the result
	close(results)
	result := <-results

	// Assert the result
	expectedResult := 10 * 2
	if result != expectedResult {
		t.Errorf("Expected %d, but got %d", expectedResult, result)
	}
}

func TestMainFunction(t *testing.T) {
	// Capture stdout for testing
	old := os.Stdout
	r, w, _ := os.Pipe()
	os.Stdout = w

	// Run the main function
	main()

	// Close the write pipe and revert stdout
	w.Close()
	os.Stdout = old

	var buf bytes.Buffer
	io.Copy(&buf, r)
	output := buf.String()

	// Perform assertions on the output
	expectedOutput := "Collected Results:"
	if !strings.Contains(output, expectedOutput) {
		t.Errorf("Expected output to contain: %s, but got: %s", expectedOutput, output)
	}
}
