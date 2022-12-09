#include <stdlib.h>
#include <string.h>

int validarCPF(char cpf);

int validarCPF(char cpf){
  int retorno;
  int soma1;
  int soma2;
  float resto1;
  float resto2;
  
  if(cpf[0] == cpf[1] && cpf[1] == cpf[2] && cpf[2] == cpf[3] && cpf[3] == cpf[4] && cpf[4] == cpf[5] && cpf[5] == cpf[6] && cpf[6] == cpf[7] && cpf[7] == cpf[8] && cpf[8] == cpf[9] && cpf[9] == cpf[10])
    retorno = 0;
  else{
    soma1 = (cpf[0] * 10) + (cpf[1] * 9) + (cpf[2] * 8) + (cpf[3] * 7) + (cpf[4] * 6) + (cpf[5] * 5) + (cpf[6] * 4) + (cpf[7] * 3) + (cpf[8] * 2);
    resto1 = (soma1 * 10) %11;
    if (resto1 == 10)
      resto1 = 0;
    soma2 = (cpf[0] * 11) + (cpf[1] * 10) + (cpf[2] * 9) + (cpf[3] * 8) + (cpf[4] * 7) + (cpf[5] * 6) + (cpf[6] * 5) + (cpf[7] * 4) + (cpf[8] * 3) + (cpf[9] * 2);
    resto2 = (soma2 * 10) %11;
    if (resto2 == 10)
      resto2 = 0;
    if(resto1 == cpf[9] && resto2 == cpf[10])
      retorno = 1;
    else
      retorno = 0;
  }
  
  return retorno;
}