package main

import ( 
	"fmt" 
	"flag"
)

var max *int = flag.Int("max", 0, "enter integer or bust!") 

func main() {
	flag.Parse()
	for i := 1; i <= *max; i++ {
		fizzbuzz(i)	
	}
}

func fizzbuzz(i int) {
	fizz := "fizz"
	buzz := "buzz"
	
	if i % 3 == 0 && i % 5 == 0 {
		fmt.Println(i, fizz + buzz)
	} else if i % 3 == 0 {
		fmt.Println(i, fizz)
	} else if i % 5 == 0 {
		fmt.Println(i, buzz)
	} else {
		fmt.Println(i)
	}
}
