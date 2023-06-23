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
{ 	TLista *topo; 	
    int qtde;
} Pilha;

int ListaVazia(Pilha *);
void InicializalizaPilha(Pilha *);
int PUSH(Pilha *, char);
int VerificaBalanceamento(char[], Pilha*);
int ComparaItem(Pilha *, char);
int POP(Pilha *);

int main(void)
{	char expr[MAX];
    Pilha descr;
    
    while(scanf("%s", expr) != EOF)
    {   InicializalizaPilha(&descr);

        if(VerificaBalanceamento(expr, &descr) == TRUE)
            printf("correct\n");
        else
            printf("incorrect\n");
    }

    return 0;
}

int VerificaBalanceamento(char expr[], Pilha *descr)
{   for(int i=0; i <= strlen(expr); i++)
    {	
        if(expr[i]=='(' || expr[i]=='[' || expr[i]== '{')
            PUSH(descr, expr[i]);	

        if(ListaVazia(descr))
        {	
            if(expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
            {	
                descr->qtde = 1;
                break;
            }	
        }
        else
        {	
            if(ComparaItem(descr, expr[i]) == TRUE)
                POP(descr);		
        }
    }
	
    if(descr->qtde == 0)
        return TRUE;
    else
        return FALSE;
}

int ListaVazia(Pilha *descr)
{	if(descr->topo == NULL)
        return TRUE;
    else
        return FALSE;
}

void InicializalizaPilha(Pilha * descr)
{	descr->topo = NULL;
    descr->qtde = 0;
}

int PUSH(Pilha *descr, char s)
{	TLista *coordenadaNo;

    coordenadaNo = (struct regLista *)malloc(sizeof(struct regLista));

    if(coordenadaNo == NULL)
        return FALSE;	
    else
    {	coordenadaNo->delimitador = s;
        coordenadaNo->prox = descr->topo;

        descr->topo=coordenadaNo;
        descr->qtde = descr->qtde + 1;

        return TRUE;
    }
}

int ComparaItem(Pilha *descr, char c)
{	TLista *coordenadaNo;

    coordenadaNo = descr->topo;

    if(c ==')' && coordenadaNo->delimitador == '(')
        return TRUE;
    else if(c == ']' && coordenadaNo->delimitador == '[')
        return TRUE;
    else if(c == '}' && coordenadaNo->delimitador == '{')
        return TRUE;
    else
        return FALSE;
}

int POP(Pilha *descr)
{	TLista *coordenadaNo;

    coordenadaNo = descr->topo;
    descr->topo = descr->topo->prox;
    descr->qtde = descr->qtde - 1;

    free(coordenadaNo);
    return TRUE;	
}