#include "list.c"

typedef struct{
	int data[100];
	int size;
}Stack;
void make_null_stack(Stack *S){
	S->size = 0;
}
void push(Stack *S, int x){
	S->data[S->size] = x;
	S->size++;
}
int top(Stack *S){
	return S->data[S->size];
}
void pop(Stack *S){
	S->	size--;
}
int empty(Stack *S){
	return S->size == 0;
}
