#include <stdio.h>
#define TAM 3

typedef struct P{
char letra;
} Letras;

void ler3letras(Letras letrinhas[TAM]);

int main()
{ 
  Letras l[TAM];
  ler3letras(l);
  printf("Primeira letra: %c\n", l[0].letra);
  printf("Segunda letra: %c\n", l[1].letra); 
  printf("Terceira letra: %c\n", l[2].letra);
}

void ler3letras(Letras letrinhas[TAM]){
  for(int i = 0; i < TAM; i++){
    printf("Digite uma letra: ");
    scanf("%c", &letrinhas[i].letra);
    getchar();
  }
}