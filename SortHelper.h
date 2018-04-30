//
// Created by hpf on 18-4-30.
//

#ifndef LEARNPROJECTS_SORTHELPER_H
#define LEARNPROJECTS_SORTHELPER_H

#include <iostream>

namespace SortHelper {
    //基数排序辅助函数
    template<typename T>
    int __maxbit(T arr[], int n) {
        //保存最大的位数
        int count = 1;
        T p = 10;
        for (int i = 0; i < n; i++) {
            while (arr[i] >= p) {
                p *= 10;
                count++;
            }
        }
        return count;
    }

    //对arr[l...r]范围的数组进行插入排序
    //在小范围内插入排序比归并排序效率高，用来优化归并排序
    template<typename T>
    void InsertionSort(T arr[], int l, int r) {
        for (int i = l + 1; i <= r; i++) {
            T e = arr[i];
            int j;
            for (j = i; j > l && arr[j - 1] > e; j--) {
                arr[j] = arr[j - 1];
            }
            arr[j] = e;
        }
    }

    //将arr[l...mid]和arr[mid+1...r]两部分进行归并
    //未优化版本
    template<typename T>
    void __merge(T arr[], int l, int mid, int r) {
        T aux[r - l + 1];
        for (int i = l; i <= r; i++)
            aux[i - l] = arr[i];
        int i = l, j = mid + 1;
        for (int k = l; k <= r; k++) {
            if (i > mid) {
                arr[k] = aux[j - l];
                j++;
            } else if (j > r) {
                arr[k] = aux[i - l];
                i++;
            } else if (aux[i - l] < aux[j - l]) {
                arr[k] = aux[i - l];
                i++;
            } else {
                arr[k] = aux[j - l];
                j++;
            }
        }
    }

    //将arr[l...mid]和arr[mid+1...r]两部分进行归并
    template<typename T>
    void __merge(T arr[], int l, int mid, int r, T aux[]) {
        for (int i = l; i <= r; i++)
            aux[i] = arr[i];
        int i = l, j = mid + 1;
        for (int k = l; k <= r; k++) {
            if (i > mid) {
                arr[k] = aux[j];
                j++;
            } else if (j > r) {
                arr[k] = aux[i];
                i++;
            } else if (aux[i] < aux[j]) {
                arr[k] = aux[i];
                i++;
            } else {
                arr[k] = aux[j];
                j++;
            }
        }
    }

    //递归使用归并排序，对arr[l...r]的范围进行排序
    template<typename T>
    void __mergeSort(T arr[], int l, int r, T aux[]) {
        //使用插入排序进行优化
        if (r - l <= 15) {
            InsertionSort(arr, l, r);
            return;
        }
        //防止l + r 越界
        int mid = l + (r - l) / 2;
        __mergeSort(arr, l, mid, aux);
        __mergeSort(arr, mid + 1, r, aux);
        //代码优化
        if (arr[mid] > arr[mid + 1])
            __merge(arr, l, mid, r, aux);
    }

    //对arr[l...r]部分进行partition操作
    //返回索引值p,使得arr[l...p-1] < arr[p]; arr[p+1...r] > arr[p]
    template<typename T>
    int __partition(T arr[], int l, int r) {
        //对几乎有序的数组进行优化，有效缓解快速排序退化为O(n^2)
        std::swap(arr[l], arr[rand() % (r - l + 1) + l]);
        T v = arr[l];
        //arr[l+1...j] < v; arr[j+1...i] > v
        int j = l;
        for (int i = l + 1; i <= r; i++)
            if (arr[i] < v)
                std::swap(arr[++j], arr[i]);
        std::swap(arr[l], arr[j]);
        return j;
    }

    //双路快速排序
    template<typename T>
    int __partition2(T arr[], int l, int r) {
        std::swap(arr[l], arr[rand() % (r - l + 1) + l]);
        T v = arr[l];
        int i = l + 1, j = r;
        while (true) {
            while (i <= r && arr[i] < v) i++;
            while (j >= l + 1 && arr[j] > v) j--;
            if (i > j) break;
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
        std::swap(arr[l], arr[j]);
        return j;
    }

    //对arr[l...r]部分进行快速排序
    template<typename T>
    void __quickSort(T arr[], int l, int r) {
        //使用插入排序进行优化
        if (r - l <= 15) {
            InsertionSort(arr, l, r);
            return;
        }
        int p = __partition(arr, l, r);
        __quickSort(arr, l, p - 1);
        __quickSort(arr, p + 1, r);
    }

    //对arr[l...r]部分进行快速排序
    template<typename T>
    void __quickSort2Ways(T arr[], int l, int r) {
        //使用插入排序进行优化
        if (r - l <= 15) {
            InsertionSort(arr, l, r);
            return;
        }
        int p = __partition2(arr, l, r);
        __quickSort2Ways(arr, l, p - 1);
        __quickSort2Ways(arr, p + 1, r);
    }

    //三路快速排序
    template<typename T>
    void __quickSort3Ways(T arr[], int l, int r) {
        //性能优化
        if (r - l <= 15) {
            InsertionSort(arr, l, r);
            return;
        }
        std::swap(arr[l], arr[rand() % (r - l + 1) + l]);
        T v = arr[l];
        int lt = l;     //arr[l+1...lt] < v
        int i = l + 1;  //arr[lt+1...i) == v
        int gt = r + 1; //arr[gt...r] > v
        while (i < gt) {
            if (arr[i] < v) {
                std::swap(arr[i], arr[lt + 1]);
                lt++;
                i++;
            } else if (arr[i] > v) {
                std::swap(arr[i], arr[gt - 1]);
                gt--;
            } else {
                i++;
            }
        }
        std::swap(arr[l], arr[lt]);
        __quickSort3Ways(arr, l, lt - 1);
        __quickSort3Ways(arr, gt, r);

        //排序完的结果是：
        //arr[l...lt-1] < v
        //arr[lt...gt-1] == v
        //arr[gt...r] > v
    }

    //堆排序辅助函数
    template<typename T>
    void __shiftDown(T arr[], int n, int k) {
        T e = arr[k];
        while (2 * k + 1 < n) {
            int j = 2 * k + 1;
            if (j + 1 < n && arr[j + 1] > arr[j])
                j += 1;
            if (e >= arr[j])
                break;
            arr[k] = arr[j];
            k = j;
        }
        arr[k] = e;

    }
}


#endif //LEARNPROJECTS_SORTHELPER_H
