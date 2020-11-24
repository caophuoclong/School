#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double he_so;
    int bac;
} DonThuc;

struct Node{
    DonThuc e;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position DaThuc;

DaThuc khoitao(){
    DaThuc s1;
    s1 = (struct Node *)malloc(sizeof(struct Node));
    s1->Next = NULL;
    return s1;
}
Position locate(DonThuc s, DaThuc L){
    Position p;
    int found =0;
    p = L;
    while(p->Next != NULL && !found){
        if(p->Next->e.bac <= s.bac)
            return p;
        p = p->Next;

    }
    return p;
}
void chenDonThuc(DonThuc s, DaThuc *L){
    DaThuc s1;
    s1 = khoitao();
    s1->e = s;
    s1->Next = NULL;
    Position p;
    p = locate(s,*L);
    if(p->Next != NULL){
        if(p->Next->e.bac == s.bac){
            p->Next->e.he_so += s.he_so;
            p->Next->e.bac = s.bac;
        }
        
        if (p->Next->e.bac < s.bac){
        Position q;
        q = p->Next;
        p->Next = s1;
        s1->Next = q;
        }
    }
    else{
        p->Next = s1;
    }
}
DaThuc congDaThuc(DaThuc D1, DaThuc D2){
    DaThuc D;
    D = D1;
    while(D2->Next != NULL){
        chenDonThuc(D2->Next->e, &D);
        D2 = D2->Next;
    }
    return D;
}