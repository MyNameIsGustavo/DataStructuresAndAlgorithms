/*Impar ou par - lista contigua em C*/

#include <stdio.h>
#include <stdlib.h>

#define		TRUE	   1
#define		FALSE	   0
#define     MAXIMO   50
typedef int TNo;

typedef struct
{  int inicializaLista, indiceAtualLista;
   TNo lista[MAXIMO];
}  TLista;

void InicializaLista(TLista *);
void ImprimeLista(TLista *, char *);
int InsereNumero(TLista *, int);
int ImparPar(TLista *, TLista *, TLista *);

int main (void)
{	int numeroDigitado;
   TLista lista1, lista2, lista3;
   
   InicializaLista(&lista1);
   InicializaLista(&lista2);
   
   while(TRUE)
   {  printf("Insira um numero na [primeira lista]: ");
      scanf("%d", &numeroDigitado);
      
      if(numeroDigitado < 0)
         break;
      
      if(InsereNumero(&lista1, numeroDigitado) == FALSE)
      {  puts("Memoria insuficiente para esta operacao.");
         return 2;
      }
   }
   while(TRUE)
   {  printf("Insira um numero na [segunda lista]: ");
      scanf("%d", &numeroDigitado);
      
      if(numeroDigitado < 0)
         break;
      
      if(InsereNumero(&lista2, numeroDigitado) == FALSE)
      {  puts("Memoria insuficiente para esta operacao.");
         return 2;
      }
   }
   
   ImprimeLista(&lista1, "O conteudo da [primeira lista]: ");
   ImprimeLista(&lista2, "O conteudo da [segunda lista]: ");
   
   InicializaLista(&lista3);
   ImparPar(&lista1, &lista2, &lista3);
   
   ImprimeLista(&lista3, "O conteudo da [terceira lista]:");
   return 0;  
}

int ImparPar(TLista *lista1, TLista *lista2, TLista *lista3)
{  int aux1, aux2, somaParcial;

   aux1 = 0;
   aux2 = 0;
   while(aux1 != lista1->indiceAtualLista && aux2 != lista2->indiceAtualLista)
   {  somaParcial = lista1->lista[aux1] + lista2->lista[aux2];
   
      if((somaParcial % 2) == 0)
      {  somaParcial = 0;
         InsereNumero(lista3, somaParcial);
      }
      else
      {	somaParcial = 1;
		   InsereNumero(lista3, somaParcial);
      }
      aux1 += 1;
      aux2 += 1;
      somaParcial = 0;
   }
}

void InicializaLista(TLista *lista)
{  lista->inicializaLista = 0;
   lista->indiceAtualLista = 0;
}

int InsereNumero(TLista *lista, int valor)
{  if(lista->indiceAtualLista == MAXIMO)
      return FALSE;
   
   lista->lista[lista->indiceAtualLista] = valor;
   lista->indiceAtualLista += 1;
   
   return TRUE;
}

void ImprimeLista(TLista *lista, char * FraseDeImprimir)
{  int aux;
   
   if(lista->indiceAtualLista == 0)
      puts("Lista vazia");
   else
   {  printf("\n%s\n", FraseDeImprimir);
      aux = 0;
      while(aux != lista->indiceAtualLista)
      {  printf("%d\n", lista->lista[aux]);
         aux += 1;
      }
   }
}