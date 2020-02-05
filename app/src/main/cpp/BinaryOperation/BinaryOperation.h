//
// Created by yanyinan on 2020/1/30.
//

#ifndef DATASTRUCTURESAMPLE_BINARYOPERATION_H
#define DATASTRUCTURESAMPLE_BINARYOPERATION_H

/**
 * 二进制相关运算
 */
class BinaryOperation {
public:
    /**
     * 二进制转为十进制
     */
    void binaryToDecimal(const int *binaryArr,const int size);

    /**
     * 除二取余法十进制转为二进制（暂时只支持自然数）
     */
    void decimalToBinary(int number);

    /**
     * 位移法（支持正负数补码）
     */
    void decimalToBinary1(int number);
};


#endif //DATASTRUCTURESAMPLE_BINARYOPERATION_H
