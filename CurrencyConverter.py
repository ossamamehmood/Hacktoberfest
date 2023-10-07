def currency_converter():
    print("Welcome to the Currency Converter program!")

    while True:
        print("\nMenu:")
        print("1. Convert USD to EUR")
        print("2. Convert EUR to USD")
        print("3. Convert USD to GBP")
        print("4. Convert GBP to USD")
        print("5. Quit")

        choice = input("Enter your choice (1/2/3/4/5): ")

        if choice == "5":
            print("Goodbye! Thanks for using the Currency Converter program.")
            break

        if choice in ("1", "2", "3", "4"):
            amount = float(input("Enter the amount: "))

            if choice == "1":
                result = amount * 0.85  # Conversion rate from USD to EUR
                print(f"{amount} USD is equal to {result} EUR")
            elif choice == "2":
                result = amount / 0.85  # Conversion rate from EUR to USD
                print(f"{amount} EUR is equal to {result} USD")
            elif choice == "3":
                result = amount * 0.72  # Conversion rate from USD to GBP
                print(f"{amount} USD is equal to {result} GBP")
            elif choice == "4":
                result = amount / 0.72  # Conversion rate from GBP to USD
                print(f"{amount} GBP is equal to {result} USD")
        else:
            print("Invalid choice. Please choose a valid option (1/2/3/4/5).")

if __name__ == "__main__":
    currency_converter()
