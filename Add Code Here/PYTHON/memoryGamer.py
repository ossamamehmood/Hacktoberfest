from random import randint

letras = ['A', 'B', 'C']
t = 20
c = 0

mapa = [
    ['', '', ''],
    ['', '', ''],
    ['', '', ''],
    ['', '', '']
]

mapaOculto = [
    ['?', '?', '?'],
    ['?', '?', '?'],
    ['?', '?', '?'],
    ['?', '?', '?']
]

mapaRevelado = [
    ['?', '?', '?'],
    ['?', '?', '?'],
    ['?', '?', '?'],
    ['?', '?', '?']
]

def embaralhar():
    simbolos = [
        [2, '#'],
        [2, '@'],
        [2, '%'],
        [2, '$'],
        [2, '&'],
        [2, '!']
    ]

    for i in range(4):
        for j in range(3):
            while True:
                s = simbolos[aleatorio(5)]
                if (s[0] > 0):
                    s[0] = s[0] - 1
                    mapa[i][j] = s[1]
                    break

def aleatorio(limiteSuperior):
    return randint(0,limiteSuperior)

def imprimirMapa(mapa):
    global letras
    print(" ", end=" ")
    for i in range(3):
        print(f"{letras[i]}", end=" ")
    print()
    i = 1
    
    for linha in mapa:
        print(i, end=" ")
        for casa in linha:
            print(casa, end=" ")
        print()
        i += 1

def leOpcaoValida(tipo, opcoesValidas, mensagem):
    escolha = None

    while escolha not in opcoesValidas:
        if tipo == "int":
            escolha = int(input(mensagem))
        elif tipo == "str":
            escolha = input(mensagem)

        if escolha not in opcoesValidas:
            print("Opção inválida!")

    return escolha

def encontrar():
    cA = leOpcaoValida('str', ['A', 'B', 'C'], "Escolha a coluna: ")
    c1 = letras.index(cA)
    l1 = leOpcaoValida('int', [1, 2, 3, 4], "Escolha a linha: ")-1
    print()

    mapaRevelado[l1][c1] = mapa[l1][c1]
    s1 = mapa[l1][c1]
    imprimirMapa(mapaRevelado)

    cB = leOpcaoValida('str', ['A', 'B', 'C'], "Escolha a coluna: ")
    c2 = letras.index(cB)
    l2 = leOpcaoValida('int', [1, 2, 3, 4], "Escolha a linha: ")-1
    print()

    mapaRevelado[l2][c2] = mapa[l2][c2]
    s2 = mapa[l2][c2]
    imprimirMapa(mapaRevelado)
    print()

    if (l1 == l2) and (c1 == c2):
        return False
    if (s1 == s2):
        mapaOculto[l1][c1] = mapa[l1][c1]
        mapaOculto[l2][c2] = mapa[l2][c2]
        return True
    else:
        for i in range(4):
            for j in range(3):
                mapaRevelado[i][j] = mapaOculto[i][j]
        return False

def tentativas():
    global t
    print("--------------------------------")
    print(f"Você possui {t} tentativas!")
    print("--------------------------------\n")
    t = t-1

def exibir(mensagem):
    print(len(mensagem) * '-')
    print(mensagem)
    print(len(mensagem) * '-', '\n')

embaralhar()
while True:
    tentativas()
    imprimirMapa(mapaOculto)
    if encontrar():
        c = c+2
    if c == 12:
        exibir("Parabéns! Você completou o jogo da memória.")
        break
    if t == 0:
        exibir("Você perdeu! É uma pena, mas suas tentativas acabaram.")
        break