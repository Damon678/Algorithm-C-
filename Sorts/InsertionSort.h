//
// Created by 王守正 on 2020-02-07.
//

#ifndef SORTS_INSERTIONSORT_H
#define SORTS_INSERTIONSORT_H

#include <iostream>

using namespace std;

template <typename T>
void InsertionSort(T arr[],int n){

    for(int i=1;i<n;i++){

        //寻找元素arr[i]插入合适的位置
        T e=arr[i];
        int j;
        for( j=i;i>0&&arr[j-1]>e;j--){

            arr[j]=arr[j-1];
        }
        arr[j]=e;

    }
}

#endif //SORTS_INSERTIONSORT_H
