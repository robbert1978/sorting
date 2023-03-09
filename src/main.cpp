#include <iostream>
#include <fstream>
#include <chrono>
#include "include/sort_alog.h"
#define MAX_SIZE 1000000
char path_test_file[100];
double *arr_;
template <typename T> void run_test_case(unsigned int num,T func){
       sprintf(path_test_file,"./test_case/%u_test.txt",num);
       FILE *f=fopen(path_test_file,"r");
       arr_=new double[MAX_SIZE];
       for(size_t i=0;i<MAX_SIZE;i++){
              fscanf(f,"%lf\n",arr_+i);
       }
       func(arr_,MAX_SIZE);
}
template <typename T> void test_alog(T func){
       for(unsigned int i=1;i<=10;i++){
              auto start = std::chrono::high_resolution_clock::now();
              run_test_case(i,func);
              auto stop =  std::chrono::high_resolution_clock::now();
              auto duration =std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
              printf("Test[%2u] Execute: %ld\n",i,duration.count());
       }
}
int main(){
       puts("Heap sort: ");
       test_alog(heapSort<double>);
}