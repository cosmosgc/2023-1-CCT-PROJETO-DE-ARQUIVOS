#ifndef PESQUISAS_H_INCLUDED
#define PESQUISAS_H_INCLUDED

int pesquisaSequencial(int chave, int v[], int n);
int pesquisaSequencialSentinela(int chave, int v[], int n);
int pesquisaBinaria(int chave, int v[], int n);
int pesquisaBinariaRecursiva(int chave, int v[], int ini, int fim);
int pesquisaInterpolacao(int chave, int v[], int n);


#endif // PESQUISAS_H_INCLUDED
