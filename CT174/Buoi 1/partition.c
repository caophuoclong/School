int partition(int arr[], int i, int j, int pivot){

    int L,R;
    L = i;
    R = j;
    while(L <= R){
        while(arr[L] < pivot) L++;
        while(arr[R] >= pivot) R--;
        if(L < R)
            swap(&arr[L],&arr[R]);
    }

    return L;
}