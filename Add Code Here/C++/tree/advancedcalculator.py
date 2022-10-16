allowed_symbol = [
    "+",
    "-",
    "*",
    "**",
    "/",
    "(",
    ")",
    "e"
]

while True:
        
    for symbol in (expr := input("[*] Enter a calculation\n>>>")):
        if not symbol in allowed_symbol and not symbol.isdigit():
            print("That's not a valid calculation!")
            exit(1)
            
    print(eval(expr))
        
    if input("[?] Try again? [Yes | No]\n>>>").lower() == "yes":
        continue

    break