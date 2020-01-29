//
// Created by yanyinan on 2020/1/29.
//

#ifndef DATASTRUCTURESAMPLE_LINKEDSTACK_HPP
#define DATASTRUCTURESAMPLE_LINKEDSTACK_HPP

#include "../LinkedList/LinkedList.hpp"

/**
 * 表示一个元素节点
 * @tparam E
 */
template<class E>
class StackNode {
public:
    StackNode *pre;
    E value;

    StackNode(E value, StackNode *pre);
};

template<class E>
StackNode<E>::StackNode(E value, StackNode *pre) {
    this->value = value;
    this->pre = pre;
}

/**
 * 用链表实现栈
 * @tparam E
 */
template<class E>
class LinkedStack {
private:
    /**
     * 栈顶节点
     */
    StackNode<E> *top = NULL;

public:
    LinkedStack();

    ~LinkedStack();

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

};

template<class E>
LinkedStack<E>::LinkedStack() {

}

template<class E>
LinkedStack<E>::~LinkedStack() {
    while (top) {
        top = top->pre;
        StackNode<E> *t = top;
        delete t;
    }
}

template<class E>
bool LinkedStack<E>::isEmpty() {
    return top == NULL;
}

template<class E>
E LinkedStack<E>::peek() {
    assert(top != NULL);
    return top->value;
}

template<class E>
E LinkedStack<E>::pop() {
    assert(top != NULL);
    StackNode<E> *node = top;
    top = node->pre;
    return node->value;
}

template<class E>
void LinkedStack<E>::push(E e) {
    top = new StackNode<E>(e, top);
}


#endif //DATASTRUCTURESAMPLE_LINKEDSTACK_HPP
