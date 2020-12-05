#include <stdio.h>
#include <math.h>
struct Node{

      int Key;

      struct Node *Left, *Right;

};
typedef struct Node*  Tree;
Tree initTree(){
    Tree T;
    T = NULL;
    return T;
}

void printPath(int x, Tree T){
    if(T != NULL){
        if(x > T->Key){
            printf("%d ",T->Key);
            printPath(x,T->Right);
        }
        else if(x < T->Key){
            printf("%d ",T->Key);
            printPath(x,T->Left);

        }
        if(T->Key == x){
            printf("%d ", T->Key);
            printf("-> Tim thay");
        }
    }
    else
        printf("-> Khong thay");  
}
int DeleteMin (Tree *pRoot ){
    int k;
    if ((*pRoot)->Left == NULL){
        k=(*pRoot)->Key;
        (*pRoot) = (*pRoot)->Right;
        return k;
    }
    else return DeleteMin(&((*pRoot)->Left));
}
void deleteNode(int x, Tree *T){
    if((*T) != NULL){
        if(x > (*T)->Key){
            deleteNode(x, &((*T)->Right));
        }
        else if(x < (*T)->Key){
            deleteNode(x, &((*T)->Left));
        }
        else{
            if((*T)->Left == NULL && (*T)->Right == NULL){
                (*T) = NULL;
            }
            else if ((*T)->Left == NULL){
                (*T) = (*T)->Right;
            }
            else if ((*T)->Right == NULL){
                (*T) = (*T)->Left;
            }
            else{
                (*T)->Key = DeleteMin(&((*T)->Right));

            }
        }
    }
}
void preOrder(Tree T){
    if(T != NULL){
        printf("%d ", T->Key);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}
void posOrder(Tree T){
    if(T != NULL){
        postOrder(T->Left);
        posOrder(T->Right);
        printf("%d ", T->Key);
    }
}

int countNode(Tree T){
    if(T == NULL) return 0;
    else{
        return 1 + countNode(T->Left) + countNode(T->Right);
    }
}
int max(int a, int b){
    if (a > b) return a;
    return b;
}
int height(Tree T){
    if(T == NULL)
        return 0;
    else{
        return 1 + max(height(T->Left),height(T->Right));
    }
}
int getHeight(Tree T){
    if(height(T) == 0){
        return -1;
    }
    else{
        return height(T);
    }
}
Tree getNext(int x, Tree T){
    if(T != NULL){
        if(x > T)
            getNext(x,T->Right);
        else if(x < T)
            getNext(x,T->Left);
        else{
            
        }
    }

}


