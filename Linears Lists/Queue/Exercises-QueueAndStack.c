#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define		TRUE	    1
#define 	FALSE	    0
#define		MAX		    51

struct noPilha
{	char vogal;	
   struct noPilha *prox;	
};	typedef struct noPilha TPilha;

typedef struct{ 
   TPilha *topo;
   int qtde;
} Pilha;

struct noFila
{	char vogal;	
   struct noFila *prox;	
};	typedef struct noFila TFila;

typedef struct{ 
   TFila *inicio, *final;
   int qtde;
} Fila;

void InicializaPilha(Pilha *);
void InicializaFila(Fila *);
int PUSH(Pilha *, char);
int InsereFila(Fila *, char);
int ComparaPilhaFila(Pilha*, Fila*);
void PreencheED(Pilha *, Fila *, char[]);

int main(void)
{	char risada[MAX];
	Pilha pilha1;
	Fila fila1;
	
	InicializaPilha(&pilha1);
	InicializaFila(&fila1);
	
	scanf("%s", risada);
	PreencheED(&pilha1, &fila1, risada);
	
	if(ComparaPilhaFila(&pilha1, &fila1) == TRUE)
	   puts("S");
	else
	   puts("N");
	   
	return 0;
}

void InicializaPilha(Pilha *pilha)
{	pilha->topo = NULL;
   pilha->qtde = 0;
}

void InicializaFila(Fila *fila)
{	fila->inicio = NULL;
   fila->final = NULL;
   fila->qtde = 0;
}

int PUSH(Pilha *pilha, char s)
{	TPilha *aux;
   int i = 0;
   
	aux = (TPilha*)malloc(sizeof(TPilha));

	if(aux == NULL)
		return FALSE;	
	else
	{	aux->vogal = s;
	   pilha->qtde++;
		aux->prox = pilha->topo;
		pilha->topo=aux;
		return TRUE;
	}
}

int InsereFila(Fila *fila, char s)
{  TFila *aux;
   
   aux = (TFila*)malloc(sizeof(TFila));
   if(aux == NULL)
      return FALSE;
   else
   {  aux->vogal = s;
      aux->prox = NULL;
      fila->qtde++;
      
      if(fila->inicio == NULL)
         fila->inicio = aux;
      else
         fila->final->prox = aux;
      
      fila->final = aux;
   }
   return TRUE;
}

void PreencheED(Pilha *pilha, Fila *fila, char risada[])
{	TPilha *aux;
   int i = 0;
   
   while(i < strlen(risada))
   {  if(risada[i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || risada[i] == 'o' || risada[i] == 'u')
	   {  PUSH(pilha, risada[i]);
	      InsereFila(fila, risada[i]);
	   }
	i++;
   }
}

int ComparaPilhaFila(Pilha *pilha, Fila *fila)
{  TPilha *auxPilha;
   TFila *auxFila;
   
   auxPilha = pilha->topo;
   auxFila = fila->inicio;
   
   while(auxPilha != NULL && auxFila != NULL)
   {  if(auxPilha->vogal != auxFila->vogal)
         return FALSE;
         
   auxPilha = auxPilha->prox;
   auxFila = auxFila->prox;
   }
   
   return TRUE;
}