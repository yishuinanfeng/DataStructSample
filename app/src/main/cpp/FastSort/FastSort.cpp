//
// Created by yanyinan on 2020/1/29.
//

#include "FastSort.h"
#include "../ArrayList/ArrayList.hpp"
#include "../ArrayUtil.h"

void FastSort::sort(int *arr, int len) {
    fastSort(arr, 0, len - 1);
}

void FastSort::sort1(int *arr, int len) {
    fastSort1(arr, 0, len - 1);
}

void FastSort::fastSort(int *arr, const int startIndex, const int endIndex) {
    if (startIndex < endIndex) {
        int l = startIndex;
        int r = endIndex;
        int x = arr[startIndex];

        while (l < r) {
            LOGD("FastSort out while l:%d,r:%d", l, r);
            while (l < r && arr[r] >= x) {
                r--;
            }

            if (l < r) {
                LOGD("arr[l++] = arr[r] l:%d,r:%d", l, r);
                arr[l++] = arr[r];
            }

            while (l < r && arr[l] <= x) {
                l++;
            }

            if (l < r) {
                LOGD("arr[r--] = arr[l] l < r l:%d,r:%d", l, r);
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

void FastSort::fastSort1(int *arr, const int startIndex, const int endIndex) {
    if (startIndex < endIndex) {
        //左指针
        int l = startIndex;
        //右指针
        int r = endIndex;

        // 数组首个元素、中间元素、最后一个元素取中间值数作为枢纽元素
        int compareValue[3] = {arr[startIndex], arr[(endIndex + startIndex) >> 1], arr[endIndex]};
        int x = getMidValue(compareValue);
        //找出枢纽元素x所在index
        int xIndex = l;
        if (x == arr[startIndex]){
            xIndex = startIndex;
        } else if(x == arr[(endIndex + startIndex) >> 1]){
            xIndex = (endIndex + startIndex) >> 1;
        } else if(x == arr[endIndex]){
            xIndex = endIndex;
        }
        //将枢纽元素x和数组首个元素交换位置
        ArrayUtil::swap4(arr[l], arr[xIndex]);
        LOGD("getMidValue x:%d", x);
        LOGD("进入新一轮递归");

        while (l < r) {
            LOGD("FastSort out while l:%d,r:%d", l, r);
            while (l < r && arr[r] >= x) {
                r--;
            }

            if (l < r) {
                LOGD("arr[l++] = arr[r] l:%d,r:%d", l, r);
                arr[l++] = arr[r];
            }

            while (l < r && arr[l] <= x) {
                l++;
            }

            if (l < r) {
                LOGD("arr[r--] = arr[l] l < r l:%d,r:%d", l, r);
                arr[r--] = arr[l];
            }
        }
        //此时l和r相等
        arr[l] = x;

        fastSort1(arr, startIndex, l);
        fastSort1(arr, l + 1, endIndex);
    }
}

/**
 * 获取三个元素的数组的中间值
 *
 * @param arr
 * @param startIndex
 * @param endIndex
 */
int FastSort::getMidValue(int *arr) {
    if (arr[0] > arr[1]) {
        ArrayUtil::swap4(arr[0], arr[1]);
    }
    if (arr[0] > arr[2]) {
        ArrayUtil::swap4(arr[0], arr[2]);
    }
    if (arr[2] < arr[1]) {
        ArrayUtil::swap4(arr[2], arr[1]);
    }

    return arr[1];
}
