//
// Created by yanyinan on 2019/12/28.
//

#ifndef DATASTRUCTURESAMPLE_LINKEDLIST_HPP
#define DATASTRUCTURESAMPLE_LINKEDLIST_HPP

#include <assert.h>
#include <stddef.h>

template<class E>
struct Node {
    Node<E> *next;
    E value;

public:
    Node(E e, Node<E> *next);
};

template<class E>
Node<E>::Node(E e, Node<E> *next) {
    this->value = e;
    this->next = next;
}

template<class E>
class LinkedList {
    Node<E> *head;

    ~LinkedList();

    int length;

public:
    void push(E e);

    Node<E> *getLastNode() const;

    Node<E> *getNodeByIndex(int index);

    int size();

    Node<E> *get(int index);
};

template<class E>
LinkedList<E>::~LinkedList() {

}

template<class E>
void LinkedList<E>::push(E e) {
    Node<E> *newNode = new Node<E>(e, NULL);
    if (head) {
        Node<E> *lastNode = getLastNode();
        lastNode->next = newNode;
    } else {
        head = newNode;
    }

    length++;
}

template<class E>
Node<E> *LinkedList<E>::getLastNode() const {
    Node<E> *h = head;
    while (h) {
        if (h->next == NULL) {
            break;
        }
        h = h->next;
    }
    return h;
}

template<class E>
Node<E> *LinkedList<E>::getNodeByIndex(int index) {
    Node<E> *h = head;
    for (int i = 0; i < index; ++i) {
        h = h->next;
    }
    return h;
}

template<class E>
int LinkedList<E>::size() {
    return length;
}

template<class E>
Node<E> *LinkedList<E>::get(int index) {
    assert(index >= 0 & index < length);
    return getNodeByIndex(index);
}


#endif //DATASTRUCTURESAMPLE_LINKEDLIST_HPP
