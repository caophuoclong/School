#include "linked_list.c"

int main(){
    List L;
    makenullList(&L);
    int n = 3;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d",&x);
        append(x,&L);
    }
    showResult(L);
    int xa = 7;
    addFirst(xa,&L);
    showResult(L);
}