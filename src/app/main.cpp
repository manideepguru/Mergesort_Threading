#include <iostream>
#include <chrono>
#include "sorting/mergeSort.hpp"
#include "sorting/parallelMergeSort.hpp"

int main(int argc, char *argv[]){
    const int SIZE=1000;
    std::vector<int> nums(SIZE);

    for(int i=0;i<SIZE;i++){
        nums[i]=rand()%1000;
    }

    MergeSort* mergesort= new MergeSort(&nums);
    auto start = std::chrono::high_resolution_clock::now();
    mergesort->sort();
    auto end=  std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergesortDuration=end-start;
    std::cout<<"MergeSort algorithm time taken: "<<mergesortDuration.count()<<" seconds"<<std::endl;
    delete mergesort;

    ParallelMergeSort* mergesort1= new ParallelMergeSort(&nums);
    start = std::chrono::high_resolution_clock::now();
    mergesort1->sort();
    end=  std::chrono::high_resolution_clock::now();
    mergesortDuration=end-start;
    std::cout<<"Parallel_MergeSort algorithm time taken: "<<mergesortDuration.count()<<" seconds"<<std::endl;
    delete mergesort1;
}