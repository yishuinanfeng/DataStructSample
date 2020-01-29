//
// Created by yanxi on 2019/12/22.
//

#ifndef DATASTRUCTURESAMPLE_ARRAYLIST_HPP
#define DATASTRUCTURESAMPLE_ARRAYLIST_HPP

#include <string.h>
#include <android/log.h>

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,"DataStructure",__VA_ARGS__)

//声明
//todo 1.有崩溃bug  2.remove方法
/**
 * 一个用c++仿写的ArrayList
 * @tparam E
 */
template<class E>
class ArrayList {
private:
    E *array;//数组指针
    int length;//数组长度
    int index = 0;//当前角标,也可以理解为当前有效数据的个数

public:

    ArrayList();

    ArrayList(int len);

    ~ArrayList();

    void add(E e);

    E remove(int index);

    E get(int index);

    int size();

    void ensureCapacityInternal(int capacity);

    void grow(int capacity);
};


//实现
template<class E>
ArrayList<E>::ArrayList() {

}

template<class E>
ArrayList<E>::ArrayList(int len) {
    if (len == 0) {
        return;
    }

    this->length = len;
    array = malloc(sizeof(E) * len);
}

template<class E>
ArrayList<E>::~ArrayList() {

}

template<class E>
void ArrayList<E>::ensureCapacityInternal(int capacity) {
    //没有指定len的构造方法创建ArrayList?
    if (array == NULL) {
        capacity = 10;
    }

    if (capacity > length) {
        grow(capacity);
    }
}

template<class E>
void ArrayList<E>::add(E e) {
    ensureCapacityInternal(index + 1);  // Increments modCount!!
    array[index++] = e;
    LOGD("add index:%d", index);
}

template<class E>
E ArrayList<E>::remove(int index) {
    E e = array[index];
    //index之后的元素进行往前挪动一位（这里只需要挪动到最后一个有效元素即可）
    for (int i = index; i < this->index - 1; ++i) {
        array[i] = array[i + 1];
    }
    this->index -= 1;
    return e;
}

template<class E>
E ArrayList<E>::get(int index) {
    return array[index];
}

template<class E>
int ArrayList<E>::size() {
    return index;
}

template<class E>
void ArrayList<E>::grow(int capacity) {
    //扩容1.5倍
    int newLength = length + (length >> 1);
    LOGD("grow length:%d,newLength:%d", length, newLength);
    //todo 什么时候条件会成立？
    if (capacity > newLength) {
        newLength = capacity;
    }

    E *newArray = (E *) malloc(sizeof(E) * newLength);
    //以下操作和realloc功能相同
    if (array) {
        memcpy(newArray, array, sizeof(E) * index);
        free(array);
    }

    array = newArray;
    length = newLength;

    LOGD("grow index:%d,length:%d", index, length);

}


#endif //DATASTRUCTURESAMPLE_ARRAYLIST_HPP
