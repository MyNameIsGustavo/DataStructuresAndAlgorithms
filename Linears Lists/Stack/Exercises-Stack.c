#include <stdio.h>
#include <stdlib.h>

#define     TRUE     1
#define     FALSE    0

struct item
{  int info; 
   struct item* prox;
}; typedef struct item TItem;

typedef struct
{  TItem *topo; 
   int qtde;
}  TDescr;

void InicializaPilha(TDescr *);
void Imprime(TDescr *);
void Tira(TDescr *);
int Poe(TDescr *, int);

int main(void)
{  int vrdig = 0;
	int fim = 0;
   
	TDescr descritor;
	InicializaPilha(&descritor);
   
	printf("Digite os numeros:\n");
	while(fim == 0)
	{	scanf("%d", &vrdig);
		if (vrdig == -1)
			fim = 1;
		else
		{  if(Poe(&descritor, vrdig) == FALSE)
				puts("Memoria insuficiente para esta operacao.");
		}
	}
	
	Imprime(&descritor);  
	Tira(&descritor);
	Imprime(&descritor);
	
	return 0;
}

void InicializaPilha(TDescr *pilha)
{  pilha->topo = NULL;
	pilha->qtde = 0;
}

int Poe(TDescr *pilha, int numero)
{  	TItem *coordenadaPilha;
   
	coordenadaPilha = (TItem*)malloc(sizeof(TItem));
	if(coordenadaPilha == NULL)
		return FALSE;
	else
	{	coordenadaPilha->info = numero;
		coordenadaPilha->prox = pilha->topo;
      
		pilha->topo = coordenadaPilha;
		pilha->qtde++;
	}
	return TRUE;
}

void Imprime(TDescr *pilha)
{  TItem *coordenadaPilha;

	coordenadaPilha = pilha->topo;
	while(coordenadaPilha != NULL)
	{  printf("Os numeros da pilha: %d\n", coordenadaPilha->info);
		coordenadaPilha = coordenadaPilha->prox;
	}
	printf("A quantidade de numeros da pilha: %d\n\n", pilha->qtde);
}

void Tira(TDescr *pilha)
{  TItem *coordenadaPilha;

	coordenadaPilha = pilha->topo;
	pilha->topo = pilha->topo->prox;
	pilha->qtde--;
	
	free(coordenadaPilha);
}