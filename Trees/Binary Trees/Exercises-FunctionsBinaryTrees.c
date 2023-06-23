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

TNo *AchaPai(TNo *, int);
int MaiorValor(TNo *);
int MenorValor(TNo *);
int QtdeFolhas(TNo *);
int AlturaArvore(TNo *);
int PesqNum(TNo *, int);
int QtdeBytes(TNo *);
int QtdeNosComUmFilho(TNo *);
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
	puts("\n\tArvore: Pre - Order.");
	ImprimeArvorePreOrder(raiz, 0);
	
	printf("O MAIOR valor da arvore: %d\n", MaiorValor(raiz));
	printf("O MENOR valor da arvore: %d\n", MenorValor(raiz));
	printf("A QUANTIDADE de folhas da arvore: %d\n", QtdeFolhas(raiz));
	printf("A ALTURA da arvore: %d\n\n", QtdeFolhas(raiz) - 1);
	
	printf("Os nos com apenas um filho: %d\n\n", QtdeNosComUmFilho(raiz));
	printf("Qtde total de bytes da arvore: %d\n\n", QtdeBytes(raiz));
	
	while(TRUE)
   {	printf("Informe um valor para pesquisar: ");
 		scanf("%d", &numero);
 		
 		if(numero < 0) 
 		   break;
	 	if(PesqNum(raiz, numero) == TRUE)
 		   printf("O numero %d esta na arvore.\n", numero);   
 		else
 		   printf("O numero %d nao esta na arvore.\n", numero);   
	}
	
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

int MaiorValor(TNo *arvore)
{ 	if(arvore == NULL)
		return 0;
	
	if (arvore->dir != NULL)
		return MaiorValor(arvore->dir);
	else
		return arvore->valor;
}

int MenorValor(TNo *arvore)
{ 	if(arvore == NULL)
		return 0;
	
	if (arvore->esq != NULL)
		return MenorValor(arvore->esq);
	else
		return arvore->valor;
}

int QtdeFolhas(TNo *arvore)
{ 	if(arvore == NULL)
		return 0;
	else
		if(arvore->esq == NULL && arvore->dir == NULL)
		   return 1;	
		else 
			return QtdeFolhas(arvore->dir) + QtdeFolhas(arvore->esq);
}

int AlturaArvore(TNo *arvore)
{ 	int ramoEsq, ramoDir;

   if(arvore == NULL)
	   return 0;	
	else
	{	ramoEsq = AlturaArvore(arvore->esq);
	   ramoDir = AlturaArvore(arvore->dir);
	   
		if(ramoEsq > ramoDir)
			return ramoEsq + 1;
		else
			return ramoDir + 1;
	}
}

int QtdeNosComUmFilho(TNo *arvore)
{  int cont;

   if (arvore == NULL)
      return 0;
   
   cont = 0;

   if ((arvore->esq == NULL && arvore->dir != NULL) || (arvore->esq != NULL && arvore->dir == NULL))
      cont++;
    
   cont += QtdeNosComUmFilho(arvore->esq);
   cont += QtdeNosComUmFilho(arvore->dir);

   return cont;
}

int QtdeBytes(TNo *arvore)
{  if (arvore == NULL)
      return 0;
      
   int tamanhoNo = sizeof(TNo) - sizeof(int);      
   int subEsq = QtdeBytes(arvore->esq);
   int subDir = QtdeBytes(arvore->dir);

   return tamanhoNo + subEsq + subDir;
}

int PesqNum(TNo* arvore, int numeroPesq)
{	if (arvore == NULL) 
		return FALSE;	
	
	if (arvore->valor == numeroPesq) 
	   return TRUE;
	else if (numeroPesq < arvore->valor) 
	   return PesqNum(arvore->esq, numeroPesq);	
	else 
	   return PesqNum(arvore->dir, numeroPesq);	
}

void ImprimeArvorePreOrder(TNo *arvore, int nivel)
{  if(arvore != NULL)
   {  for(int aux = 0; aux < nivel; aux++) printf("\t");
      printf("%d\n", arvore->valor);
      
      ImprimeArvorePreOrder(arvore->esq, nivel + 1);
      ImprimeArvorePreOrder(arvore->dir, nivel + 1);
   }
}