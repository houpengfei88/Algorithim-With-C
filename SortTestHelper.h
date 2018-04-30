//
// Created by hpf on 18-4-30.
//

#ifndef LEARNPROJECTS_SORTTESTHELPER_H
#define LEARNPROJECTS_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>

namespace SortTestHelper {
    template<typename T>
    T *generateRandomArray(int n, T rangeL, T rangeR) {
        assert(rangeL <= rangeR && n > 0);
        T *arr = new T[n];
        srand(time(0));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    template<typename T>
    T *generateNearlyOrderedArray(int n, T rangeL, T rangeR, int swapTime) {
        assert(n > 0 && swapTime >= 0 && rangeL <= rangeR);
        int posx, posy = 0;
        T *arr = new T[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i + (rangeR - rangeL);
        }
        srand(time(0));
        for (int j = 0; j < swapTime; ++j) {
            posx = rand() % n;
            posy = rand() % n;
            if (posx == posy)
                j--;
            else
                std::swap(arr[posx], arr[posy]);
        }
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {
        assert(n > 0 && arr != nullptr);
        for (int i = 0; i < n; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    template<typename T>
    bool isSorted(T arr[], int n) {
        assert(n > 0 && arr != nullptr);
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    template<typename T>
    void testSort(std::string sortName, void(*Sort)(T[], int), T arr[], int n) {
        assert(n > 0 && arr != nullptr);
        clock_t startTime = clock();
        Sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        std::cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << std::endl;
    }

    template<typename T>
    T *copyArray(T a[], int n) {
        T *arr = new T[n];
        std::copy(a, a + n, arr);
        return arr;
    }
}

#endif //LEARNPROJECTS_SORTTESTHELPER_H
