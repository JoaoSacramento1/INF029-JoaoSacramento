#include <stdio.h>

int main(){
  int n1, n2, soma;
  printf("Digite uma idade: ");
  scanf("%d",&n1);
  printf("Digite uma outra idade: ");
  scanf("%d",&n2);
  soma = n1 + n2;
  printf("A soma das idades é %d", soma);
}