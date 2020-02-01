//
// Created by yanyinan on 2020/1/30.
//

#ifndef DATASTRUCTURESAMPLE_ARRAYQUEUE_HPP
#define DATASTRUCTURESAMPLE_ARRAYQUEUE_HPP

#include <malloc.h>
#include <assert.h>

#define INIT_SIZE  4
#define MAXIMUM_CAPACITY  1 << 30


/**
 * 使用数组实现的单向队列（循环队列，即当数组的head或者tail到达数组末尾的时候下一个位置是数组头位置）
 * @tparam E
 */
template<class E>
class ArrayQueue {
private:
    /**
     * 表示队列的数组
     */
    E *array = NULL;
    /**
     * head：头指针，指向最先进入的元素的index
     * tail：尾指针，指向最后一个入队的元素的下一个位置的index
     */
    int head = 0, tail = 0;
    /**
     * 表示数组当前的长度。
     * 为了使用位运算来实现取模功能，这里的size必须为2的次幂（参考hashMap的做法提高性能）
     */
    int arraySize = INIT_SIZE;

public:
    ArrayQueue();

    ArrayQueue(int size);

    ~ArrayQueue();

    bool add(E e);

    /**
     * 返回最先入队的元素
     * @return
     */
    E peek();

    E poll();

    bool isEmpty();

    /**
     * 将数组的长度初始化为大于size的最小2次幂数（如size为3，则arraySize为4）
     */
    void initArraySize(int size);

    /**
     * 数组扩容
     */
    void growArray();

    /**
     * 将srcArray中从startSrc位置开始赋值len个元素到dstArray从startDst位置开始
     * @tparam E
     * @tparam E
     * @param srcArray 源数组
     * @param dstArray 目标数组
     * @param startSrc 源数组开始索引
     * @param startDst 目标数组开始索引
     * @param len 复制元素长度
     */
    void copyElements(E *srcArray, E *dstArray, int startSrc, int startDst, int len);
};

template<class E>
bool ArrayQueue<E>::add(E e) {
    if (arraySize >= MAXIMUM_CAPACITY) {
        return false;
    }
    array[tail] = e;
    tail = (tail + 1) & (arraySize - 1);
    LOGD("arrayQueue add head:%d,tail:%d,arraySize:%d", head, tail, arraySize);
    if (head == tail) {
        growArray();
    }

    return true;
}

template<class E>
E ArrayQueue<E>::peek() {
    assert(array != NULL);
    return array[head];
}

template<class E>
E ArrayQueue<E>::poll() {
    assert(array != NULL);
    E e = array[head];
    head = (head + 1) & (arraySize - 1);
    LOGD("arrayQueue poll head:%d,tail:%d,arraySize:%d", head, tail, arraySize);
    return e;
}

template<class E>
ArrayQueue<E>::ArrayQueue() {
    LOGD("arrayQueue ArrayQueue ");
    array = (E *) malloc(arraySize * sizeof(E));
}

template<class E>
ArrayQueue<E>::~ArrayQueue() {
    delete array;
}

template<class E>
ArrayQueue<E>::ArrayQueue(int size) {
    LOGD("arrayQueue ArrayQueue size:%d", size);
    initArraySize(size);
    LOGD("arrayQueue ArrayQueue head:%d,tail:%d,arraySize:%d", head, tail, arraySize);
    array = (E *) malloc(arraySize * sizeof(E));
}

template<class E>
void ArrayQueue<E>::initArraySize(int size) {
    int n = size - 1;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    if (n < 0) {
        arraySize = 1;
    } else if (n >= MAXIMUM_CAPACITY) {
        arraySize = MAXIMUM_CAPACITY;
    } else {
        arraySize = n + 1;
    }
}

template<class E>
bool ArrayQueue<E>::isEmpty() {
    return head == tail;
}

template<class E>
void ArrayQueue<E>::growArray() {
    LOGD("arrayQueue growArray");
    int newSize = arraySize << 1;

    E *newArray = (E *) malloc(newSize * sizeof(E));

    copyElements(array, newArray, tail, 0, arraySize - tail);
    copyElements(array, newArray, 0, arraySize - tail, tail);

    delete array;
    array = newArray;
    head = 0;
    tail = arraySize;
    arraySize = newSize;

    LOGD("arrayQueue growArray head:%d,tail:%d,arraySize:%d", head, tail, arraySize);
}

template<class E>
void ArrayQueue<E>::copyElements(E *srcArray, E *dstArray, int startSrc, int startDst, int len) {
    for (int i = 0; i < len; ++i) {
        dstArray[startDst + i] = srcArray[startSrc + i];
    }
}


#endif //DATASTRUCTURESAMPLE_ARRAYQUEUE_HPP
