<<<<<<< HEAD
int find_pivot(int arr[], int i, int j){
    int k = i+1;
    int first_key = arr[i];
    while(k<=j && arr[k] == first_key)
        k++;
    if(k > j) return -1;
    else
        if(arr[k] < first_key)
            return k;
        else
            return i;
}
=======
int find_pivot(int arr[], int i, int j){
    int k = i+1;
    int first_key = arr[i];
    while(k<=j && arr[k] == first_key)
        k++;
    if(k > j) return -1;
    else
        if(arr[k] > first_key)
            return k;
        else
            return i;
}
>>>>>>> 02efd1fe79bf716e22eab7f7d172ddc083e9f706
