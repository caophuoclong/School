#include "queue.c"
typedef struct{
	int n, m;
	int A[100][100];
}Graph;

int mark[100];

void init_graph(Graph *G, int n, int m){
    G->n = n;
    G->m = m;
    int i,j;
    for( i = 1 ; i < n ; i++){
        for ( j = 1 ;j < m; j++){
            G->A[i][j] = 0;
        }
    }
}void add_edges(Graph *G,int e,int x, int y){
    G->A[x][e] = 1;
    G->A[y][e] = 1;
}
List neighbors(Graph* G, int x) {
    List L;
    make_null(&L);
    int e, y;
    for (y = 1; y <= G->n; y++) {
    	if (x == y) continue;
        for (e = 1; e <= G->m; e++)
            if (G->A[x][e] > 0 && G->A[y][e] > 0) {
                push_back(&L, y);
                break;
            }
    }
    return L;
}
int mark[100];
int parent[100];
void breath_search(Graph *G,int xxs){
	Queue frontier;
	int i;
	make_null_queue(&frontier);
	push(&frontier, xxs);
	mark[xxs] = 1;
    if(parent[xxs] == 0)
        parent[xxs] = 0;
	while(!is_empty(&frontier)){
		int x = top(&frontier); 
		pop(&frontier);
		List list = neighbors(G, x);
		for ( i = 1 ; i <= list.size; i++){
			int y = element_at(&list, i);
			if(mark[y] == 0){
				mark[y] = 1;
                printf("asd");
                parent[y] = x;
				push(&frontier,y);
			}
		}
	}
}
//	int e;
//	for(e = 1; e <= G->n;e++){
//		if(mark[e] == 0){
//			push(&frontier, e);
//			mark[e] = 1;
//		while(!is_empty(&frontier)){
//		int x = top(&frontier); 
//		pop(&frontier);
//		printf("%d\n",x);
//		List list = neighbors(G, x);
//		for ( i = 1 ; i <= list.size; i++){
//			int y = element_at(&list, i);
//			if(mark[y] == 0){
//				mark[y] = 1;
//				push(&frontier,y);
//			}
//		}
//	}
//		}
//		mark[e] =1;
//		
//	}
//}




