#include <stdio.h>
#include "swap.c"
#include "print_arr.c"
#include "intersection_sort.c"
#include "selection_sort.c"
#include "buble_sort.c"
int main(){
    int arr[100];
    freopen("dayso.inp", "r", stdin);
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    print(arr,n);
    bubble_sort(arr,n);
    print(arr,n);
    
    return 0;
}