#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUCKETS 101

#define TAM_CPF  20
#define TAM_NOME 41

struct cliente	{	char cpf[TAM_CPF], nome[TAM_NOME], sexo;
					float limite;
					int filial;
					struct cliente *prox;
				};
typedef struct cliente TCliente;

TCliente *Hash_Table[MAX_BUCKETS];

int Hash_Function( char *key )
{	int c = 0, total = 0;

	while (key[c] != '\0')
	{	total = total + (key[c] - '0');
		c++;
	}
		
	return total % MAX_BUCKETS;
}

int main()
{	TCliente *aux, *tmp;
	int N, c, x, pos;
	char cpf[TAM_CPF];
	
	for (c = 0; c < MAX_BUCKETS; c++)
		Hash_Table[c] = NULL;
	
	scanf("%d", &N);
	for (x = 0; x < N; x++ )
	{	aux = (TCliente *) malloc( sizeof(TCliente) );
	
		scanf("%s %s %c %f %d", (aux->cpf), (aux->nome),
				&(aux->sexo), &(aux->limite), &(aux->filial) );
		aux->prox = NULL;
	
		pos = Hash_Function(aux->cpf);

		if (Hash_Table[pos] == NULL)
			Hash_Table[pos] = aux;
		else
		/* Colisao, buscar final da lista no bucket */
		{	tmp = Hash_Table[pos];
			while (tmp->prox != NULL)
				tmp = tmp->prox;
		
			tmp->prox = aux;
		}
	}

	while( scanf("%s", cpf) && strcmp(cpf, "-1") != 0)
	{	pos = Hash_Function(cpf);

		if (Hash_Table[pos] == NULL)
			printf("CPF %s nao encontrado\n", cpf);
		else
		{	tmp = Hash_Table[pos];
			while (tmp != NULL && strcmp(tmp->cpf, cpf) != 0)
				tmp = tmp->prox;
			
			if (tmp != NULL)
				printf("CPF %s encontrado no bucket %d\n", cpf, pos);
			else
				printf("CPF %s nao encontrado\n", cpf);
		}
	}

	return 0;
}
