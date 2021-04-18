void bubble_sort(int arr[],int n){
    for(int i = 0 ;i <= n -2  ; i++){
        for (int j = n - 1 ; j >= i+1; j--){
            if(arr[j] < arr[j-1]){
                swap(&arr[j],&arr[j-1]);
            }
        }
    }

}