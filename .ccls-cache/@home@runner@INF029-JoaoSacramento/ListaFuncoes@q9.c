#include <stdio.h>
#include <stdlib.h>
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
  
}
void ValidarNome(Cliente C[TAM]){
  for(int i = 0; i < TAM; i++){
    printf("Digite seu nome: ");
    fgets(C[i].nome, 40, stdin);
    
  }
}