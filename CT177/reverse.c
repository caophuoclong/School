#include <stdio.h>
void xoatrung(int *n, int arr[]){
    int count = 0;
    for(int i = 0; i < *n;i++){
        for(int j = i+1; j < *n;j++){
            if(arr[i] == arr[j]){
                for (int z = j; z < *n;z++)
                    arr[z] = arr[z+1];
                    count += 1;
            }
                
        }
    }
    *n -= count;
}
void showReverse(int n, int arr[]){
    for(int i = n -1;i>=0;i--)
        printf("%d ",arr[i]);
    printf("\n");

}
void intersectionArr(int x, int y ,int *z,int arr[], int arr1[], int arr3[]){
    int as = 0;
    int arr2[100];
    for(int i = 0 ; i < x; i++)
        for(int j = 0 ; j < y;j++){
            if(arr[i] == arr1[j]){
                arr2[as] = arr[i];
                as++;
            }
                

        }
    *z = as;
    arr3 = arr2;
}

int main(){

    int n,x;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0 ; i < n;i++){
        scanf("%d",&arr[i]);
    }
    xoatrung(&n,arr);
    showReverse(n,arr);
    scanf("%d",&x);
    int arr_1[x];
    for(int i = 0 ; i < x;i++){
        scanf("%d",&arr_1[i]);
    }
    xoatrung(&n,arr_1);
    showReverse(n,arr_1);
    int z, arr_2[100];
   intersectionArr(n,x,&z,arr,arr_1,arr_2);
    showReverse(z,arr_2);


}