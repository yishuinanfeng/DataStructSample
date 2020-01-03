//
// Created by yanyinan on 2020/1/1.
//

#include "InsertSort.h"

void InsertSort::sort(int *arr, int len) {
    for (int i = 1; i < len; ++i) {
        int temp = arr[i];
        int j;
        //temp和每个已排序的元素从大到小比较，如果元素比temp大，则元素往后挪动一位，直到有一个元素比temp小，就将temp放在该元素之后的位置
        for (j = i - 1; j >= 0 && arr[j] < temp; j--) {
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = temp;
    }
}
