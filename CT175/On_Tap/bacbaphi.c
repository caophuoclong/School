#include <stdio.h>
#define MAX_vertices 20
#define MAX_N 100


typedef struct{
	int u,v;
	int w;
	int t;
}Edge;
typedef struct{
	Edge edges[100];
	int n,m;
}Graph;

//khoi tao ma tran trong do thi

void init_graph(Graph *G, int n){
	G->n = n;
	G->m = 0;
	
}
//them cung trong do thi


void add_edge(Graph *G, int u, int v, int w, int t){
	G->edges[G->m].u = u;
	G->edges[G->m].v = v;
	G->edges[G->m].w = w;
	G->edges[G->m].t = t;
	G->m++;
}

//kiem tra lang gieng trong do thi
int adjacent(Graph *G, int x, int y){
	int i;
	for(i = 1; i<=G->m;i++){
		if((G->edges[i-1].u == x && G->edges[i-1].v == y) || (G->edges[i-1].u == y && G->edges[i-1].v == x)){
			return i;
		}
	}
	return -1;
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
		if (adjacent(G,x,i)){
			push_back(&L, i);
		}
	}
	return L;
}

int pi[MAX_N];
int p[MAX_N];
int t[MAX_N];
int mark[MAX_N];
#define INFINITY 99999
int Prim2(Graph *G, Graph *T){
	init_graph (T, G->n);
	int i, u, v;
	for (u=1; u<=G->n; u++)
		pi[u] = INFINITY;
	pi[1]=0;
	for (v=1; v<=G->n; v++){
		int m = adjacent(G,1,v);
		if(m != -1){
			pi[v]=G->edges[m].w;	//gan pi[v] = trong so cung (1, v)
			p[v]=1;				//dinh trong s gan voi v la dinh 1
			t[v] = G->edges[m].w * G->edges[m].t;
		}
	}
		
	for (i=1; i<=G->n; i++)
		mark[i]=0;
	mark[1]=1;
	int sum_w=0;
	int min_money = 0;
	for (i=1; i<G->n; i++){
		//1. Tim u gan voi S nhat (tim u co pi[u] nho nhat)
		int min_dist = INFINITY, min_u;
		for (u=1; u<=G->n; u++)
			if (mark[u] == 0)
				if (min_dist > pi[u]){
					min_dist = pi[u];
					min_money = t[u];
					min_u = u;
				}
		u = min_u;	//dinh u co pi[u] nho nhat
		//2. Danh dau min_u
		mark[min_u] =1;
		//3. Dua cung (u, p[u], min_dist) vao T
		
		sum_w += min_money;
		//4. cap nhat lai pi va p cua cac dinh ke v cua u
		for (v=1; v<=G->n; v++)
		{
			int m = adjacent(G,u,v);
			if(m != -1 && mark[v]==0)
				if (pi[v] > G->edges[m].w){
					pi[v] = G->edges[m].w;
					p[v]=u;
				}
			}
	}
	return sum_w;
}

int main(){
	Graph G, T;
	int n, m, e, u, v, w, t;
  	freopen("deadline.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_graph(&G, n);
	for (e=1; e<=m; e++){
		scanf ("%d%d%d%d", &u, &v, &w, &t);
		add_edge(&G, u, v, w,t);
	}
	int sum_w = Prim2(&G, &T);
	printf("%d ",sum_w);
	for (e=0; e<T.m; e++)
		printf("%d %d %d\n", T.edges[e].v, T.edges[e].u, T.edges[e].w);
	
	return 0;
}
