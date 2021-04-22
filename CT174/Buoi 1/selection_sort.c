void selection_sort(int arr[], int n){
	int i,j;
    for( i = 0; i <= n-2; i++){
        int low_index = i;
        int low_value = arr[i];
        for(j = i + 1; j <= n-1;j++){
            if(arr[j] < low_value){
                low_index = j;
                low_value = arr[j];
            }
        }
        swap(&arr[i],&arr[low_index]);

    }
}
