//
// Created by 王守正 on 2020-02-07.
//

#ifndef SORTS_BUBBLESORT_H
#define SORTS_BUBBLESORT_H

#include <iostream>

using namespace std;

//版本1：
template <typename T>
void BubbleSort(T arr[],int n){

        bool swapped;

    do{
         swapped= false;

        for(int i=1;i<n;i++){
            if(arr[i-1]>arr[i]){
                swap(arr[i-1],arr[i]);
                swapped= true;
            }
        }
        // 优化, 每一趟Bubble Sort都将最大的元素放在了最后的位置
        // 所以下一次排序, 最后的元素可以不再考虑
        n--;

    }while (swapped);
}

//版本2：升级一下下
template <typename T>
void BubbleSortPro(T arr[],int n){

    int newn;
    do{
        newn=0;
        for (int i=1;i<n;i++){
            if(arr[i-1]>arr[i]){
                swap(arr[i-1],arr[i]);
                newn=i;
            }
        }
        n=newn;


    }while (newn>0);
}

template <typename T>
void BubbleSort2(T arr[],int n){

    //躺数
    for(int i=0;i<n;i++){

        for(int j=1;j<n-i;j++){

            if(arr[j-1]>arr[j]){
                swap(arr[j-1],arr[j]);
            }
        }
    }
};



#endif //SORTS_BUBBLESORT_H
