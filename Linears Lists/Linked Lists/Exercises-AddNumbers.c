#include <stdio.h>
#include <stdlib.h>

#define		TRUE	1
#define		FALSE	0

struct conteudo{
	int numero;
	struct conteudo *proximo;
}; typedef struct conteudo TNo;

typedef struct{
	TNo *inicio, *final;
} TLista;

void InicializaLista (TLista*);
void ImprimeLista(TLista*, char *);
int InsereNumero(TLista*, int);
int SomaListas(TLista*, TLista*);
int ExcluiNumero (TLista*, int);

int main(void)
{  int numeroDigitado;
	TLista lista1, lista2;
	
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
	printf("A soma dos numeros da listas eh: %d", SomaListas(&lista1, &lista2));
	
   return 0;
}

int SomaListas(TLista *lista1, TLista *lista2)
{  TNo *coordenadaLista1, *coordenadaLista2;
   int somaListas = 0;
   
   coordenadaLista1 = lista1->inicio;
   coordenadaLista2 = lista2->inicio;
   
   while(coordenadaLista1 != NULL && coordenadaLista2 != NULL)
   {  somaListas += coordenadaLista1->numero + coordenadaLista2->numero;
      coordenadaLista1 = coordenadaLista1->proximo;
      coordenadaLista2 = coordenadaLista2->proximo;
   }
   return somaListas;
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