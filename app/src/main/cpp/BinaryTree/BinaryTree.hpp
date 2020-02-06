//
// Created by yanyinan on 2020/2/5.
//

#ifndef DATASTRUCTURESAMPLE_BINARYTREE_HPP
#define DATASTRUCTURESAMPLE_BINARYTREE_HPP


#include<cmath>

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

    /**
     * 求二叉树高度
     * @param tree 树的根节点
     * @return
     */
    int getTreeHeight(TreeNode<E> *tree);

    /**
     * 是否是平衡二叉树
     * @param tree 树的根节点
     * @return
     */
    bool isBalanceTree(TreeNode<E> *tree);

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

template<class E>
int BinaryTree<E>::getTreeHeight(TreeNode<E> *tree) {
    if (tree == NULL) {
        return 0;
    }
    int leftHeight = getTreeHeight(tree->leftNode);
    int rightHeight = getTreeHeight(tree->rightNode);
    //左边和右边的高度加上自己
    return fmax(leftHeight, rightHeight) + 1;
}

template<class E>
bool BinaryTree<E>::isBalanceTree(TreeNode<E> *tree) {
    if (tree == NULL) {
        return true;
    }
    int leftHeight = getTreeHeight(tree->leftNode);
    LOGD("getTreeHeight leftHeight：%d",leftHeight);
    int rightHeight = getTreeHeight(tree->rightNode);
    LOGD("getTreeHeight rightHeight：%d",rightHeight);
    //左右子树高度差是否不大于1
    bool isHeightDifferenceSatisfied = fabs(leftHeight - rightHeight) <= 1;
    LOGD("isHeightDifferenceSatisfied：%d",isHeightDifferenceSatisfied);
    if (!isHeightDifferenceSatisfied) {
        //左右子树高度差大于1则不是平衡二叉树
        return false;
    }
    //左右子树是否是平衡二叉树
    bool isLeftBalanced = isBalanceTree(tree->leftNode);
    bool isRightBalanced = isBalanceTree(tree->rightNode);
    return isLeftBalanced && isRightBalanced;
}


#endif //DATASTRUCTURESAMPLE_BINARYTREE_HPP
