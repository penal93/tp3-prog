/*implementação das funções auxiliares*/

#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

void imprime_vetor (struct racional** vetor, long tam){
  int i;
  
  printf("VETOR =");

  for (i = 0; i < tam; i++)
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

void destroi_vetor (struct racional **vetor, long tam){
  for (int i = 0; i < tam; i++){
    free(vetor[i]);
    vetor[i] = NULL;
  }
}