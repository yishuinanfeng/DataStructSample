//
// Created by yanyinan on 2020/2/5.
//

#ifndef DATASTRUCTURESAMPLE_BINARYTREE_HPP
#define DATASTRUCTURESAMPLE_BINARYTREE_HPP

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,"BinaryTree",__VA_ARGS__)

template<class E>
class TreeNode {
public:
    E e;
    TreeNode<E> *leftNode = NULL;
    TreeNode<E> *rightNode = NULL;

    TreeNode(E e, TreeNode<E> *leftNode, TreeNode<E> *rightNode);

    TreeNode(E e);
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
class BinaryTree {
public:
    /**
     * 前序遍历
     * @param tree 树的根节点
     * @param visit 访问节点函数指针
     */
    void preOrderTravel(TreeNode<E> *tree, void (*visit)(const E e));
    /**
     * 中序遍历
     * @param tree 树的根节点
     * @param visit 访问节点函数指针
     */
    void inOrderTravel(TreeNode<E> *tree, void (*visit)(const E e));
    /**
     * 后序遍历
     * @param tree 树的根节点
     * @param visit 访问节点函数指针
     */
    void postOrderTravel(TreeNode<E> *tree, void (*visit)(const E e));

};

template<class E>
void BinaryTree<E>::preOrderTravel(TreeNode<E> *tree, void (*visit)(const E)) {
    if (tree == NULL) {
        return;
    }

    visit(tree->e);
    preOrderTravel(tree->leftNode, visit);
    preOrderTravel(tree->rightNode, visit);
}

template<class E>
void BinaryTree<E>::inOrderTravel(TreeNode<E> *tree, void (*visit)(const E)) {
    if (tree == NULL) {
        return;
    }

    inOrderTravel(tree->leftNode, visit);
    visit(tree->e);
    inOrderTravel(tree->rightNode, visit);
}

template<class E>
void BinaryTree<E>::postOrderTravel(TreeNode<E> *tree, void (*visit)(const E)) {
    if (tree == NULL) {
        return;
    }

    postOrderTravel(tree->leftNode, visit);
    postOrderTravel(tree->rightNode, visit);
    visit(tree->e);
}


#endif //DATASTRUCTURESAMPLE_BINARYTREE_HPP
