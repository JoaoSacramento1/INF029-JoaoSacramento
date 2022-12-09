#include <stdio.h>
#define TAM 1

typedef struct{
  char rua[40];
  char Bairro[40];
  int numero;
  int CEP;  
}endereco;

 typedef struct{
  char nome[40];
  float salario;
  char cpf[16];
  char nome_empresa[40];
  char sexo;
  endereco e;
  }Funcionario;

void CadastrarFuncionario(Funcionario F[TAM]);

int main(){
  
  Funcionario C[TAM];
  CadastrarFuncionario(C);
  for (int i = 0; i < TAM; i++){
    printf("----------Dados Cadastrados----------\n");
  
    printf("\nFuncionario: %s",  C[i].nome);
    printf("\nCPF: %s", C[i].cpf);
    printf("\nSexo: %c", C[i].sexo);
    printf("\nNome da empresa: %s", C[i].nome_empresa);
    printf("\nSalario: R$%.2f", C[i].salario);
    printf("\nEndereco:");
    printf("\nRua: %s", C[i].e.rua);
    printf("\nnumero: %d", C[i].e.numero);
    printf("\nBairro: %s", C[i].e.Bairro);
    printf("\nCEP: %d", C[i].e.CEP);  
  } 
}

void CadastrarFuncionario(Funcionario F[TAM]){
  for(int i = 0; i < TAM; i++){
    printf("Digite o seu nome: ");
    fgets(F[i].nome, 40, stdin);
    printf("Digite o seu CPF: ");
    fgets(F[i].cpf, 16, stdin);
    printf("Digite o seu sexo(M/F): ");
    scanf("%c",&F[i].sexo);
    getchar();
    printf("Digite o nome da empresa em que trabalha: ");
    fflush(stdin);
    fgets(F[i].nome_empresa, 40, stdin);
    printf("Digite o seu salario: ");
    scanf("%f", &F[i].salario);
    getchar();
    printf("\nVamos preencher seu endereco: \n");
    printf("Digite a rua: ");
    fflush(stdin);
    fgets(F[i].e.rua, 40, stdin);
    printf("Digite o seu Bairro: ");
    fflush(stdin);
    fgets(F[i].e.Bairro, 40, stdin);
    printf("Digite o numero da rua: ");
    scanf("%d", &F[i].e.numero);
    printf("Digite o CEP: ");
    scanf("%d", &F[i].e.CEP);
  }
}