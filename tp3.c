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

void elimina_vetor (struct racional** vetor, long tam){

}

/* programa principal */
int main ()
{
  long n, i, numerador, denominador;
  struct racional **vetor;

  scanf("%ld", &n);

  vetor = malloc(n * sizeof(struct racional*));

  for (i = 0; i < n; i++){
    scanf("%ld", &numerador);
    scanf("%ld", &denominador);

    vetor[i] = cria_r(numerador, denominador);
  }

  imprime_vetor(vetor, n);

  return 0;
}

