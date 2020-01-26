//
// Created by yanyinan on 2019/12/30.
//

#include <assert.h>
#include "ArrayUtil.h"
#include <stdlib.h>
#include <android/log.h>
#include <time.h>
#include <assert.h>
#include <iostream>

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,"DataStructure",__VA_ARGS__)
/**
 * 通过临时变量交换
 * @param a
 * @param b
 */
void ArrayUtil::swap1(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * 通过指针交换
 * @param a
 * @param b
 */
void ArrayUtil::swap2(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 通过加法减法交换
 * @param a
 * @param b
 */
void ArrayUtil::swap3(int &a, int &b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

/**
 * 通过异或交换
 * 异或：同值取0，异值取1。支持交换律和结合律
 * @param a
 * @param b
 */
void ArrayUtil::swap4(int &a, int &b) {
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}

namespace ArrayUtil {
    int *create_random_array(int len, int low, int high) {
        int *arr = new int[len];

        for (int i = 0; i < len; ++i) {
            arr[i] = rand() % (high - low) + low;
        }

        return arr;
    }

    int *create_nearly_ordered_array(int len, int swapNums) {
        int *arr = new int[len];

        for (int i = 0; i < len; ++i) {
            arr[i] = i;
        }

        for (int i = 0; i < swapNums; ++i) {
            int randomX = rand() % (len - 1);
            int randomY = rand() % (len - 1);
            std::swap(arr[randomX], arr[randomY]);
        }

        return arr;
    }

    int *copy_random_array(int *arr, int len) {
        int *copy_arr = new int[len];
        memcpy(copy_arr, arr, sizeof(int) * len);
        return copy_arr;
    }

    void sort_array(char *sortName, void(*sort)(int *, int), int *arr, int len) {
        size_t start_time = static_cast<size_t>(clock());
        sort(arr, len);
        size_t end_time = static_cast<size_t>(clock());
        // 计算算法的执行时间
        double time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
        LOGD("%s的执行时间：%lf", sortName, time);

        // 检测这个数组有没有拍好序
        for (int i = 0; i < len - 1; ++i) {
            assert(arr[i] <= arr[i + 1]);
        }
    }
}
