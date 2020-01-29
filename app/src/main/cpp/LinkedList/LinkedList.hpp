//
// Created by yanyinan on 2019/12/28.
//

#ifndef DATASTRUCTURESAMPLE_LINKEDLIST_HPP
#define DATASTRUCTURESAMPLE_LINKEDLIST_HPP

#include <assert.h>
#include <stddef.h>
#include <android/log.h>

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,"DataStructure",__VA_ARGS__)


template<class E>
struct Node {
    Node<E> *next, *pre;
    E value;

public:
    Node(E e, Node<E> *pre, Node<E> *next);
};

template<class E>
Node<E>::Node(E e, Node<E> *pre, Node<E> *next) {
    this->value = e;
    this->pre = pre;
    this->next = next;
}

/**
 * 一个用c++仿写的LinkedList
 * @tparam E
 */
template<class E>
class LinkedList {
    Node<E> *head;
    Node<E> *last;

    ~LinkedList();

    //链表的长度
    int length;

public:
    void addLast(E e);

    void addFirst(E e);

    Node<E> *getLastNode() const;

    Node<E> *node(int index);

    int size();

    Node<E> *get(int index);

    void insert(int index, E e);

    void remove(int index);
};

template<class E>
LinkedList<E>::~LinkedList() {

}

template<class E>
void LinkedList<E>::addLast(E e) {
    Node<E> *last = this->last;
    Node<E> *newNode = new Node<E>(e, last, NULL);
    if (head) {
        last->next = newNode;
        this->last = newNode;
    } else {
        head = newNode;
        this->last = newNode;
    }

    length++;
}

template<class E>
void LinkedList<E>::addFirst(E e) {
    Node<E> *h = head;
    Node<E> *newNode = new Node<E>(e, NULL, h);
    if (head) {
        h->pre = newNode;
        head = newNode;
    } else {
        head = newNode;
        last = newNode;
    }

    length++;
}

template<class E>
Node<E> *LinkedList<E>::getLastNode() const {
    return last;
}

template<class E>
Node<E> *LinkedList<E>::node(int index) {
    if (index < (length >> 1)) {
        //index在链表前半部分，从head开始遍历
        Node<E> *h = head;
        for (int i = 0; i < index; ++i) {
            LOGD("getNodeByIndex i:%d，length：%d", i, length);
            h = h->next;
        }
        return h;
    } else {
        //index在链表后半部分，从last开始遍历
        Node<E> *l = last;
        for (int i = length - 1; i > index; --i) {
            LOGD("getNodeByIndex i:%d，length：%d", i, length);
            l = l->pre;
        }
        return l;
    }


}

template<class E>
int LinkedList<E>::size() {
    return length;
}

template<class E>
Node<E> *LinkedList<E>::get(int index) {
    LOGD("get index:%d,length:%d", index, length);
    assert(index >= 0 & index < length);
    return node(index);
}

template<class E>
void LinkedList<E>::insert(int index, E e) {
    LOGD("insert index:%d,length:%d", index, length);
    assert(index >= 0 && index <= length);
    if (index == 0) {
        Node<E> *headNode = head;
        Node<E> *newNode = new Node<E>(e, NULL, head);
        head = newNode;
        if (headNode != NULL) {
            headNode->pre = newNode;
        }

        length++;
    } else if (index == length) {
        addLast(e);
    } else {
        Node<E> *preNode = get(index - 1);
        Node<E> *nextNode = preNode->next;
        Node<E> *newNode = new Node<E>(e, preNode, nextNode);
        preNode->next = newNode;
        //因为不是插入到末尾，所以nextNode不会为NULL
        nextNode->pre = newNode;

        length++;
    }


}

template<class E>
void LinkedList<E>::remove(int index) {
    LOGD("remove index:%d,length:%d", index, length);
    assert(index >= 0 && index < length);
    if (index == 0) {
        Node<E> *h = head;
        head = h->next;
        //如果last就是head
        if (h == last) {
            last = NULL;
        }
        //记得释放内存
        delete h;
    } else if (index == length - 1) {
        Node<E> *l = last;
        Node<E> *pre = l->pre;
        pre->next = NULL;
        last = pre;
        delete l;
    } else {
        Node<E> *preNode = get(index - 1);
        LOGD("Node<E> *preNode = get(index - 1);");
        Node<E> *deleteNode = preNode->next;
        LOGD("Node<E> *deleteNode = preNode->next;");
        Node<E> *nextNode = deleteNode->next;
        LOGD(" Node<E> *nextNode = deleteNode->next;");
        preNode->next = nextNode;
        if (nextNode) {
            nextNode->pre = preNode;
        }
        delete deleteNode;
    }

    length--;
    LOGD("remove length:%d", length);
}


#endif //DATASTRUCTURESAMPLE_LINKEDLIST_HPP
