def generate_table(number, range_limit):
    for i in range(1, range_limit + 1):
        product = number * i
        print(f"{number} x {i} = {product}")

number = int(input("Enter a number: "))
range_limit = int(input("Enter the range limit: "))

generate_table(number, range_limit)
