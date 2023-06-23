#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define		TRUE	   1
#define 	FALSE	   0
#define		MAX 	   1000

struct regLista
{	char delimitador;	
    struct regLista *prox;	
};	typedef struct regLista TLista;

typedef struct
{ 	TLista *topo; 	} 
Pilha;

int ListaVazia(Pilha *);
void InicializalizaPilha(Pilha *);
int PUSH(Pilha *, char);
int VerificaBalanceamento(char[], Pilha*);
int ComparaItem(Pilha *, char);
int POP(Pilha *);

int main(void)
{  char expr[MAX];
   Pilha descr;
   int qtdeTeste;
   
   scanf("%d", &qtdeTeste);
   while(qtdeTeste)
   {  scanf("%s", expr);
      InicializalizaPilha(&descr);

      printf("%d\n", VerificaBalanceamento(expr, &descr));
      qtdeTeste--;
   }

   return 0;
}

void InicializalizaPilha(Pilha * descr)
{	descr->topo = NULL;
}

int PUSH(Pilha *descr, char s)
{	TLista *coordenadaNo;

   coordenadaNo = (struct regLista *)malloc(sizeof(struct regLista));

   if(coordenadaNo == NULL)
      return FALSE;	
   else
   {  coordenadaNo->delimitador = s;
      coordenadaNo->prox = descr->topo;

      descr->topo=coordenadaNo;

      return TRUE;
   }
}

int VerificaBalanceamento(char expr[], Pilha *descr)
{  int qtdeDiamante;

   qtdeDiamante = 0;
	for(int i=0; i <= strlen(expr); i++)
   {	if(expr[i]=='<')
         PUSH(descr, expr[i]);	

      else if(expr[i] == '>')
      {  if(ListaVazia(descr) == FALSE)
         {  if(ComparaItem(descr, expr[i]) == TRUE){
               POP(descr);
               qtdeDiamante++;
            }
         }
      }
   }
   return qtdeDiamante;
}

int ComparaItem(Pilha *descr, char c)
{	TLista *coordenadaNo;

   coordenadaNo = descr->topo;
   if(c =='>' && coordenadaNo->delimitador == '<')
      return TRUE;
   else
      return FALSE;
}

int POP(Pilha *descr)
{	TLista *coordenadaNo;

   coordenadaNo = descr->topo;
   descr->topo = descr->topo->prox;

   free(coordenadaNo);
   return TRUE;	
}

int ListaVazia(Pilha *descr)
{	if(descr->topo == NULL)
      return TRUE;
    else
      return FALSE;
}