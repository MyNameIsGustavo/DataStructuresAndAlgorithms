#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_BUCKETS 799999

struct regValor	{	int valor;
					struct regValor *prox;
				};
typedef struct regValor TValor;

TValor *HashTable[MAX_BUCKETS];

int HashFunction(int k)
{	return k % MAX_BUCKETS;
}

int main()
{	TValor *aux, *pos;
	int c, vPesq;
	
	for (c = 0; c < MAX_BUCKETS; c++ )
		HashTable[c] = NULL;
	
	while( 1 )
	{	aux = (TValor *) malloc(sizeof(TValor));
		scanf("%d", &(aux->valor));
		if(aux->valor == -999999)
			break;

		aux->prox = NULL;
		
		c = HashFunction(aux->valor);
		
		if(HashTable[c] == NULL)
			HashTable[c] = aux;
		else
		{	pos = HashTable[c];
			while (pos->prox != NULL)
				pos = pos->prox;
			
			pos->prox = aux;
		}
	}
     
    #ifdef DEBUG
        double tInicio_=clock() ;
    #endif
	
	while( 1 )
	{	scanf("%d", &vPesq);
		if(vPesq == -999999)
			break;

		c = HashFunction(vPesq);
		
		if (HashTable[c] == NULL)
			printf("Valor nao cadastrado\n");
		else
		{	pos = HashTable[c];
			while (pos != NULL && pos->valor != vPesq)
				pos = pos->prox;
			
			if (pos == NULL)
				printf("Valor %d nao cadastrado\n", vPesq);
			else
				printf("Valor %d encontrado no bucket %d\n", vPesq, c);
		}
	}
     
    #ifdef DEBUG
        printf( "Tempo: %.1lf %.1lf\n", clock() - tInicio_, (clock() - tInicio_)/CLK_TCK ) ;
    #endif

	return 0;
}
