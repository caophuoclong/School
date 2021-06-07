#include <stdio.h>
#define MAX_Vertices 20
#define MAX_Length 20
#define MAX_Element 40
#define WHITE 0
#define GRAY 1
#define BLACK 2
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


void Binh(Graph *G, List *L1, List *L2, int x){
	int mark[100];
	make_null_list(L1);
	push_list(L1,x);
	for(int i = 0; i <= G->n;i++){
		mark[i] = 0;
	}
	mark[x] = 1;

	*L2 = neighbors(G,x);
	for(int i = 0; i < L2->size;i++){
		List L3 = neighbors(G,L2->data[i]);
		mark[L2->data[i]] = 1;
		for(int j = 0; j < L3.size;j++){
			int y = L3.data[j];
			if(mark[y] == 0){
				push_list(L1,L3.data[j]);
				mark[y] = 1;
			}
		}
	}

	for (int i = 1; i <= G->n;i++){
		if(mark[i] == 0)
			push_list(L2,i);
	}
	

	



}
int color[MAX_Vertices];
int cycle;
void dfs(Graph *G, int u, int parent){
	color[u]=GRAY;
	if (cycle==1)
		return;
	List L=neighbors(G, u);
	int i;
	for (i=1;i<=L.size;i++){
		int v= L.data[i-1];
		if (v==parent) continue;
		if (color[v]==GRAY){
			cycle=1;
			return;
		}
		if (color[v]==WHITE){
			dfs(G,v,u);
		}
	}
	color[u]=BLACK;
}
int contain_cycle(Graph *G){
	int i;
	for (i=1;i<=G->n;i++){
		color[i]=WHITE;
	}
	cycle=0;
	for (i=1;i<=G->n;i++){
		if (color[i]==WHITE)
			dfs(G,i,0);
	}
	return cycle;
}

int main(){
	int n, m;
	int u,v;
	Graph G;
	List L1, L2;
	freopen("deadline.txt","r",stdin);
	scanf("%d %d",&n,&m);
	init_graph(&G,n);

	for(int i = 0; i < m;i++){
		scanf("%d %d",&u,&v);
		add_edge(&G,u,v);
	}
	if(contain_cycle(&G) == 0){
			Binh(&G,&L1,&L2,1);
			printf("%d %d",L1.size,L2.size);
	}
	else{
		printf("-1 -1");
	}


}