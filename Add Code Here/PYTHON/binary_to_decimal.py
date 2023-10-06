def decimal_to_binary(decimal_num):
    if decimal_num == 0:
        return "0b0"  # the binary representation of 0 is 0b0
    binary_num = ""
    while decimal_num > 0:
        remainder = decimal_num % 2
        binary_num = str(remainder) + binary_num
        decimal_num = decimal_num // 2
    return "0b" + binary_num

# Input a decimal number
decimal_num = int(input("Enter a decimal number: "))

if decimal_num < 0:
    print("Please enter a non-negative integer.")
else:
    binary_representation = decimal_to_binary(decimal_num)
    print("Binary representation:", binary_representation)
