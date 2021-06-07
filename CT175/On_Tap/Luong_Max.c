#include <stdio.h>
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
typedef struct{
	int dir; // >0: +; <0 -; = 0 chua co nhan;
	int pre; // dinh truoc
	int sigma; // luong tang luong;
}Label;
typedef struct{
	ElementType	C[100][100];
	ElementType F[100][100];
	int n; 
}Graph;

void init_graph(Graph *G, int n){
	int i,j;
	G->n = n;
	for(i =1; i <= n;i++){
		for(j = 1; j <= n;j++){
			G->data[i][j] = 0;
		}
	}
}

void add_edge(Graph *G, ElementType u, ElementType v, int w){
	G->C[u][v] = w;
}
void init_flow(Graph *G){
	int i, j;
	for(i = 1; i <= G->n;i++){
		for(j = 1; j<= G->n;j++){
			G->F[i][j] = 0;
		}
	}
}

int deg(Graph *G, ElementType x){
	int deg = 0;
	int i;
	for( i = 0; i <= G->n;i++)
		deg += G->data[x][i];
	return deg;
}

int adjacent(Graph *G, ElementType x, ElementType y){
	return (G->data[x][y] != 0);
}

List neighbors(Graph *G, ElementType x){
	List L;
	int i;
	make_null_list(&L);
	for( i = 1; i <= G->n;i++){
		if(adjacent(G,x,i) && i != x){
			push_list(&L,i);
		}
	}
	return L;

}

int main(){
	int n, m, u,v,w;
	int i,j;
	Graph G;
	freopen("data_luong.txt", "r", stdin);
	scanf("%d%d",&n,&m);
	init_graph(&G,n);
	for(i =0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add_edge(&G,u,v,w);
	}



	return 0;
}