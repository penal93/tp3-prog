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

void elimina_vetor (struct racional** vetor, long *tam){
  int i = 0;

  while (i < *tam){

    if (valido_r(vetor[i]) == 0){
      free(vetor[i]);
      for (int j = i; j < *tam; j++)
          vetor[j] = vetor[j + 1];
      (*tam)--;
    }

    else 
      i++;
  }
}

void selectSort (struct racional** vetor, long tam){
  int min;
  struct racional* aux;

  for (int i = 0; i < tam - 1; i++){
    min = i;

    for (int j = i + 1; j < tam; j++)
      if (compara_r(vetor[min], vetor[j]) == 1)
        min = j;

    aux = vetor[min];
    vetor[min] = vetor[i];
    vetor[i] = aux;
  }
}

struct racional *soma_vetor (struct racional **vetor, long tam){
  struct racional *p = cria_r(0, 1);

  for (int i = 0; i < tam; i ++)
    soma_r (vetor[i], p, p);

  return p;
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

  selectSort(vetor, *n);
  imprime_vetor(vetor, *n);

  struct racional *soma = soma_vetor(vetor, *n);
  printf("SOMA = ");
  imprime_r(soma);
  printf("\n");

  return 0;
}

