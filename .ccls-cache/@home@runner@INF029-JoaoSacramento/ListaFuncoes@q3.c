#include <stdio.h>
#include <stdlib.h>
int fatorial(int n);

int main()
{   
    int a, resultado;
    printf("Digite um valor para saber seu fatorial: ");
    scanf("%d", &a);
    if (a < 0)
      printf("Valor invalido. Finalizando programa...");
    else{
      resultado = fatorial(a);
      printf("O resultado do fatorial de %d eh %d", a, resultado);
    }
}


int fatorial(int n){
  if(n >= 0){
    int fat = 1;
    while(n > 0){
      fat *= n;
      n --;
    }
    return fat;
  }else
    return -1;
}