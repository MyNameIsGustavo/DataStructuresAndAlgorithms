#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define  TRUE     1
#define  FALSE    0
#define  MAXIMO   500

struct regNo
{  struct regNo *esq;
   int valor;
   struct regNo *dir;
}; typedef struct regNo TNo;

TNo *AchaPai(TNo *, int);
void PercorreArvore(TNo *);

int main(void)
{  TNo *raiz = NULL, *aux, *pai;
   int numero, qtdeTestes, cont, qtdeNumeros;

   scanf("%d", &qtdeTestes);
   cont = 0;
   while (qtdeTestes--)
   {  scanf("%d", &qtdeNumeros);
   
      while (qtdeNumeros--)
      {  scanf("%d", &numero);

         if (numero < 0)
            break;

         aux = (TNo *)malloc(sizeof(TNo));
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

      printf("Case %d:\n", ++cont);
      PercorreArvore(raiz);
      raiz = NULL;
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

void PercorreArvore(TNo *arvore)
{  TNo *fila[MAXIMO], *aux;
   int inicio, final;
   
   int imprimeSemEspaco = FALSE;
   inicio = 0;
   final = 0;

   fila[final] = arvore;
   final++;
   while (inicio != final)
   {  aux = fila[inicio++];
   
      if (aux->esq != NULL)
         fila[final++] = aux->esq;
      if (aux->dir != NULL)
         fila[final++] = aux->dir;
      
      if(imprimeSemEspaco == FALSE){
         printf("%d",aux->valor);
         imprimeSemEspaco = TRUE;
      }
      else
         printf(" %d",aux->valor);
   }
   printf("\n\n");
}