#include <stdio.h>

int main(){
  int n1, n2;
  printf("Digite o primeiro valor: ");
  scanf("%d", &n1);
  printf("Digite o segundo valor: ");
  scanf("%d", &n2);
  n1 += n2;
  n2 = n1 - n2;
  n1 = n1 - n2;
  printf("O primeiro valor agora vale %d e o segundo vale %d", n1, n2);
}