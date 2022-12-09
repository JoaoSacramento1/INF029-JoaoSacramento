#include <stdio.h>
#define TAM 5
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Validacoes.h"

int imprimeMenu();

int imprimeMenu(){
  int opcao;
  printf("Digite a opcao\n");
  printf("0. Sair\n");
  printf("1. Aluno\n");
  printf("2. Professor\n");
  printf("3. Disciplina\n");
  scanf("%d", &opcao);
  return opcao;
}

int main(void){
  Aluno listaAluno[TAM];
  Professor listaProfessor[TAM];
  Disciplina listaDisciplina[TAM];
  int qtdAluno = 0;
  int qtdProfessor = 0;
  int qtdDisciplina = 0;
  int opcao = 1;
  while(opcao != 0){
    opcao = imprimeMenu();
    switch(opcao){
      case 1:{
        qtdAluno = mainAluno(listaAluno, qtdAluno);
        break;
      }
      case 2:{
        qtdProfessor = mainProfessor(listaProfessor, qtdProfessor);
        break;
      }
      case 3:{
        qtdDisciplina = mainDisciplina(listaDisciplina, qtdDisciplina);
        break;
      }
      default:{
        printf("Opcao Invalida.");
      }
    }
  }
  return 0;
}