#include <stdio.h>
#include "swap.c"
typedef struct {
	int key;
	float otherfield;
}recordtype;
void print(recordtype arr[], int n){
	int i;
    for( i = 0 ; i < n ; i++){
        printf("%3d ", arr[i].key);
    }
    printf("\n");
}

int find_pivot(recordtype arr[], int i, int j){
    int k = i+1;
    int first_key = arr[i].key;
    while(k<=j && arr[k].key == first_key)
        k++;
    if(k > j) return -1;
    else
        if(arr[k].key < first_key)
            return k;
        else
            return i;
}

int partition(recordtype arr[], int i, int j, int pivot){

    int L,R;
    L = i;
    R = j;
    while(L <= R){
        while(arr[L].key <= pivot) L++;
        while(arr[R].key > pivot) R--;
        if(L < R)
            swap(&arr[L].key,&arr[R].key);
    }

    return L;
}

void quick_sort(recordtype arr[], int i, int j){
    int pvi, k;
    int pv;
    pvi = find_pivot(arr,i,j);
    if(pvi != -1){
        pv = arr[pvi].key;
        k = partition(arr,i,j,pv);
        quick_sort(arr,i,k-1);
        quick_sort(arr,k,j);
    }
}















int main(){
    recordtype record[100];
    freopen("dayso.inp", "r", stdin);
    int n,i;
    scanf("%d",&n);
    

    for(i = 0 ; i < n ; i++){
        scanf("%d",&record[i].key);
    }
    printf("Day so truoc khi sap xep: \n");
    print(record,n);
	quick_sort(record,0,n-1);
    printf("Day so sau khi sap xep: \n");
	print(record,n);


    
    return 0;
}
