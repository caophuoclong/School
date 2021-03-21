#include <stdio.h>
#define MAX_ELEMENTS 100
typedef int ElementType;
typedef struct {
ElementType data[MAX_ELEMENTS];
int size;
} List;
/* Tao danh sach rong */
void make_null(List* L) {
L->size = 0;
}
/* Them mot phan tu vao cuoi danh sach */
void push_back(List* L, ElementType x) {
L->data[L->size] = x;
L->size++;
}
/* Lay phan tu tai vi tri i, phan tu bat dau o vi tri 1 */
int element_at(List* L, int i) {
return L->data[i-1];
}
/* Tra ve so phan tu cua danh sach */
int count_list(List* L) {
return L->size;
}
void print_list(List L){
	int i;
	for (i = 0;i < L.size;i++)
		printf("%d ",L.data[i]);
		
}
typedef struct{
	int data[100];
	int front, rear;
} Queue;
void make_null_queue(Queue * Q){
	Q->front = 0;
	Q->rear = -1;
}
void push(Queue *Q, int Element){
	Q->rear++;
	Q->data[Q->rear] = Element;
}

int top(Queue *Q){
	return Q->data[Q->front];
}

void pop(Queue *Q){
	Q->front++;
}

int is_empty(Queue *Q){
	return Q->front > Q->rear;
}

typedef struct{
	int n, m;
	int A[100][100];
}Graph;



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
int parent[100];
void print(Graph *G){
	int i,  j;
     for ( i = 1 ; i <= G->n; i++){
        for( j = 1 ; j <= G->n; j++){
            printf("%d ",G->A[i][j]);
        }
        printf("\n");
    }
}
void breath_first_search(Graph *G){
	Queue frontier;
	int mark[100];
	int i;
	make_null_queue(&frontier);
	for ( i = 1; i <= G->n;i ++){
		mark[i] = 0;
	}
	push(&frontier, 1);
	mark[1] = 1;
    parent[1] = 0;
	while(!is_empty(&frontier)){
		int x = top(&frontier); 
		pop(&frontier);
		List list = neighbors(G, x);
		for ( i = 1 ; i <= list.size; i++){
			int y = element_at(&list, i);
			if(mark[y] == 0){
				mark[y] = 1;
                parent[y] = x;
				push(&frontier,y);
			}
		}
	}
	int e;
	for(e = 1; e <= G->n;e++){
		if(mark[e] == 0){
			push(&frontier, e);
			mark[e] = 1;
            parent[e] = 0;
		while(!is_empty(&frontier)){
		int x = top(&frontier); 
		pop(&frontier);
		List list = neighbors(G, x);
		for ( i = 1 ; i <= list.size; i++){
			int y = element_at(&list, i);
			if(mark[y] == 0){
				mark[y] = 1;
                parent[y] = x;
				push(&frontier,y);
			}
		}
	}
		}
		mark[e] =1;
		
	}
}
	

int main(){
	freopen("dt1.txt", "r", stdin);
	Graph G;
	int n, m;
	int x,y;
	int i;
	scanf("%d%d",&n,&m);
	init_graph(&G,n,m);
	for(i = 1; i <= m;i++){
		scanf("%d %d",&x,&y);
		add_edges(&G,i,x,y);
	}
	
	breath_first_search(&G);
	
    for(int i = 1; i<=n; i++){
        printf("%d %d",i,parent[i]);
    }
	return 0;
}