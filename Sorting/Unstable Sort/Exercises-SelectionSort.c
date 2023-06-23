//Algoritmo - Seleção Direta.
#include <stdio.h>

int main (void)
{   int numeros[5];
    int cont1, cont2, menor, aux;
    
    cont1 = 1;
    
    while(cont1 <= 5){
        scanf("%d", &numeros[cont1]);
        cont1 = cont1 + 1;
    }
    
    cont1 = 1;
    while( cont1 <= 5){
        menor = cont1;
        cont2 = cont1 + 1;
        
        while(cont2 <= 5){
            if(numeros[cont2] < numeros[menor]){
                menor = cont2;
            }
            cont2 = cont2 + 1;
        }
        
        aux = numeros[cont1];
        numeros[cont1] = numeros[menor];
        numeros[menor] = aux;
        
        cont1 = cont1 + 1;
    }
    
    cont1 = 1;
    while(cont1 <= 5){
        printf("%4d", numeros[cont1]);
        cont1 = cont1 + 1;
    }
    
    return 0;
}