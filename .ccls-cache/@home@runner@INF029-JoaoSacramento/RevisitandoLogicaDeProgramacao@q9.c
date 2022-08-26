#include <stdio.h>

int main(){
  int n[10];
  int primos[10];

  for (int i = 0; i < 10; i++){
    primos[i] = 1;
  }
  for (int i = 0; i < 10; i++){
    printf("Digite o numero %d: ", i);
    scanf("%d", &n[i]);
  }
  for (int i = 0; i < 10; i++){
    for(int j = 2; j < n[i]; j++)
      if (n[i] % j == 0){
        primos[i] = 0;
        break;
      }  
  }
  int soma = 0;
  printf("Os numeros primos sao: ");
  for (int i = 0; i < 10; i++){
    if (primos[i] == 1){
      soma = soma + n[i];
      printf("%d ", n[i]);
    }
  }
  printf("\nA soma eh: %d", soma);
}