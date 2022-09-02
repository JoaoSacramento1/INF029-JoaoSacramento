#include <stdio.h>
int soma(int x, int y);

int main()
{   
    int a, b, resultado;
    printf("Digite o primeiro valor: ");
    scanf("%d", &a);
    printf("Digite o segundo valor: ");
    scanf("%d", &b);
    resultado = soma(a, b);
    printf("O resultado da soma entre %d e %d eh %d", a, b, resultado);
    return 1;
}

int soma(int x, int y)
{
    int res = x + y;
    return res;
}