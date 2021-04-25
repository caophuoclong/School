void bubble_sort(int arr[],int n){
    int i,j;
	for(i = 0 ;i <= n -2  ; i++){
        for (j = n - 1 ; j >= i+1; j--){
            if(arr[j] < arr[j-1]){
                swap(&arr[j],&arr[j-1]);
            }
        }
    }

}
