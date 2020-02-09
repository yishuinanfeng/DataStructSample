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

    int length = 0;

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

    /**
     * 递归搜索对应的节点
     * @param pNode
     * @return
     */
    STreeNode<K, V> *findNode(STreeNode<K, V> *pNode, K key);

    /**
     * 找到以rootNode为根节点的树的最小节点
     * @param treeNode
     * @return
     */
    STreeNode<K, V> *findMin(STreeNode<K, V> *treeNode);


public:
    void put(K key, V value);

    STreeNode<K, V> *remove(K key);

    V search(K key);

    void printTree(void (*visit)(const V));

    int size();

    STreeNode<K, V> *findMinNode();
};

template<class K, class V>
void BinarySearchTree<K, V>::put(K key, V value) {
    assert(key != NULL);
    assert(value != NULL);
    rootNode = addNode(rootNode, key, value);
    length++;
}

template<class K, class V>
STreeNode<K, V> *BinarySearchTree<K, V>::remove(K key) {
    STreeNode<K, V> *removeNode = rootNode;
    STreeNode<K, V> *parentNode = NULL;
    while (removeNode != NULL) {
        if (removeNode->key > key) {
            parentNode = removeNode;
            removeNode = removeNode->leftNode;
        } else if (removeNode->key < key) {
            parentNode = removeNode;
            removeNode = removeNode->rightNode;
        } else if (removeNode->key == key) {
            break;
        }
    }
    //没找到对应key的节点
    if (removeNode == NULL) {
        return NULL;
    }
    LOGD_BinarySearchTree("remove node key:%d,value:%c:", removeNode->key, removeNode->value);

    if (removeNode->leftNode != NULL && removeNode->rightNode != NULL) {
        //有左右2个节点
        //找到removeNode的右子树中的最小节点
        STreeNode<K, V> *node = removeNode->rightNode;
        STreeNode<K, V> *parent = parentNode;
        while (node->leftNode != NULL) {
            parent = node;
            node = node->leftNode;
        }

        LOGD_BinarySearchTree("smallest node key:%d,value:%c:", node->key, node->value);
        if (parent != NULL && node->rightNode != NULL) {
            parent->leftNode = node->rightNode;
        }
        removeNode->key = node->key;
        removeNode->value = node->value;
    } else {
        //被删节点最多一个子节点
        STreeNode<K, V> *child;
        if (removeNode->leftNode != NULL) {
            child = removeNode->leftNode;
        } else if (removeNode->rightNode != NULL) {
            child = removeNode->rightNode;
        } else {
            child = NULL;
        }

        if (removeNode == parentNode->leftNode) {
            parentNode->leftNode = child;
        } else if (removeNode == parentNode->rightNode) {
            parentNode->rightNode = child;
        }
    }
    length--;
    return NULL;
}

template<class K, class V>
V BinarySearchTree<K, V>::search(K key) {
    STreeNode<K, V> *treeNode = findNode(rootNode, key);
    if (treeNode == NULL) {
        return NULL;
    }

    return treeNode->value;
}

template<class K, class V>
STreeNode<K, V> *BinarySearchTree<K, V>::addNode(STreeNode<K, V> *treeNode, K key, V value) {
    if (treeNode == NULL) {
        LOGD_BinarySearchTree("treeNode == NULL new STreeNode");
        return new STreeNode<K, V>(key, value);
    }
    //递归添加节点
    //如果key比当前节点的key小，则往左子树放。如果key比当前节点的key大，则往右子树放
    if (treeNode->key > key) {
        treeNode->leftNode = addNode(treeNode->leftNode, key, value);
    } else if (treeNode->key < key) {
        treeNode->rightNode = addNode(treeNode->rightNode, key, value);
    } else {
        //如果和当前节点value一样大，则替换当前节点value
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

template<class K, class V>
STreeNode<K, V> *BinarySearchTree<K, V>::findNode(STreeNode<K, V> *pNode, K key) {
    if (pNode == NULL) {
        return NULL;
    }

    if (pNode->key > key) {
        return findNode(pNode->leftNode, key);
    } else if (pNode->key < key) {
        return findNode(pNode->rightNode, key);
    } else {
        return pNode;
    }

}

template<class K, class V>
int BinarySearchTree<K, V>::size() {
    return length;
}

template<class K, class V>
STreeNode<K, V> *BinarySearchTree<K, V>::findMin(STreeNode<K, V> *treeNode) {
    if (treeNode == NULL) {
        return NULL;
    }

    STreeNode<K, V> *node = findMin(treeNode->leftNode);
    if (node == NULL) {
        return treeNode;
    } else {
        return node;
    }
}

template<class K, class V>
STreeNode<K, V> *BinarySearchTree<K, V>::findMinNode() {
    return findMin(rootNode);
}


#endif //DATASTRUCTURESAMPLE_BINARYSEARCHTREE_HPP
