#include <iostream>
template <typename T> long partition (T* arr, long low, long high)
{
    long pivot = arr[rand() % (high-low)+low];    // pivot
    long left = low;
    long right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        std::swap(arr[left], arr[right]);
        left++;
        right--;
    }
    std::swap(arr[left], arr[high]);
    return left;
}
template <typename T> void quicksort(T* arr, long low, long high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        long pi = partition<T>(arr, low, high);
 
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quicksort<T>(arr, low, pi - 1);
        quicksort<T>(arr, pi + 1, high);
    }
}
template <typename T> void quickSort(T* arr,long size){
    quicksort<T>(arr,0,size-1);
}