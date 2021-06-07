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
int FordFullkerson(Grap *G, int s, int t){
	int_flow(G);
	Queue Q;

	while(1){
		Label labels[G->n];
		lables[s].dir = 1;
		labels[s].pre = s;
		laebls[s].sigma = 100000;
		make_null_queue(&Q);
		push_queue(&Q,s);
		while(!empty_queue(&Q)){

		}


	}
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