#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
void insertNode(int x,Tree *pRoot ){
if (*pRoot == NULL) //thêm nút m?i ch?a khoá x
{ (*pRoot)=(struct Node*)malloc(sizeof(struct Node));
(*pRoot)->Key = x;
(*pRoot)->Left = NULL;
(*pRoot)->Right = NULL;
}
else if (x < (*pRoot)->Key) insertNode(x,
&((*pRoot)->Left));
else if (x> (*pRoot)->Key) insertNode(x,
&((*pRoot)->Right));
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
        posOrder(T->Left);
        posOrder(T->Right);
        printf("%d ", T->Key);
    }
}
void inOrder(Tree T){
    if(T != NULL){
        inOrder(T->Left);
        printf("%d ", T->Key);
        inOrder(T->Right);
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
Tree minOfRight(Tree T){ // lay node nho nhat ben phai
    Tree p = T;
    while (p->Left != NULL){
        p = p->Left;
    }
    return p;
}

Tree minOfLeft(Tree T){ // lay node nho nhat ben trai
    Tree p = T;
    while (p->Left != NULL){
        p = p->Left;
    }
    return p;
}

Tree maxOfLeft(Tree T){
    Tree p = T;
    while (p->Right != NULL){
        p = p->Right;
    }
    return p; 
}

// tra ve nut sau node mamg gia tri x
Tree getNext(int x, Tree T){
    // ke tiep nut root la nut nho nhat ben phai
    if (T->Key == x) return minOfRight(T->Right);
    // ke tiep nut lon nhat ben trai la not Root
    else if (x == maxOfLeft(T->Left)->Key) return T;
    // nut lon nhat ben phai se khong co nut sau
    else if (x == minOfRight(T->Right)->Key) return NULL; 
    // 
    if (x > T->Key) return getNext(x, T->Right);
    return getNext(x, T->Left);
}
int checkIn(int x, Tree T){
	if(T != NULL){
		if (x > T->Key) return checkIn(x,T->Right);
		if (x < T->Key) return checkIn(x,T->Left);
		if (x == T->Key) return 1;
	}
	return 0;
}
Tree rightSibling(int x, Tree T){
	if(!checkIn(x,T)) return NULL;
	else{
		
	}
}
Tree getLeft(Tree T){
	Tree p = T;
	while(p->Left != NULL){
		p = p->Left;
	}
	return p;
}
Tree getPrevious(int x, Tree T){
    if(x == T->Key) return minOfLeft(T);
    else if (x == minOfRight(T->Right)->Key) return T;
	else if (x == minOfLeft(T->Left)->Key) return NULL;
	if(x > T->Key) return getPrevious(x,T->Right);
	else return getPrevious(x,T->Left);
}
Tree getParent(int x, Tree T){
	if(!checkIn(x,T)) return NULL;
	else{
		if(x == T->Right->Key) return T;
		if (x == T->Left->Key) return T;
		if(x > T->Key) return getParent(x,T->Right);
		else return getParent(x,T->Left);
	}
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



