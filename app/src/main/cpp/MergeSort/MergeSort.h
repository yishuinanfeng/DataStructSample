//
// Created by yanyinan on 2020/1/16.
//

#ifndef DATASTRUCTURESAMPLE_MERGESORT_H
#define DATASTRUCTURESAMPLE_MERGESORT_H
/**
 * 归并排序
 */
class MergeSort {
    /**
     * 普通的归并排序
     * @param arr
     * @param len
     */
    void sort(int arr[], int len);

    /**
     * 优化版归并排序。每次将两个数组归并的时候判断前一个数组的最大数是否小于后一个数组的最小数，是则两个数组不需要进行归并排序
     * @param arr
     * @param len
     */
    void sort1(int arr[], int len);
};


#endif //DATASTRUCTURESAMPLE_MERGESORT_H
