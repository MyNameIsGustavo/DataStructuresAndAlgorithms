/*Demonstração do Heap Sort em Vetor
Normalmente, a ordenação é feita com arvore binaria completa*/

#include<stdio.h>
#define TAM 10

void troca(int*,int*);
void heapSort(int[], int n);
void heapify(int[],int,int);

int main()
{
    int numeros[TAM];

    printf("Insira %d numeros para o vetor\n",TAM);
    for (int i = 0; i < TAM; i++)
    {
        scanf("%d", &numeros[i]);
    }

    heapSort(numeros,TAM);
    
    printf("Vetor Ordenado:\n");
    for (int i = 0; i < TAM; i++)
    {
        scanf("%d ", &numeros[i]);
    }
    printf("\n");
    return 0;
}

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int vetor[], int n, int i) {

    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
  
    if (esquerda < n && vetor[esquerda] > vetor[maior])
      maior = esquerda;
  
    if (direita < n && vetor[direita] > vetor[maior])
      maior = direita;
  
    
    if (maior != i) {
      troca(&vetor[i], &vetor[maior]);
      heapify(vetor, n, maior);
    }
}

void heapSort(int vetor[], int n) {
    
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(vetor, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      troca(&vetor[0], &vetor[i]);
  

      heapify(vetor, i, 0);
    }
  }
