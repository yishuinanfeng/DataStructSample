//
// Created by yanyinan on 2019/12/30.
//

#ifndef DATASTRUCTURESAMPLE_ARRAYUTIL_H
#define DATASTRUCTURESAMPLE_ARRAYUTIL_H


namespace ArrayUtil {
    //-----------四种交换方式-------------
    void swap1(int &a, int &b);

    void swap2(int *a, int *b);

    void swap3(int &a, int &b);

    void swap4(int &a, int &b);
    //-----------四种交换方式-------------
    /**
     * 创建一个随机序列的数组
     * @param len
     * @param low
     * @param high
     * @return
     */
    int *create_random_array(int len, int low, int high);

    /**
     * 创建一个接近有序的数组
     * @param len
     * @param swapNums：乱序的个数
     * @return
     */
    int *create_nearly_ordered_array(int len, int swapNums);

    /**
     * 复制一个数组
     * @param arr
     * @param len
     * @return
     */
    int *copy_random_array(int *arr, int len);

    /**
     * 对数组排序进行时间记录
     * @param sortName
     * @param sort
     * @param arr
     * @param len
     */
    void sort_array(char *sortName, void(*sort)(int *, int), int *arr, int len);
};


#endif //DATASTRUCTURESAMPLE_ARRAYUTIL_H
