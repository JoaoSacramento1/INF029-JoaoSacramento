#include <stdio.h>

int main(){
  int n1, n2, n3;
  printf("Digite o primeiro numero: ");
  scanf("%d", &n1);
  printf("Digite o segundo numero: ");
  scanf("%d",& n2);
  n3 = n1;
  n1 = n2;
  n2 = n3;
  printf("Os valores invertidos são %d e %d", n1, n2);
}