/*Autores: Gabriel Silva dos Santos (22211293) e Luiz Gustavo Souza Oliveira (21211017)
Componente curricular: Estrutura de dados (EXA 806)
Concluido em: 28/04/2023*/

#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef struct Node{

    char cpf_str[50];
    long long int cpf;
    
    char name[50];
    char date_of_birth[20];
    int phone;
    struct Node *left,*right;
    int height;

} node;

//referências das funções

node *create_node();

node *insert_node(node *root, long long int cpf, char *name, char *birth, int phone, char *cpf_str);

node *delete(node *root, long long int cpf);

node *search(node *root, long long int cpf);

node *left_rotation(node *father);

node *right_rotation(node *father);

node *left_right_rotation(node *father);

node *right_left_rotation(node *father);

node *height(node *root);

node *balancing(node *root);

int calculating_height(node *root);

int whitch_is_bigger(int a, int b);

int whitch_is_the_height(node *root);

int fb(node *root);

void fuction_print(node *root);


#endif
