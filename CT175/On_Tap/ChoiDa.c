#include <stdio.h>
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct{
	int data[100];
	int size;
}List;

void make_null(List *L){
	L->size = 0;
}

void push_back_list(List *L, int x){
	L->data[L->size] = x;
	L->size++;
}

int element_at(List *L, int i){
	return L->data[i-1];
}

void copy_list(List *L1, List *L2){
	make_null(L1);
	int i, y;
	for (i=1; i<=L2->size; i++){
		y = element_at(L2, i);
		push_back_list(L1, y);
	}
}

typedef struct{
	int n, m;
	int A[100][100];
}Graph;

int mark[100];

void init_graph(Graph *G, int n){
    G->n = n;
    int i,j;
    for( i = 1 ; i <= n ; i++){
        for ( j = 1 ;j <= n; j++){
            G->A[i][j] = 0;
        }
    }
}void add_edges(Graph *G, int x, int y){
   G->A[x][y] = 1;
}
int j = 1;
void sort_i(int arr[], int n, int arr1[]){
    int min = 999;
    int key;
    
    for(int i = 2; i <= n ;i++){
        if(arr[i] < min){
            min = arr[i];
            key = i;
        }
        if(i == n){
            arr1[j] = key;
            arr[key] = 999;
            j++;
        }
        
    }
    for(int i = 2; i <= n; i++){
        if(arr[i] != 999){
            sort_i(arr,n,arr1);
        }
    }
}
void ranking(Graph *G){
	int d[100], rank[100];
	List S1, S2;
	int u;
	for(u = 1; u <= G->n; u++){
		d[u] = 0;
	}
	int x;
	for(x = 1; x <= G->n; x++){
		for(u = 1; u <= G->n; u++){
			if(G->A[x][u] != 0){
				d[u]++;
			}
		}
	}
	make_null(&S1);
	for(u = 1; u <= G->n; u++){
		if(d[u] == 0){
			push_back_list(&S1,u);
		}
	}
	int k =0;
	while(S1.size > 0){
		make_null(&S2);
		int i;
		for(i = 1; i <= S1.size; i++){
			int u = element_at(&S1,i);
			rank[u] = k;
			int v;
			for(v = 1; v <= G->n;v++){
				if(G->A[u][v] != 0){
					d[v]--;
					if(d[v] == 0)
						push_back_list(&S2,v);
				}
			}
		}
		copy_list(&S1,&S2);
		k++;
	}
	int arr[100];

	for(int i =0; i <= G->n;i++){
		arr[i] = 0;
	}
	arr[0] = 1;
	sort_i(rank, G->n,arr);
	for(int i =0;i<G->n;i++){
		printf("%d ",arr[i]);
	}
	
}




int main(){
	Graph G;
	int n, m, u, v, i;
 	freopen("dt1.txt", "r", stdin);
	scanf ("%d%d", &n, &m);
	init_graph(&G, n);
	for (i=1; i<=m; i++){
		scanf ("%d%d", &u, &v);
		add_edges(&G, u, v);
	}
	ranking(&G);
//	for (i=1; i<=n; i++)
//		printf ("%d ", rank[i]);
	return 0;
}
