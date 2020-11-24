#include <stdio.h>

typedef struct {
    char MSSV[10];
    char Hotel[50];
    float R1, R2, R3;

}SinhVien;
typedef SinhVien ElementType;

struct Node{
    ElementType Element;
    struct Node* Next;
};
typedef struct Node Position;
typedef Position List;

List getFailedList(List L){
    float dtb;
    List L2;
    L2 = getList();
    struct Node* p = L;
    while(p->Next != NULL){
        dtb = p->Next->Element.R1 + p->Next->Element.R2 + p->Next->Element.R3;
        dtb = dtb/3;
        if(dtb < 4){
            append(p->Next->Element, &L2);
        }
        L = L->Next;
    }
    return L2;
}