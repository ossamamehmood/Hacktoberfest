from bank import Bank

bank = Bank()

print("=======================> [ATM Machine] <===========================")
print("1. Create account")
print("2. Check balance")
print("3. Withdraw")

while True:
    userInput = int(input("Choose an option: "))

    if userInput == 1:
        nama = str(input("Enter your name: "))
        pin = int(input("Enter your pin: "))

        if len(str(pin)) != 6:
            print("Pin must be 6 digits")
            pin = int(input("Enter your pin: "))
            continue

        rekening = bank.buatAkun(nama, pin)
        print("Your account has been created:")
        print(f"Nama            : {nama}")
        print(f"No. Rekening    : {rekening}")
        continue
    elif userInput == 2:
        rekening = int(input("Enter your account number: "))

        if bank.cekRekening(rekening) == False:
            print("Account number is not valid")
            rekening = int(input("Enter your account number: "))
            continue

        pin = int(input("Enter your pin: "))

        if bank.cekPin(pin) == False:
            print("Pin is not valid")
            pin = int(input("Enter your pin: "))
            continue

        saldo = bank.cekSaldo(rekening)
        print("Your balance is: ", saldo)
        continue
    elif userInput == 3:
        rekening = int(input("Enter your account number: "))

        if bank.cekRekening(rekening) == False:
            print("Account number is not valid")
            rekening = int(input("Enter your account number: "))
            continue

        pin = int(input("Enter your pin: "))

        if bank.cekPin(pin) == False:
            print("Pin is not valid")
            pin = int(input("Enter your pin: "))
            continue

        jumlah = int(input("Enter the amount you want to withdraw: "))
        saldo = bank.cekSaldo(rekening)

        if saldo < jumlah:
            print("Your balance is not enough")
            continue

        saldoAkhir = bank.kurangiSaldo(rekening, jumlah)
        print(f"Your balance is: {saldoAkhir}")
        continue
    else:
        print("Invalid option")
