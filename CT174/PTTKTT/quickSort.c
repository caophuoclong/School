#include <stdio.h>

void swap(int *x, int *y){
	int t;
	t = *x;
	*x = *y;
	*y = t;
}

int findPivot(int arr[], int i, int j){
	int k = i+1;
	int firstKey = arr[i];
	while((k<j) && (arr[k] == firstKey)) k++;
	if (k > j) return -1;
	if (arr[k] > firstKey) return k;
	return i;

}

int Partition(int arr[], int first, int last, int pivot){
	int L, R;
	L = first;
	R = last;
	while(L <= R){
		while(arr[L] < pivot) L++;
		while(arr[R] >= pivot) R--;
		if (L < R) swap(&arr[L],&arr[R]);
	}
	return L;
}
void quickSort(int arr[], int first, int last){
	int pvi, pv;
	pvi = findPivot(arr,first,last);
	if(pvi != -1){
		pv = arr[pvi];
		int k = Partition(arr,first,last,pv);
		quickSort(arr,first,k-1);
		quickSort(arr,k,last);
	}
}
int main(){
	freopen("dayso.inp","r",stdin);
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0; i < n; i++)
		scanf("%d",&arr[i]);
	quickSort(arr,0,n-1);
	for(int i = 0; i < n; i++)
		printf("%d ",arr[i]);
}
