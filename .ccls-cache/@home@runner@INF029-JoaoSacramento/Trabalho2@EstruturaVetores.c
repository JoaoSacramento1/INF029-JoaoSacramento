#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

typedef struct{
  int qtd;
  int qtdmax;
  int *valor;  
} valor;

valor vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho) {
  // a posicao pode já existir estrutura auxiliar
  if (vetorPrincipal[posicao-1].qtdmax != 0)
    return JA_TEM_ESTRUTURA_AUXILIAR;
  // se posição é um valor válido {entre 1 e 10}
  if(posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;
  // o tamanho nao pode ser menor que 1
  if (tamanho < 1)
    return TAMANHO_INVALIDO;
  // o tamanho ser muito grande
  vetorPrincipal[posicao-1].qtdmax = tamanho;
  vetorPrincipal[posicao - 1].valor = (int *)malloc(tamanho * sizeof(int));

  // deu tudo certo, crie

  return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor) {
  
  if (posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;
    // testar se existe a estrutura auxiliar
  if(vetorPrincipal[posicao-1].qtdmax == 0)
    return SEM_ESTRUTURA_AUXILIAR;
      //testa se tem espaço 
  if(vetorPrincipal[posicao-1].qtd == vetorPrincipal[posicao-1].qtdmax)
    return SEM_ESPACO;
        //insere
  vetorPrincipal[posicao-1].valor[vetorPrincipal[posicao-1].qtd]= valor;   
  vetorPrincipal[posicao-1].qtd = vetorPrincipal[posicao-1].qtd + 1;

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar
da seguinte forma [3, 8, 7,  ,  ,  ]. Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
  if(posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;

  if(vetorPrincipal[posicao-1].qtdmax == 0)
    return SEM_ESTRUTURA_AUXILIAR;

  if(vetorPrincipal[posicao-1].qtd == 0)
    return ESTRUTURA_AUXILIAR_VAZIA;
        
  vetorPrincipal[posicao-1].qtd--;

  return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições
anteriores ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o
valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ] Obs. Esta é
uma exclusão lógica Rertono (int) SUCESSO - excluido com sucesso 'valor' da
estrutura na posição 'posicao' ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
  int num_aux = -1;
  
  if(posicao < 1 || posicao > 10)
     return POSICAO_INVALIDA;

  if(vetorPrincipal[posicao-1].qtdmax == 0)
    return SEM_ESTRUTURA_AUXILIAR;

  if(vetorPrincipal[posicao-1].qtd == 0)
    return ESTRUTURA_AUXILIAR_VAZIA;  

  
  for(int i = 0; i < vetorPrincipal[posicao-1].qtd; i++){
      if(vetorPrincipal[posicao-1].valor[i] == valor){
        num_aux = i;
        for(int j = num_aux; j < vetorPrincipal[posicao-1].qtd - 1; j++){
            vetorPrincipal[posicao-1].valor[j] = vetorPrincipal[posicao-1].valor[j + 1];
        }
      vetorPrincipal[posicao-1].qtd = vetorPrincipal[posicao-1].qtd - 1;
      break;
      }   
  }

  if(num_aux == -1)
    return NUMERO_INEXISTENTE;
  else 
    return SUCESSO; 
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao) {
  int retorno = 0;
  if (posicao < 1 || posicao > 10) {
    retorno = POSICAO_INVALIDA;
  } else
    retorno = SUCESSO;

  return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

  if(posicao < 1 || posicao > 10)
     return POSICAO_INVALIDA;

  if(vetorPrincipal[posicao-1].qtdmax == 0)
     return SEM_ESTRUTURA_AUXILIAR;   
     
  for(int i = 0; i< vetorPrincipal[posicao-1].qtd; i++){
    vetorAux[i] = vetorPrincipal[posicao-1].valor[i];
  }
  
  return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao
(1..10)'. os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao
(1..10)' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

  int vetor[vetorPrincipal[posicao-1].qtd];

  int i, j, k;
  
  if(posicao < 1 || posicao > 10)
     return POSICAO_INVALIDA;  

  if(vetorPrincipal[posicao-1].qtdmax == 0)
     return SEM_ESTRUTURA_AUXILIAR;

  
  for(int l = 0; l< vetorPrincipal[posicao-1].qtd; l++){
    vetor[l] = vetorPrincipal[posicao-1].valor[l];
  }

    int guardar;

    for(i = 0; i < vetorPrincipal[posicao-1].qtd; i++){
      for(j = i+1; j < vetorPrincipal[posicao-1].qtd; j++){
          if(vetor[i] > vetor[j]){
            guardar = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = guardar;
          }
      }    
    }          
      for(k = 0; k < vetorPrincipal[posicao-1].qtd; k++){
        vetorAux[k] = vetor[k];
      } 

  return SUCESSO;         
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {

  int aux  = 0;
  int indice = 0;
  int i, j, cont;

  for(i = 0; i < TAM; i++){
    if(vetorPrincipal[i].valor == NULL || vetorPrincipal[i].qtd == 0)
       aux++;
  }     
     
  if(aux == 10)
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
   
  for(cont = 1; cont < TAM; cont++){    
      for(j = 0; j < vetorPrincipal[cont].qtd; j++){       
        vetorAux[indice] = vetorPrincipal[cont].valor[j];        
        indice++;            
      }      
  }    
       
  return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {

  //Criando vetor auxiliar;
  int vetor_2[50];

  int i, j, k, o;
  int p, l;
  int cont;
  int guardar;  
  int aux = 0;
  int indice = 0;
  
  for(o = 0; o < TAM; o++){
    if(vetorPrincipal[o].valor == NULL || vetorPrincipal[o].qtd == 0)
       aux++;
  }     
     
  if(aux == 10)
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;


  for(cont = 1; cont < TAM; cont++){    
      for(j = 0; j < vetorPrincipal[cont].qtd; j++){       
        vetor_2[indice] = vetorPrincipal[cont].valor[j];        
        indice++;            
      }      
  }     
  
  for(i = 0; i < indice; i++){
      for(j = i + 1;j < indice; j++){ 
          if(vetor_2[i] > vetor_2[j]){  
            guardar = vetor_2[i];
            vetor_2[i] = vetor_2[j];
            vetor_2[j] = guardar;
          }  
      }
  }      
     
  for(k = 0; k < indice; k++){
    vetorAux[k] = vetor_2[k];
  }
    
  return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o
novo tamanho 'novoTamanho' + tamanho atual Suponha o tamanho inicial = x, e novo
tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser
sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {

    int removidos = 0;
    
  if(novoTamanho < 0)
   removidos = novoTamanho; 

  novoTamanho = vetorPrincipal[posicao-1].qtdmax + novoTamanho;  

  if(posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;
    
  if(vetorPrincipal[posicao-1].valor == NULL)
    return SEM_ESTRUTURA_AUXILIAR;
                                                                  
  if(novoTamanho < 1)
    return NOVO_TAMANHO_INVALIDO;   

  vetorPrincipal[posicao-1].valor = realloc(vetorPrincipal[posicao-1].valor, novoTamanho);       
  vetorPrincipal[posicao-1].qtdmax = novoTamanho;
  vetorPrincipal[posicao-1].qtd += removidos; 
               
  return SUCESSO; 
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da
posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da
estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao) {

  int retorno; 

  if(posicao < 1 || posicao > 10)
    return POSICAO_INVALIDA;

  if(vetorPrincipal[posicao-1].valor == NULL)
    return SEM_ESTRUTURA_AUXILIAR;    
    
  if(vetorPrincipal[posicao-1].qtd == 0)
    return ESTRUTURA_AUXILIAR_VAZIA;

  retorno = vetorPrincipal[posicao-1].qtd;
  return retorno; 
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes
em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote() { return NULL; }

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em
vetorAux. Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio) {}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar() {
  for (int i = 0; i < TAM; i++) {
    vetorPrincipal[i].valor = NULL;
    vetorPrincipal[i].qtd = 0;
    vetorPrincipal[i].qtdmax = 0;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar() {
  for(int i = 0; i < TAM; i++){
    free(vetorPrincipal[i].valor);
  }
}