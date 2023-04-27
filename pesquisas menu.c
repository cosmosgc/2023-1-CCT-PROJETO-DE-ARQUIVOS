#include <stdio.h>
#include "pesquisas.c"

int main() {
    int opcao, chave, resultado;
    int v[] = {1, 2, 3, 4, 5};

    printf("Escolha uma opcao:\n");
    printf("1. Pesquisa Sequencial\n");
    printf("2. Pesquisa Sequencial com Sentinela\n");
    printf("3. Pesquisa Binaria\n");
    printf("4. Pesquisa Binaria Recursiva\n");
    printf("5. Pesquisa por Interpolacao\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    printf("Digite a chave a ser procurada: ");
    scanf("%d", &chave);

    switch (opcao) {
        case 1:
            resultado = pesquisaSequencial(chave, v, 5);
            break;
        case 2:
            resultado = pesquisaSequencialSentinela(chave, v, 5);
            break;
        case 3:
            resultado = pesquisaBinaria(chave, v, 5);
            break;
        case 4:
            resultado = pesquisaBinariaRecursiva(chave, v, 0, 4);
            break;
        case 5:
            resultado = pesquisaInterpolacao(chave, v, 5);
            break;
        default:
            printf("Opcao invalida!\n");
            return 1;
    }

    if (resultado == -1) {
        printf("Chave nao encontrada.\n");
    } else {
        printf("Chave encontrada no indice %d.\n", resultado);
    }

    return 0;
}
