/*Implementacao de uma Lista linear Contigua Dinamicamente (ArrayList)*/

/*O desafio para o dia é implementar uma versão simplificada de uma lista de compras usando arrays. 
A lista deve permitir adicionar novos itens, remover itens e listar todos os itens.
Ao adicionar um novo item,o usuário deve inserir o nome do produto e a quantidade desejada. 
Ao remover um item, o usuário deve especificar o nome do produto. 
Por fim, ao listar todos os itens, a lista deve exibir o nome do produto e a quantidade em um formato legível.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char nome[50];
    int quantidade;
}Item;

typedef struct{

    Item *compras;
    int tamanho;
    int capacidade;

}ListaDeCompras;

ListaDeCompras *criarListadeCompras() {
    ListaDeCompras *lista = (ListaDeCompras *) malloc(sizeof(ListaDeCompras));
    lista->compras = NULL;
    lista->tamanho = 0;
    lista->capacidade = 0;
    return lista;
}

void adicionarItem(ListaDeCompras **lista, char *nome, int quantidade) {
    for (int i = 0; i < (*lista)->tamanho; i++) {
        if (strcmp((*lista)->compras[i].nome, nome) == 0) {
            printf("O produto já está na lista de compras.\n");
            return;
        }
    }

    if ((*lista)->tamanho == (*lista)->capacidade) {
        (*lista)->capacidade += 1;
        (*lista)->compras = (Item *) realloc((*lista)->compras, (*lista)->capacidade * sizeof(Item));
    }
    Item item;
    strcpy(item.nome, nome);
    item.quantidade = quantidade;
    (*lista)->compras[(*lista)->tamanho++] = item;
}

void removerItem(ListaDeCompras **lista, char *nome) {
    int indice = -1;
    for (int i = 0; i < (*lista)->tamanho; i++) {
        if (strcmp((*lista)->compras[i].nome, nome) == 0) {
            indice = i;
            break;
        }
    }
    if (indice != -1) {
        for (int i = indice; i < (*lista)->tamanho - 1; i++) {
            (*lista)->compras[i] = (*lista)->compras[i+1];
        }
        (*lista)->tamanho--;
    }
}

void listarItens(ListaDeCompras **lista) {
    printf("\nLista de compras:\n");
    for (int i = 0; i < (*lista)->tamanho; i++) {
        printf("%s - %d\n", (*lista)->compras[i].nome, (*lista)->compras[i].quantidade);
    }
    printf("\n");
}

int main()
{
    ListaDeCompras *lista = criarListadeCompras();
    char produto[50];
    int quantidade,opcao,inicio;

    inicio = TRUE;

    while (inicio)
    {
        printf("\tLista de Compras\n");
        printf("1-Adicionar Produto\n");
        printf("2-Remover Produto\n");
        printf("3-Mostrar Lista De Compras\n\n");
        printf("4-Sair e Excluir Lista de Compras");
        printf("\nDigite uma opcao:");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            printf("Nome do Produto: ");
            scanf("%s",produto);
            printf("Quantidade do produto: ");
            scanf("%d",&quantidade);
            adicionarItem(&lista,produto,quantidade);
            break;
        case 2:
            printf("Nome do Produto: ");
            scanf("%s",produto);
            removerItem(&lista,produto);
            break;
        case 3:
            listarItens(&lista);
            break;
        if (opcao == 4)
        {
            inicio = FALSE;
            break;
        }
        
    }
    free(&(*lista));
    
    return 0;
}
}