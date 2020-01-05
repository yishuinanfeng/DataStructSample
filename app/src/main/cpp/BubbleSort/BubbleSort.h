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
     * 冒泡排序通过加标志位进行优化
     * @param arr
     * @param len
     */
    void sort1(int arr[], int len);

    /**
     * 冒泡排序通过记录上一次最后一个有比较的位置进行优化（在乱序度不高。且乱序集中在序列前面部分的时候效率很高，因为它可以提前终止循环）
     * @param arr
     * @param len
     */
    void sort2(int arr[], int len);
};


#endif //DATASTRUCTURESAMPLE_BUBBLESORT_H
