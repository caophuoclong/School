#include <stdio.h>
typedef struct{
    int Elements[100];
    int Last;
} List;
void makenullList(List *L){
    L->Last = 0;
}
int members(int x, List L){
    for(int i=0; i<L.Last;i++)
        if(x == L.Elements[i])
            return 1;
    return 0;
}
void insertList(int x, List *L){
    L->Elements[L->Last] = x;
    L->Last ++;
}
void sort(List *L){
    for(int i = 0 ; i < L->Last;i++){
        for(int j =i+1 ; j < L->Last;j++){
            if(L->Elements[i] > L->Elements[j]){
                int temp = L->Elements[i];
                L->Elements[i] = L->Elements[j];
                L->Elements[j] = temp;
            }
        }

    }
}
void showList(List L){
    for(int i = 0 ;i < L.Last;i++)
        printf("%d ", L.Elements[i]);
    printf("\n");
}
void Hop(List L, List L1, List *L2){
    makenullList(L2);
   *L2 = L;
    for(int i = 0 ;i < L1.Last;i++)
        if(!members(L1.Elements[i],*L2 ))
            insertList(L1.Elements[i],L2);

}
int main(){
    int n;
    scanf("%d",&n);
    List L;
    int x;
    makenullList(&L);
    for(int i=0;i <n;i++){
        scanf("%d",&x);
        if(!members(x,L))
            insertList(x,&L);
    }
    showList(L);
    List L1;
    makenullList(&L1);
    scanf("%d",&n);
    for(int i = 0;i <n;i++){
        scanf("%d",&x);
        if(!members(x,L1))
            insertList(x,&L1);
    }
    showList(L1);
    List L2;
    Hop(L,L1,&L2);
    showList(L2);

    
    return 0; // return
}