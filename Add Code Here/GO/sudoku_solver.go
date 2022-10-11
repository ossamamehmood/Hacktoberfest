package main

import (
	"errors"
	"fmt"
	"math"
	"os"
	"strconv"
	"time"
)

func main() {
	board := Board{Size: 9}
	puzzle := "003020600900305001001806400008102900700000008006708200002609500800203009005010300"
	if len(os.Args) > 1 {
		args := os.Args[1:]
		if len(args) > 0 && args[0] != "" {
			puzzle = args[0]
		}
	}
	fmt.Println(puzzle)
	_, err := board.Generate(puzzle)
	if err != nil {
		fmt.Println(err)
		return
	}
	board.Print()
	// fmt.Println(board.InBox(1, 1, 7))
	start := time.Now()
	isSolved := board.Solve()

	if isSolved {
		fmt.Println("Board is solved 😄")
	} else {
		fmt.Println("Board is not solved 🙁")
	}
	board.Print()
	t := time.Now()
	elapsed := t.Sub(start)
	fmt.Printf("Toke %v secs to solve.\n", elapsed.Seconds())
	// board.PrintPossibles()
}

type Number struct {
	Solved    bool
	Possibles []int
	Number    int
	PosX      int
	PosY      int
}

type Board struct {
	Size    int
	Numbers []Number
	Value   string
}

func (board *Board) Generate(value string) (bool, error) {
	mod := math.Mod(float64(len(value)), float64(board.Size))
	if mod > 0 {
		return false, errors.New("Your board value is not correct. ")
	}
	board.Value = value
	fmt.Printf("Board Size: %v\n", board.Size)
	counter := 0
	for row := 0; row < board.Size; row++ {
		for col := 0; col < board.Size; col++ {
			pint, _ := strconv.ParseInt(value[counter:counter+1], 0, 32)
			v := int(pint)
			board.Numbers = append(board.Numbers, Number{Number: v, PosX: row, PosY: col, Solved: v > 0})
			counter++
		}
	}

	return true, nil
}

func (board *Board) Print() (bool, error) {
	fmt.Println("———————————| BOARD |———————————")
	for i := 0; i < len(board.Numbers); i++ {
		if board.Numbers[i].PosY == 0 {
			fmt.Print("|")
		}
		if board.Numbers[i].Number == 0 {
			fmt.Print(" · ")
		} else {
			fmt.Printf(" %v ", board.Numbers[i].Number)
		}
		if int(math.Mod(float64(i+1), float64(3))) == 0 {
			fmt.Print("|")
		}
		if int(math.Mod(float64(i+1), float64(board.Size))) == 0 {
			fmt.Println()
		}
		if int(math.Mod(float64(i+1), float64(27))) == 0 {
			fmt.Println("———————————————————————————————")
		}
	}

	return true, nil
}

func (number *Number) HasPossible(n int) bool {
	for _, v := range number.Possibles {
		if v == n {
			return true
		}
	}
	return false
}

func (board *Board) Solve() bool {
	size := len(board.Numbers)
	for i := 0; i < size; i++ {
		number := &board.Numbers[i]
		// fmt.Printf("%d. X: %d, Y:%d, V:%v, STATUS:%v\n", i, number.PosX, number.PosY, number.Number, number.Solved)
		if !number.Solved {
			for n := 1; n <= 9; n++ {
				if board.IsSafe((number.PosX + 1), (number.PosY + 1), n) {
					number.Number = n
					number.Solved = true
					if !number.HasPossible(n) {
						number.Possibles = append(number.Possibles, n)
					}
					// fmt.Printf("%v is safe to put %d,%d\n", n, number.PosX, number.PosY)
					if board.Solve() {
						return true
					}
					number.Number = 0
					number.Solved = false
				}
			}
			return false
		}
	}
	fmt.Println()
	return true
}

func (board *Board) IsSafe(row int, col int, number int) bool {
	return !board.InRow(row, number) && !board.InColumn(col, number) && !board.InBox(row, col, number)
}

func (board *Board) InBox(row int, col int, n int) bool {
	row--
	col--
	rowmin := row - int(math.Mod(float64(row), float64(3)))
	colmin := col - int(math.Mod(float64(col), float64(3)))

	rowmax := rowmin + 3
	colmax := colmin + 3

	for _, number := range board.Numbers {
		if number.PosX >= rowmin && number.PosX < rowmax && number.PosY >= colmin && number.PosY < colmax {
			if number.Number == n {
				return true
			}
		}
	}
	return false
}

func (board *Board) InRow(row int, number int) bool {
	row--
	for _, v := range board.Numbers {
		if v.PosX == row && v.Number == number {
			return true
		}
	}
	return false
}

func (board *Board) InColumn(column int, number int) bool {
	column--
	for _, v := range board.Numbers {
		if v.PosY == column && v.Number == number {
			return true
		}
	}
	return false
}
