//
// Created by yanyinan on 2020/1/16.
//

#include "MergeSort.h"
#include "../ArrayList/ArrayList.hpp"

void MergeSort::sort(int *arr, int len) {
    mergeSort(arr, 0, len - 1);
}

void MergeSort::sort1(int *arr, int len) {
    mergeSort1(arr, 0, len - 1);
}

void MergeSort::mergeSort(int *arr, const int startIndex, const int endIndex) {
    //递归先将数组元素拆分为一个元素为一组，然后从1到整个数组一层层合并
    if (startIndex < endIndex) {
        //使用位移求中间值
        int midIndex = (startIndex + endIndex) >> 1;
        LOGD("MergeSort startIndex：%d,midIndex:%d,endIndex:%d", startIndex, midIndex, endIndex);
        mergeSort(arr, startIndex, midIndex);
        mergeSort(arr, midIndex + 1, endIndex);
        merge(arr, startIndex, midIndex, endIndex);
    }
}

void MergeSort::merge(int *arr, const int startIndex, const int midIndex, const int endIndex) {
    LOGD("merge start");
    int len = endIndex - startIndex + 1;
    //临时数组，用来存储当前两个数组合并好的结果
    int tempArr[len];
    int i = startIndex;
    int j = midIndex + 1;
    int k = 0;
    //arr中的元素从midIndex分为两部分，对两部分进行合并
    while (i <= midIndex && j <= endIndex) {
        //两部分元素从最小的依次比较大小，更小的放在tempArr的index更小的位置
        if (arr[i] <= arr[j]) {
            tempArr[k++] = arr[i++];
            LOGD("tempArr k：%d,i:%d", k, i);
        } else {
            tempArr[k++] = arr[j++];
            LOGD("tempArr k：%d,j:%d", k, j);
        }
    }
    //在其中一部分合并结束之后，合并剩余部分元素
    while (i <= midIndex) {
        tempArr[k++] = arr[i++];
    }

    while (j <= endIndex) {
        tempArr[k++] = arr[j++];
    }
    //将tempArr的元素赋值给arr对应位置的元素
    for (int l = startIndex; l <= endIndex; ++l) {
        LOGD("tempArr to arr", l);
        arr[l] = tempArr[l - startIndex];
    }

}

void MergeSort::mergeSort1(int *arr, int startIndex, int endIndex) {
//递归先将数组元素拆分为一个元素为一组，然后从1到整个数组一层层合并
    if (startIndex < endIndex) {
        //使用位移求中间值
        int midIndex = (startIndex + endIndex) >> 1;
        LOGD("MergeSort startIndex：%d,midIndex:%d,endIndex:%d", startIndex, midIndex, endIndex);
        mergeSort(arr, startIndex, midIndex);
        mergeSort(arr, midIndex + 1, endIndex);
        //如果前一个数组的最大值小于等于后一个数组的最小值，则不需要专门进行合并
        if (arr[midIndex] > arr[midIndex + 1]) {
            merge(arr, startIndex, midIndex, endIndex);
        }
    }
}
