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
}

int deg(Graph *G, ElementType x){
	int deg = 0;
	for(int i = 0; i <= G->n;i++)
		deg += G->data[x][i];
	return deg;
}

int adjacent(Graph *G, ElementType x, ElementType y){
	return (G->data[y][x] != 0);
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

int cong_viec(Graph *G, int x){
    List L = neighbors(G,x);
    return L.size;
    
}


int main(){
	int n, m;
	int u,v;
	Graph G;

//freopen("deadline.txt","r",stdin);
	scanf("%d %d",&n,&m);
	init_graph(&G,n);

	for(int i = 0; i < m;i++){
		scanf("%d %d",&u,&v);
		add_edge(&G,u,v);
	}
	int a;
	scanf("%d",&a);
	printf("%d:%d",a,cong_viec(&G,a));


}