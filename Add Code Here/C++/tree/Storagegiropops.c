 // name - Wallace Leonel
    // github name - wallaceleonel
    // github profile link - https://github.com/wallaceleonel

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    char livro[30][40],autor[50],tag[45];
    
    int preco[50],qtd,cont=1,sacola[100],total=0;
    
    int aux,sair,op,car,excluir,apagar,remov,pagando;
    
    aux=0;
    sair =2;
    
    while (sair==2) {
      system("cls");
      
      printf("\t\t%c--------------------------------------------------------%c",155,187);
      printf("\n\t\t|      Adicicionando livros  Giropops Bliclioteca on           |\n");
      printf("\t\t%c--------------------------------------------------------%c",155,187);
      
      printf("op 1 começar a comprar informe seus livros :) >>>>CLIQUE AQUI<<<<<<<\n");
      printf("op 2 vizualizar sacola \n");
      printf("op 3 deseja remover algo ? \n");
      printf("op 4 finalizar venda \n");
      
      printf("digite a opacao :) ");
      scanf("%d",&op);
      
      switch (op){
      case 1:
         system("cls");
         printf("Quantos livros deseja adionar ?");
         scanf("%d",&qtd);
 
      for (cont=0;cont<qtd;cont++){
         
         printf("\ninforme o nome do livro :");
         fflush(stdin);
         scanf("%[^\n]s",&livro[aux]);
         
         printf("\ninfome o nome do autor :");
         fflush(stdin);
         scanf("%[^\n]s",&autor[aux]);
         
         printf("\n informe a tag deste livro :");
         fflush(stdin);
         scanf("%[^\n]s",&tag[aux]);
         
         printf("\ninforme o preco do livro :");
         fflush(stdin);
         scanf("%d",&preco[aux]);
         
       aux++; //snedo usado como contador apagando ...   
      }
      system("pause");
      break;
      case 2:
      system("cls");
      
      printf("\t\t%c--------------------------------------------------------%c",155,187);
      printf("\n\t\t|             Carrinho Giropops Bliclioteca on            |\n");
      printf("\t\t%c--------------------------------------------------------%c",155,187);
      total = qtd*preco[50];

      printf("Carrinho de compras ");
      for(cont=0;cont<aux;cont++){
        printf("\n%d\n%d     -     %s\n\n",cont,total,livro[cont]);
      }
     
     printf("Estes são os itens em seu carrinho :");
     scanf("%d",&car);
     
       printf("\n nome do livro :%s \n ",livro[car]);
       printf("\n nome do autor : %s \n ",autor[car]);
       printf("\n codigo do livro : %s \n ",tag[car]);
       printf("\n preco do livro  %d \n ",preco[car]);
       
       system("pause");
       break;

       case 3:
       system("cls");
       printf("\t\t%c--------------------------------------------------------%c",155,187);
       printf("\n\t\t|    remover itens Giropops Bliclioteca on |\n");
       printf("\t\t%c--------------------------------------------------------%c",155,187);
               
         printf("codigo - Carrinho ");
         for (cont=0;cont<aux;cont++){
            printf("\n%d \n%d    -    %s\n",cont,total,livro[cont]); //aux é quantidades de linha 
         }
         
         printf("Digite qual codigo do livro ira remover se desejar :");
         scanf("%d",&excluir);

         for (apagar=excluir;apagar<aux;apagar++){
            
            remov=apagar+1;
                     
             strcpy(livro[apagar],livro[remov]); //copia o valor cliente pata [cliente excluir]
             autor[apagar]=autor[remov];
             tag[apagar]=tag[remov];
             preco[apagar]=preco[remov];
             }
             aux=aux+1;
             system("pause");
      
      break;
      case 4:
            ystem("cls");
       printf("\t\t%c--------------------------------------------------------%c",155,187);
       printf("\n\t\t|    fechando a conta ! Giropops Bliclioteca on |\n");
       printf("\t\t%c--------------------------------------------------------%c",155,187);  
       
       printf("Deseja encerra a compra ou gostaria de adicionar mais algum item ?");
       printf(" 1-Sim   2-NAO  ");
       scanf("%d",&pagando);

       printf("%d total de sua compra é :  \n\n",total);
       
         
         break;
      }//switch
      
      
      }//while
    
 system("pause");
    } //fim do programa :)
  
     


