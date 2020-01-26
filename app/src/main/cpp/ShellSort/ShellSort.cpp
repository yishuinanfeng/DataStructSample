//
// Created by yanyinan on 2020/1/21.
//

#include "ShellSort.h"
#include "../ArrayList/ArrayList.hpp"

void ShellSort::sort(int *arr, int len) {
    //步长
    int increment = len / 2;
    while (increment >= 1) {
        LOGD("ShellSort increment:%d", increment);
        //i为每组的首个元素
        for (int i = 0; i < increment; ++i) {
            //对以i为首元素的一组进行插入排序
            for (int j = i + increment; j < len; j = j + increment) {
                int temp = arr[j];
                int k;
                //temp和排序区域的元素从大到小对比，如果temp比对比的元素小则将对比的元素往后挪increment个元素
                for (k = j - increment; k >= 0 && arr[k] > temp; k = k - increment) {
                    arr[k + increment] = arr[k];
                }
                //将temp放到正确的位置上（因为在上面的for循环中最后执行了k = k - increment，所以这里是arr[k + increment]）
                arr[k + increment] = temp;
            }
        }

        increment /= 2;
    }
}
