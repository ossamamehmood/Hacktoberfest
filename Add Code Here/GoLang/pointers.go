package main

import "fmt"

type Counter struct {
	hits int
}

func increment(counter *Counter) {
	// Using dot notation automatically dereferences. No asterisk(*) needed.
	counter.hits += 1
	fmt.Println("Counter", counter)
}

func replace(old *string, new string, counter *Counter) {
	*old = new
	increment(counter)
}

func main() {
	counter := Counter{}

	hello := "Hello"
	world := "World!"
	fmt.Println(hello, world)

	// Pointer to hello
	replace(&hello, "Hi", &counter)
	fmt.Println(hello, world)

	phrase := []string{hello, world}
	fmt.Println(phrase)

	// Pointer to `world` in the `phrase` slice
	replace(&phrase[1], "Go!", &counter)
	fmt.Println(phrase)

}
