#include <stdio.h>

int pesquisaSequencial(int chave, int v[], int n);

int main() {
    int v[] = {10, 20, 30, 40, 50};
    int chave, indice;
    char opcao;

    do {
        printf("\nDigite a chave de busca: ");
        scanf("%d", &chave);

        indice = pesquisaSequencial(chave, v, 5);

        if (indice == -1) {
            printf("\nChave nao encontrada.\n");
        } else {
            printf("\nChave encontrada na posicao %d.\n", indice);
        }

        printf("\nDeseja continuar? (S/N): ");
        scanf(" %c", &opcao);
    } while (opcao == 'S' || opcao == 's');

    return 0;
}

int pesquisaSequencial(int chave, int v[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (v[i] == chave) {
            return i;
        }
    }
    return -1; // índice inválido
}
