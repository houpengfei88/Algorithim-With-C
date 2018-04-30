//
// Created by hpf on 18-4-30.
//

#ifndef LEARNPROJECTS_SORT_H
#define LEARNPROJECTS_SORT_H

#include <iostream>
#include "SortHelper.h"

//选择排序
template<typename T>
void SelectionSort(T arr[], int n) {
    int minIndex = 0;
    for (int i = 0; i < n; ++i) {
        minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

//插入排序
template<typename T>
void InsertionSort(T arr[], int n) {
    T e;
    int j;
    for (int i = 1; i < n; ++i) {
        e = arr[i];
        for (j = i; j > 0 && arr[j - 1] > e; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}

//冒泡排序
template<typename T>
void BubbleSort(T arr[], int n) {
    bool swaped;
    do {
        swaped = false;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                swaped = true;
            }
        }
        --n;
    } while (swaped);
}

//基数排序只能用于整数排序
template<typename T>
void RadixSort(T arr[], int n) {
    assert(T == int);
    int d = SortHelper::__maxbit(arr, n);
    T *tmp = new T[n];
    int *count = new int[10];
    int i, j, k;
    int radix = 1;
    for (i = 1; i <= d; i++) {
        for (j = 0; j < 10; j++)
            count[j] = 0;
        for (j = 0; j < n; j++) {
            k = (arr[j] / radix) % 10;
            count[k]++;
        }
        for (j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j];
        for (j = n - 1; j >= 0; j--) {
            k = (arr[j] / radix) % 10;
            tmp[count[k] - 1] = arr[j];
            count[k]--;
        }
        for (j = 0; j < n; j++)
            arr[j] = tmp[j];
        radix = radix * 10;
    }
    delete[] tmp;
    delete[] count;
}

//归并排序
template<typename T>
void MergeSort(T arr[], int n) {
    //性能优化
    //如果将aux数组作为参数传递给__merge子过程，整个归并排序还会更快
    T aux[n];
    SortHelper::__mergeSort(arr, 0, n - 1, aux);
}

//自底向上的归并排序
template<typename T>
void MergeSortBU(T arr[], int n) {
    for (int i = 0; i < n; i += 16)
        SortHelper::InsertionSort(arr, i, std::min(i + 15, n - 1));
    for (int sz = 16; sz < n; sz += sz)
        //注意数组越界问题
        for (int i = 0; i < n - sz; i += sz + sz)
            //优化操作
            if (arr[i + sz - 1] > arr[i + sz])
                //对arr[i...i+sz-1]和arr[i+sz...i+2*sz-1]进行归并排序
                SortHelper::__merge(arr, i, i + sz - 1, std::min(i + sz + sz - 1, n - 1));
}

//希尔排序
template<typename T>
void ShellSort(T arr[], int n) {
    int h = 1;
    while (h < n / 3)
        h = 3 * h + 1;
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            T e = arr[i];
            int j;
            for (j = i; j >= h && e < arr[j - h]; j -= h)
                arr[j] = arr[j - h];
            arr[j] = e;
        }
        h /= 3;
    }
}

//快速排序
template<typename T>
void QuickSort(T arr[], int n) {
    srand(time(NULL));
    SortHelper::__quickSort(arr, 0, n - 1);
}

//双路快速排序
template<typename T>
void QuickSort2Ways(T arr[], int n) {
    srand(time(NULL));
    SortHelper::__quickSort2Ways(arr, 0, n - 1);
}

//三路快速排序
template<typename T>
void QuickSort3Ways(T arr[], int n) {
    srand(time(NULL));
    SortHelper::__quickSort3Ways(arr, 0, n - 1);
}

//堆排序
template<typename T>
void HeapSort(T arr[], int n) {
    for (int i = (n - 1 - 1) / 2; i >= 0; i--)
        SortHelper::__shiftDown(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        SortHelper::__shiftDown(arr, i, 0);
    }
}

#endif //LEARNPROJECTS_SORT_H
