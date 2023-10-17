package main

import "fmt" 

func main() {
	var n, sisi int
	fmt.Print("masukan banyaknya persegi yang mau diitung: ")
	fmt.Scan(&n)

	for i := 1; i <= n; i++ {
		fmt.Printf("masukkin panjang sisi persegi ke-%d (dalam meter): ", i)
		fmt.Scan(&sisi)
		
		if sisi <= 0 {
			fmt.Println("panjang sisi persegi harus lebih dari 0")
			return
		}

		luas := sisi * sisi
		keliling := 4 * sisi

		fmt.Printf("luas persegi` ke-%d: %d meter\n", i, luas)
		fmt.Printf("keliling persegi ke-%d: %d meter\n", i, keliling)
	}

}
