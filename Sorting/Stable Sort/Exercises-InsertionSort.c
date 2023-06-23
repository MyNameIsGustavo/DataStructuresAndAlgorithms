#include <stdio.h>
#include <stdio.h>
#define TAM 5

int main(void)
{   int vetor[TAM];
    int iFor, jFor, Aux;
    
    printf("Insira os elementos do vetor:");
    
    for(iFor = 0; iFor < TAM; iFor++){
        scanf("%d", &vetor[iFor]);
    }
    
    //Inicio do algoritmo INSERÇÃO DIRETA:

    for(iFor = 1; iFor < TAM; iFor++){
        Aux = vetor[iFor];
        for(jFor = iFor; (jFor > 0) && (Aux < vetor[jFor - 1]); jFor--)
            vetor[jFor] = vetor[jFor - 1];
        vetor[jFor] = Aux;
        
    }
    
    printf("Elementos do vetor em ordem ascedente:\n");
        for (iFor = 0; iFor < TAM; iFor++) {
        printf("%4d", vetor[iFor]);
    }
    return 0;
}