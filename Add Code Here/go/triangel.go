package main

import "fmt"

func main() {
    n := 5 // Number of rows for the star pattern

    for i := 1; i <= n; i++ {
        // Print spaces
        for j := 1; j <= n-i; j++ {
            fmt.Print(" ")
        }

        // Print asterisks
        for k := 1; k <= 2*i-1; k++ {
            fmt.Print("*")
        }

        // Move to the next line
        fmt.Println()
    }
}
