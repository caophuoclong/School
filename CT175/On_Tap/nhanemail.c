#include <stdio.h>

typedef int ElementType;


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

void add_edge(Graph *G, ElementType u, ElementType v,int w){
	G->data[u][v] = w;
}

int deg(Graph *G, ElementType x){
	int deg = 0;
	for(int i = 0; i <= G->n;i++)
		deg += G->data[i][x];
	return deg;
}



int main(){
	Graph G;
	int n, a;
	freopen("email.txt","r",stdin);
	scanf("%d",&n);
	init_graph(&G,n);
	for(int i = 1; i <= n;i++){
		for(int j = 1; j <= n; j++){
			scanf("%d",&a);
			G.data[i][j] = a;
		}
	}
	int arr[100];
	for(int i = 1; i <= G.n;i++){
		arr[i] = deg(&G,i);
	}
	int max = 0;
	int e ;
	for (int i = 1; i <= G.n;i++){
		if(arr[i] > max){

			max = arr[i];
			e = i;
		}
	}
	printf("%d has received %d email(s).",e,max);
	return 0;
}