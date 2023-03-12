#include <iostream>
#include <chrono>
#include "include/sort_alog.h"
#define MAX_SIZE 1000000
char path_test_file[100];
double *arr_;
FILE *test_file;
template <typename T> std::chrono::microseconds 
meansure_time(unsigned int num_test,T func){
_init_arr:
       sprintf(path_test_file,"./test_case/%u_test.txt",num_test);
       test_file=fopen(path_test_file,"r");
       if (test_file==NULL)
              return (std::chrono::microseconds)-1;
       arr_=new double[MAX_SIZE];
       for(size_t i=0;i<MAX_SIZE;i++){
              fscanf(test_file,"%lf\n",arr_+i);
       }
count_time:
       auto start = std::chrono::high_resolution_clock::now();
       func(arr_,MAX_SIZE);
       auto stop =  std::chrono::high_resolution_clock::now();
       std::chrono::microseconds duration =std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
clean:
       free(arr_);
       fclose(test_file);
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
              mergeSort_time=meansure_time(num_test,mergeSort<double>);
              cxxSort_time  =meansure_time(num_test,cxxSort<double>);
              printf("|%10u\t|\t%10ld\t|\t%10ld\t|\t%10ld\t|\t%10ld\t|\n",
                     num_test,heapSort_time,quickSort_time,mergeSort_time,cxxSort_time
              );
       }
}