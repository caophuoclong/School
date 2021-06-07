#include <stdio.h>
typedef int ElementType;
typedef struct
{
   ElementType data[100];
   int         front, rear;
} Queue;

void make_null_queue(Queue *Q)
{
   Q->front = 0;
   Q->rear  = -1;
}


void push_queue(Queue *Q, ElementType element)
{
   Q->rear++;
   Q->data[Q->rear] = element;
}


ElementType top_queue(Queue *Q)
{
   return Q->data[Q->front];
}


void pop_queue(Queue *Q)
{
   Q->front++;
}


int empty_queue(Queue *Q)
{
   return Q->front > Q->rear;
}


typedef struct
{
   int dir;      // >0: +; <0 -; = 0 chua co nhan;
   int pre;      // dinh truoc
   int sigma;    // luong tang luong;
} Label;
Label labels[100];
typedef struct
{
   ElementType C[100][100];
   ElementType F[100][100];
   int n;
} Graph;

void init_graph(Graph *G, int n)
{
   int i, j;

   G->n = n;
   for (i = 1; i <= n; i++)
   {
      for (j = 1; j <= n; j++)
      {
         G->C[i][j] = 0;
      }
   }
}


void add_edge(Graph *G, ElementType u, ElementType v, int w)
{
   G->C[u][v] = w;
}


void init_flow(Graph *G)
{
   int i, j;

   for (i = 1; i <= G->n; i++)
   {
      for (j = 1; j <= G->n; j++)
      {
         G->F[i][j] = 0;
      }
   }
}


int deg(Graph *G, ElementType x)
{
   int deg = 0;
   int i;

   for (i = 0; i <= G->n; i++)
   {
      deg += G->C[x][i];
   }
   return deg;
}


int adjacent(Graph *G, ElementType x, ElementType y)
{
   return(G->C[x][y] != 0);
}

int min(int x, int y){
	if (x > y) return y;
	return x;
}

int FordFullkerson(Graph *G, int s, int t)
{
   init_flow(G);
   Queue Q;
   
   int   sum_flow = 0;
   do
   {
      int u;
      for (u = 1; u <= G->n; u++)
      {
         labels[u].dir = 0;
      }
      labels[s].dir   = 1;
      labels[s].pre   = s;
      labels[s].sigma = 100000;
      make_null_queue(&Q);
      push_queue(&Q, s);
         int   found = 0;

      while (!empty_queue(&Q))
      {
         int u = top_queue(&Q);
         pop_queue(&Q);
         int v;
         for (v = 1; v <= G->n; v++)
         {
            if ((labels[v].dir == 0) && G->C[u][v] != 0 && (G->F[u][v] < G->C[u][v]))
            {
               labels[v].dir   = 1;
               labels[v].pre   = u;
               labels[v].sigma = min(labels[u].sigma,G->C[u][v] - G->F[u][v]);
               push_queue(&Q,v);
            }
            if ((labels[v].dir == 0) && G->C[v][u] != 0 && (G->F[v][u] > 0))
            {
               labels[v].dir   = -1;
               labels[v].pre   = u;
               labels[v].sigma = min(labels[u].sigma, G->F[v][u]);
               push_queue(&Q,v);
            }
         }


         if (labels[t].dir != 0)
         {
            found = 1;
            break;
         }
      }
      if (found)
      {
         int x     = t;
         int sigma = labels[t].sigma;
         sum_flow += sigma;
         while (x != s)
         {
            int u = labels[x].pre;
            if (labels[x].dir > 0)
            {
               G->F[u][x] += sigma;
            }
            else
            {
               G->F[x][u] -= sigma;
            }
            x = u;
         }
      }
      else
      {
         break;
      }
   }
   /* code */
   while (1);

   return sum_flow;
}


int main()
{
   int   n, m, u, v, w;
   int   i, j;
   Graph G;

   freopen("data_luong.txt", "r", stdin);
   scanf("%d%d", &n, &m);
   init_graph(&G, n);
   for (i = 0; i < m; i++)
   {
      scanf("%d%d%d", &u, &v, &w);
      add_edge(&G, u, v, w);
   }
   int max_flow = FordFullkerson(&G,1,n);
   printf("Max Flow = %d\n",max_flow);
   printf("X0: ");
   for(i = 1; i <= G.n;i++){
   	if(labels[i].dir != 0)
   		printf("%d ",i);
   }
   printf("\nY0: ");
   for(i = 1; i <= G.n;i++){
   	if(labels[i].dir == 0)
   		printf("%d ",i);
   }


   return 0;
}
