#include "Aluno.h"
#include "Validacoes.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>



int cadastrarAluno(Aluno lista[], int qtd);
void listarAlunos(Aluno lista[], int qtd);
int excluirAluno(Aluno lista[], int qtd);
int atualizarAluno(Aluno lista[], int qtd);

int pegaProximaMatricula(){
  static int matriculaAtualAluno = 100;
  matriculaAtualAluno++;
  return matriculaAtualAluno;
}
int menuAluno() { 
  int opcao;
  printf("Opcoes de Aluno\n"); 
  printf("0. Voltar\n");
  printf("1. Cadastrar\n");
  printf("2. Listar\n");
  printf("3. Excluir\n");
  printf("4. Atualizar\n");
  scanf("%d", &opcao);
  return opcao;
}

int mainAluno(Aluno listaAluno[], int qtdAluno){
  int opcao = 1;
  while(opcao != 0){
    opcao = menuAluno();
    
    switch(opcao){
      case 1:{
        qtdAluno = cadastrarAluno(listaAluno, qtdAluno);
        break;
      }
      case 2:{
        listarAlunos(listaAluno, qtdAluno);
        break;
      }
      case 3:{
        int retorno = excluirAluno(listaAluno, qtdAluno);
        if(retorno != -1){
          qtdAluno = retorno;
        }
        break;
      }
      case 4:{
        int retorno = atualizarAluno(listaAluno, qtdAluno);
        break;
      }
    }
  }
  return qtdAluno;
}

int cadastrarAluno(Aluno lista[], int qtd){
  printf("### Cadastrando Aluno...\n");
  getchar();
  printf("Digite seu nome: ");
  fflush(stdin);
  fgets(lista[qtd].nome, 40, stdin);
  size_t a = strlen(lista[qtd].nome) - 1;
    if(lista[qtd].nome[a] == '\n')
      lista[qtd].nome[a] = '\0';
  lista[qtd].matricula = pegaProximaMatricula();
  printf("Digite o seu sexo(M/F): ");
  scanf("%c", &lista[qtd].sexo);
  lista[qtd].sexo = toupper(lista[qtd].sexo);
  getchar();
  printf("Digite a data de nascimento(dd/mm/aa): ");
  scanf("%s", lista[qtd].data_nascimento);
  getchar();
  printf("Digite o seu cpf: ");
  fflush(stdin);
  fgets(lista[qtd].cpf, 12, stdin);
  size_t a1 = strlen(lista[qtd].cpf) - 1;
    if(lista[qtd].cpf[a1] == '\n')
      lista[qtd].cpf[a1] = '\0';
  qtd++;
  
  return qtd;
}

void listarAlunos(Aluno lista[], int qtd){
  printf("### Lista de alunos...\n");
  for(int i = 0; i < qtd; i++){
    printf("Nome: %s - Matricula: %ld - Sexo: %c - Data de nascimento: %s - CPF: %s\n", lista[i].nome, lista[i].matricula, lista[i].sexo, lista[i].data_nascimento, lista[i].cpf);
  }
}

int excluirAluno(Aluno lista[], int qtd){
  int matricula, achou = 0;
  printf("Digite a matricula: ");
  scanf("%d", &matricula);
  
  for(int i = 0; i < qtd; i++){
    if (matricula == lista[i].matricula){
      achou = 1;
      for(int j = i; j < qtd-1; j++){
        lista[j] = lista[j+1];
      }
      qtd--;
      break;
    }
  }
  if(achou == 1){
    printf("Aluno excluido com sucesso\n ");
    return qtd;
  }
  else{
    printf("Aluno nao encontrado\n");
    return -1;
  }
}

int atualizarAluno(Aluno lista[], int qtd){
  int matricula, achou = 0;
  int i = 0;
  printf("Digite a matricula: ");
  scanf("%d", &matricula);
  for(i = 0; i < qtd; i++){
    if (matricula == lista[i].matricula){
      achou = 1;
      printf("### Atualizando Aluno...\n");
      getchar();
      printf("Digite seu nome: ");
      fflush(stdin);
      fgets(lista[i].nome, 40, stdin);
      size_t a = strlen(lista[i].nome) - 1;
        if(lista[i].nome[a] == '\n')
          lista[i].nome[a] = '\0';
      lista[i].matricula = pegaProximaMatricula();
      printf("Digite o seu sexo(M/F): ");
      scanf("%c", &lista[i].sexo);
      lista[i].sexo = toupper(lista[i].sexo);
      getchar();
      printf("Digite a data de nascimento(dd/mm/aa): ");
      scanf("%s", lista[i].data_nascimento);
      getchar();
      printf("Digite o seu cpf: ");
      fflush(stdin);
      fgets(lista[i].cpf, 12, stdin);
      size_t a1 = strlen(lista[i].cpf) - 1;
        if(lista[i].cpf[a1] == '\n')
          lista[i].cpf[a1] = '\0';
      break;
    }
  }
  if(achou == 1){
    printf("Aluno atualizado com sucesso\n ");
    return i;
  }
  else{
    printf("Aluno nao encontrado\n");
    return -1;
  }
}