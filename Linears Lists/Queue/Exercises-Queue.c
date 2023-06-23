#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define		TRUE	   1
#define		FALSE	   0

struct conteudo{
	int numero;
	struct conteudo *proximo;
}; typedef struct conteudo TNo;

typedef struct{
	TNo *inicio, *final;
} TLista;

void InicializaLista (TLista*);
void ImprimeLista(TLista*);
int InsereNumero(TLista*, int);
int ExcluiNumero (TLista*, int);

int main (void)
{	int numeroDigitado, qtdeTeste;
   int qtdeDelete;
   
	TLista lista;
	
	InicializaLista(&lista);
	scanf("%d", &qtdeTeste);
	
	while(qtdeTeste--)
	{	scanf("%d", &numeroDigitado);
		
		InsereNumero(&lista, numeroDigitado);
	}
	
	scanf("%d", &qtdeDelete);
	while(qtdeDelete--)
	{	scanf("%d", &numeroDigitado);

		ExcluiNumero(&lista, numeroDigitado);
	}
	
	ImprimeLista(&lista);
}

void InicializaLista(TLista *lista)
{	lista->inicio = NULL;
	lista->final = NULL;
}

int InsereNumero(TLista *lista, int valor)
{	TNo *coordenadaNo;
	
	coordenadaNo = (TNo*)malloc(sizeof(TNo));
	
	coordenadaNo->numero = valor;
	coordenadaNo->proximo = NULL;
	
	if(lista->inicio == NULL)
		lista->inicio = coordenadaNo;
	else
		lista->final->proximo = coordenadaNo;
	
	lista->final = coordenadaNo;
	return TRUE;
}

void ImprimeLista(TLista *lista)
{	TNo *coordenadaNo;
   int primeiroFila;
   
   primeiroFila = TRUE;
   
	coordenadaNo = lista->inicio;
	while(coordenadaNo != NULL)
	{	if(!primeiroFila)
	      printf(" ");
	   else
	      primeiroFila = FALSE;
	   
	   printf("%d", coordenadaNo->numero);
	   coordenadaNo = coordenadaNo->proximo;
	}
	printf("\n");
}


int ExcluiNumero(TLista *lista, int valor)
{	TNo *coordenadaNo, *anterior;
	
	anterior = NULL;
	coordenadaNo = lista->inicio;
	while(coordenadaNo != NULL && valor != coordenadaNo->numero)
	{	anterior = coordenadaNo;
		coordenadaNo = coordenadaNo->proximo;
	}
		

	if(anterior == NULL)
      lista->inicio = coordenadaNo->proximo;
	else
		anterior->proximo = coordenadaNo->proximo;
		
	if(coordenadaNo == lista->final)
		lista->final = anterior;
		
	free(coordenadaNo);
	return TRUE;
}