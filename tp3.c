/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 09/09/2025 para a disciplina CI1001 - Programação 1.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include "racional.h"
#include "auxiliar.h"

/* coloque aqui as funções auxiliares que precisar neste arquivo */

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

  selectSort(vetor, *n);
  imprime_vetor(vetor, *n);

  struct racional *soma = soma_vetor(vetor, *n);
  printf("SOMA =");
  imprime_r(soma);
  printf("\n");

  destroi_vetor(vetor, *n);
  imprime_vetor(vetor, *n);
  printf("\n");

  return 0;
}

