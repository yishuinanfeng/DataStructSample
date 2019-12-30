//
// Created by yanyinan on 2019/12/30.
//

#include "SelectSort.h"
#include "../ArrayUtil.h"

void SelectSort::sort(int *arr, int len) {
    for (int i = 0; i < len - 1; ++i) {
        //记录未排序区最小元素的index.这里比较最小元素需要包括arr[i]
        int minIndex = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        //得到从i到len -1中最小的元素的index，然后交换最小元素和首个元素
        ArrayUtil::swap1(arr[i], arr[minIndex]);
    }
}
