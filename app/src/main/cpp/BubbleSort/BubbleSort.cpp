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


