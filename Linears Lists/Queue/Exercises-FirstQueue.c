#include <stdio.h>
#include <stdlib.h>

#define     TRUE     1
#define     FALSE    0

struct item{
   int info; 
   struct item* prox;
}; typedef struct item TItem;

typedef struct{
   TItem *inicio, *final; 
   int qtde;
} TDescr;

void InicializaFila(TDescr *);
void Imprime(TDescr *);
void Ajusta(TDescr *);
int Poe(TDescr *, int);

int main(void)
{  int vrdig = 0, fim = 0;
	TDescr descritor;
	
	InicializaFila(&descritor);
	printf("Digite os numeros:\n");
	while (fim == 0)
	{	scanf("%d", &vrdig);
		if (vrdig == -1)
			fim = 1;
		else
			if(Poe(&descritor, vrdig) == FALSE)
				puts("Memoria insuficiente para esta operacao.");
	}
 
	Imprime(&descritor);
	Ajusta(&descritor);
	Imprime(&descritor);
   
	return 0;
}

void InicializaFila(TDescr *fila)
{  fila->inicio = NULL;
   fila->final = NULL;
   fila->qtde = 0;
}

void Imprime(TDescr *fila)
{	TItem *coordenadaFila;
	
	coordenadaFila = fila->inicio;
	while(coordenadaFila != NULL)
	{	printf("Os numeros da fila: %d\n", coordenadaFila->info);
		coordenadaFila = coordenadaFila->prox;
	}
	printf("Qtde total de bytes da fila: %d\n\n", fila->qtde);
}

int Poe(TDescr *fila, int numero)
{  TItem *coordenadaFila;
   
   fila->qtde = sizeof(TDescr);
   
	coordenadaFila = (TItem*)malloc(sizeof(TItem));
	if(coordenadaFila == NULL)
		return FALSE;
	
	coordenadaFila->info = numero;
	coordenadaFila->prox = NULL;
	
	fila->qtde += sizeof(TItem);
	
	if(fila->inicio == NULL)
		fila->inicio = coordenadaFila;
	else
		fila->final->prox = coordenadaFila;
	
	fila->final = coordenadaFila;
	
	return TRUE;
}

void Ajusta(TDescr *fila)
{	TItem *coordenadaFila;

	coordenadaFila = fila->inicio;
	while(coordenadaFila != NULL)
	{  if(coordenadaFila->info < 0)
			coordenadaFila->info = abs(coordenadaFila->info);
   
		coordenadaFila = coordenadaFila->prox;
	}
}