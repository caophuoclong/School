#include <stdio.h>
#include "swap.c"
#include "print_arr.c"
#include "intersection_sort.c"
#include "selection_sort.c"
#include "bubble_sort.c"
#include "quick_sort.c"

int main(){
    int record[100];
    freopen("dayso.inp", "r", stdin);
    int n,i;
    scanf("%d",&n);
    

    for(i = 0 ; i < n ; i++){
        scanf("%d",&record[i]);
    }
    printf("Day so truoc khi sap xep: \n");
    print(record,n);
	selection_sort(record,n);
    printf("Day so sau khi sap xep: \n");
	print(record,n);


    
    return 0;
}
