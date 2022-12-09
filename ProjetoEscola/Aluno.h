typedef struct alu{
  long int matricula;
  char data_nascimento[11];
  char sexo;
  char nome[40];
  char cpf[12];
} Aluno;

int mainAluno(Aluno listaAluno[], int qtdAluno);