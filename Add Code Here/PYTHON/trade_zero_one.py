def troca(vet):
    for i in range(3):
        if vet[i] >= 0:
            vet[i] = 1
        else:
            vet[i] = 0
    return vet

vet = [0]*3
for i in range(3):
    vet[i] = input('Digite um valor: ')
print vet
troca(vet)
print vet
