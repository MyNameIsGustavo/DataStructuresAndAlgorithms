/*Exercicio 03 - Gustavo Rocha: 0030482121034*/

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
void ImprimeArvorePreOrder(TNo *, int);
int isEquivalente(TNo *, TNo*);

int main(void)
{	TNo *raiz = NULL, *aux, *pai;
    TNo *raiz2 = NULL;
	int numero;
   
	puts("\tINICIANDO A ARVORE 1");
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
	
	puts("\n\tINICIANDO A ARVORE 2");
	while (TRUE)
	{	printf("\nInforme o valor: ");
		scanf("%d", &numero);

		if (numero < 0) 
			break;
			
		aux = (TNo *) malloc(sizeof(TNo));
		aux->valor = numero;
		aux->dir = NULL;
		aux->esq = NULL;

		pai = AchaPai(raiz2, numero);
		if (pai == NULL)
			raiz2 = aux;
		else
			if (numero <= pai->valor)
				pai->esq = aux;
			else
				pai->dir = aux;
	}
	
	puts("\tConteudo da arvore 1 - PreOrder.");
	ImprimeArvorePreOrder(raiz, 0);
	
	puts("\n\n\tConteudo da arvore 2 - PreOrder.");
	ImprimeArvorePreOrder(raiz2, 0);
	
	if(isEquivalente(raiz, raiz2) == TRUE)
	   puts("Arvores equivalentes");
	else
	   puts("Arvores nao equivalentes");
	
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

int isEquivalente(TNo *arvore1, TNo *arvore2)
{  	int subEsq, subDir;

	if(arvore1 != NULL && arvore2 != NULL)
	{  if(arvore1->valor == arvore2->valor)
		{  	subEsq = isEquivalente(arvore1->esq, arvore2->esq);
			subDir = isEquivalente(arvore1->dir, arvore2->dir);
         
			if(subEsq == TRUE && subDir == TRUE)
				return TRUE;
			else
				return FALSE;
		}
		else
			return FALSE;
	}
	else if(arvore1 == NULL && arvore2 == NULL)
		return TRUE;
	else
		return FALSE;
}

void ImprimeArvorePreOrder(TNo *arvore, int nivel)
{  	if(arvore != NULL)
	{  for(int aux = 0; aux < nivel; aux++) printf("\t");
		printf("%d\n", arvore->valor);
      
		ImprimeArvorePreOrder(arvore->esq, nivel + 1);
		ImprimeArvorePreOrder(arvore->dir, nivel + 1);
	}
}