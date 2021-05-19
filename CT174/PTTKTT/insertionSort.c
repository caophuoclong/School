#include <stdio.h>
void swap(int *x, int *y){
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
void insertionSort(int arr[], int n){
	for(int i = 1; i < n;i++){
		int j = i;
		while((j>0) && (arr[j] < arr[j-1])){
			swap(&arr[j], &arr[j-1]);
			j--;
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
	insertionSort(arr,n);
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}

	return 0;}
