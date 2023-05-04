/*Autores: Gabriel Silva dos Santos (22211293) e Luiz Gustavo Souza Oliveira (21211017)
Componente curricular: Estrutura de dados (EXA 806)
Concluido em: 28/04/2023*/

#include <stdio.h>
#include <stdlib.h>
#include "tree.c"

int main(){

    node *root = NULL, *result_seach = NULL;
    int phone = 0,option = 0;
    long long int cpf = 0,remover = 0;
    char name[50], birth[20],cpf_str[50];

    do { 
        
        printf("==============================================================================\n");
        printf("O que deseja fazer?\n\n");
        printf("[1] - Cadastro\n[2] - Remocao\n[3] - Busca\n[4] - Sair\n");
        printf("==============================================================================\n");
        scanf("%d",&option);



        switch (option){

            case 1:
                
                printf("Insira o nome: ");
                scanf("%s", &name);
                printf("Insira o cpf: ");
                scanf("%s", &cpf_str);
                cpf = strtod(cpf_str,NULL);
                printf("Insira a data de nascimento: ");
                scanf("%s",&birth);
                printf("Insira o telefone: ");
                scanf("%d",&phone);
                root = insert_node(root,cpf,name,birth,phone,cpf_str);
                break;
            
            case 2:

                printf("Insira o cpf da pessoa que deseja remover: ");
                scanf("%d",&remover);
                
                result_seach = search(root,remover);

                if (result_seach){
                    
                    root = delete(root,remover);
                    printf("\nOperacao efetuada com sucesso!\n");
                
                }
                else{
                    printf("\nNenhum cadastro correspondente encontrado!\n");
                }
                
                break;
            
            case 3:

                printf("Insira o cpf da pessoa que deseja buscar: ");
                scanf("%lld",&remover);
                result_seach = search(root,remover);

                if (result_seach){

                    printf("\nNome --> %s\n",result_seach->name);
                    printf("Cpf --> %s\n",result_seach->cpf_str);
                    printf("Data de nascimento --> %s\n",result_seach->date_of_birth);
                    printf("Telefone --> %d\n",result_seach->phone);

                }
                else{

                    printf("\nNada encontrado na busca\n");
                }
                break;

            case 4:
                
                option = 4;
                break;

            default:

                printf("Opcao invalida!\n");
                break;
        }

    } while (option != 4);
    

    return 0;
    
}
