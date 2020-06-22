//
// Created by 王守正 on 2020-02-07.
//

#ifndef SORTS_SHELLSORT_H
#define SORTS_SHELLSORT_H
#include <iostream>

using namespace std;

// 比较SelectionSort, InsertionSort和BubbleSort和ShellSort四种排序算法的性能效率
// ShellSort是这四种排序算法中性能最优的排序算法
template <typename T>
void ShellSort(T arr[], int n){

    int h=1;
    while (h<n/3){
        h=3*h+1;
    }

    while (h>=1){
        for(int i=h;i<n;i++){
            T e=arr[i];
            int j;
            for(j=i;j>=h&&arr[j-h]>e;j-=h){

                arr[j]=arr[j-h];
            }
            arr[j]=e;

        }

        h/=3;

    }

}

#endif //SORTS_SHELLSORT_H
