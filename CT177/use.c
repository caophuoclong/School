#include "BinaryTree.c"

int main(){
Tree T=NULL;
Tree p;
int x;

insertNode(27,&T);
insertNode(12,&T);
insertNode(40,&T);
insertNode(4,&T);
insertNode(20,&T);
insertNode(34,&T);
insertNode(30,&T); 
insertNode(50,&T); 
inOrder(T);
printf("%d",getParent(50,T)->Key);
return 0;
}
