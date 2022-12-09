#include <stdio.h>

void ordena(int *Valores);
int main(){
  int vetor[5];
  int *pVetor;
  pVetor = vetor;
  for(int i = 0; i < 5; i++){
    printf("Digite o valor da posicao %d do vetor: ", i+1);
    scanf("%d", pVetor[i]);
  }
  ordena(*pVetor);
  for(int i = 0; i < 5; i++){
    printf("%d\n", vetor[i]);
  }
}

void ordena(int *Valores){
  int menor, j, i, aux;
  for(i = 0; i < 5 - 1; i++){
    menor = i;
    for(j = (i + 1); j < 5; j++){
      if(*Valores[j] < *Valores[menor])
        menor = j;
    }
    if(i != menor){
      aux = *Valores[i];
      *Valores[i] = *Valores[menor];
      *Valores[menor] = aux;
    }
  }
}