/*	Exercicio: 03;
	Nome do aluno: Gustavo Rocha Maia;
	RA: 0030482121034.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define 	TRUE		1
#define 	FALSE		0

struct regLista
{ 	char nomeProduto[26];
	float quantidade;
	int produtoComprado;
	struct regLista *prox;
};	
typedef struct regLista TItem;

typedef struct
{ 	TItem *inicio, *final;
	int qtde;
	char primeiroProduto[26];
	char ultimoProduto[26];
} TLista;

void InicializaLista(TLista *);							
void ImprimeLista(TLista *, char *);
int IncluiItem(TLista *, char[], float, int);
int ExcluiItem(TLista *, char[]);

int main(void)
{	char nomeProdutoDigitado[26];
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
	lst->inicio = NULL;
	lst->final = NULL;
	lst->qtde = 0;
	strcpy(lst->primeiroProduto, "");
	strcpy(lst->ultimoProduto, "");
}

void ImprimeLista(TLista *lst, char *cabec)
{	TItem *aux;
	
	if (lst->inicio == NULL)
		puts("Lista vazia.");
	else
	{	/* imprimindo os valores da lista */
		printf("\n\n\n%s\n", cabec);
		aux = lst->inicio;
		while (aux != NULL)
		{	printf("Nome do produto: %s\n", aux->nomeProduto);
			printf("Quantidade: %f\n", aux->quantidade);
			printf("Check: %d\n", aux->produtoComprado);
			
			aux = aux->prox;
		}
		printf("\nO PRIMEIRO produto da lista: %s\n", lst->primeiroProduto);
		printf("O ULTIMO produto da lista: %s\n", lst->ultimoProduto);
		printf("A QUANTIDADE de itens na lista: %d\n", lst->qtde);
	}
}

int IncluiItem(TLista *lst, char nomeProduto[], float quantidade, int produtoCheck)
{	TItem *aux;
	
	/* criando uma variável struct regLista dinamicamente */
	aux = (TItem *) malloc(sizeof(TItem));
	if (aux == NULL)
		return FALSE;
		
	/* preenchendo os campos da variável criada dinamicamente */		
	strcpy(aux->nomeProduto, nomeProduto);
	aux->quantidade = quantidade;
	aux->produtoComprado = produtoCheck;
	aux->prox = NULL;
		
	/* fazendo o encadeamento do novo item na lista e
	   atualizando os seus descritores */
	if (lst->inicio == NULL){
		lst->inicio = aux;
	   strcpy(lst->primeiroProduto, aux->nomeProduto);
	}
	else
		lst->final->prox = aux;
   
	lst->final = aux;
	strcpy(lst->ultimoProduto, aux->nomeProduto);
	lst->qtde = lst->qtde + 1;	// lst->qtde++;
	
	return TRUE;
}

int ExcluiItem(TLista *lst, char nomeProduto[]) 
{  TItem *aux, *ant;

   // procurando o valor a excluir na lista
	aux = lst->inicio;
	ant = NULL;
	while (aux != NULL && strcmp(aux->nomeProduto, nomeProduto) != 0) 
	{  	ant = aux;
		aux = aux->prox;
	}

	if (aux == NULL)
		return FALSE;
	
	if (ant == NULL)
		lst->inicio = aux->prox;
    else
        ant->prox = aux->prox;
         
    lst->qtde = lst->qtde - 1; // lst->qtde--;
      
    if (aux == lst->final)
		lst->final = ant;

    free(aux);
      
    if(lst->inicio != NULL)
    {  aux = lst->inicio;
       strcpy(lst->primeiroProduto, aux->nomeProduto);
       aux = lst->final;
       strcpy(lst->ultimoProduto, aux->nomeProduto);
    }
	  
	return TRUE;
}