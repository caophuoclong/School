void intersection_sort(int arr[], int n){
    int i;
	for( i =1 ; i<=n-1; i++){
        int j = i;
        while(j > 0 && (arr[j] < arr[j-1])){
            swap(&arr[j], &arr[j-1]);
            j -=1;

        }
    }
    
}
