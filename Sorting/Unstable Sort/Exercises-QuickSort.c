#include<stdio.h>
#include<stdlib.h>
#define TAM 30

void quickSort(int [],int,int);

int main(){

    int vetor[TAM];
    int iFor;

    printf("Insira os elementos do vetor:\n");
    
    for(iFor = 0; iFor < TAM; iFor++){
        scanf("%d",&vetor[iFor]);
    }
    quickSort(vetor,0,TAM-1);

    printf("Elementos do vetor em ordem ascendente:\n");
    for (iFor = 0; iFor < TAM; iFor++) {
        printf("%d ",vetor[iFor]);
    }

    return 0;
}

void quickSort(int arr[], int esquerda, int direita) {

      int i = esquerda, j = direita;

      int temporario;

      int pivo = arr[(esquerda + direita) / 2]; //Para melhores casos de Ordenacao, usa-se o meio do vetor como pivo

      while (i <= j) {

            while (arr[i] < pivo)
                  i++;
            while (arr[j] > pivo)
                  j--;
            if (i <= j) {

                  temporario = arr[i];

                  arr[i] = arr[j];

                  arr[j] = temporario;
                  i++;
                  j--;

            }

      };

      if (esquerda < j)
            quickSort(arr, esquerda, j);
      if (i < direita)
            quickSort(arr, i, direita);
}