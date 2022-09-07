#include <stdio.h>
#define TAM 4

typedef struct P{
int n;
} Valores;

void ler4numeros(Valores valor[4]);

int main()
{ 
  Valores v[TAM];
  ler4numeros(v);
  printf("Primeiro valor: %d\n", v[0].n);
  printf("Segundo valor: %d\n", v[1].n); 
  printf("Terceiro valor: %d\n", v[2].n); 
  printf("Quarto valor: %d\n", v[3].n); 
}

void ler4numeros(Valores valor[TAM]){
  for(int i = 0; i < TAM; i++){
    printf("Digite um numero: ");
    scanf("%d", &valor[i].n);
  }
}