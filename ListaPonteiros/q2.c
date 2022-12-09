#include <stdio.h>

void troca(int *n1, int *n2);
int main(){
  int primeiro, segundo;
  int *pPrimeiro, *pSegundo;
  pPrimeiro = &primeiro;
  pSegundo = &segundo;
  printf("Digite um valor: ");
  scanf("%d", pPrimeiro);
  printf("Digite outro valor: ");
  scanf("%d", pSegundo);
  troca(pPrimeiro, pSegundo);
  printf("primeiro: %d\n", primeiro);
  printf("segundo: %d", segundo);
}

void troca(int *n1, int *n2){
  int aux;
  aux = *n1;
  *n1 = *n2;
  *n2 = aux;
}