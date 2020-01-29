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
     * 选择更合适的枢纽元素的优化版的快速排序
     * @param arr
     * @param len
     */
    void sort1(int arr[], int len);

    void fastSort(int *arr, int startIndex, int endIndex);
};


#endif //DATASTRUCTURESAMPLE_FASTSORT_H
