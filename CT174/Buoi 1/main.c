<<<<<<< HEAD
#include <stdio.h>
#include "swap.c"
#include "print_arr.c"
#include "intersection_sort.c"
#include "selection_sort.c"
#include "bubble_sort.c"
#include "quick_sort.c"
#include <time.h>
int main(){
    clock_t start, end;
    clock_t start1, end1;
    int arr[100];
    freopen("dayso.inp", "r", stdin);
    int n;
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i++){
        scanf("%d",&arr[i]);
    }
    print(arr,n);
    start = clock();
    quick_sort(arr,0,n-1);
    end = clock();
    start1 = clock();
    //intersection_sort(arr,n);
    end1 = clock();
    print(arr,n);
    //printf("%lf\n", (double) start - end);
    //printf("%lf", (double) start1 - end1);

    
    return 0;
}
=======
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
>>>>>>> 02efd1fe79bf716e22eab7f7d172ddc083e9f706
