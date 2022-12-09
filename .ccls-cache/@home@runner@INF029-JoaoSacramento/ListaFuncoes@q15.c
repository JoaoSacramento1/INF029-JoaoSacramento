#include <stdio.h>
#include <stdlib.h>
int main(){
  int vetor[5];
  for(int i = 0; i < 5; i++){
    printf("Digite as 5 posicoes do vetor: ");
    scanf("%d", &vetor[i]);
  }
}