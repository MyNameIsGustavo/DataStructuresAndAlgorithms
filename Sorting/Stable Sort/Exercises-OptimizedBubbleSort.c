#include <stdio.h>
#define TAM 10

int main(void)
{   int Numeros [10];
    int vFor, Aux, Contador,flag = 0;

    printf("Digite 10 números: ");
    
    for(vFor = 0; vFor < TAM; vFor++){
        scanf("%d", &Numeros[vFor]);
    }
    
    //Inicio do algoritmo BUBBLESORT:
    
    for(Contador = 1; Contador < TAM; Contador++){
        

        for (vFor = 0; vFor < TAM - 1; vFor++){
            
            if (Numeros[vFor] > Numeros[vFor + 1]){
                
                Aux = Numeros[vFor];
                Numeros[vFor] = Numeros [vFor + 1];
                Numeros[vFor + 1] = Aux;
                flag=1;
                
            }
            if (!flag) //Se o vetor estiver ordenado (flag = 0) ele parará de pesquisar
            {
                break;
            }
            
        }
    }
    
    printf("Elementos do array em ordem crescente:\n");
        for (vFor = 0; vFor < TAM; vFor++) {
        printf("%4d", Numeros[vFor]);
    }
    return 0;
}