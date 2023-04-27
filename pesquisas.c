#include "pesquisas.h"

int pesquisaSequencial(int chave, int v[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (v[i] == chave) {
            return i;
        }
    }
    return -1; // índice inválido
}

int pesquisaSequencialSentinela(int chave, int v[], int n) {
    int i = 0;
    v[n] = chave; // A última posição do vetor possui o sentinela
    while (v[i] != chave) {
        i++;
    }
    if (i < n) {
        return i;
    }
    return -1; // Índice inválido
}

int pesquisaBinaria(int chave, int v[], int n) {
    int inicio = 0, meio, fim = n - 1;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (chave < v[meio]) {
            fim = meio - 1;
        } else if (chave > v[meio]) {
            inicio = meio + 1;
        } else {
            return meio;
        }
    }
    return -1; // Índice impossível
}

int pesquisaBinariaRecursiva(int chave, int v[], int ini, int fim) {
    int meio = (ini + fim) / 2;
    if (ini > fim) {
        return -1;
    }
    if (chave == v[meio]) {
        return meio;
    } else if (chave < v[meio]) {
        return pesquisaBinariaRecursiva(chave, v, ini, meio - 1);
    } else {
        return pesquisaBinariaRecursiva(chave, v, meio + 1, fim);
    }
}

int pesquisaInterpolacao(int chave, int v[], int n) {
    int ini = 0, meio, fim = n - 1;
    while (ini <= fim) {
        meio = ini + ((fim - ini) * (chave - v[ini])) / (v[fim] - v[ini]);
        if (chave < v[meio]) {
            fim = meio - 1;
        } else if (chave > v[meio]) {
            ini = meio + 1;
        } else {
            return meio;
        }
    }
    return -1; // Índice impossível
}
