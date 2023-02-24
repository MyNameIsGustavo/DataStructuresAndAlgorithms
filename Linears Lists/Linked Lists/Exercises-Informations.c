#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define     TRUE     1
#define     FALSE    0

struct conteudo
{  char utilizacaoComodo[10];
   int larguraComodo;
   int comprimentoComodo;
   int classeComodo;
   int potenciaLampada;
   struct conteudo *proximo;
};  typedef struct conteudo TNo;

typedef struct
{  TNo *inicio, *final; }  
TLista;

void InicializaLista(TLista*);
void ImprimeLista(TLista*, char *);
int InsereInformacoes(TLista*);

int main(void)
{  TLista lista;
   
   InicializaLista(&lista);
   if(InsereInformacoes(&lista) == FALSE)
      puts("Memoria insuficiente para esta operacao");
   ImprimeLista(&lista, "---INFORMACOES ADICIONADAS---");
   return 0;
}

void InicializaLista(TLista *lista)
{  lista->inicio = NULL;
   lista->final = NULL;
}

int InsereInformacoes(TLista *lista)
{  TNo *coordenadaNo;

   coordenadaNo = lista->inicio;
   coordenadaNo = (TNo*)malloc(sizeof(TNo));
   if(coordenadaNo == NULL)
      return FALSE;
   else
   {  printf("Informe o nome do comodo: ");
      scanf("%s", coordenadaNo->utilizacaoComodo);
   
      printf("Informe a largura do comodo: ");
      scanf("%d", &coordenadaNo->larguraComodo);
   
      printf("Informe o comprimento do comodo: ");
      scanf("%d", &coordenadaNo->comprimentoComodo);
   
      printf("Informe a classe do comodo: ");
      scanf("%d", &coordenadaNo->classeComodo);
   
      printf("Informe a potencia da lampada: ");
      scanf("%d", &coordenadaNo->potenciaLampada);
   
      if(lista->inicio == NULL)
         lista->inicio = coordenadaNo;
      else
         lista->final->proximo = coordenadaNo;
      
      lista->final = coordenadaNo;
      
      return TRUE;
   }
}

void ImprimeLista(TLista *lista, char *fraseDeImprimir)
{  TNo *coordenadaNo;
   
   coordenadaNo = lista->inicio;
   printf("\n%s\n", fraseDeImprimir);
   while(coordenadaNo != NULL)
   {  printf("Nome do comodo: %s.\n", coordenadaNo->utilizacaoComodo); 
      printf("Largura do comodo: %d.\n", coordenadaNo->larguraComodo); 
      printf("Comprimento do comodo: %d.\n", coordenadaNo->comprimentoComodo); 
      printf("Classe do comodo: %d.\n", coordenadaNo->classeComodo); 
      printf("Potencia da lampada: %d\n", coordenadaNo->potenciaLampada); 

      coordenadaNo = coordenadaNo->proximo;
   }
}