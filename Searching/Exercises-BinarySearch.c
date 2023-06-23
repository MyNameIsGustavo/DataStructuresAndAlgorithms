#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define TRUE  1
#define FALSE 0

#define MAX_TAM 25

int vetor[MAX_TAM];

int main(void)
{	int N, c, vInfo, ini, fim, meio;

	scanf("%d", &N);
	
	/* Recebendo os elementos do vetor */
	/* Para este programa funcionar o usuário deverá informar 
		os valores em ordem crescente */
	for (c = 0; c < N; c++)
		scanf("%d", &vetor[c]);
	
	scanf("%d", &vInfo);
	
	ini = 0;
	fim = N - 1;

	while (ini <= fim)
	{	meio = (ini + fim) / 2;

		if (vInfo < vetor[meio])
			fim = meio - 1;
		else 
			if (vInfo > vetor[meio])
				ini = meio + 1;
			else
				break;
	}
	
	if (ini <= fim)
		printf("vetor[%d] == %d\n", meio, vInfo);
	else
		printf("Valor %d NAO EXISTE no vetor\n", vInfo);
	
	return 0;
}
