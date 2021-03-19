#include "list.c"


typedef struct{
	int data[100];
	int front, rear;
} Queue;
void make_null_queue(Queue * Q){
	Q->front = 0;
	Q->rear = -1;
}
void push(Queue *Q, int Element){
	Q->rear++;
	Q->data[Q->rear] = Element;
}

int top(Queue *Q){
	return Q->data[Q->front];
}

void pop(Queue *Q){
	Q->front++;
}

int is_empty(Queue *Q){
	return Q->front > Q->rear;
}
