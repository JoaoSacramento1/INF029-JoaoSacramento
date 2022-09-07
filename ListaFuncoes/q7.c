#include <stdio.h>
#define TAM 3

typedef struct P{
char palavra[20];
} Palavras;

void ler3Palavras(Palavras p[TAM]);

int main()
{ 
  Palavras n[TAM];
  ler3Palavras(n);
  printf("-----\n");
  printf("Primeira palavra: %s\n", n[0].palavra);
  printf("Segunda palavra: %s\n", n[1].palavra); 
  printf("Terceira palavra: %s\n", n[2].palavra);
}

void ler3Palavras(Palavras p[TAM]){
  for(int i = 0; i < TAM; i++){
    printf("Digite uma palavra: ");
    fflush(stdin);
    fgets(p[i].palavra, 31, stdin);
  }
}