from random import randint

mapa = [
    ["A","A","A","A","A", "" ,"" ,"A","A","A","A","A"],
    ["A","","","" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"A"],
    ["A","" ,"" ,"" ,"A","" ,"" ,"" ,"" ,"" ,"" ,"A"],
    ["A","E","E","E","A","E","E","E","G","G","G","A"],
    ["A","" ,"" ,"" ,"A","G","G","G","G","G","G","A"],
    ["A","E","E","E","A","G","G","G","G","G","G","A"],
    ["A","" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"A"],
    ["A","" ,"" ,"" ,"" ,"" ,"" ,"" ,"G","G","G","A"],
    ["A","A","E","E","E","A","A","A","G","G","G","A"],
    ["A","" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"A"],
    ["A","E","" ,"E","E","" ,"E","E","E","E","E","A"],
    ["A","" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"A"],
    ["A","" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" , "A"],
    ["A","A","A","A","A","A","G","G","G","E","E","A"],
    ["A","" ,"" ,"" ,"" ,"" ,"G","G","G","" ,"" ,"A"],
    ["A","" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"" ,"A"],
    ["A","E","E","" ,"" ,"E","E","E","E","E","E","A"],
    ["A","" ,"G","G","G","G","" ,"" ,"G","G","G","A"],
    ["A","G","G","G","" ,"" ,"" ,"G","G","" ,"" ,"A"],
    ["A","A","A","A","A","A","G","A","A","A","A","A"]
        ]

posicao = [19, 6]
pokedex = []
pokemons = ["Ratata", "Pidgey", "Weedle", "Caterpie","Paras", "Charmander", "Buldasaur", "Squirtle", "Pikachu", "Evee"]

def aleatorio(valor):
    return randint(0,valor)

def colisao():
    print("\nBump!\n")

def pokemonSelvagem():
    print("\nUm pokemon selvagem apareceu!")
    e = verificaEntrada([1, 2], int(input("Capturar ou correr? [1-Capturar ou 2-Correr]\n")))
    if (e == 1):
        novoPokemon()
        posicaoAtual()
    else:
        print("Fujão")
        posicaoAtual()

def novoPokemon():
    pokemon = pokemons[aleatorio(9)]
    for i in range(len(pokedex)):
        if (pokedex[i]["Nome"] == pokemon):
            print("Já existe o registro de um pokemon de mesma espécie, nada novo será salvo")
            return False
    status = {
        "Nome": pokemon,
        "HP": aleatorio(100),
        "Atk": aleatorio(100),
        "Def": aleatorio(100),
        "Sp. Def": aleatorio(100),
        "Speed": aleatorio(100)
    }
    pokedex.append(status)
    print(f"{status['Nome']} capturado!")
    print("Novo pokemon registrador!")
    
def menu():
    print("\nBem-vindo!\nA qualquer momento você pode escolher umas das opções:")
    print(" 9 - Para abrir esse menu\n 8 - Subir\n 2 - Descer\n 4 - Ir para a esquerda")
    print(" 6 - Ir para a direita\n 5 - Abrir Pokedex\n 0 - Sair do Jogo")

def menuPokedex():
    while True:
        print("\nDigite\n1 para Listar Detalhes\n2 para Apagar Registro\n0 para voltar ao menu principal")
        e = verificaEntrada([1, 2, 0], int(input("Escolha uma ação:\n")))
        if (e == 1):
            listarDetalhes()
        elif (e == 2):
            apagarRegistro()
        elif (e == 0):
            break

def listarDetalhes():
    for i in range(len(pokedex)):
        print(pokedex[i])

def apagarRegistro():
    print("\nEscolha qual pokemon deve ser apagado do registro: [0 para cancelar ação]")
    n = []
    for i in range(len(pokedex)):
        print(f"{i}", pokedex[i]["Nome"])
        n.append(i)
    e = verificaEntrada(n, int(input()))
    pokemonRemove = pokedex.pop(e)["Nome"]
    print(f"O pokemon {pokemonRemove} foi removido da pokedex!")

def posicaoAtual():
    print("\nAtual posição:")
    coluna = posicao[0]
    linha = posicao[1]
    print(f"coluna {coluna},  linha {linha}")

def imprimirMapa(mapa):
    print(" ", *range(0,12))
    i = 0
    
    for linha in mapa:
        if i <= 9: print(i, end="  ")
        else:
            print(i, end=" ")
        for casa in linha:
            if (casa == ""): print(" ", end=" ")
            else:
                print(casa, end=" ")
        print()
        i += 1

def rota():
    print(f"Entrando na rota 1")

def checarGrama():
    if (mapa[posicao[0]][posicao[1]] == "G"):
        if (aleatorio(1) == 0):
             pokemonSelvagem()

def checarVitoria():
    if (len(pokedex) == 10):
        print("Parabéns! Você completou a pokedex.")
        exit()

def fimDeJogo():
    print("Fim de jogo")
    exit()

def Movimento(movi):
    if (movi == "Subir"):
        if (posicao[0]-1 < 0):
            fimDeJogo()
        else:
            l = mapa[posicao[0]-1][posicao[1]]
            if (l == "G"):
                posicao[0] = posicao[0] - 1
            elif (l == ""):
                posicao[0] = posicao[0] - 1
            elif (l == "A"):
                colisao()
            elif (l == "E"):
                colisao()
    elif (movi == "Descer"):
        if (posicao[0]+1 > 19):
            fimDeJogo()
        else:
            l = mapa[posicao[0]+1][posicao[1]]
            if (l == "G"):
                posicao[0] = posicao[0] + 1
            elif (l == ""):
                posicao[0] = posicao[0] + 1
            elif (l == "A"):
                colisao()
            elif (l == "E"):
                posicao[0] = posicao[0] + 1
    elif (movi == "Ir para a esquerda"):
        l = mapa[posicao[0]][posicao[1]-1]
        if (l == "G"):
            posicao[1] = posicao[1] - 1
            print("Grama")
        elif (l == ""):
            posicao[1] = posicao[1] - 1
        elif (l == "A"):
            colisao()
        elif (l == "E"):
            colisao()
    elif (movi == "Ir para a direita"):
        l = mapa[posicao[0]][posicao[1]+1]
        if (l == "G"):
            posicao[1] = posicao[1] + 1
            print("Grama")
        elif (l == ""):
            posicao[1] = posicao[1] + 1
        elif (l == "A"):
            colisao()
        elif (l == "E"):
            colisao()

def verificaEntrada(valValidos, verificar):
    while verificar not in valValidos:
        verificar = int(input('Entrada inválida. \nInforme uma entrada válida!\n'))
        posicaoAtual()
    return verificar

imprimirMapa(mapa)
print()
menu()
rota()
posicaoAtual()

while True:
    checarGrama()
    checarVitoria()
    R = verificaEntrada([9, 8, 2, 4, 6, 5, 0], int(input("")))
    if (R == 9):
        menu()
    elif (R == 8):
        Movimento("Subir")
        posicaoAtual()
    elif (R == 2):
        Movimento("Descer")
        posicaoAtual()
    elif (R == 4):
        Movimento("Ir para a esquerda")
        posicaoAtual()
    elif (R == 6):
        Movimento("Ir para a direita")
        posicaoAtual()
    elif (R == 5):
        menuPokedex()
    elif (R == 0):
        break