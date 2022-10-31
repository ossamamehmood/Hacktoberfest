// A program to print transpose of a matrix
package main

import "fmt"

func main() {
	var i, j, rows, columns int

	var orgMat [10][10]int
	var transposeMat [10][10]int

	fmt.Print("Enter the Matrix rows and Columns = ")
	fmt.Scan(&rows, &columns)

	fmt.Println("Enter Matrix Items to Transpose = ")
	for i = 0; i < rows; i++ {
		for j = 0; j < columns; j++ {
			fmt.Scan(&orgMat[i][j])
		}
	}
	for i = 0; i < rows; i++ {
		for j = 0; j < columns; j++ {
			transposeMat[j][i] = orgMat[i][j]
		}
	}
	fmt.Println("The Transpose Matrix Items are ")
	for i = 0; i < columns; i++ {
		for j = 0; j < rows; j++ {
			fmt.Print(transposeMat[i][j], "  ")
		}
		fmt.Println()
	}
}
