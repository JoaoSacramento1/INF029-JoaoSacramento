#include <stdio.h>
#include <string.h>
#define TAM 5

typedef struct dados_pessoas{
  char nome[40];
  int idade;
  char sexo;
  int cpf[10];
  } pessoas;

int main(){
  pessoas pessoa[TAM];
  
  for (int i = 0; i < TAM; i++){
    printf("Digite o nome: ");
    fgets(pessoa[i].nome, 40, stdin);
    size_t ln = strlen(pessoa[i].nome) - 1; //size_t = unsigned integer type
    if (pessoa[i].nome[ln] == '\n')
      pessoa[i].nome[ln] = '\0'; // caracter de final de string

    printf("Digite a idade: ");
    scanf("%d", &pessoa[i].idade);

    printf("Digite o sexo: ");
    scanf("%c",&pessoa[i].sexo);

    getchar();
    
    printf("Digite o cpf: ");
    fgets(pessoa[i].cpf, 10, stdin); 
    ln = strlen(pessoa[i].cpf) - 1; 
    if (pessoa[i].cpf[ln] == '\n')
      pessoa[i].cpf[ln] = '\0';
  }
  printf("\n**********Pessoas cadastradas**********\n");
  for(int i = 0; i < TAM; i++){
    printf("------\n");
    printf("Nome: %s\n", pessoa[i].nome);
    printf("Idade: %d\n", pessoa[i].idade);
    printf("Sexo: %c\n", pessoa[i].sexo);
    printf("CPF: %s\n", pessoa[i].cpf);
  }
}