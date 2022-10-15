package main

import (
	"fmt"
)


func factorialRecursive(value int) int {
	if value == 1 {
		return 1
	} else {
		return value * factorialRecursive(value-1) 
	}
}


func main() {
	recursive := factorialRecursive
	fmt.Println(recursive(5))
}
