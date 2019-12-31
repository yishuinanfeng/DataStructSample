//
// Created by yanyinan on 2019/12/29.
//

#include "BubbleSort.h"
#include "../ArrayUtil.h"


void BubbleSort::sort(int *arr, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
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


