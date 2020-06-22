#include <iostream>
#include "SortTestHelper.h"
#include "InsertSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

template <typename T>
void __quickSort3Ways(T arr[],int l,int r){

    if(r-l<=15){
        insertionSort(arr,l,r);
        return;
    }

    //partition
    swap(arr[l],arr[rand()%(r-l+1)+l]);
    T v=arr[l];

    int lt=l; //arr[l+1,lt]<v
    int i=l+1;//arr[lt+1,i)==v
    int gt=r+1;//arr[gt,r]>v

    while (i<gt){

        if(arr[i]<v){
            swap(arr[i],arr[lt+1]);
            lt++;
            i++;
        }
        else if(arr[i]>v){
            swap(arr[i],arr[gt-1]);
            gt--;

        } else{
            i++;
        }
    }

    swap(arr[l],arr[lt]);

    __quickSort3Ways(arr,l,lt-1);
    __quickSort3Ways(arr,gt,r);



}

template <typename T>
void quickSort3Ways(T arr[],int n){

    srand(time(NULL));

    __quickSort3Ways(arr,0,n-1);

}

int main() {
    int n=1000000;
    // 测试1 一般性测试
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1=SortTestHelper::generateRandomArray(n,0,n);
    int* arr2=SortTestHelper::copyIntArray(arr1,n);
    int* arr3=SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);


    delete []arr1;
    delete []arr2;
    delete[] arr3;

    cout<<endl;

    // 测试2 测试近乎有序的数组
    // 加入了随机选择标定点的步骤后, 我们的快速排序可以轻松处理近乎有序的数组
    // 但是对于近乎有序的数组, 其效率比优化后的归并排序要低, 但完全再容忍范围里
    // 思考一下为什么对于近乎有序的数组, 快排的性能比优化后的归并排序低? :)
    int swapTimes = 100;
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);


    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout<<endl;

    // 测试3 测试存在包含大量相同元素的数组
    // 使用双快速排序后, 我们的快速排序算法可以轻松的处理包含大量元素的数组
    cout<<"Test for random array, size = "<<n<<", random range [0,10]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,10);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
    SortTestHelper::testSort("Quick Sort 3 Ways", quickSort3Ways, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;


    return 0;
}