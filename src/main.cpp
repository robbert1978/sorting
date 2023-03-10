#include <iostream>
#include <chrono>
#include "include/sort_alog.h"
#define MAX_SIZE 1000000
char path_test_file[100];
double *arr_;
FILE *test_file;
template <typename T> void run_test_case(unsigned int num,T func){
       sprintf(path_test_file,"./test_case/%u_test.txt",num);
       test_file=fopen(path_test_file,"r");
       arr_=new double[MAX_SIZE];
       for(size_t i=0;i<MAX_SIZE;i++){
              fscanf(f,"%lf\n",arr_+i);
       }
       func(arr_,MAX_SIZE);
       free(arr_);
       fclose(test_file);
}
template <typename T> std::chrono::microseconds meansure_time(unsigned int num_test,T func){
              auto start = std::chrono::high_resolution_clock::now();
              run_test_case(num_test,func);
              auto stop =  std::chrono::high_resolution_clock::now();
              std::chrono::microseconds duration =std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
              return duration;
}
int main(){
       static std::chrono::microseconds heapSort_time;
       static std::chrono::microseconds quickSort_time;
       static std::chrono::microseconds mergeSort_time;
       static std::chrono::microseconds cxxSort_time;
       printf("|%10s\t|\t%10s\t|\t%10s\t|\t%10s\t|\t%10s\t|\n",
              "Test","Heap Sort","Quick Sort","Merge Sort","C++ Sort"
       );
       for(unsigned int num_test=1;num_test<=10;num_test++){
              heapSort_time =meansure_time(num_test,heapSort<double>);
              quickSort_time=meansure_time(num_test,quickSort<double>);
              quickSort_time=meansure_time(num_test,mergeSort<double>);
              cxxSort_time  =meansure_time(num_test,cxxSort<double>);
              printf("|%10u\t|\t%10lu\t|\t%10lu\t|\t%10lu\t|\t%10lu\t|\n",
                     num_test,heapSort_time,quickSort_time,quickSort_time,cxxSort_time
              );
       }
}