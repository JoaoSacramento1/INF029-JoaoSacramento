#include <stdio.h>

void ler3num(int n[]);

int main()
{   
  int numeros [3];
  numeros[0] = 11;
  numeros[1] = 12;
  numeros[2] = 13;
  ler3num(numeros);
  printf("Os valores lidos são %d, %d e %d\n", numeros[0], numeros[1], numeros[2]); 
}

void ler3num(int n[]){
  n[0] = 1;
  n[1] = 2;
  n[2] = 3;
}