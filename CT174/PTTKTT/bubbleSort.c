#include <stdio.h>

void swap(int *x, int *y){
	int t;
	t = *x;
	*x = *y;
	*y = t;
}

void bubbleSort(int arr[], int n){
	for(int i = 0; i < n-2;i++){
		for(int j = n-1; j>= i+1;j--){
			if(arr[j] < arr[j-1])
				swap(&arr[j],&arr[j-1]);
		}
	}
}

int main(){
	int n;
	freopen("dayso.inp","r",stdin);
	scanf("%d",&n);
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	bubbleSort(arr,n);
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}
