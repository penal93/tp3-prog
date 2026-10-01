/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 09/09/2025 para a disciplina CI1001 - Programação 1.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/* coloque aqui as funções auxiliares que precisar neste arquivo */

void imprime_vetor (struct racional** vetor, long tam){
  printf("VETOR = ");

  for (int i = 0; i < tam; i++)
    imprime_r(vetor[i]);

  printf("\n");
}

void elimina_elemento (int pos, struct racional** vetor, long* tam){
  for (int i = pos; )
}

void elimina_NaN (struct racional** vetor, long *tam){
  for (int i = 0; i < *tam; i++){

    if (valido_r(vetor[i]) == 0){
      free(vetor[i]);
      printf("um NaN foi identificado no indice: %d \n", i);


}

/* programa principal */
int main ()
{
  long i, numerador, denominador;
  long *n;
  struct racional **vetor;

  n = malloc(sizeof(long));
  scanf("%ld", n);

  vetor = malloc(*n * sizeof(struct racional*));

  for (i = 0; i < *n; i++){
    scanf("%ld", &numerador);
    scanf("%ld", &denominador);

    vetor[i] = cria_r(numerador, denominador);
  }

  imprime_vetor(vetor, *n);

  elimina_vetor(vetor, n);
  imprime_vetor(vetor, *n);
  printf("o tamanho do tam eh: %ld \n", *n);

  return 0;
}

