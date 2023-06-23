#include<stdio.h>
#define TAM 30

void merge(int*,int,int,int);
void mergeSort(int*,int,int);

int main()
{
    int vetor[TAM];
    int iFor;

    printf("Insira os elementos do vetor:\n");
    
    for(iFor = 0; iFor < TAM; iFor++){
        scanf("%d",&vetor[iFor]);
    }

    mergeSort(vetor,0,TAM-1);


    printf("Elementos do vetor em ordem ascendente:\n");
    for (iFor = 0; iFor < TAM; iFor++) {
        printf("%d ",vetor[iFor]);
    }

    return 0;
}

void mergeSort(int *vetor,int Lvetor,int Rvetor)
{
    if (Lvetor < Rvetor)
    {
        int meio = (Lvetor + Rvetor) / 2;
        mergeSort(vetor,Lvetor,meio);
        mergeSort(vetor,meio+1,Rvetor);

        merge(vetor,Lvetor,meio,Rvetor);

    }
}

void merge(int *vetor,int Lvetor,int meio,int Rvetor)
{
    int iFor,jFor,kFor;

    const int n1 = meio - Lvetor + 1;
    const int n2 = Rvetor - meio;

    int Laux[n1];
    int Raux[n2];

    for (iFor = 0; iFor < n1; iFor++)
    {
        Laux[iFor] = vetor[Lvetor + iFor];
    }
    for (jFor = 0; jFor < n2; jFor++)
    {
        Raux[jFor] = vetor[meio + 1 + jFor];
    }

    iFor = 0;
    jFor = 0;
    kFor = Lvetor;

    while (iFor < n1 && jFor < n2)
    {
        if (Laux[iFor] <= Raux[jFor])
        {
            vetor[kFor] = Laux[iFor];
            iFor++;
        }
        else
        {
            vetor[kFor] = Raux[jFor];
            jFor++;
        }
        kFor++;
    }

    while (iFor < n1)
    {
        vetor[kFor] = Laux[iFor];
        iFor++;
        kFor++;
    }

    while (jFor < n2)
    {
        vetor[kFor] = Raux[jFor];
        jFor++;
        kFor++;
    }
}
