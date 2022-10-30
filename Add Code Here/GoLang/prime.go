package main

import "fmt"

func isPrime(n int) {
	for i := 2; i < n/2+1; i++ {
		if n%i == 0 {
			fmt.Println("Not a Prime Number")
			return
		}
	}
	fmt.Println("Prime Number")
	return
}

func main() {
	var n int
	_, err := fmt.Scanf("%d", &n)
	if err != nil {
		fmt.Println(err)
	}

	isPrime(n)
}
