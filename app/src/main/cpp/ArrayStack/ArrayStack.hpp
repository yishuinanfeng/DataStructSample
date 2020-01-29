//
// Created by yanyinan on 2020/1/29.
//

#ifndef DATASTRUCTURESAMPLE_ARRAYSTACK_HPP
#define DATASTRUCTURESAMPLE_ARRAYSTACK_HPP

#include <malloc.h>
#include <assert.h>

/**
 * 数组实现的栈
 */
template<class E>
class ArrayStack {
private:
    /**
     * 栈顶指针
     */
    int top = -1;
    E *array = NULL;
    /**
     * 初始长度
     */
    size_t size = 10;

public:
    ArrayStack();

    ~ArrayStack();

    /**
     * 是否为空
     * @return
     */
    bool isEmpty();

    /**
     * 获取栈顶元素
     * @return
     */
    E peek();

    /**
     * 弹出栈顶元素
     * @return
     */
    E pop();

    /**
     * 入栈
     * @param e
     */
    void push(E e);

    void growArray();
};

template<class E>
ArrayStack<E>::ArrayStack() {
    array = (E *) malloc(sizeof(E) * size);
}

template<class E>
ArrayStack<E>::~ArrayStack() {
    delete array;
}

template<class E>
bool ArrayStack<E>::isEmpty() {
    return top == -1;
}

template<class E>
E ArrayStack<E>::peek() {
    assert(top >= 0);
    return array[top];
}

template<class E>
E ArrayStack<E>::pop() {
    assert(top >= 0);
    return array[top--];
}

template<class E>
void ArrayStack<E>::push(E e) {
    if (top + 1 == size) {
        growArray();
    }

    array[++top] = e;
}

template<class E>
void ArrayStack<E>::growArray() {
    size += size >> 1;
    //开辟一段新的内存，将原来内存数据从头到尾拷贝到新的内存中，并将指向array新的内存地址
    array = (E *) realloc(array, size * sizeof(E));
}


#endif //DATASTRUCTURESAMPLE_ARRAYSTACK_HPP
