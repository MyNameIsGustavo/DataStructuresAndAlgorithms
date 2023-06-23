#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define     TRUE     1
#define     FALSE    0

struct regLista 
{  int numero;
   struct regLista* prox;
}; typedef struct regLista TLista;

typedef struct 
{  TLista* topo;
   int qtde, qtdeForaPilha;
} Pilha;

void InicializaPilha(Pilha*);
void ImprimePilha(Pilha*);
void PUSH(Pilha*, int);
void POP(Pilha*, int[]);
void regraJogo(Pilha*);

int qtdeForaPilha;

int main(void) 
{  int numero, i;
   Pilha pilha;
   while (TRUE) 
   {  scanf("%d", &numero);
      if (numero == 0 || numero > 50)
         break;
         
      InicializaPilha(&pilha);
      
      int foraPilha[numero];
      
      for (i = numero; i > 0; i--)
         PUSH(&pilha, i);

      POP(&pilha, foraPilha);

      printf("Discarded cards:");
      for (i = 0; i < qtdeForaPilha; i++) 
      {  printf(" %d", foraPilha[i]);
         if (i != qtdeForaPilha - 1)
            printf(",");
      }
      printf("\nRemaining card: %d\n", pilha.topo->numero);
      qtdeForaPilha = 0;
   }
   return 0;
}

void regraJogo(Pilha* pilha) 
{  TLista *coordenadaPilha, *basePilha;

   basePilha = pilha->topo;
   coordenadaPilha = pilha->topo;
   
   if (basePilha->prox != NULL) 
   {  while (basePilha->prox != NULL)
         basePilha = basePilha->prox;

      pilha->topo = pilha->topo->prox;
      coordenadaPilha->prox = basePilha->prox;
      basePilha->prox = coordenadaPilha;
   }
}

void InicializaPilha(Pilha* pilha) 
{  pilha->topo = NULL;
   pilha->qtde = 0;
}

void PUSH(Pilha* pilha, int numero) 
{  TLista *coordenadaPilha;

   coordenadaPilha = (TLista*)malloc(sizeof(TLista));
   coordenadaPilha->prox = pilha->topo;
   pilha->topo = coordenadaPilha;
   coordenadaPilha->numero = numero;

   pilha->qtde++;
}

void POP(Pilha* pilha, int foraPilha[]) 
{  TLista *coordenadaPilha;

   while (pilha->topo->prox) 
   {  coordenadaPilha = pilha->topo;
      foraPilha[qtdeForaPilha++] = coordenadaPilha->numero;
      pilha->topo = pilha->topo->prox;
      free(coordenadaPilha);
      regraJogo(pilha);
   }
}