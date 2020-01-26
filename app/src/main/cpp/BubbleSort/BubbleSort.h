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
     * 若在某一趟排序中未发现气泡位置的交换，则说明待排序的无序区中所有气泡均满足轻者在上，重者在下的原则，因此，冒泡排序过程可在此趟排序后终止
     * @param arr
     * @param len
     */
    void sort1(int arr[], int len);

    /**
     * 冒泡排序通过记录上一次最后一个有交换的位置进行优化（在乱序度不高。且乱序集中在序列前面部分的时候效率很高，因为它可以提前终止循环）
     * 在每趟扫描中，记住最后一次交换发生的位置lastExchange，（该位置之后的相邻记录均已有序）。下一趟排序开始时，R[1..lastExchange-1]是无序区，R[lastExchange..n]是有序区。
     * @param arr
     * @param len
     */
    void sort2(int arr[], int len);
};


#endif //DATASTRUCTURESAMPLE_BUBBLESORT_H
