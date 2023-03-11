#include <iostream>
template <typename T> long partition(T* arr,long start,long end)
{
 
   T pivot = arr[rand()%(end-start) + start];
 
   long count = 0;
    for (long i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
   long pivotIndex = start + count;
    std::swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
   long i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
template <typename T> void quicksort(T* arr,long start,long end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
   long p = partition(arr, start, end);
 
    // Sorting the left part
    quicksort(arr, start, p - 1);
 
    // Sorting the right part
    quicksort(arr, p + 1, end);
}
template <typename T> void quickSort(T* arr,long size){
    quicksort(arr,0,size-1);
}