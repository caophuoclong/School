#include "init.c"


int main()
{
   int   n;
   int   m;
   Graph G;

   freopen("data.txt", "r", stdin);
   scanf("%d%d", &n, &m);
   init_graph(&G, n);
   for (int i = 0; i <= m; i++)
   {
      int u, v;
      scanf("%d %d", &u, &v);
      add_edge(&G, u, v);
   }
   for (int i = 1; i <= n; i++)
   {
      Mark[i] = 0;
   }
   for (int i = 1; i <= n; i++)
   {
      Mark[i] = 0;
   }
   for (int i = 1; i <= n; i++)
   {
      List list = BFS(&G, i);
      for (int j = 0; j < list.size; j++)
      {
         printf("%d ", list.data[j]);
      }
   }


   for (int i = 1; i <= n; i++)
   		parent[i] = 0;
   for (int i = 1; i <= n; i++)
   {
      List list = DFS(&G, i);
      for (int j = 0; j < list.size; j++)
      {
         printf("%d - %d\n", list.data[j], parent[list.data[j]]);
      }
   }
   return 0;
}
