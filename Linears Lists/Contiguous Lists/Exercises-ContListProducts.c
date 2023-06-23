/* Exercicio: 04;
   Nome do aluno: Gustavo Rocha Maia;
   RA: 0030482121034.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define        TRUE        1 
#define        FALSE       0
#define        MAXIMO      50

struct regLista
{  	char nomeProduto[26];
	float quantidade;
	int produtoComprado;
}; typedef struct regLista TItem;

typedef struct
{  	int final, inicio;
	int qtde;
	char primeiroProduto[26];
	char ultimoProduto[26];
	TItem lista[MAXIMO];
} TLista;

void InicializaLista(TLista *);							
void ImprimeLista(TLista *, char *);
int IncluiItem(TLista *, char[], float, int);
int ExcluiItem(TLista *, char[]);

int main(void)
{  char nomeProdutoDigitado[26];
	float quantidadeDigitada;
	int produtoCheck;
	
	TLista lista;
	InicializaLista(&lista);
	printf("--- Lista de compras ---");	
	while (TRUE)
	{	printf("\nInforme o nome do produto que deseja comprar: ");
		scanf("%s", nomeProdutoDigitado);
		
		if (strcmp(nomeProdutoDigitado, "FIM") == 0)
			break;
		
		printf("Informe a quantidade: ");
		scanf("%f", &quantidadeDigitada);
		
		printf("Informe se o produto foi comprado [0 ou 1]: ");
		scanf("%d", &produtoCheck);
		
		if (IncluiItem(&lista, nomeProdutoDigitado, quantidadeDigitada, produtoCheck) == FALSE)
		{	puts("Memoria insuficiente para esta operacao...");
			return 2;
		}
	}
   
   ImprimeLista(&lista, "Conteudo da lista de compras: ");
	
	while(TRUE)
	{	printf("Informe o nome de um produto para exclusao: ");
		scanf("%s", nomeProdutoDigitado);
	
		if (strcmp(nomeProdutoDigitado, "FIM") == 0)
			break;

		if (ExcluiItem(&lista, nomeProdutoDigitado) == FALSE)
			puts("Este produto nao existe na lista.");
		else
			ImprimeLista(&lista, "A lista de compras atualizada: ");
	}
	
	return 0;
}

void InicializaLista(TLista *lst)
{	/* inicializando o conjunto de descritores da lista */
	lst->inicio = 0;
	lst->final = 0;
	lst->qtde = 0;
	strcpy(lst->primeiroProduto, "");
	strcpy(lst->ultimoProduto, "");
}

void ImprimeLista(TLista *lst, char *cabec)
{	int aux;
	
	if (lst->final == 0)
		puts("Lista vazia.");
	else
	{	/* imprimindo os valores da lista */
		printf("\n\n%s\n", cabec);
		aux = 0;
		while (aux != lst->final)
		{	printf("Nome do produto: %s\n", lst->lista[aux].nomeProduto);
			printf("Quantidade: %f\n", lst->lista[aux].quantidade);
			printf("Check: %d\n", lst->lista[aux].produtoComprado);
			
			aux = aux + 1;
		}
		printf("\nO PRIMEIRO produto da lista: %s\n", lst->primeiroProduto);
		printf("O ULTIMO produto da lista: %s\n", lst->ultimoProduto);
		printf("A QUANTIDADE de itens na lista: %d\n", lst->qtde);
	}
}

int IncluiItem(TLista *lst, char nomeProduto[], float quantidade, int produtoCheck)
{	if(lst->final == MAXIMO)
		return FALSE;
	else
	{  	if(lst->final == 0)
			strcpy(lst->primeiroProduto, nomeProduto);
	
		strcpy(lst->lista[(lst->final)].nomeProduto, nomeProduto);
		lst->lista[(lst->final)].quantidade = quantidade;
		lst->lista[(lst->final)].produtoComprado = produtoCheck;
		lst->final = lst->final + 1;
		lst->qtde = lst->qtde + 1;			// lst->qtde++;
		strcpy(lst->ultimoProduto, nomeProduto);
	}
	return TRUE;
}

int ExcluiItem(TLista *lst, char nomeProduto[]) 
{  	int aux;

	// procurando o valor a excluir na lista
	aux = 0;
	while (aux < lst->final && strcmp(lst->lista[aux].nomeProduto, nomeProduto) != 0) 
		aux = aux + 1;

	if(aux == lst->final)
		return FALSE;

	else
	{  	while(aux < lst->final)
		{  lst->lista[aux] = lst->lista[aux + 1];
			aux = aux + 1;
		}
		lst->final = lst->final - 1;
		lst->qtde = lst->qtde - 1;
   
		strcpy(lst->primeiroProduto, lst->lista[lst->inicio].nomeProduto);
		strcpy(lst->ultimoProduto, lst->lista[lst->final - 1].nomeProduto); 
	}
	return TRUE;
}