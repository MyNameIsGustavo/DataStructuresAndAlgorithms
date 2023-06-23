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
void ImprimeArvoreInOrderTextual (TNo *);

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
	printf("\n\n");
	
	ImprimeArvoreInOrderTextual(raiz);
	
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

void ImprimeArvoreInOrderTextual(TNo *arvore)
{	if (arvore != NULL)
	{	printf("<");
		ImprimeArvoreInOrderTextual(arvore->esq);
	
		printf("%d", arvore->valor);
		
		ImprimeArvoreInOrderTextual(arvore->dir);
		printf(">");
	}
	else
	   printf("< >");
}