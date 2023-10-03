def atoi(s):
    result = 0
    sign = 1
    i = 0

    # Gérer les espaces en début de chaîne
    while i < len(s) and s[i].isspace():
        i += 1

    # Gérer le signe +/- optionnel
    if i < len(s) and (s[i] == '+' or s[i] == '-'):
        if s[i] == '-':
            sign = -1
        i += 1

    # Conversion de la chaîne en entier
    while i < len(s) and s[i].isdigit():
        result = result * 10 + int(s[i])
        i += 1

    return sign * result
