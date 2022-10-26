package main

import "fmt"

func main() {
	for {
		var number1, number2 float64
		var operator string

		fmt.Print("Enter the first number: \n")
		fmt.Scanln(&number1)

		fmt.Print("Enter the second number: \n")
		fmt.Scanln(&number2)

		fmt.Print("Enter the operator (+ - * /) :\n")
		fmt.Scanln(&operator)

		switch operator {

		case "+":
			fmt.Printf("%.2f %s %.2f = %.2f\n", number1, operator, number2, number1+number2)

		case "-":
			fmt.Printf("%.2f %s %.2f = %.2f \n", number1, operator, number2, number1-number2)

		case "":
			fmt.Printf("%.2f %s %.2f = %.2f\n", number1, operator, number2, number1*number2)

		case "/":
			if number2 == 0.0 {
				fmt.Printf("Cannot divide by zero")
			} else {
				fmt.Printf("%.2f %s %.2f = %.2f\n", number1, operator, number2, number1/number2)
			}
		default:
			fmt.Printf("Invalid operator")

		}

	}

}
