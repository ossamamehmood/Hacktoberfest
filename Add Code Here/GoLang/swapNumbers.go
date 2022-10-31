// Program to swap number without using
// temporary variables.
package main

import "fmt"

func main(){
    fmt.Println("Enter first number : ")
    var first int
    fmt.Scanln(&first)
    fmt.Println("Enter second number : ")
    var second int
    fmt.Scanln(&second)
    first = first-second
    second = first+second
    first = second-first
    fmt.Println("First number :",first)
    fmt.Println("Second number :",second)
}