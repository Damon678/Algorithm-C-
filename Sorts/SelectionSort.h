//
// Created by 王守正 on 2020-02-07.
//

#ifndef SORTS_SELECTIONSORT_H
#define SORTS_SELECTIONSORT_H

#include <iostream>

using namespace std;

template <typename T>
void SelectionSort(T arr[],int n){
    for(int i=0;i<n;i++){

        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[minIndex]>arr[j])
                minIndex=j;
        }
        swap(arr[i],arr[minIndex]);

    }
}

//选择排序的优化
//在每一轮中，可以同时找到当前未处理元素的最大值和最小值
template <typename T>
void SelectionSortPro(T arr[],int n){

    int left=0,right=n-1;

    while (left<right){

        int minIndex=left;
        int maxIndex=right;

        //在每一轮查找时, 要保证arr[minIndex] <= arr[maxIndex]
        if(arr[minIndex]>arr[maxIndex]){
            swap(arr[maxIndex],arr[minIndex]);
        }

        for(int i=left+1;i<right;i++){
            if(arr[i]<arr[minIndex])
                minIndex=i;
            else if(arr[i]>arr[maxIndex])
                maxIndex=i;
        }

        swap(arr[left],arr[minIndex]);
        swap(arr[right],arr[maxIndex]);

        left++;
        right--;

    }
    return;

}
#endif //SORTS_SELECTIONSORT_H
