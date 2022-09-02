#include <stdio.h>
int subtrai(int x, int y, int z);

int main()
{   
    int a, b, c, resultado;
    printf("Digite o primeiro valor: ");
    scanf("%d", &a);
    printf("Digite o segundo valor: ");
    scanf("%d", &b);
    printf("Digite o terceiro valor: ");
    scanf("%d", &c);
    resultado = subtrai(a, b, c);
    printf("O resultado da subtracao entre %d, %d e %d eh %d", a, b, c, resultado);
    return 1;
}


int subtrai(int x, int y, int z)
{
    int sub = x - y - z;
    return sub;
}