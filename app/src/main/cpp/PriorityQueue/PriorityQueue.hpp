//
// Created by yanyinan on 2020/2/8.
//

#ifndef DATASTRUCTURESAMPLE_PRIORITYQUEUE_HPP
#define DATASTRUCTURESAMPLE_PRIORITYQUEUE_HPP
#define LOGD_PriorityQueue(...) __android_log_print(ANDROID_LOG_DEBUG,"PriorityQueue",__VA_ARGS__)


#include "../ArrayUtil.h"

/**
 * 优先级队列
 * 基于大根堆实现，底层数据结构为数组
 * @tparam E
 */
template<class E>
class PriorityQueue {
    /**
     * 数组大小
     */
    int count;
    /**
     * 数据数组
     */
    E *array;
    /**
     * 队列最后一个数据在数组中的index
     */
    int index = -1;

public:

    PriorityQueue(int count = 10);

    ~PriorityQueue();

    /**
     * 插入数据
     * @param e
     * @return 插入失败
     */
    bool offer(E e);

    /**
     * 获取堆顶数据并移除
     * @return
     */
    E poll();

    /**
     * 获取堆顶数据
     * @return
     */
    E peek();

    bool isEmpty();

    int size();

    /**
     * 从下往上堆化
     * @tparam E
     */
    void heapifyFromDown();

    /**
     * 从上（index为0）往下（index为heapifyIndex）堆化
     * @tparam heapifyIndex:需要进行堆化的最后一个元素的index
     */
    void heapifyFormUp(int heapifyIndex);

    /**
     * 遍历打印出整个数组,用于调试
     */
    void printArray();
};

template<class E>
bool PriorityQueue<E>::offer(E e) {
    if (index == count - 1) {
        //数组已满
        return false;
    }
    array[++index] = e;
    heapifyFromDown();
    return true;
}

template<class E>
void PriorityQueue<E>::heapifyFromDown() {
    int currentIndex = index;
    while ((currentIndex - 1) / 2 >= 0 && array[currentIndex] > array[(currentIndex - 1) / 2]) {
        ArrayUtil::swap1(array[currentIndex], array[(currentIndex - 1) / 2]);
        currentIndex = (currentIndex - 1) / 2;
    }
}

template<class E>
E PriorityQueue<E>::poll() {
    if (index == -1) {
        return false;
    }
    E e = array[0];
    //堆顶元素和堆末元素进行交换，然后对除原堆顶元素外的元素进行堆化
    if (index > 0) {
        ArrayUtil::swap1(array[0], array[index]);
        heapifyFormUp(index - 1);
    }
    index--;

    return e;
}

template<class E>
PriorityQueue<E>::PriorityQueue(int count) {
    this->count = count;
    array = (E *) malloc(this->count * sizeof(E));
}

template<class E>
PriorityQueue<E>::~PriorityQueue() {
    LOGD_PriorityQueue("delete array");
    delete array;
}

template<class E>
E PriorityQueue<E>::peek() {
    if (index == -1) {
        return false;
    }
    return array[index];
}

template<class E>
bool PriorityQueue<E>::isEmpty() {
    return index == -1;
}

template<class E>
void PriorityQueue<E>::heapifyFormUp(int heapifyIndex) {
    int currentIndex = 0;
    int maxIndex;

    while ((maxIndex = currentIndex * 2 + 1) <= heapifyIndex) {
        //找出currentIndex的节点左右子节点偏大的节点
        if ((maxIndex + 1 <= heapifyIndex) && (array[maxIndex] < array[maxIndex + 1])) {
            maxIndex += 1;
        }
        //如果currentIndex的节点小于左右节点偏大的节点值，则交换二者
        if (array[currentIndex] < array[maxIndex]) {
            ArrayUtil::swap1(array[currentIndex], array[maxIndex]);
        } else {
            break;
        }
        //将currentIndex移动到原来根节点新的位置
        currentIndex = maxIndex;
    }
}

template<class E>
void PriorityQueue<E>::printArray() {
    for (int i = 0; i <= index; ++i) {
        LOGD_PriorityQueue("array factor:%d", array[i]);
    }
}

template<class E>
int PriorityQueue<E>::size() {
    return index + 1;
}


#endif //DATASTRUCTURESAMPLE_PRIORITYQUEUE_HPP
