//
// Created by yanyinan on 2020/1/30.
//


#include "BinaryOperation.h"
#include <stack>
#include<math.h>
#include <android/log.h>

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,"BinaryOperation",__VA_ARGS__)

/**
 * 二进制转十进制
 * @param binaryArr:二进制数数组
 */
void BinaryOperation::binaryToDecimal(const int *binaryArr, const int size) {
    //std::stack<int> s;
    LOGD("binaryToDecimal start size:%d", size);
    int result = 0;
    for (int i = 1; i <= size; ++i) {
        int t = size - i;
        LOGD("binaryToDecimal for t:%d,binaryArr[t]:%d", t, binaryArr[t]);
        //从低位到高位遍历
        if (binaryArr[t] >= 0 && binaryArr[t] <= 1) {
            result += binaryArr[t] * pow(2, i - 1);
            LOGD("binaryToDecimal  for result:%d", result);
        }
    }

    LOGD("binaryToDecimal result:%d", result);
}

void BinaryOperation::decimalToBinary(int number) {

}

void BinaryOperation::decimalToBinary1(int number) {

}


