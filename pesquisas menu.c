#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pesquisas.c"

int main() {
    int opcao, chave, resultado, n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n];

    // Inicializa a semente do gerador de números aleatórios
    srand(time(NULL));

    // Preenche o vetor com valores aleatórios entre 1 e 100
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 100 + 1;
    }
    while(1){
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
                resultado = pesquisaSequencial(chave, v, n);
                break;
            case 2:
                resultado = pesquisaSequencialSentinela(chave, v, n);
                break;
            case 3:
                resultado = pesquisaBinaria(chave, v, n);
                break;
            case 4:
                resultado = pesquisaBinariaRecursiva(chave, v, 0, n-1);
                break;
            case 5:
                resultado = pesquisaInterpolacao(chave, v, n);
                break;
            default:
                printf("Opcao invalida!\n");
                //return 1;
        }

        if (resultado == -1) {
            printf("Chave nao encontrada.\n");
        } else {
            printf("Chave encontrada no indice %d.\n", resultado);
        }

        //return 0;
    }
    
}
