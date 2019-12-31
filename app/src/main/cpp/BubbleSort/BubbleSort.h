//
// Created by yanyinan on 2019/12/29.
//

#ifndef DATASTRUCTURESAMPLE_BUBBLESORT_H
#define DATASTRUCTURESAMPLE_BUBBLESORT_H

/**
 * 冒泡排序
 */
class BubbleSort {
public:

    /**
     * 最常规的冒泡排序
     * @param arr
     * @param len
     */
    void sort(int arr[], int len);

    /**
     * 冒泡排序加标志位进行优化
     * @param arr
     * @param len
     */
    void sort1(int arr[], int len);
};


#endif //DATASTRUCTURESAMPLE_BUBBLESORT_H
