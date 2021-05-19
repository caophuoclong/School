#include <stdio.h>

void swap(int *x, int *y){
	int t;
	t = *x;
	*x = *y;
	*y = t;
}
void Pushdown(int arr[], int first, int last){
	int r = first;
	while(r <= (last-1)/2){
		if(last == (2*r+1)){
			if(arr[last] < arr[2*r+1])
				swap(&arr[last],&arr[2*r+1]);
			else
				r = last;
		}
		else if ((arr[r] > arr[2*r+1]) && (arr[2*r+1] < arr[2*r+2])){
			swap(&arr[r],&arr[2*r+1]);
			r = 2*r+1;
		}
		else if ((arr[r] > arr[2*r+2]) && (arr[2*r+2] < arr[2*r+1])){
			swap(&arr[r],&arr[2*r+2]);
			r = 2*r+2;
		}
		else
			r = last;
	}
}

void heapSort(int arr[], int n){
	for(int i = (n-2)/2; i >= 0; i--){
		Pushdown(arr,i,n);
	}
	for(int i = n -1; i >= 2; i--){
		swap(&arr[i],&arr[0]);
		Pushdown(arr,0,i-1);
	}
	swap(&arr[1],&arr[0]);
}
int main(){
	freopen("dayso.inp","r",stdin);
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&arr[i]);

	}
	heapSort(arr,n);
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}
