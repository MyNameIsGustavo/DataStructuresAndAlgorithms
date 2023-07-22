/*Normalmente, a Ordenação por Seleção Direta
(Selection Sort) ela é instavel, ou seja,
os elementos que são iguais em um vetor por exemplo,
nao sao ordenados pela ordem de entrada, porém é possivel tornar o selection sort estavel.*/

#include <stdio.h>

int main(void)
{
    int numeros[5];
    int cont1, cont2, menor, aux;

    cont1 = 1;

    while (cont1 <= 5)
    {
        scanf("%d", &numeros[cont1]);
        cont1++;
    }
    for (cont1 = 0; cont1 < 5 - 1; cont1++)
    {
        menor = cont1;
        for (cont2 = cont1 + 1; cont2 < 5; cont2++)
        {
            if (numeros[menor] > numeros[cont2])
                menor = cont2;
        }

        aux = numeros[menor];
        for (int k = menor; k > cont1; k--)
        {
            numeros[k] = numeros[k - 1];
            numeros[cont1] = aux;
        }
    }

    cont1 = 1;
    while(cont1 <= 5){
        printf("%4d", numeros[cont1]);
        cont1 = cont1 + 1;
    }

    return 0;
}