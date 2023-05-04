#include <stdio.h>
#include <stdlib.h>
//https://github.com/Francielly-Nascimento/Arvore_binaria_busca

typedef struct No {
    char value;
    struct No* esquerda;
    struct No* direita;
} No;

No* newNo(char value) {
    No* Node = (No*)malloc(sizeof(No));
    Node->value = value;
    Node->esquerda = NULL;
    Node->direita = NULL;
    return Node;
}

No* inserir(No* root, char value) {
    if (root == NULL) {
        return newNo(value);
    }
    if (value < root->value) {
        root->esquerda = inserir(root->esquerda, value);
    } else if (value > root->value) {
        root->direita = inserir(root->direita, value);
    }
    return root;
}

int procurar
(No* root, char value) {
    if (root == NULL) {
        return 0;
    }
    if (value == root->value) {
        return 1;
    }
    if (value < root->value) {
        return procurar
          (root->esquerda, value);
    } else {
        return procurar
          (root->direita, value);
    }
}

No* removeNo(No* root, char value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->value) {
        root->esquerda = removeNo(root->esquerda, value);
    } else if (value > root->value) {
        root->direita = removeNo(root->direita, value);
    } else {
        if (root->esquerda == NULL) {
            No* temp = root->direita;
            free(root);
            return temp;
        } else if (root->direita == NULL) {
            No* temp = root->esquerda;
            free(root);
            return temp;
        }
        No* temp = root->direita;
        while (temp && temp->esquerda != NULL) {
            temp = temp->esquerda;
        }
        root->value = temp->value;
        root->direita = removeNo(root->direita, temp->value);
    }
    return root;
}

No* remover(No* root, char value) {
    if (!procurar
      (root, value)) {
        printf("O valor %c nao esta presente na arvore.\n", value);
        return root;
    }
    printf("Removendo o valor %c da arvore.\n", value);
    return removeNo(root, value);
}

void preOrder(No* root) {
    if (root != NULL) {
        printf("%c ", root->value);
        preOrder(root->esquerda);
        preOrder(root->direita);
    }
}

void inOrder(No* root) {
    if (root != NULL) {
        inOrder(root->esquerda);
        printf("%c ", root->value);
        inOrder(root->direita);
    }
}

void postOrder(No* root) {
    if (root != NULL) {
        postOrder(root->esquerda);
        postOrder(root->direita);
        printf("%c ", root->value);
    }
}

int main() {
    No* root = NULL;
    int option;
    char value;

    do {
        printf("\n\nMenu de opcoes:\n");
        printf("(1) Adicionar na arvore\n");
        printf("(2) Valor esta na arvore?\n");
        printf("(3) Remover da arvore\n");
        printf("(4) Imprimir Pre-Ordem\n");
        printf("(5) Imprimir em ordem Central\n");
        printf("(6) Imprimir em Pos-Ordem\n");
        printf("(0) Sair\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Digite o valor a ser adicionado: ");
                scanf(" %c", &value);
                root = inserir(root, value);
                printf("Valor %c adicionado com sucesso na arvore.\n", value);
                break;
            case 2:
                printf("Digite o valor a ser buscado: ");
                scanf(" %c", &value);
                if (procurar
                  (root, value)) {
                    printf("O valor %c esta presente na arvore.\n", value);
                } else {
                    printf("O valor %c nao esta presente na arvore.\n", value);
                }
                break;
            case 3:
                printf("Digite o valor a ser removido: ");
                scanf(" %c", &value);
                root = remover(root, value);
                break;
            case 4:
                printf("Pre-Ordem: ");
                preOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Em ordem central: ");
                inOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Pos-Ordem: ");
                postOrder(root);
                printf("\n");
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (option != 0);

    return 0;
}
