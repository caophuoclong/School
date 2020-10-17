void nhap(List *L){
	int n,a;
	makenullList(L);
	scanf("%d",&n);
	for(int i = 0 ; i <n;i++){
		scanf("%d",&a);
		L->Elements[i] = a;
		L->Last += 1;
	}
}
void hienthi(List L){
	for(int i = 0 ;i < L.Last;i++){
		printf("%d ",L.Elements[i]);
	}
	printf("\n";)
}
void sort(List *L){
	for(int i = 0 ;i < L->Last;i++)
		for(int j = 0;j < ->Last;j++)
			if(L->Elements[i] > L->Elements[j]){
				int temp = L->Elements[i];
				L->Elements[i] = L->Elements[j];
				L->Elements[j] = temp;
			}
}
