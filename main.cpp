#include <iostream>
#include "SortTestHelper.h"
#include "Sort.h"

int main() {
    //当n = 100000时 冒泡排序去掉
    //当n = 1000000时 选择排序和插入排序去掉
    //当n = 10000000时 归并排序去掉 内存不够
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr1 = SortTestHelper::copyArray(arr, n);
    int *arr2 = SortTestHelper::copyArray(arr, n);
    int *arr3 = SortTestHelper::copyArray(arr, n);
    int *arr4 = SortTestHelper::copyArray(arr, n);
    int *arr5 = SortTestHelper::copyArray(arr, n);
    int *arr6 = SortTestHelper::copyArray(arr, n);
    int *arr7 = SortTestHelper::copyArray(arr, n);
    int *arr8 = SortTestHelper::copyArray(arr, n);
    int *arr9 = SortTestHelper::copyArray(arr, n);
    int *arr10 = SortTestHelper::copyArray(arr, n);

    std::cout << "Test for Random Array , size = " << n << ", random range [0, " << n << "]" << std::endl;
    SortTestHelper::testSort("Bubble Sort", BubbleSort, arr, n);
    SortTestHelper::testSort("Selection Sort", SelectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", InsertionSort, arr2, n);
    SortTestHelper::testSort("Radix Sort", RadixSort, arr3, n);
    SortTestHelper::testSort("Merge Sort", MergeSort, arr4, n);
    SortTestHelper::testSort("Merge Sort BU", MergeSortBU, arr5, n);
    SortTestHelper::testSort("Shell Sort", ShellSort, arr6, n);
    SortTestHelper::testSort("Quick Sort", QuickSort, arr7, n);
    SortTestHelper::testSort("Quick Two Sort", QuickSort2Ways, arr8, n);
    SortTestHelper::testSort("Quick Three Sort", QuickSort3Ways, arr9, n);
    SortTestHelper::testSort("Heap Sort", HeapSort, arr10, n);
    std::cout << std::endl;

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    delete[] arr10;

    int swapTime = n / 10;
    arr = SortTestHelper::generateNearlyOrderedArray(n, 0, n, swapTime);
    arr1 = SortTestHelper::copyArray(arr, n);
    arr2 = SortTestHelper::copyArray(arr, n);
    arr3 = SortTestHelper::copyArray(arr, n);
    arr4 = SortTestHelper::copyArray(arr, n);
    arr5 = SortTestHelper::copyArray(arr, n);
    arr6 = SortTestHelper::copyArray(arr, n);
    arr7 = SortTestHelper::copyArray(arr, n);
    arr8 = SortTestHelper::copyArray(arr, n);
    arr9 = SortTestHelper::copyArray(arr, n);
    arr10 = SortTestHelper::copyArray(arr, n);

    std::cout << "Test for Random Nearly Ordered Array , size = " << n << ", swapTime = " << swapTime << std::endl;
    SortTestHelper::testSort("Bubble Sort", BubbleSort, arr, n);
    SortTestHelper::testSort("Selection Sort", SelectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", InsertionSort, arr2, n);
    SortTestHelper::testSort("Radix Sort", RadixSort, arr3, n);
    SortTestHelper::testSort("Merge Sort", MergeSort, arr4, n);
    SortTestHelper::testSort("Merge Sort BU", MergeSortBU, arr5, n);
    SortTestHelper::testSort("Shell Sort", ShellSort, arr6, n);
    SortTestHelper::testSort("Quick Sort", QuickSort, arr7, n);
    SortTestHelper::testSort("Quick Two Sort", QuickSort2Ways, arr8, n);
    SortTestHelper::testSort("Quick Three Sort", QuickSort3Ways, arr9, n);
    SortTestHelper::testSort("Heap Sort", HeapSort, arr10, n);
    std::cout << std::endl;

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    delete[] arr10;

    arr = SortTestHelper::generateRandomArray(n, 0, 10);
    arr1 = SortTestHelper::copyArray(arr, n);
    arr2 = SortTestHelper::copyArray(arr, n);
    arr3 = SortTestHelper::copyArray(arr, n);
    arr4 = SortTestHelper::copyArray(arr, n);
    arr5 = SortTestHelper::copyArray(arr, n);
    arr6 = SortTestHelper::copyArray(arr, n);
    arr7 = SortTestHelper::copyArray(arr, n);
    arr8 = SortTestHelper::copyArray(arr, n);
    arr9 = SortTestHelper::copyArray(arr, n);
    arr10 = SortTestHelper::copyArray(arr, n);

    std::cout << "Test for Random Array , size = " << n << ", random range [0, " << n << "]" << std::endl;
    SortTestHelper::testSort("Bubble Sort", BubbleSort, arr, n);
    SortTestHelper::testSort("Selection Sort", SelectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", InsertionSort, arr2, n);
    SortTestHelper::testSort("Radix Sort", RadixSort, arr3, n);
    SortTestHelper::testSort("Merge Sort", MergeSort, arr4, n);
    SortTestHelper::testSort("Merge Sort BU", MergeSortBU, arr5, n);
    SortTestHelper::testSort("Shell Sort", ShellSort, arr6, n);
    SortTestHelper::testSort("Quick Sort", QuickSort, arr7, n);
    SortTestHelper::testSort("Quick Two Sort", QuickSort2Ways, arr8, n);
    SortTestHelper::testSort("Quick Three Sort", QuickSort3Ways, arr9, n);
    SortTestHelper::testSort("Heap Sort", HeapSort, arr10, n);
    std::cout << std::endl;

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    delete[] arr10;

    return 0;
}
