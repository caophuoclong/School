#include <stdio.h>
#define MAX_vertices 20
#define MAX_N 100

typedef struct{
	int A[MAX_vertices][MAX_vertices];
	int n;
}Graph;

typedef struct{
	int u,v;
	int w;
}Edge;
typedef struct{
	Edge edges[100];
	int n,m;
}Graph1;

//khoi tao ma tran trong do thi
void init_graph(Graph *G, int n){
	int i, j;
	G->n = n;
	for (i = 1; i <= n; i++){		//dong
		for (j = 1; j <= n; j++)	//cot
			G->A[i][j] = 0;
	}
}
void init_graph1(Graph1 *G, int n){
	G->n = n;
	G->m = 0;
	
}
//them cung trong do thi
void add_edge(Graph *G, int x, int y, int w){
	G->A[x][y] = w;
	G->A[y][x] = w;
} 

void add_edge1(Graph1 *G, int u, int v, int w){
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w = w;
	G->m++;
}

//kiem tra lang gieng trong do thi
int adjacent(Graph *G, int x, int y){
	return (G->A[x][y] != 0);
}

//tinh bac cua dinh x trong do thi
int degree(Graph *G, int x){
	int i, deg = 0;
	for (i = 1; i<= G->n; i++){
		if(G->A[i][x] == 1)
			deg++;
	}
	return deg;
}

//khoi tao cau truc ds 
typedef struct{
	int data[MAX_vertices];
	int size;
}List;

//ham khoi tao ds rong
void make_null(List *list){
	list->size = 0;
}

//them mot phan tu (dinh) vao cuoi ds
void push_back(List *list, int x){
	list->data[list->size] = x; 
	list->size++;
}

//lay mot phan tu (dinh) trong ds tai vi tri i
int element_at(List *list, int i){
	return list->data[i-1];
}

//tim lang gieng cua dinh x
List neighbors(Graph *G, int x){
	List L;
	make_null(&L);
	int i;
	for (i = 1; i<=G->n; i++){
		if (G->A[i][x] == 1){
			push_back(&L, i);
		}
	}
	return L;
}

int pi[MAX_N];
int p[MAX_N];
int mark[MAX_N];
#define INFINITY 99999
int Prim2(Graph *G, Graph1 *T){
	init_graph1 (T, G->n);
	int i, u, v;
	for (u=1; u<=G->n; u++)
		pi[u] = INFINITY;
	pi[1]=0;
	for (v=1; v<=G->n; v++)
		if(G->A[1][v] != 0){
			pi[v]=G->A[1][v];	//gan pi[v] = trong so cung (1, v)
			p[v]=1;				//dinh trong s gan voi v la dinh 1
		}
	for (i=1; i<=G->n; i++)
		mark[i]=0;
	mark[1]=1;
	int sum_w=0;
	for (i=1; i<G->n; i++){
		//1. Tim u gan voi S nhat (tim u co pi[u] nho nhat)
		int min_dist = INFINITY, min_u;
		for (u=1; u<=G->n; u++)
			if (mark[u] == 0)
				if (min_dist > pi[u]){
					min_dist = pi[u];
					min_u = u;
				}
		u = min_u;	//dinh u co pi[u] nho nhat
		//2. Danh dau min_u
		mark[min_u] =1;
		//3. Dua cung (u, p[u], min_dist) vao T
		add_edge1(T, u, p[u], min_dist);
		sum_w += min_dist;
		//4. cap nhat lai pi va p cua cac dinh ke v cua u
		for (v=1; v<=G->n; v++)
			if(G->A[u][v] != 0 && mark[v]==0)
				if (pi[v] > G->A[u][v]){
					pi[v] = G->A[u][v];
					p[v]=u;
				}
	}
	return sum_w;
}

int main(){
	Graph G; Graph1 T;
	int n, m, e, u, v, w;
  	freopen("deadline.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_graph(&G, n);
	for (e=1; e<=m; e++){
		scanf ("%d%d%d", &u, &v, &w);
		add_edge(&G, u, v, w);
	}
	int sum_w = Prim2(&G, &T);
	printf ("Tong trong so cua cay T la: %d\n", sum_w);
	for (e=0; e<T.m; e++)
		printf("%d %d %d\n", T.edges[e].v, T.edges[e].u, T.edges[e].w);
	
	return 0;
}
