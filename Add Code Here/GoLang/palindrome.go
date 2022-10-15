package main

import "fmt"

func main() {
	str := "katak"
	fmt.Printf("String : '%s' palindrome status : %t\n", str, isPalindrome(str))
}

func isPalindrome(str string) bool {
	lastIdx := len(str) - 1
	for i := 0; i < lastIdx/2 && i < (lastIdx-i); i++ {
		if str[i] != str[lastIdx-i] {
		return false
		}
	}
	return true
}