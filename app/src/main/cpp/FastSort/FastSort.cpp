//
// Created by yanyinan on 2020/1/29.
//

#include "FastSort.h"
#include "../ArrayList/ArrayList.hpp"

void FastSort::sort(int *arr, int len) {
    fastSort(arr, 0, len - 1);
}

void FastSort::sort1(int *arr, int len) {

}

void FastSort::fastSort(int *arr, const int startIndex, const int endIndex) {
    if (startIndex < endIndex) {
        int l = startIndex;
        int r = endIndex;
        int x = arr[startIndex];

        while (l < r) {
            LOGD("FastSort out while l:%d,r:%d",l, r);
            while (l < r && arr[r] >= x) {
                r--;
            }

            if (l < r) {
                LOGD("arr[l++] = arr[r] l:%d,r:%d",l, r);
                arr[l++] = arr[r];
            }

            while (l < r && arr[l] <= x) {
                l++;
            }

            if (l < r) {
                LOGD("arr[r--] = arr[l] l < r l:%d,r:%d",l, r);
                arr[r--] = arr[l];
            }
        }
        //此时l和r相等
        arr[l] = x;
        LOGD("进入下轮递归");
        fastSort(arr, startIndex, l);
        fastSort(arr, l + 1, endIndex);
    }

}
