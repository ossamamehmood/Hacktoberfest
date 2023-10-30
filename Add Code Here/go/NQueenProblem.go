package main

import "fmt"

const N = 8 // The size of the chessboard

func main() {
	chessboard := make([][]int, N)
	for i := range chessboard {
		chessboard[i] = make([]int, N)
	}

	if solveNQueens(chessboard, 0) {
		printChessboard(chessboard)
	} else {
		fmt.Println("No solution found.")
	}
}

func solveNQueens(chessboard [][]int, col int) bool {
	if col == N {
		return true
	}

	for i := 0; i < N; i++ {
		if isSafe(chessboard, i, col) {
			chessboard[i][col] = 1

			if solveNQueens(chessboard, col+1) {
				return true
			}

			chessboard[i][col] = 0
		}
	}

	return false
}

func isSafe(chessboard [][]int, row, col int) bool {
	for i := 0; i < col; i++ {
		if chessboard[row][i] == 1 {
			return false
		}
	}

	for i, j := row, col; i >= 0 && j >= 0; i, j = i-1, j-1 {
		if chessboard[i][j] == 1 {
			return false
		}
	}

	for i, j := row, col; i < N && j >= 0; i, j = i+1, j-1 {
		if chessboard[i][j] == 1 {
			return false
		}
	}

	return true
}

func printChessboard(chessboard [][]int) {
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			fmt.Print(chessboard[i][j], " ")
		}
		fmt.Println()
	}
}
