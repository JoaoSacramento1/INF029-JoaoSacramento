#include "Disciplina.h"
#include <stdio.h>
#include <string.h>

int cadastrarDisciplina(Disciplina lista[], int qtd);
void listarDisciplinas(Disciplina lista[], int qtd);
int excluirDisciplina(Disciplina lista[], int qtd);
int atualizarDisciplina(Disciplina lista[], int qtd);

int pegaCodigo(){
  static int codigoDisciplina = 10;
  codigoDisciplina++;
  return codigoDisciplina;
}

int menuDisciplina(){
  int opcao;
  printf("Opcoes de Disciplina\n");
  printf("0. Voltar\n");
  printf("1. Cadastrar\n");
  printf("2. Listar\n");
  printf("3. Excluir\n");
  printf("4. Atualizar\n");
  printf("5. Incluir aluno na disciplina\n");
  printf("6. Excluir aluno na disciplina\n");
  scanf("%d", &opcao);
  return opcao;
}

int mainDisciplina(Disciplina listaDisciplina[], int qtdDisciplina){
  int opcao = 1;
  while(opcao != 0){
    opcao = menuDisciplina();
    
    switch(opcao){
      case 1:{
      qtdDisciplina = cadastrarDisciplina(listaDisciplina, qtdDisciplina);
      break;
      }
      case 2:{
      listarDisciplinas(listaDisciplina, qtdDisciplina);
      break;
      }
      case 3:{
      int retorno = excluirDisciplina(listaDisciplina, qtdDisciplina);
      if(retorno != -1){
        qtdDisciplina = retorno;
      }
      break;
      }
      case 4:{
      int retorno = atualizarDisciplina(listaDisciplina, qtdDisciplina);
      break;
      }
    }
  }
  return qtdDisciplina;
}

int cadastrarDisciplina(Disciplina lista[], int qtd){
  printf("### Cadastrando Disciplina...\n");
  getchar();
  printf("Digite o nome da Disciplina: ");
  fflush(stdin);
  fgets(lista[qtd].nome, 40, stdin);
  size_t c = strlen(lista[qtd].nome) - 1; 
    if (lista[qtd].nome[c] == '\n')
      lista[qtd].nome[c] = '\0';
  lista[qtd].codigo = pegaCodigo();
  printf("Digite o semestre da Disciplina: ");
  fgets(lista[qtd].semestre, 20, stdin);
  size_t c1 = strlen(lista[qtd].semestre) - 1; 
    if (lista[qtd].semestre[c1] == '\n')
      lista[qtd].semestre[c1] = '\0';
  printf("Digite o nome do professor que ministra essa Disciplina: ");
  fflush(stdin);
  fgets(lista[qtd].professor, 40, stdin);
  size_t c2 = strlen(lista[qtd].professor) - 1; 
    if (lista[qtd].professor[c2] == '\n')
      lista[qtd].professor[c2] = '\0';
  qtd++;
  return qtd;
}

void listarDisciplinas(Disciplina lista[], int qtd){
  printf("### Lista de Disciplinas...\n");
  for(int i = 0; i < qtd; i++){
    printf("Disciplina: %s - Codigo: %ld - Semestre: %s - Professor: %s\n", lista[i].nome, lista[i].codigo, lista[i].semestre, lista[i].professor);
  }
}

int excluirDisciplina(Disciplina lista[], int qtd){
  int codigo, achou = 0;
  printf("Digite o codigo da disciplina: ");
  scanf("%d", &codigo);
  
  for(int i = 0; i < qtd; i++){
    if (codigo == lista[i].codigo){
      achou = 1;
      for(int j = i; j < qtd-1; j++){
        lista[j] = lista[j+1];
      }
      qtd--;
      break;
    }
  }
  if(achou == 1){
    printf("Disciplina excluida com sucesso\n ");
    return qtd;
  }
  else{
    printf("Disciplina nao encontrada\n");
    return -1;
  }
}

int atualizarDisciplina(Disciplina lista[], int qtd){
  int codigo, achou = 0;
  int i = 0;
  printf("Digite o codigo da disciplina: ");
  scanf("%d", &codigo);
  for(i = 0; i < qtd; i++){
    if(codigo == lista[i].codigo){
      achou = 1;
      printf("###Atualizando Disciplina...\n");
      getchar();
      printf("Digite o nome da Disciplina: ");
      fflush(stdin);
      fgets(lista[i].nome, 40, stdin);
      size_t c = strlen(lista[i].nome) - 1; 
        if (lista[i].nome[c] == '\n')
          lista[i].nome[c] = '\0';
      lista[i].codigo = pegaCodigo();
      printf("Digite o semestre da Disciplina: ");
      fgets(lista[i].semestre, 20, stdin);
      size_t c1 = strlen(lista[i].semestre) - 1; 
        if (lista[i].semestre[c1] == '\n')
          lista[i].semestre[c1] = '\0';
      printf("Digite o nome do professor que ministra essa Disciplina: ");
      fflush(stdin);
      fgets(lista[i].professor, 40, stdin);
      size_t c2 = strlen(lista[i].professor) - 1; 
        if (lista[i].professor[c2] == '\n')
          lista[i].professor[c2] = '\0';
      break;
    }
  }
  if(achou == 1){
    printf("Disciplina atualizada com sucesso.\n");
    return i;
  }
  else{
    printf("Disciplina nao encontrada.\n");
    return -1;
  }
}