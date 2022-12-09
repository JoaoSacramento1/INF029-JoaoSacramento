#include <stdio.h>

int main(){
  // declarando e fazendo o ponteiro apontar para um endereço válido
  int n;
  int *pInt;
  pInt = &n;
  char letra;
  char *pChar;
  pChar = &letra;
  char palavra[10];
  char *pString;
  pString = palavra;
  float n2;
  float *pFloat;
  pFloat = &n2;
  double n3;
  double *pDouble;
  pDouble = &n3;

  // fazendo a leitura dos valores
  printf("Digite um numero inteiro: ");
  scanf("%d", pInt);
  printf("Digite uma letra: ");
  scanf("%c", pChar);
  getchar();
  printf("Digite uma palavra: ");
  scanf("%s", pString);
  getchar();
  printf("Digite um valor float: ");
  scanf("%f", pFloat);
  printf("Digite um valor double: ");
  scanf("%lf", pDouble);

  // imprimindo os valores
  printf("Numero inteiro: %d\n", n);
  printf("Letra: %c\n", letra);
  printf("Palavra: %s\n", palavra);
  printf("Numero float: %f\n", n2);
  printf("Numero double: %lf\n", n3);
  
}