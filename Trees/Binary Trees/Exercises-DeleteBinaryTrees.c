#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define        TRUE        1
#define        FALSE       0

struct regNo
{ 	struct regNo *esq;
	int valor;
	struct regNo *dir;
}; typedef struct regNo TNo;

TNo *AchaPai (TNo *, int);
void DeletaArvorePosOrder(TNo *);
void ImprimeArvorePreOrder(TNo *, int);

int main(void)
{	TNo *raiz = NULL, *aux, *pai;
	int numero;

	while (TRUE)
	{	printf("\nInforme o valor: ");
		scanf("%d", &numero);

		if (numero < 0) 
			break;
			
		aux = (TNo *) malloc(sizeof(TNo));
		aux->valor = numero;
		aux->dir = NULL;
		aux->esq = NULL;

		pai = AchaPai(raiz, numero);
		if (pai == NULL)
			raiz = aux;
		else
			if (numero <= pai->valor)
				pai->esq = aux;
			else
				pai->dir = aux;
	} 
	
	ImprimeArvorePreOrder(raiz, 0);
	
	puts("Deseja deletar a arvore - Menu: SIM[1] OU NAO[0]");
	printf("Informe uma opcao: ");
	scanf("%d", &numero);
	
	if(numero)
	{   DeletaArvorePosOrder(raiz);
	    puts("\n\tArvore eliminada com sucesso!");
	}
	else
	   puts("Encerrando o exercicio 4.");
	   
	return 0;
}

TNo *AchaPai(TNo *arvore, int numero)
{	if (arvore == NULL)
		return NULL;
	else
		if (numero <= arvore->valor)
			if (arvore->esq == NULL)
				return arvore;
			else
				return AchaPai(arvore->esq, numero);
		else
			if (arvore->dir == NULL)
				return arvore;
			else
				return AchaPai(arvore->dir, numero);
}

void ImprimeArvorePreOrder(TNo *arvore, int nivel)
{  	if(arvore != NULL)
	{  	for(int aux = 0; aux < nivel; aux++) printf("\t");
		printf("%d\n", arvore->valor);
      
		ImprimeArvorePreOrder(arvore->esq, nivel + 1);
		ImprimeArvorePreOrder(arvore->dir, nivel + 1);
	}
}

void DeletaArvorePosOrder(TNo *arvore)
{  	if(arvore != NULL)
	{  	DeletaArvorePosOrder(arvore->esq);
		DeletaArvorePosOrder(arvore->dir);
		free(arvore);
	}
}