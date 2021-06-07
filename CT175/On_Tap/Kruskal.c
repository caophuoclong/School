#include<stdio.h>
#define MAX_N 1000

typedef struct{
	int u, v, w;
}Edge;

typedef struct{
	Edge A[MAX_N];
	int n, m;		
}Graph;

void init_graph(Graph *G, int n){
	G->n = n;
	G->m = 0;
}

void add_edge(Graph *G, int u, int v, int w){
	G->A[G->m].u = u;
	G->A[G->m].v = v;
	G->A[G->m].w = w;
	G->m++;
}
int parent[MAX_N];
int findRoot(int u){
	while(parent[u]!=u)
		u=parent[u];
	return u;
}

int Kruskal(Graph *G, Graph *T){
	int i, j;
	for(i=0; i<G->m; i++)
		for (j=i+1; j<G->m; j++)
			if (G->A[i].w > G->A[j].w){
				Edge tmp=G->A[i];
				G->A[i]=G->A[j];
				G->A[j]=tmp;
			}
	init_graph(T, G->n);
	int u, e, v, w;
	for(u=1; u<=G->n; u++)
		parent[u]=u;
	int sum_w=0;
	for(e=0; e<G->m; e++){
		u=G->A[e].u;
		v=G->A[e].v;
		w=G->A[e].w;
		int root_u=findRoot(u);
		int root_v=findRoot(v);
		if(root_u != root_v){
				add_edge(T, u, v, w);
				parent[root_v] = root_u;
				sum_w += w;
		}
	}
	return sum_w;
}
int main(){
	Graph G, T;
	int n, m, e, u, v, w;
  	//freopen("deadline.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_graph(&G, n);
	for (e=1; e<=m; e++){
		scanf ("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	int sum_w = Kruskal(&G, &T);
	printf ("%d\n", sum_w);
	
	for (e=0; e<T.m; e++){
		if(T.A[e].u < T.A[e].v) 
			printf("%d %d %d\n", T.A[e].u, T.A[e].v, T.A[e].w);
		else
			printf("%d %d %d\n", T.A[e].v, T.A[e].u, T.A[e].w);

	}
	return 0;
}