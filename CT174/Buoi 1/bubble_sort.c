#include <stdio.h>
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void bubble_sort(int arr[],int n){
    int i,j;
    n = 12;
	for(i = 0 ;i <= n -2  ; i++){
        for (j = n - 1 ; j >= i+1; j--){
            if(arr[j] < arr[j-1]){
                swap(&arr[j],&arr[j-1]);
            }
        }
    }

}

void print(int arr[]){
    for(int i = 0 ;i < 12; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    int arr[100];
    freopen("dayso.inp", "r", stdin);
    scanf("%d",&n);
    for (int i = 0 ; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("%d\n", n);
    print(arr);
    bubble_sort(arr,n);
    print(arr);

    return 0;
    
}
