#include "linked_list.c"

void showReverse1(List *L){
    Position p = (*L)->Next;
    while(p->Next != NULL){
        p = p->Next;
    }
    (*L)->Next = p;
    printf("%d ", (*L)->Next->Element);
    free(p);
}
int main(){
    int x = 5;
    List L;
    makenullList(&L);
    for(int i = 0 ; i  < x; i++){
        int n;
        scanf("%d",&n);
        append(n,&L);

    }
    printf("\n");
    showReverse1(&L);
    printf("\n");
    showResult(L);
    return 0;
}