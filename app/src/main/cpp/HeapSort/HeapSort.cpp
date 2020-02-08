//
// Created by yanyinan on 2020/2/8.
//

#include "HeapSort.h"
#include "../ArrayUtil.h"

void HeapSort::sort(int *arr, int length) {
    buildHeap(arr, length);
    for (int i = length - 1; i > 0; --i) {
        //堆顶元素和最后一个元素进行交换
        ArrayUtil::swap1(arr[0], arr[i]);
        //除了原来的堆顶元素（即当前最后一个元素），其余元素进行堆化
        heapifyFormUp(arr, i - 1);
    }
}

void HeapSort::buildHeap(int *arr, int length) {
    //从第二个元素开始到最后一个元素进行大根堆插入
    for (int i = 1; i < length; ++i) {
        //从index为0到i的元素进行堆化
        int currentIndex = i;
        int parentIndex;
        while ((parentIndex = (currentIndex - 1) / 2) >= 0 &&
               arr[currentIndex] > arr[parentIndex]) {
            ArrayUtil::swap1(arr[currentIndex], arr[parentIndex]);
            currentIndex = parentIndex;
        }
    }
}

void HeapSort::heapifyFormUp(int *array, int heapifyIndex) {
    int currentIndex = 0;
    int maxIndex;

    while ((maxIndex = currentIndex * 2 + 1) <= heapifyIndex) {
        //找出currentIndex的节点左右子节点偏大的节点
        if ((maxIndex + 1 <= heapifyIndex) && (array[maxIndex] < array[maxIndex + 1])) {
            maxIndex += 1;
        }
        //如果currentIndex的节点小于左右节点偏大的节点值，则交换二者
        if (array[currentIndex] < array[maxIndex]) {
            ArrayUtil::swap1(array[currentIndex], array[maxIndex]);
        } else {
            break;
        }
        //将currentIndex移动到原来根节点新的位置
        currentIndex = maxIndex;
    }
}


