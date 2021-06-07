#include <stdio.h>
typedef int ElementType;
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
			G->C[i][j] = 0;
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
		deg += G->C[x][i];
	return deg;
}

int adjacent(Graph *G, ElementType x, ElementType y){
	return (G->C[x][y] != 0);
}



int FordFullkerson(Graph *G, int s, int t){
	init_flow(G);
	Queue Q;
	int found = 0;
	Label labels[G->n];
	while(1){
		int u;
		for(u = 1; u <= G->n;u++){
			labels[u].dir = 0;
		}
		labels[s].dir = 1;
		labels[s].pre = s;
		labels[s].sigma = 100000;
		make_null_queue(&Q);
		push_queue(&Q,s);
		while(!empty_queue(&Q)){
			ElementType u = top_queue(&Q);
			pop_queue(&Q);
			int v;
			for(v = 1; v <= G->n;v++){
				if (labels[v].dir == 0 && adjacent(G,u,v) && G->F[u][v] < G->C[u][v]){
					labels[v].dir = 1;
					labels[v].pre = u;
					labels[v].sigma = G->C[u][v];
				}
				if(labels[v].dir == 0 && adjacent(G,v,u) && G->F[v][u] > 0){
					labels[v].dir = -1;
					labels[v].pre = u;
					labels[v].sigma = G->C[v][u];
				}
			}
			

			if(labels[t].dir != -1){
				found = 1;
				break;
			}
		}
		if(found){

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