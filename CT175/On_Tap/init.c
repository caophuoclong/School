#include <stdio.h>

typedef int ElementType;
// List



typedef struct{
	ElementType data[100];
	int size; 
}List;

void make_null_list(List *L){
	L->size = 0;
}

void push_list(List *L, ElementType element){
	L->data[L->size] = element;
	L->size++;
}

int count_element(List *L){
	return L->size;
}

// stack
// 
typedef struct{
	ElementType data[100];
	int size;
} Stack;

void make_null_stack(Stack *S){
	S->size = 0;
}

void push_stack(Stack *S, ElementType element){
	S->data[S->size] = element;
	S->size++;
}

ElementType top_stack(Stack *S){
	return S->data[S->size -1];
}

void pop_stack(Stack *S){
	S->size--;
}

int empty_stack(Stack *S){
	return S->size ==0;
}

// Queue

typedef struct{
	ElementType data[100];
	int front, rear;
}Queue;

void make_null_queue(Queue *Q){
	Q->front = 0;
	Q->rear = -1;
}

void push_queue(Queue *Q, ElementType element){
	Q->rear++;
	Q->data[Q->rear] = element;
}

ElementType top_queue(Queue *Q){
	return Q->data[Q->front];
}

void pop_queue(Queue *Q){
	Q->front++;
}

int empty_queue(Queue *Q){
	return Q->front > Q->rear;
}

// Edges
typedef struct{
	ElementType x, y;
}Edge;
// Graph

typedef struct{
	Edge edges[100];
	int n, m; 
}Graph;



