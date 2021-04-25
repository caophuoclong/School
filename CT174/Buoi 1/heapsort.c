#include <stdio.h>
#include "swap.c"
void Pushdown(int arr[], int first, int last){
	int r = first;
	while(r <= (last-1)/2){
		if(last == 2*r+1){
			swap(&arr[r],&arr[last]);
			r = last;
		}
		else{
			if((arr[r] > arr[2*r+1]) && (arr[2*r+1] <= arr[2*r+2])){
				swap(&arr[r],&arr[2*r+1]);
				r = 2*r+1;
			}
			else{
				if(arr[r] > arr[2*r+2] && (arr[2*r+1] > arr[2*r+2])){
					swap(&arr[r],&arr[2*r+2]);
					r = 2*r+2;
				}
				else{
					r = last;
				}
			}
		}
	}
}
void print(int arr[], int n){
	int i;
    for( i = 0 ; i < n ; i++){
        printf("%3d ", arr[i]);
    }
    printf("\n");
}
void print_heap(int arr[], int n){
	int i;
	for(i = n-1; i >=0;i--){
		printf("%d ",arr[i]);
	}
}
void heapsort(int arr[], int n){
	int i;
	for(i = (n-2)/2; i >= 0; i--){
		Pushdown(arr,i,n-1);
	}
	for(i = n-1;i >= 2;i--){
		swap(&arr[0],&arr[i]);
		Pushdown(arr,0,i-1);
	}
	swap(&arr[0],&arr[1]);
}

int main(){
	int n;
	freopen("dayso.inp","r",stdin);
	scanf("%d",&n);
	int arr[100];
	int i;
	for(i = 0; i < n;i++){
		scanf("%d",&arr[i]);
		
	}
	printf("Mang truoc khi sap xep: ");
	print(arr,n);
	printf("\n");
	heapsort(arr,n);
	printf("Mang sau khi sap xep: ");
	print_heap(arr,n);
	
	
	
	
	
	
	
	
	
	return 0;
}
