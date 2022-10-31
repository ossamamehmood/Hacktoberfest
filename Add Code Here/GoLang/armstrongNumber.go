// Golang Program to check Armstrong Number
// Eg: 153= 1*1*1 + 5*5*5 + 3*3*3

package main
import "fmt"

func main() {
	var number,tempNumber,remainder int
	var result int =0
	fmt.Print("Enter a number : ")
	fmt.Scan(&number)

	tempNumber = number



	// Use of For Loop as While Loop
	for {
		remainder = tempNumber%10
		result += remainder*remainder*remainder		
		tempNumber /=10
		
		if(tempNumber==0){
			break  
		}
	}

	if(result==number){
		 fmt.Printf("%d is an Armstrong number.",number)
	}else{
		fmt.Printf("%d is not an Armstrong number.",number)
	}
}