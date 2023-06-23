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

void ImprimeArvoreInOrder(TNo *, int);
void ImprimeArvorePreOrder(TNo *, int);
void ImprimeArvorePosOrder(TNo *, int);
TNo *AchaPai(TNo *, int);

int main(void)
{	TNo *raiz = NULL, *aux, *pai;
	int numero, qtdeTestes, contTestes, qtdeValores;

	
	scanf("%d", &qtdeTestes);
	contTestes = 1;
	while(contTestes <= qtdeTestes)
	{  raiz = NULL;
	
	   scanf("%d", &qtdeValores);
	   for(int i = 0; i < qtdeValores; i++)
	   {  scanf("%d", &numero);
		   if (numero < 0) 
			   break;
			
		   aux = (TNo *) malloc(sizeof(TNo));
		   aux->valor = numero;
		   aux->dir = NULL;
		   aux->esq = NULL;

		   /* Fazendo o encadeamento do novo noh */
		   pai = AchaPai(raiz, numero);
		   if (pai == NULL)
			   raiz = aux;
		   else
			   if (numero <= pai->valor)
				   pai->esq = aux;
			   else
				   pai->dir = aux;
	   }
	    printf("Case %d:", contTestes);
   	    printf("\nPre.:");
   	    ImprimeArvorePreOrder(raiz, 0);
   	
   	    printf("\nIn..:");
   	    ImprimeArvoreInOrder(raiz, 0);
   	
   	    printf("\nPost:");
   	    ImprimeArvorePosOrder(raiz, 0);
   	
   	    printf("\n\n");
	contTestes++;
	}
	return 0;
}

TNo *AchaPai(TNo *r, int n)
{	if (r == NULL)
		return NULL;
	else
		if (n <= r->valor)
		/* n é descendente do lado esquerdo de r */
			if (r->esq == NULL)
				return r;
			else
				return AchaPai(r->esq, n);
		else
		/* n é descendente do lado direito de r */
			if (r->dir == NULL)
				return r;
			else
				return AchaPai(r->dir, n);
}

void ImprimeArvorePreOrder(TNo *arvore, int nivel)
{  int aux;

   if(arvore != NULL)
   {  
      printf(" %d", arvore->valor);
      ImprimeArvorePreOrder(arvore->esq, nivel + 1);
      ImprimeArvorePreOrder(arvore->dir, nivel + 1);
   }
}

void ImprimeArvoreInOrder(TNo *arvore, int nivel)
{  int aux;

   if (arvore != NULL)
   {  
      ImprimeArvoreInOrder(arvore->esq, nivel + 1);
      printf(" %d", arvore->valor);
      ImprimeArvoreInOrder(arvore->dir, nivel + 1);
   }
}

void ImprimeArvorePosOrder(TNo *arvore, int nivel)
{  int aux;

   if (arvore != NULL)
   {  
      ImprimeArvorePosOrder(arvore->esq, nivel + 1);
      ImprimeArvorePosOrder(arvore->dir, nivel + 1);
      printf(" %d", arvore->valor);
   }
}