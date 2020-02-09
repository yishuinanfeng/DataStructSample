//
// Created by yanyinan on 2020/2/9.
//

#ifndef DATASTRUCTURESAMPLE_TREENODE_HPP
#define DATASTRUCTURESAMPLE_TREENODE_HPP

#define LOGD_TreeNode(...) __android_log_print(ANDROID_LOG_DEBUG,"BinaryTree",__VA_ARGS__)


template<class E>
class TreeNode {
public:
    E e;
    TreeNode<E> *leftNode = NULL;
    TreeNode<E> *rightNode = NULL;

    TreeNode(E e, TreeNode<E> *leftNode, TreeNode<E> *rightNode);

    TreeNode(E e);

    ~TreeNode();

    /**
     * 释放以当前节点为根节点的树
     */
    void freeTree();

};

template<class E>
TreeNode<E>::TreeNode(E e, TreeNode<E> *leftNode, TreeNode<E> *rightNode) {
    this->e = e;
    this->leftNode = leftNode;
    this->rightNode = rightNode;
}

template<class E>
TreeNode<E>::TreeNode(E e) {
    this->e = e;
}

template<class E>
TreeNode<E>::~TreeNode() {
    LOGD_TreeNode("free Node:%d", this->e);
}

template<class E>
void TreeNode<E>::freeTree() {
    //释放所有的节点(类似后序遍历方式)
    if (this->leftNode) {
        this->leftNode->freeTree();
    }

    if (this->rightNode) {
        this->rightNode->freeTree();
    }

    delete this;
}

#endif //DATASTRUCTURESAMPLE_TREENODE_HPP
