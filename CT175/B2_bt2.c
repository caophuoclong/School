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
int mark[100];
void traversal(Graph *G, int x){
    if (mark[x] == 1)
        return;
    printf("%d\n",x);
    mark[x] =1;
    List list = neighbors(G, x);
    int j;
    for(j = 1; j <= list.size;j++){
        int y = element_at(&list,j);
        traversal(G,y);
    }
}
void depth_first_search(Graph *G){
    int j;
    for(j = 1; j <= G-> n;j++)
        mark[j] = 0;
    for(int i = 1; i <= G->n;i++){
        if(mark[i] == 0)
            traversal(G,i);
        mark[i] =1;
            
        
    }
    
}
	
	

int main(){
	//freopen("dt1.txt", "r", stdin);
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
	
    depth_first_search(&G);



	return 0;
}