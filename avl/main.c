#include "avl.c"
void printStuff(int stuff){
    printf("%i \n", stuff);
}
int main() {
    AVLArvore* a = AVLcriar();

    for (int i = 1; i <= 7; i++) {
        AVLadicionar(a,i);
    }

    printf("\n");
    printf("Contador: %i\n", AVLcontador);
    AVLcontador=0;

    AVLArvore* b = AVLcriar();

    AVLadicionar(b,4);
    AVLadicionar(b,2);
    AVLadicionar(b,8);
    AVLadicionar(b,1);
    AVLadicionar(b,3);
    AVLadicionar(b,6);
    AVLadicionar(b,9);
    AVLadicionar(b,5);
    AVLadicionar(b,7);

    printf("Contador: %i\n", AVLcontador);
    printf("\n");
    //AVLpercorrerProfundidadeInOrder(b);
    AVLpercorrerProfundidadeInOrder(b->raiz, printStuff);
    AVLNo* avlDeletar = AVLlocalizar(b->raiz, 6);
    AVLremover(b, avlDeletar);

    int localizado = 0;
    AVLNo* avlLocalizado = AVLlocalizar(b->raiz, 6);
    if(avlLocalizado!=NULL){
        localizado = avlLocalizado->valor;
        printf("resultado de procurar o nó 6: %i\n", localizado);
    }else{
        printf("resultado de procurar o nó 6: Nó não encontrado\n");
    }
    AVLpercorrerProfundidadeInOrder(b->raiz, printStuff);
    AVLcontador=0;
}
