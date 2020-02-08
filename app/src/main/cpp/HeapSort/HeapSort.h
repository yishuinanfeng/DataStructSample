//
// Created by yanyinan on 2020/2/8.
//

#ifndef DATASTRUCTURESAMPLE_HEAPSORT_H
#define DATASTRUCTURESAMPLE_HEAPSORT_H

#include <zconf.h>

/**
 * 基于大根堆的堆排序
 */
class HeapSort {
private:
    /**
     * 对原始数组进行建堆
     */
    void buildHeap(int *arr, int length);
    /**
     *
     * @param arr 进行排序的数组
     * @param heapifyIndex 堆化范围从index为0到heapifyIndex
     */
    void heapifyFormUp(int *arr, int heapifyIndex);

public:
    /**
     * 堆排序
     * @param arr
     * @param length
     */
    void sort(int *arr,int length);
};


#endif //DATASTRUCTURESAMPLE_HEAPSORT_H
