template <typename T> void merge(T *arr, long l, long m, long r) 
{ 
    long n1 = m - l + 1; 
    long n2 = r - m; 
  
    // Create temp arrays  
    T *L=new T[n1], *R=new T[n2]; 
  
    // Copy data to temp arrays L[] and R[]  
    for(long i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for(long j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    // Merge the temp arrays back longo arr[l..r] 
      
    // Initial index of first subarray 
    long i = 0;  
      
    // Initial index of second subarray 
    long j = 0;  
      
    // Initial index of merged subarray 
    long k = l; 
      
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j])  
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else 
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements of 
    // L[], if there are any  
    while (i < n1)  
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of 
    // R[], if there are any  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
// l is for left index and r is  
// right index of the sub-array 
// of arr to be sorted */ 
template <typename T>  void mergesort(T* arr, long l, long r) 
{ 
    if (l < r) 
    { 
          
        // Same as (l+r)/2, but avoids  
        // overflow for large l and h 
        long m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergesort(arr, l, m); 
        mergesort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
}
template <typename T>  void mergeSort(T* arr,long size){
    mergesort(arr, 0,size - 1);
}