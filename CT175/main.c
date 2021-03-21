#include "graph.c"
int main(){
	Graph G;
	int n, m;
	int x, y;
	freopen("dt1.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i = 1; i<=m;i++){
		scanf("%d %d",&x,&y);
		add_edges(&G,i,x,y);
	}
	for(int i = 1; i <= n; i++)
		parent[i] = 0;
	for(int i = 1; i<=n;i++){
		if(mark[i] == 0)
			breath_search(&G,i);
	}
	
	for(int i = 1; i<=n; i++){
		printf("%d %d\n",i,parent[i]);
	}
}
