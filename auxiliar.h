/*Protótipo das funções auxiliares do programa principal*/

/*Imprime os elementos apontados pelos elementos do vetor de ponteiros*/
void imprime_vetor (struct racional** vetor, long tam);

/*Elimina os elementos NaN do vetor de ponteiros*/
void elimina_vetor (struct racional** vetor, long *tam);

/*Ordena os elementos do vetor apartir do método de Select Sort*/
void selectSort (struct racional** vetor, long tam);

/*Armazena a soma de todos os racionais apontados pelos elementos do vetor */
/*em um ponteiro para struct racional. Depois, retorna esse ponteiro */
struct racional *soma_vetor (struct racional **vetor, long tam);

/*Destroi e libera todos os ponteiros elementos do vetor de ponteiros*/
void destroi_vetor (struct racional **vetor, long tam);
