#include <stdio.h>

int main(){
  int n;
  printf("Digite um numero: ");
  scanf("%d", &n);
  int ehPrimo = 1;
  for (int i = 2; i < n; i++)
    if (n % i == 0){
      ehPrimo = 0;
      break;
    }
  if (ehPrimo == 1)
    printf("o numero %d eh primo", n);
  else
    printf("o numero %d nao eh primo", n);
}