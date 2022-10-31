/*  A golang program to print Floyd's Triangle
Eg: Rows = 4
1
2 3
4 5 6
7 8 9 10 */

package main

import "fmt"

func main() {
	var rows int
	var temp int = 1
	fmt.Print("Enter number of rows : ")
	fmt.Scan(&rows)
	for i := 1; i <= rows; i++ {
		for j := 1; j <= i; j++ {
			fmt.Printf("%d ",temp)
			temp++
		}
		fmt.Println()
	}
}
