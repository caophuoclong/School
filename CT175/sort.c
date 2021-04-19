void sort_i(int arr[], int n, int arr1[]){
    int min = 999;
    int key;
    
    for(int i = 2; i <= n ;i++){
        if(arr[i] < min){
            min = arr[i];
            key = i;
        }
        if(i == n){
            arr1[j] = key;
            arr[key] = 999;
            j++;
        }
        
    }
    for(int i = 2; i <= n; i++){
        if(arr[i] != 999){
            sort_i(arr,n,arr1);
        }
    }
}