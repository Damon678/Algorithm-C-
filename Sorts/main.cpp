#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "ShellSort.h"

using namespace std;

int main() {
    int n=20000;
    cout<<"Test for random array, size = "<<n<<", random range [0, "<<n<<"]"<<endl;
    int* arr1=SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);
    int *arr5 = SortTestHelper::copyIntArray(arr1, n);
    int *arr6 = SortTestHelper::copyIntArray(arr1, n);



    SortTestHelper::testSort("Seleciton Sort",SelectionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort 2", SelectionSortPro,arr3,n);
    SortTestHelper::testSort("Insertion Sort",InsertionSort,arr2,n);
    SortTestHelper::testSort("Bubble Sort", BubbleSort, arr4, n);
    SortTestHelper::testSort("Bubble Sort 2", BubbleSortPro, arr5, n);
    SortTestHelper::testSort("Shell Sort", ShellSort, arr6, n);

    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    delete []arr5;
    delete []arr6;

    cout<<endl;

    // 测试2 有序性更强的测试
    cout<<"Test for more ordered random array, size = "<<n<<", random range [0, 3]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n,0,3);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);


    SortTestHelper::testSort("Seleciton Sort",SelectionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort 2", SelectionSortPro,arr3,n);
    SortTestHelper::testSort("Insertion Sort",InsertionSort,arr2,n);
    SortTestHelper::testSort("Bubble Sort", BubbleSort, arr4, n);
    SortTestHelper::testSort("Bubble Sort 2", BubbleSortPro, arr5, n);
    SortTestHelper::testSort("Shell Sort", ShellSort, arr6, n);

    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    delete []arr5;
    delete []arr6;

    cout<<endl;


    // 测试3 测试近乎有序的数组
    int swapTimes = 100;
    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    arr4 = SortTestHelper::copyIntArray(arr1, n);
    arr5 = SortTestHelper::copyIntArray(arr1, n);
    arr6 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Seleciton Sort",SelectionSort,arr1,n);
    SortTestHelper::testSort("Selection Sort 2", SelectionSortPro,arr3,n);
    SortTestHelper::testSort("Insertion Sort",InsertionSort,arr2,n);
    SortTestHelper::testSort("Bubble Sort", BubbleSort, arr4, n);
    SortTestHelper::testSort("Bubble Sort 2", BubbleSortPro, arr5, n);
    SortTestHelper::testSort("Shell Sort", ShellSort, arr6, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete []arr4;
    delete []arr5;
    delete []arr6;

    cout<<endl;



    return 0;
}