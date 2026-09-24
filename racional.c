/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 20/09/2024 para a disciplina CI1001 - Programação 1.
 * Atualizado em 09/09/2025 para a disciplina CI1001 - Programação 1.
 *
 * Este arquivo deve conter as implementações das funções cujos protótipos
 * foram definidos em racional.h. Neste arquivo também podem ser definidas
 * funções auxiliares para facilitar a implementação daquelas funções.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>

/* aqui vem a struct racional propriamente dita, nao modifique! */
struct racional {
  long num;          /* numerador   */
  long den;          /* denominador */
};

/*
 * Implemente aqui as funcoes definidas no racionais.h; caso precise,
 * pode definir aqui funcoes auxiliares adicionais, que devem ser usadas
 * somente neste arquivo.
*/

/* Maximo Divisor Comum entre a e b      */
/* calcula o mdc pelo metodo de Euclides */
long mdc (long a, long b)
{
  int resto;

  while (b != 0){
    resto = a % b;
    a = b;
    b = resto;
  }

  return a;
}

/* Minimo Multiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc (long a, long b)
{
  return (a * b) / mdc(a, b);
}

/* Simplifica o número racional indicado no parâmetro.
 * Por exemplo, se o número for 10/8 muda para 5/4.
 * Retorna 1 em sucesso e 0 se r for inválido ou o ponteiro for nulo.
 * Se ambos numerador e denominador forem negativos, o resultado é positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador. */
int simplifica_r (struct racional *r)
{
  if (!valido(r))
    return 0;

  if (!r)
    return 0;

  long divisor = mdc(r->num, r->den);

  r->num *= r->num / divisor;
  r->den *= r->den / divisor; 

  if (r->den < 0){
    r->num *= (-1);
    r->den *= (-1);
  }

  return 1;
}

/* implemente as demais funções de racional.h aqui */

long numerador_r (struct racional *r){
  long numerador;

  scanf("%ld", &numerador);
  r->num = numerador;

  return r->num;
}

long denominador_r (struct racional *r){
  long denominador;

  scanf("%ld", &denominador);
  r->den = denominador;

  return r->den;
}

struct racional *cria_r (long numerador, long denominador){
  struct racional *p;

  p = malloc(sizeof(struct racional));

  if (!p)
    return NULL;

  p->num = numerador;
  p->den = denominador;

  return p;
}

void destroi_r (struct racional **r){
  free(*r);
  *r = NULL;
}

int valido_r (struct racional *r){
  if (r->den == 0)
    return 0;

  return 1;
}

int compara_r (struct racional *r1, struct racional *r2){


}

