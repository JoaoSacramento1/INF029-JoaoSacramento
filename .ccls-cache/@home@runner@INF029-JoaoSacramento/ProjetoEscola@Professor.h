typedef struct prof{
  long int matricula;
  char data_nascimento[11];
  char sexo;
  char nome[40];
  char cpf[16];
} Professor;

int mainProfessor(Professor listaProfessor[], int qtdProfessor);