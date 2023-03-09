#include <iostream>
template<typename T> void heapify(T* arr, long N, long i)
{
 
    // Initialize largest as root
    long largest = i;
 
    // left = 2*i + 1
    long l = 2 * i + 1;
 
    // right = 2*i + 2
    long r = 2 * i + 2;
 
    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify<T>(arr, N, largest);
    }
}
 
// Main function to do heap sort
template<typename T> void heapSort(T* arr, long N)
{
 
    // Build heap (rearrange array)
    for (long i = N / 2 - 1; i >= 0; i--)
        heapify<T>(arr, N, i);
 
    // One by one extract an element
    // from heap
    for (long i = N - 1; i > 0; i--) {
 
        // Move current root to end
        std::swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify<T>(arr, i, 0);
    }
}