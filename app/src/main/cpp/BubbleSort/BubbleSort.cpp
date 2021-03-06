//
// Created by yanyinan on 2019/12/29.
//

#include "BubbleSort.h"
#include "../ArrayUtil.h"

void BubbleSort::sort(int *arr, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            //这里不要写>=，不然编程不稳定排序，而且会增加没必要的交换
            if (arr[j] > arr[j + 1]) {
                //   ArrayUtil::swap1(arr[j], arr[j + 1]);
                //  ArrayUtil::swap2(&arr[j], &arr[j + 1]);
                //  ArrayUtil::swap3(arr[j], arr[j + 1]);
                ArrayUtil::swap4(arr[j], arr[j + 1]);
            }
        }
    }
}

void BubbleSort::sort1(int *arr, int len) {
    for (int i = 0; i < len - 1; ++i) {
        bool isChange = false;
        for (int j = 0; j < len - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                //   ArrayUtil::swap1(arr[j], arr[j + 1]);
                //  ArrayUtil::swap2(&arr[j], &arr[j + 1]);
                //  ArrayUtil::swap3(arr[j], arr[j + 1]);
                ArrayUtil::swap4(arr[j], arr[j + 1]);
                isChange = true;
            }
        }
        //如果isChange为false，即一次小循环中并没有发生交换，说明现在已经处于有序状态
        if (!isChange) {
            break;
        }
    }
}

void BubbleSort::sort2(int *arr, int len) {
    //记录上一次小循环最后一个交换的位置 。第一次循环设置为len - 1 - i
    int lastExchangeIndex = len - 1;
    for (int i = 0; i < len - 1; ++i) {
        //lastExchangeIndex == -1说明本次循环没有交换，已经为有序数组，提前结束本次排序
        if (lastExchangeIndex == -1) {
            break;
        }

        int k = lastExchangeIndex;
        //将lastExchangeIndex置为-1重新在循环中赋值
        lastExchangeIndex = -1;
        //除了第一次小循环，以后的小循环都是循环到上一次小循环最后一次交换的位置即可
        for (int j = 0; j < k; ++j) {
            //这里不要写>=，不然编程不稳定排序，而且会增加没必要的交换
            if (arr[j] > arr[j + 1]) {
                //   ArrayUtil::swap1(arr[j], arr[j + 1]);
                //  ArrayUtil::swap2(&arr[j], &arr[j + 1]);
                //  ArrayUtil::swap3(arr[j], arr[j + 1]);
                ArrayUtil::swap4(arr[j], arr[j + 1]);
                lastExchangeIndex = j;
            }
        }
    }
}


