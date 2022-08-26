#include <stdio.h>

int main(){
  int n, fat;
  printf("Digite um numero para saber seu fatorial: ");
  scanf("%d", &n);
  for (fat = 1; n > 1; n = n - 1)
    fat = fat * n;
  printf("O fatorial eh %d", fat);
}