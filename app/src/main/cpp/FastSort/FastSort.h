//
// Created by yanyinan on 2020/1/29.
//

#ifndef DATASTRUCTURESAMPLE_FASTSORT_H
#define DATASTRUCTURESAMPLE_FASTSORT_H

/**
 * 快速排序
 */
class FastSort {
public:
    /**
     * 普通快速排序
     * @param arr
     * @param len
     */
    void sort(int arr[], int len);

    /**
     * 通过三数取中选择更合适的枢纽元素的快速排序（尽量避免取到的枢纽元素为最大或者最小的数，适用于数组已经接近有序的情况下）
     * @param arr
     * @param len
     */
    void sort1(int arr[], int len);

    void fastSort(int *arr, int startIndex, int endIndex);

    void fastSort1(int *arr, int startIndex, int endIndex);

    int getMidValue(int *arr);
};


#endif //DATASTRUCTURESAMPLE_FASTSORT_H
