#include <stdio.h>

int main(){
  int idade;
  do {
    printf("Digite a sua idade: ");
    scanf("%d", &idade);
    if(idade >=0){
      if (idade >= 18)
        printf("Voce eh de maior!\n");
      else
        printf("Voce nao eh de maior\n");
    }else{
      printf("Finalizando o progama...\n");
    }
  }while(idade >=0);
}