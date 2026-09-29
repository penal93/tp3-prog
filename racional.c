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

int valido_r (struct racional *r){
  if (!r)
    return 0;

  if (r->den == 0)
    return 0;

  return 1;
}

/* Simplifica o número racional indicado no parâmetro.
 * Por exemplo, se o número for 10/8 muda para 5/4.
 * Retorna 1 em sucesso e 0 se r for inválido ou o ponteiro for nulo.
 * Se ambos numerador e denominador forem negativos, o resultado é positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador. */
int simplifica_r (struct racional *r)
{
  if (valido_r(r) == 0)
    return 0;

  if (!r)
    return 0;

  long divisor = mdc(r->num, r->den);

  r->num /= divisor;
  r->den /= divisor; 

  if (r->den < 0){
    r->num *= (-1);
    r->den *= (-1);
  }

  return 1;
}

/* implemente as demais funções de racional.h aqui */

long numerador_r (struct racional *r){
  return r->num;
}

long denominador_r (struct racional *r){
  return r->den;
}

struct racional *cria_r (long numerador, long denominador){
  struct racional *p;

  p = malloc(sizeof(struct racional));

  if (!p)
    return NULL;

  p->num = numerador;
  p->den = denominador;

  simplifica_r(p);

  return p;
}

void imprime_r (struct racional *r){
  if (valido_r(r) == 0){
    printf ("NaN ");
    return ;
  }
  
  if (r->num == 0){
    printf("0 ");
    return ;
  }

  if (r->den == 1){
    printf("%ld ", r->num);
    return ;
  }
  
  if (r->den == r->num){
    printf("1 ");
    return ;
  }
  
  printf("%ld/%ld ", r->num, r->den);
}


void destroi_r (struct racional **r){
  free(*r);
  *r = NULL;
}

int compara_r (struct racional *r1, struct racional *r2){
  if (valido_r(r1) == 0 || valido_r(r2) == 0)
    return -2;

  if (!r1 || !r2)
    return -2;
  
  if (r1->num == r2->num && r1->den == r2->den)
    return 0;

  long newDen = mmc(r1->den, r2->den);
  long newNum1 = r1->num * newDen/r1->den;
  long newNum2 = r2->num * newDen/r2->den;

  if (newNum1 > newNum2)
    return 1;

  return -1;
}

int soma_r (struct racional *r1, struct racional *r2, struct racional *r3){
  if (!r1 || !r2)
    return 0;

  if (valido_r(r1) == 0 || valido_r(r2) == 0)
    return 0;

  long newDen = mmc(r1->den, r2->den);
  long newNum1 = r1->num * newDen/r1->den;
  long newNum2 = r2->num * newDen/r2->den;
  
  r3->den = newDen;
  r3->num = newNum1 + newNum2;

  simplifica_r(r3);

  return 1;
}

int subtrai_r (struct racional *r1, struct racional *r2, struct racional *r3){
  if (!r1 || !r2)
    return 0;

  if (valido_r(r1) == 0 || valido_r(r2) == 0)
    return 0;

  long newDen = mmc(r1->den, r2->den);
  long newNum1 = r1->num * newDen/r1->den;
  long newNum2 = r2->num * newDen/r2->den;
  
  r3->den = newDen;
  r3->num = newNum1 - newNum2;

  simplifica_r(r3);

  return 1;
}

int multiplica_r (struct racional *r1, struct racional *r2, struct racional *r3){
  if (!r1 || !r2)
    return 0;

  if (valido_r(r1) == 0 || valido_r(r2) == 0)
    return 0;

  r3->den = r1->den * r2->den;
  r3->num = r1->num * r2->num;

  simplifica_r(r3);

  return 1;
}

int divide_r (struct racional *r1, struct racional *r2, struct racional *r3){
  if (!r1 || !r2)
    return 0;

  if (valido_r(r1) == 0 || valido_r(r2) == 0)
    return 0;

  r3->den = r1->den * r2->num;
  r3->num = r1->num * r2->den;

  simplifica_r(r3);

  return 1;
}

