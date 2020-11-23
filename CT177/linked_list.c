#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct Node {
  ElementType Element;
  struct Node *Next;
};
typedef struct Node *Position;
typedef Position List; 
void makenullList(List *L){ // Khởi tạo danh sách rỗng
  (*L) = (struct Node*)malloc(sizeof(struct Node));
  (*L)->Next  = NULL;
};
int member(ElementType x, List L){ // Kiểm tra tồn tại của phần tử trong danh sách
  while(L->Next != NULL){
    if (x == L->Next->Element)
      return 1;
    L = L->Next;
  }
  return 0;
}
void append(ElementType x, List *L){ // Thêm phần tử vào cuối
  Position p;
  List P;
  makenullList(&P);
  P ->Element = x;
  P->Next = NULL;
  p = (*L);
  while(p->Next != NULL){
    p = p->Next;
  }
  p->Next = P;
}
Position locate(ElementType x, List L){ // Tìm vị trí đầu tiên của danh sách
  Position p = L;
  while(p->Next != NULL){
    if (p->Next->Element == x)
      break;
    else
      p = p ->Next;
  }
  return p;
}
void addFirst(ElementType x, List *L){ // Thêm phần tử vào đầu danh sách
  Position p;
  makenullList(&p);
  p->Element = x;
  p->Next = NULL;
  p->Next = (*L) ->Next;
  (*L) ->Next = p;
}
List intersectionSet(List L1, List L2){ // Giao 2 tập hợp
  List L3;
  makenullList(&L3);
  while(L1->Next  != NULL){
    if(member(L1->Next->Element,L2)){
      append(L1->Next->Element,&L3);
    }
    L1 = L1->Next;
  }
  return L3;
}
List unionSet(List L1, List L2){ // Hợp 2 tập hợp
  while(L2->Next != NULL){
    if(!member(L2->Next->Element,L1)){
      append(L2->Next->Element,&L1);
    }
    L2 = L2->Next;
  }
  return L1;
}

void deleteList(Position p, List *L){ // Xoá phần tử tại vị trí P
  Position T = (struct Node *)malloc(sizeof(struct Node));
  //makenullList(&T); 
  T = p->Next;
  p->Next = T->Next;
  free(T);
}
void deleteFirst(ElementType x, List *L){ // Xoá phần tử x đầu tiên xuất hiện
  Position p = locate(x,*L);
  deleteList(p,L);
}
void showResult(List L){ // Hiển thị danh sách
  while(L ->Next != NULL){
    printf("%d ",L->Next->Element);
    L = L->Next;
  }
  printf("\n");
}
void sort(List *L){ // Sắp xếp danh sách tăng dần
    Position p = (*L);
  while(p->Next != NULL){
      Position q = p->Next;
      while(q->Next != NULL){
          if(q->Next->Element < p->Next->Element ){
                int temp;
                temp = p ->Next->Element;
                p->Next->Element = q->Next->Element;
                q->Next->Element = temp;
          }
          
        q = q->Next;
      }
    p = p->Next;
}
}

void normalize(List *L){ // Xoá phần tử trùng
  Position p = (*L);
  while(p->Next != NULL){
    Position q = p->Next;
    while(q->Next != NULL){
      if(q->Next->Element == p->Next->Element)
        deleteList(q,L);
      else
      {
        q = q->Next;
      }
      
    }
    p = p->Next;
  }
  
}

void copyEvenNumbers(List L1, List *L2){ // Copy số chẵn 
  makenullList(L2);
  while(L1->Next != NULL){
    if(L1->Next->Element % 2 == 0)
      append(L1->Next->Element,L2);
    L1 = L1->Next;
  }
}
List difference(List L1, List L2){ // Hiệu 2 tập hợp
  List L3;
  makenullList(&L3);
  while(L1->Next != NULL){
    if(!member(L1->Next->Element,L2))
      append(L1->Next->Element,&L3);
    L1 = L1->Next;

  }
  return L3;
  
}
float getAvg(List L){
  float sum = 0;
  int count = 0;
  while(L->Next != NULL){
    sum += L->Next->Element;
    count ++;
    L=L->Next;
  }
  return (float)sum/count;
}
// List reverseList(List L){
//   List L3;
//   makenullList(&L3);
//   while(L->Next != NULL){

//   }
// }
