#include "stack.c"

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
void print(Graph *G){
	int i,  j;
     for ( i = 1 ; i <= G->n; i++){
        for( j = 1 ; j <= G->n; j++){
            printf("%d ",G->A[i][j]);
        }
        printf("\n");
    }
}
//void breath_first_search(Graph *G){
//	Queue frontier;
//	int mark[100];
//	int i;
//	make_null_queue(&frontier);
//	for ( i = 1; i <= G->n;i ++){
//		mark[i] = 0;
//	}
//	push(&frontier, 1);
//	mark[1] = 1;
//	while(!is_empty(&frontier)){
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



void depth_search(Graph *G, int x){
	Stack frontier;
	make_null_stack(&frontier);
	push(&frontier,x);
	mark[x] = 1;
	while(!empty(&frontier)){
		int x = top(&frontier); pop(&frontier);
		printf("%d\n",x);
	}
	
	
}


