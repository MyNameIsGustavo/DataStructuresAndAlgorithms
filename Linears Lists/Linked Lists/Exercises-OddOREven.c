#include <stdio.h>
#include <stdlib.h>

#define		TRUE	1
#define		FALSE	0

struct conteudo
{  int numero;
	struct conteudo *proximo;
}; typedef struct conteudo TNo;

typedef struct
{  TNo *inicio, *final; } 
TLista;

void InicializaLista (TLista*);
void ImprimeLista(TLista*, char *);
int InsereNumero(TLista*, int);
int ImparPar(TLista*, TLista*, TLista*);
int ExcluiNumero (TLista*, int);

int main(void)
{  int numeroDigitado;
	TLista lista1, lista2, lista3;
	
	InicializaLista(&lista1);
	InicializaLista(&lista2);
	
	while(TRUE)
	{	printf("Insira um numero na [primeira lista]: ");
		scanf("%d", &numeroDigitado);
		
		if(numeroDigitado <= 0)
			break;
		
		if(InsereNumero(&lista1, numeroDigitado) == FALSE)
			puts("Memoria insuficiente para esta operacao");
	}
	
	while(TRUE)
	{	printf("Insira um numero na [segunda lista]: ");
		scanf("%d", &numeroDigitado);
		
		if(numeroDigitado <= 0)
			break;
		
		if(InsereNumero(&lista2, numeroDigitado) == FALSE)
			puts("Memoria insuficiente para esta operacao");
	}
   ImprimeLista(&lista1, "O conteudo da [primeira lista]: ");
   ImprimeLista(&lista2, "O conteudo da [segunda lista]: ");
   
   InicializaLista(&lista3);
   ImparPar(&lista1, &lista2, &lista3);
   ImprimeLista(&lista3, "O conteudo da terceira lista: ");
   return 0;
}

int ImparPar(TLista *lista1, TLista *lista2, TLista *lista3)
{  TNo *coordernadaLista1, *coordernadaLista2;
   int somaParcial;
   
   coordernadaLista1 = lista1->inicio;
   coordernadaLista2 = lista2->inicio;
   while(coordernadaLista1 != NULL && coordernadaLista2 != NULL)
   {  somaParcial = coordernadaLista1->numero + coordernadaLista2->numero;
      if((somaParcial % 2) == 0)
      {  somaParcial = 0;
         InsereNumero(lista3, somaParcial);
      }
      else
      {  somaParcial = 1;
         InsereNumero(lista3, somaParcial);
      }
      coordernadaLista1 =coordernadaLista1->proximo;
      coordernadaLista2 =coordernadaLista2->proximo;
   }
}

void InicializaLista(TLista *lista)
{	lista->inicio = NULL;
	lista->final = NULL;
}

int InsereNumero(TLista *lista, int valor)
{	TNo *coordenadaNo;
	
	coordenadaNo = (TNo*)malloc(sizeof(TNo));

	if(coordenadaNo == NULL)
		return FALSE;
	
	coordenadaNo->numero = valor;
	coordenadaNo->proximo = NULL;
	
	if(lista->inicio == NULL)
		lista->inicio = coordenadaNo;
	else
		lista->final->proximo = coordenadaNo;
	
	lista->final = coordenadaNo;
	
	return TRUE;
}

void ImprimeLista(TLista *lista, char * fraseImprecao)
{	TNo *coordenadaNo;

	coordenadaNo = lista->inicio;
	printf("\n%s\n", fraseImprecao);
	while(coordenadaNo != NULL)
	{	printf("%d\n", coordenadaNo->numero);
		coordenadaNo = coordenadaNo->proximo;
	}
}