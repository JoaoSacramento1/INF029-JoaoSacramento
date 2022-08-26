#include <stdio.h>

int main(){
  int idade;
  printf("Digite a sua idade: ");
  scanf("%d", &idade);
  if (idade >= 18)
    printf("Voce eh de maior!");
  else
    printf("Voce nao eh de maior");
}