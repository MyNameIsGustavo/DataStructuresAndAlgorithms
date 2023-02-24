//Algoritmo - Pesquisa Sequencial.
#include <stdio.h>

int main (void)
{   int c, v, t;
    int a[11];
    
    //Inicio;
    
    c = 1;
    while(c <= 10){
        a[c] = c * 10;
        c = c + 1;
    }
    
    c = 1;
    while(c <= 10){
        printf("%d\n", a[c]);
        c = c + 1;
    }
    
    printf("\nInforme o valor a pesquisar: ");
    scanf("%d", &v);
    
    c = 1;
    while(c <= 10){
        if (a[c] == v){
            break;
        }
        c = c + 1;
    }
    
    if(c > 10){
        printf("Valor não encontrado no vetor.");
    }
    else{
        printf("Valor encontrado no elemento número %d", c);
    }
    return 0;
}