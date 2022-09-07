#include <stdio.h>
#define TAM 3

typedef struct Dados_Cliente{
char nome[40];
char dataNascimento[11];
char sexo;
char cpf[16];
}Cliente;

void CadastrarClientes(Cliente C[TAM]);

int main(){
  Cliente Clientes[TAM];
  CadastrarClientes(Clientes);
  printf("\n**********Clientes cadastrados**********\n");
  for(int i = 0; i < TAM; i++){
    printf("Nome: %s\n",  Clientes[i].nome);
    printf("Data de nascimento: %s\n", Clientes[i].dataNascimento);
    printf("Sexo: %c\n", Clientes[i].sexo);
    printf("CPF: %s\n", Clientes[i].cpf);
  }
  
}

void CadastrarClientes(Cliente C[TAM]){
  for(int i = 0; i < TAM; i++){
    printf("Digite o nome: ");
    fflush(stdin);
    fgets(C[i].nome, 40, stdin); 
    printf("Digite o sexo(M/F/O): ");
    scanf("%c", &C[i].sexo);
    getchar();
    printf("Digite a data de nascimento(somente numeros): ");
    fflush(stdin);
    fgets(C[i].dataNascimento, 11, stdin);
    printf("Digite o CPF: ");
    fgets(C[i].cpf, 16, stdin);
  }
}