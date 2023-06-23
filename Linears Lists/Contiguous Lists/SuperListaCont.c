/*SUPER LISTA CONTIGUA EM C*/

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
int ExcluiNumero(TLista *, int);
int PesquisaNumero(TLista *, int);

int main (void)
{	int numeroDigitado;
   TLista lista;
   
   InicializaLista(&lista);
   while(TRUE)
   {  printf("Insira um numero na lista: ");
      scanf("%d", &numeroDigitado);
      
      if(numeroDigitado <= 0)
         break;
      
      if(InsereNumero(&lista, numeroDigitado) == FALSE)
      {  puts("Memoria insuficiente para esta operacao.");
         return 2;
      }
   }
   
   ImprimeLista(&lista, "O conteudo da lista: ");
   
   while(TRUE)
   {  printf("Insira um numero de pesquisa na lista: ");
      scanf("%d", &numeroDigitado);
      
      if(numeroDigitado <= 0)
         break;
      
      if(PesquisaNumero(&lista, numeroDigitado) == FALSE)
         puts("Valor nao existe na lista.");
      else
         puts("Valor existe na lista");
   }
   
   while(TRUE)
   {  printf("Insira um numero para exclusao da lista: ");
      scanf("%d", &numeroDigitado);
      
      if(numeroDigitado <= 0)
         break;
      
      if(ExcluiNumero(&lista, numeroDigitado) == FALSE)
         puts("Valor nao existe na lista.");
      else if(ExcluiNumero(&lista, numeroDigitado) == 10)
      {   puts("\nCodigo 10: Lista vazia. [ENCERRANDO O PROGRAMA].");
		    break;
		}
      else
         ImprimeLista(&lista, "O novo conteudo da lista: ");
   }

   return 0;  
}

int PesquisaNumero(TLista *lista, int valor)
{  int aux;
   
   aux = 0;
   while(aux < lista->indiceAtualLista && valor != lista->lista[aux])
      aux += 1;
   
   if(aux == lista->indiceAtualLista)
      return FALSE;
   else
      return TRUE;
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

int ExcluiNumero(TLista *lista, int valor)
{  int aux;

   if(lista->indiceAtualLista == 0)
      return 10;

   aux = 0;
   while(aux < lista->indiceAtualLista && valor != lista->lista[aux])
      aux += 1;
      
   if(aux == lista->indiceAtualLista)
      return FALSE;
   else
   {
      while(aux < lista->indiceAtualLista)
      {  lista->lista[aux] = lista->lista[aux + 1];
         aux += 1;
      }
      lista->indiceAtualLista = lista->indiceAtualLista - 1;
   }
   return TRUE;
}