#Programinha para descobrir a quantidade de ações que você 
# precisa ter para ganhar o suficiente em dividendos para 
# comprar novas cotas do ativo.
#
import math

valorAcao = float(input("Valor da ação: "))
valorDiv = float(input("Valor do dividendo: "))

cotas = valorAcao / valorDiv
cotas =  math.ceil(cotas)
valorTotal = cotas * valorAcao

print(f"\nVocê precisa gastar R${valorTotal} em um total de {cotas} cotas")