#include "find_pivot.c"
#include "partition.c"

void quick_sort(int  arr[], int i, int j){
    int pvi, k;
    int pv;
    pvi = find_pivot(arr,i,j);
    if(pvi != -1){
        pv = arr[pvi];
        k = partition(arr,i,j,pv);
        quick_sort(arr,i,k-1);
        quick_sort(arr,k,j);
    }
}
