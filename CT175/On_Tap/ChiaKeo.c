#include<stdio.h>

#define MAX_N 100
#define MAX_VERTICES 100
typedef struct{
	int A[MAX_N][MAX_N];
	int n;
}Graph;

typedef struct{
	int data[MAX_VERTICES];
	int size;
}List;

void makenull_list(List *L){
	L->size = 0;
}

void push_list(List *L, int x){
	L->data[L->size] = x;
	L->size++;
}

int element_at(List *L, int i){
	return L->data[i-1];
}

void copy_list(List *L1, List *L2){
	makenull_list(L1);
	int i, y;
	for (i=1; i<=L2->size; i++){
		y = element_at(L2, i);
		push_list(L1, y);
	}
}

void init_graph(Graph *G, int n){
	int i, j;
	G->n = n;
	for (i=1; i<=G->n; i++)
		for (j=1; j<=G->n; j++)
			G->A[i][j] = 0;
}

void add_edge(Graph *G, int u, int v){
	G->A[u][v] = 1;
}
int adjacent(Graph *G,int x, int y){
	return (G->A[x][y] != 0);
}

List neighbors(Graph *G, int x){
	List L;
	makenull_list(&L);
	for(int i = 1; i <= G->n;i++){
		if(adjacent(G,x,i) && i != x){
			push_list(&L,i);
		}
	}
	return L;

}
int rank[MAX_VERTICES];
int d[MAX_VERTICES];
int k=0;
void ranking(Graph *G){
	int x, u;
	for (u=1; u<=G->n; u++){
		d[u] = 1;
	}
	for (x=1; x<=G->n; x++){
		for (u=1; u<=G->n; u++){
			if (G->A[u][x] != 0){
				if(d[x] >= d[u]){
					d[u] = d[x] + 1;
				}
			}
		}

	}
	for(x = 1; x <= G->n; x++){
		for(u = 1; u <= G->n;u++){
			if(G->A[u][x] != 0){
				if(d[x] == d[u])
					d[u] += 1;
			}
		}
	}	
	for(int i = 1; i <= G->n;i++){
		printf("%d\n",d[i]);
	}


}


int main(){
	Graph G;
	int n, m, u, v, i;
	// freopen("deadline.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_graph(&G, n);
	for (i=1; i<=m; i++){
		scanf ("%d%d", &u, &v);
		add_edge(&G, u, v);
	}
	ranking(&G);
	int sum = 0;
	for (int x = 1; x <= G.n;x++){
		sum+= d[x];
	}
	printf("%d",sum);
	return 0;
}