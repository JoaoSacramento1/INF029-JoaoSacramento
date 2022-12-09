#include "Professor.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int cadastrarProfessor(Professor lista[], int qtd);
void listarProfessores(Professor lista[], int qtd);
int excluirProfessor(Professor lista[], int qtd);
int atualizarProfessor(Professor lista[], int qtd);

int pegaProximaMatricula1(){
  static int matriculaAtualProfessor = 100;
  matriculaAtualProfessor++;
  return matriculaAtualProfessor;
}
int menuProfessor(){ 
  int opcao;
  printf("Opcoes de Professor\n"); 
  printf("0. Voltar\n");
  printf("1. Cadastrar\n");
  printf("2. Listar\n");
  printf("3. Excluir\n");
  printf("4. Atualizar\n");
  scanf("%d", &opcao);
  return opcao;
}

int mainProfessor(Professor listaProfessor[], int qtdProfessor){
  int opcao = 1;
  while(opcao != 0){
    opcao = menuProfessor();
    
    switch(opcao){
      case 1:{
        qtdProfessor = cadastrarProfessor(listaProfessor, qtdProfessor);
        break;
      }
      case 2:{
        listarProfessores(listaProfessor, qtdProfessor);
        break;
      }
      case 3:{
        int retorno = excluirProfessor(listaProfessor, qtdProfessor);
        if(retorno != -1){
          qtdProfessor = retorno;
        }
        break;
      }
      case 4:{
        int retorno = atualizarProfessor(listaProfessor, qtdProfessor);
        break;
      }
    }
  }
  return qtdProfessor;
}

int cadastrarProfessor(Professor lista[], int qtd){
  printf("### Cadastrando Professor...\n");
  getchar();
  printf("Digite seu nome: ");
  fflush(stdin);
  fgets(lista[qtd].nome, 40, stdin);
  size_t b = strlen(lista[qtd].nome) - 1;
    if(lista[qtd].nome[b] == '\n')
      lista[qtd].nome[b] = '\0';
  lista[qtd].matricula = pegaProximaMatricula1();
  printf("Digite o seu sexo(M/F): ");
  scanf("%c", &lista[qtd].sexo);
  lista[qtd].sexo = toupper(lista[qtd].sexo);
  getchar();
  printf("Digite a data de nascimento: ");
  scanf("%s", lista[qtd].data_nascimento);
  getchar();
  printf("Digite o seu cpf: ");
  fflush(stdin);
  fgets(lista[qtd].cpf, 16, stdin);
  size_t b1 = strlen(lista[qtd].cpf) - 1;
    if(lista[qtd].cpf[b1] == '\n')
      lista[qtd].cpf[b1] = '\0';
  qtd++;
  return qtd;
}

void listarProfessores(Professor lista[], int qtd){
  printf("### Lista de professores...\n");
  for(int i = 0; i < qtd; i++){
    printf("Nome: %s - Matricula: %ld - Sexo: %c - Data de nascimento: %s - CPF: %s\n", lista[i].nome, lista[i].matricula, lista[i].sexo, lista[i].data_nascimento, lista[i].cpf);
  }
}

int excluirProfessor(Professor lista[], int qtd){
  int matricula, achou = 0;
  printf("Digite a matricula: ");
  scanf("%d", &matricula);
  for(int i = 0; i < qtd; i++){
    if(matricula == lista[i].matricula){
      achou = 1;
      for(int j = 0; j < qtd-1; j++){
        lista[j] = lista[j+1];
      }
      qtd--;
      break;
    }
  }
  if(achou == 1){
    printf("Professor excluido com sucesso.\n");
    return qtd;
  }
  else{
    printf("Aluno nao encontrado.\n");
    return -1;
  }
}

int atualizarProfessor(Professor lista[], int qtd){
  int matricula, achou = 0;
  int i = 0;
  printf("Digite a matricula: ");
  scanf("%d", &matricula);
  for(i = 0; i < qtd; i++){
    if(matricula == lista[i].matricula){
      achou = 1;
      printf("###Atualizando Professor...\n");
      getchar();
      printf("Digite seu nome: ");
      fflush(stdin);
      fgets(lista[i].nome, 40, stdin);
      size_t b = strlen(lista[i].nome) - 1;
        if(lista[i].nome[b] == '\n')
          lista[i].nome[b] = '\0';
      lista[i].matricula = pegaProximaMatricula1();
      printf("Digite o seu sexo(M/F): ");
      scanf("%c", &lista[i].sexo);
      lista[i].sexo = toupper(lista[i].sexo);
      getchar();
      printf("Digite a data de nascimento: ");
      scanf("%s", lista[i].data_nascimento);
      getchar();
      printf("Digite o seu cpf: ");
      fflush(stdin);
      fgets(lista[i].cpf, 16, stdin);
      size_t b1 = strlen(lista[i].cpf) - 1;
        if(lista[i].cpf[b1] == '\n')
          lista[i].cpf[b1] = '\0';
      break;
    }
  }
  if(achou == 1){
    printf("Professor atualizado com sucesso.\n");
    return i;
  }
  else{
    printf("Professor nao encontrado.\n");
    return -1;
  }
}