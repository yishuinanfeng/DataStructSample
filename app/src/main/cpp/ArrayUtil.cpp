//
// Created by yanyinan on 2019/12/30.
//

#include "ArrayUtil.h"
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
