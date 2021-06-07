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

// Grap
typedef struct{
	ElementType	data[100][100];
	int n; 
}Graph;

void init_graph(Graph *G, int n){
	G->n = n;
	for(int i =1; i <= n;i++){
		for(int j = 1; j <= n;j++){
			G->data[i][j] = 0;
		}
	}
}

void add_edge(Graph *G, ElementType u, ElementType v){
	G->data[u][v] = 1;
	G->data[v][u] = 1;
}

int deg(Graph *G, ElementType x){
	int deg = 0;
	for(int i = 0; i <= G->n;i++)
		deg += G->data[x][i];
	return deg;
}

int adjacent(Graph *G, ElementType x, ElementType y){
	return (G->data[x][y] != 0);
}

List neighbors(Graph *G, ElementType x){
	List L;
	make_null_list(&L);
	for(int i = 1; i <= G->n;i++){
		if(adjacent(G,x,i) && i != x){
			push_list(&L,i);
		}
	}
	return L;

}

int Mark[100]; // Bien cuc bo Mark de tranh truong hop do thi khong lien thong
int parent[100];
List DFS(Graph *G, ElementType x){
	Stack frontier;
	List list;
	make_null_list(&list);
	make_null_stack(&frontier);
	push_stack(&frontier, x);
	while(!empty_stack(&frontier)){
		ElementType u = top_stack(&frontier);
		pop_stack(&frontier);
		if(Mark[u] == 0)
			push_list(&list, u);
		Mark[u] = 1;
		List L = neighbors(G,u);
		for(int i = 0; i < L.size; i++){
			ElementType y = L.data[i];
			if(Mark[y] == 0){
				parent[y] = u;
				printf("%d-%d\n",u,y);
				push_stack(&frontier,y);
			}
		} 

	}

	return list;
}

List BFS(Graph *G, ElementType x){
	List list;
	make_null_list(&list);
	Queue frontier;
	make_null_queue(&frontier);
	if (Mark[x] == 0)
		push_queue(&frontier, x);
	while(!empty_queue(&frontier)){
		ElementType u = top_queue(&frontier);
		pop_queue(&frontier);
		push_list(&list, u);
		Mark[u] = 1;
		List L = neighbors(G,u);
		for(int i = 0; i < L.size; i++){
			ElementType y = L.data[i];
			if(Mark[y] == 0)
				push_queue(&frontier,y);
			Mark[y] = 1;
		}


	}
	return list;
}