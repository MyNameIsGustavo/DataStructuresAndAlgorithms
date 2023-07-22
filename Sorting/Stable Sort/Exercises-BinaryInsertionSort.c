#include <stdio.h>
#define TAM 100 

/*a constante TAM tem um valor maior comparada com outros códigos,
para demonstrar a pesquisa e troca feita pela Busca Binária*/

int buscaBinaria(int *vetor, int esquerda, int direita, int Aux) {
    int meio;

    while (esquerda <= direita) {
        meio = (esquerda + direita) / 2;
        if (vetor[meio] == Aux)
            return meio;
        else if (vetor[meio] < Aux)
            esquerda = meio + 1;
        else
            direita = meio - 1;
    }

    return esquerda;
}

int main()
{
    int vetor[TAM];
    int iFor, jFor, Aux,posicao;
    
    printf("Insira os elementos do vetor:");
    
    for(iFor = 0; iFor < TAM; iFor++){
        scanf("%d", &vetor[iFor]);
    }
    
    //Inicio do algoritmo INSERÇÃO DIRETA BINARIA:

    for(iFor = 1; iFor < TAM; iFor++){
        Aux = vetor[iFor];
        jFor = iFor - 1;
        posicao = buscaBinaria(vetor,0,jFor,Aux);
         while (jFor >= posicao) {
            vetor[jFor + 1] = vetor[jFor];
            jFor--;
        }     
        vetor[jFor + 1] = Aux;
        
    }
    
    printf("Elementos do vetor em ordem ascedente:\n");
        for (iFor = 0; iFor < TAM; iFor++) {
        printf("%4d", vetor[iFor]);
    }
    return 0;
}



