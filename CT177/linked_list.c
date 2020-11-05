#include <stdio.h>

typedef int ElementType;
struct Node {
  ElementType data;
  struct Node *next;
}
typedef struct Node List;

void makenullList(List *L){
  (*L) = (struct Node)malloc(sizeof(Node));
  (*L)->next  = NULL;

};

