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
    std::stack<int> stack;
    while (number > 0) {
        int n = number % 2;
        stack.push(n);
        number /= 2;
    }

    while (!stack.empty()) {
        //从高位到低位循环打印出该二进制数
        LOGD("decimalToBinary result:%d", stack.top());
        stack.pop();
    }

}

void BinaryOperation::decimalToBinary1(int number) {
    std::stack<int> stack;
    bool isNegative = false;
    if (number < 0) {
        isNegative = true;
    }
    for (int i = 0; i < 32; ++i) {
        //正数只打印最高位的1，负数打印出全部32位
        if (number == 0 & !isNegative) {
            break;
        }

        //    if (i == 32 && number < 0) {
        //number为负数的情况
        //      LOGD("decimalToBinary1 result:%d", 1);
        //   }

        int result = number & 1;
        stack.push(result);
        // LOGD("for i:%d,number:%d,result:%d，stack size:%d", i, number, result, stack.size());
        //  LOGD("for result:%d", result);
        number = number >> 1;
    }

    while (!stack.empty()) {
        //从高位到低位循环打印出该二进制数
        //这里非常诡异，要打印出stack size才可以将数据打印全。。。
        LOGD("stack size:%d,result:%d", stack.size(), stack.top());
        stack.pop();
    }
}


