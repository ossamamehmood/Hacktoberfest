package main

import (
	"fmt"
	"math/rand"
)

func main() {
	number := rand.Intn(100000) // Generate a random number between 1 and 99999
	prime :=SieveOfEratosthenes(number)
	fmt.Println("Following are the prime numbers smaller than or equal to ", number)
	fmt.Println(prime)
}

func SieveOfEratosthenes(n int) ([] int){
   // Make a list with size till the number n        
   prime := make([]bool, n+1)
   // Intitalize a slice to store the prime numbers
   primes :=make([]int,0)
    for p := 2; p < n; p++ {
        prime[p] = true
    }
    
    for p := 2; p * p <= n; p++ {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            for i:= p * p; i <= n; i += p{
                prime[i] = false;
            }
        }
    }
    
      // Print all prime numbers
    for p := 2; p <= n; p++ {
        if prime[p]==true {
        // Append prime numbers to the slice    
           primes=append(primes,p)
        }
    }
    return primes
}
