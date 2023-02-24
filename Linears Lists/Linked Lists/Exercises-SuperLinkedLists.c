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
	int	posicao, contador;
	int soma;
} TLista;

void InicializaLista (TLista*);
void ImprimeLista(TLista*, char *);
int InsereNumero(TLista*, int);
int ExcluiNumero (TLista*, int);
int PesquisaNumero(TLista*, int);

int main (void)
{	int numeroDigitado;
	TLista lista;
	
	InicializaLista(&lista);
	
	while(TRUE)
	{	printf("Insira um numero na lista: ");
		scanf("%d", &numeroDigitado);
		
		if(numeroDigitado <= 0)
			break;
		
		if(InsereNumero(&lista, numeroDigitado) == FALSE)
			puts("Memoria insuficiente para esta operacao");
	}
	
	while(TRUE)
	{	printf("Insira um numero para pesquisa na lista: ");
		scanf("%d", &numeroDigitado);
		
		if(numeroDigitado <= 0)
			break;

		if(PesquisaNumero(&lista, numeroDigitado) == FALSE)
			puts("Valor nao existe na lista");
		else
			puts("Valor existe na lista.");
	}
	
	ImprimeLista(&lista, "O conteudo da lista: ");
	
	while(TRUE)
	{	printf("Insira um numero para exclusao da lista: ");
		scanf("%d", &numeroDigitado);
		
		if(numeroDigitado <= 0)
			break;

	   if(ExcluiNumero(&lista, numeroDigitado) == FALSE)
			puts("Valor nao existe na lista");
		else if(ExcluiNumero(&lista, numeroDigitado) == 10)
		{   puts("\nCodigo 10: Lista vazia. [ENCERRANDO O PROGRAMA].");
		    break;
		}
		else
			ImprimeLista(&lista, "Novo conteudo da lista: ");
	}
}

int PesquisaNumero(TLista *lista, int valorPesquisa)
{	TNo *coordenadaNo;
	
	coordenadaNo = lista->inicio;
	while(coordenadaNo != NULL && valorPesquisa != coordenadaNo->numero)
		coordenadaNo = coordenadaNo->proximo;

	if(coordenadaNo == NULL)
		return FALSE;
	else
		return TRUE;
}

void InicializaLista(TLista *lista)
{	lista->inicio = NULL;
	lista->final = NULL;
	lista->posicao = 0;
	lista->contador = 0;
	lista->soma = 0;
}

int InsereNumero(TLista *lista, int valor)
{	TNo *coordenadaNo;
	
	coordenadaNo = (TNo*)malloc(sizeof(TNo));
	lista->contador++;
	if(coordenadaNo == NULL)
		return FALSE;
	
	coordenadaNo->numero = valor;
	coordenadaNo->proximo = NULL;
	
	if(lista->inicio == NULL)
		lista->inicio = coordenadaNo;
	else
		lista->final->proximo = coordenadaNo;
	
	lista->final = coordenadaNo;
	
	lista->soma += coordenadaNo->numero;
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
	printf("A soma da lista eh: %d.\n", lista->soma);
	printf("A lista possui %d nós.\n", lista->contador);
	
}

int ExcluiNumero(TLista *lista, int valor)
{	TNo *coordenadaNo, *anterior;
	
	if(lista->inicio == NULL)
	   return 10;
	
	anterior = NULL;
	coordenadaNo = lista->inicio;
	while(coordenadaNo != NULL && valor != coordenadaNo->numero)
	{	anterior = coordenadaNo;
		coordenadaNo = coordenadaNo->proximo;
	}
	
	if(coordenadaNo == NULL)
		return FALSE;
		
	else
	{	if(anterior == NULL)
		   lista->inicio = coordenadaNo->proximo;
		else
			anterior->proximo = coordenadaNo->proximo;
		lista->soma = lista->soma - coordenadaNo->numero;
		
		if(coordenadaNo == lista->final)
			lista->final = anterior;
		
		free(coordenadaNo);
		lista->contador--;
	}
	return TRUE;
}