//
// Created by yanyinan on 2020/2/9.
//

#ifndef DATASTRUCTURESAMPLE_BINARYSEARCHTREE_HPP
#define DATASTRUCTURESAMPLE_BINARYSEARCHTREE_HPP

#define LOGD_BinarySearchTree(...) __android_log_print(ANDROID_LOG_DEBUG,"BinarySearchTree",__VA_ARGS__)

/**
 * 二叉查找树节点(键值对)
 * @tparam K 键
 * @tparam V 值
 */
template<class K, class V>
class STreeNode {
public:
    K key = NULL;
    V value = NULL;
    STreeNode<K, V> *leftNode = NULL;
    STreeNode<K, V> *rightNode = NULL;

    STreeNode(K key, V value, STreeNode<K, V> *leftNode, STreeNode<K, V> *rightNode);

    STreeNode(K key, V value);

    ~STreeNode();

    /**
     * 释放以当前节点为根节点的树
     */
    void freeTree();

};

template<class K, class V>
STreeNode<K, V>::STreeNode(K key, V value, STreeNode<K, V> *leftNode, STreeNode<K, V> *rightNode) {
    this->key = key;
    this->value = value;
    this->leftNode = leftNode;
    this->rightNode = rightNode;
}

template<class K, class V>
STreeNode<K, V>::STreeNode(K key, V value) {
    this->key = key;
    this->value = value;
}

template<class K, class V>
STreeNode<K, V>::~STreeNode() {

}

template<class K, class V>
void STreeNode<K, V>::freeTree() {

}

/**
 * 二叉搜索树
 * 键值对查找
 */
template<class K, class V>
class BinarySearchTree {

private:
    /**
     * 树的根节点
     */
    STreeNode<K, V> *rootNode = NULL;

    /**
     * 添加节点
     * @param treeNode 当前遍历到的节点
     * @param key
     * @param value
     * @return
     */
    STreeNode<K, V> *addNode(STreeNode<K, V> *treeNode, K key, V value);

    /**
    * 中序遍历
    * @param tree 树的根节点
    * @param visit 访问节点函数指针
    */
    void inOrderTravel(STreeNode<K, V> *tree, void (*visit)(const V value));

public:
    void put(K key, V value);

    bool remove(K key);

    bool search(K key);

    void printTree(void (*visit)(const V));

};

template<class K, class V>
void BinarySearchTree<K, V>::put(K key, V value) {
    rootNode = addNode(rootNode, key, value);
}

template<class K, class V>
bool BinarySearchTree<K, V>::remove(K key) {
    return false;
}

template<class K, class V>
bool BinarySearchTree<K, V>::search(K key) {
    return false;
}


template<class K, class V>
STreeNode<K, V> *BinarySearchTree<K, V>::addNode(STreeNode<K, V> *treeNode, K key, V value) {
    if (treeNode == NULL) {
        treeNode = new STreeNode<K, V>(key, value);
        LOGD_BinarySearchTree("treeNode == NULL new STreeNode");
        return treeNode;
    }
    //递归添加节点
    //如果key比当前节点的key小，则往左子树放。如果key比当前节点的key大，则往右子树放
    if (treeNode->key < key) {
        LOGD_BinarySearchTree("treeNode->key < key");
        treeNode->leftNode = addNode(treeNode->leftNode, key, value);
    } else if (treeNode->key > key) {
        LOGD_BinarySearchTree("treeNode->key > key");
        treeNode->rightNode = addNode(treeNode->rightNode, key, value);
    } else {
        //如果和当前节点value一样大，则替换当前节点value
        LOGD_BinarySearchTree("treeNode->value = value");
        treeNode->value = value;
    }

    return treeNode;
}

template<class K, class V>
void BinarySearchTree<K, V>::inOrderTravel(STreeNode<K, V> *tree, void (*visit)(const V)) {
    if (tree == NULL) {
        return;
    }

    inOrderTravel(tree->leftNode, visit);
    visit(tree->value);
    inOrderTravel(tree->rightNode, visit);
}

template<class K, class V>
void BinarySearchTree<K, V>::printTree(void (*visit)(const V)) {
    inOrderTravel(rootNode, visit);
}


#endif //DATASTRUCTURESAMPLE_BINARYSEARCHTREE_HPP
