package main

import "fmt"

func main() {
	slice := []string{"Hello", "world", "!"}

	// i is the index
	for i, element := range slice {
		fmt.Println(i, element, ":")
		// values can be ignore with an underscore
		for _, ch := range element {
			// %q prints out the value as a rune/string
			fmt.Printf("  %q\n", ch)
		}
	}
}
