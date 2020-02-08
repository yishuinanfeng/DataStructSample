#include <jni.h>
#include <string>
#include "ArrayList/ArrayList.hpp"
#include "LinkedList/LinkedList.hpp"
#include "BubbleSort/BubbleSort.h"
#include "SelectSort/SelectSort.h"
#include "InsertSort/InsertSort.h"
#include "ShellSort/ShellSort.h"
#include "MergeSort/MergeSort.h"
#include "FastSort/FastSort.h"
#include "ArrayStack/ArrayStack.hpp"
#include "LinkedStack/LinkedStack.hpp"
#include "ArrayQueue/ArrayQueue.hpp"
#include "BinaryOperation/BinaryOperation.h"
#include "BinaryTree/BinaryTree.hpp"
#include "PriorityQueue/PriorityQueue.hpp"
#include "HeapSort/HeapSort.h"

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,"DataStructure",__VA_ARGS__)

void visitNode(const int data) {
    __android_log_print(ANDROID_LOG_ERROR, "BinaryTree", "%d", data);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_haha_datastructuresample_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    //---------------------ArrayList-----------------
//    auto *list = new ArrayList<int>();
//
//    for (int i = 0; i < 100; ++i) {
//        list->add(i);
//    }

    //  list->remove(10);

//    for (int i = 0; i < list->size(); ++i) {
//        LOGD("arr factor:%d", list->get(i));
//    }
//
//    delete (list);
//---------------------ArrayList-----------------

//-------------------LinkedList----------------------------
//    auto *list = new LinkedList<int>();
//
//    list->addLast(2);
//    list->addLast(3);
//    list->addLast(4);
//    list->addLast(6);
//
//    list->insert(0, 100);
//
//    list->remove(0);
//    //  LOGD("list->size():%d", list->size());
//    list->remove(list->size() - 1);
//    list->addLast(9);
//
//    list->insert(list->size(), 200);

    // LOGD("list get 3:%d", list->get(3)->value);

//    for (int i = 0; i < list->size(); ++i) {
//        LOGD("list(%d):%d", i, list->get(i)->value);
//    }
//-------------------LinkedList----------------------------

// -----------------------BubbleSort------------------------------
//    int a[] = {2, 5, 3, 8, 1, 4, 0, 6};
//    BubbleSort *bubbleSort = new BubbleSort();
//    bubbleSort->sort2(a, 8);
//
//    for (int i = 0; i < 8; ++i) {
//        LOGD("arr factor:%d", a[i]);
//    }

    // -----------------------BubbleSort------------------------------
    //
    // -----------------------SelectSort------------------------------
//    int a[] = {2, 5, 3, 8, 1, 4, 0, 6};
//    SelectSort* selectSort = new SelectSort();
//    selectSort->sort(a,8);
//
//    for (int i = 0; i < 8; ++i) {
//        LOGD("arr factor:%d", a[i]);
//    }

    // -----------------------SelectSort------------------------------


    // -----------------------InsertSort------------------------------
//    int a[] = {2, 5, 3, 8, 1, 4, 0, 6};
//
//
//    InsertSort *insertSort = new InsertSort();
//    insertSort->sort(a, 8);
//        for (int i = 0; i < 8; ++i) {
//        LOGD("arr factor:%d", a[i]);
//    }
//    // -----------------------InsertSort------------------------------


//    // -----------------------ShellSort------------------------------
//    LOGD("ShellSort start");
//
//    int a[] = {2, 5, 3, 8, 1, 4, 0, 6};
//    ShellSort *pShellSort = new ShellSort();
//    pShellSort->sort(a, 8);
//    for (int i = 0; i < 8; ++i) {
//        LOGD("arr factor:%d", a[i]);
//    }
//
//    LOGD("ShellSort end");

//    // -----------------------ShellSort------------------------------

// -----------------------MergeSort------------------------------

//    LOGD("MergeSort start");
//
//    int a[] = {2, 5, 3, 8, 1, 4, 0, 6};
//    MergeSort *mergeSort = new MergeSort();
//    mergeSort->sort1(a, 8);
//
//    for (int i = 0; i < 8; ++i) {
//        LOGD("arr factor:%d", a[i]);
//    }

    // -----------------------MergeSort------------------------------
    //
    // -----------------------FastSort------------------------------

//    LOGD("FastSort start");
//
//    int a[] = {2, 5, 3, 8, 1, 4, 0, 6};
//    FastSort *pFastSort = new FastSort();
//    pFastSort->sort1(a, 8);
//
//    for (int i = 0; i < 8; ++i) {
//        LOGD("arr factor:%d", a[i]);
//    }

    // -----------------------FastSort------------------------------

    //--------------------------ArrayStack-----------------------------

    //   auto *arrayStack = new ArrayStack<int>();
    //--------------------------ArrayStack-----------------------------


    // -----------------------LinkedStack------------------------------
    //  auto *pLinkedStack = new LinkedStack<int>();

//    pLinkedStack->pop();
//    pLinkedStack->peek();

//    for (int i = 0; i < 20; ++i) {
//        pLinkedStack->push(i);
//    }
//
//    LOGD("arrayStack factor:%d", pLinkedStack->peek());
//
//    while (!pLinkedStack->isEmpty()) {
//        LOGD("arrayStack factor:%d", pLinkedStack->pop());
//    }
//
//    for (int i = 0; i < 5; ++i) {
//        pLinkedStack->push(i);
//    }
//
//    LOGD("arrayStack factor:%d", pLinkedStack->pop());
//    while (!pLinkedStack->isEmpty()) {
//        LOGD("arrayStack factor:%d", pLinkedStack->pop());
//    }
//
//    delete pLinkedStack;

    // -----------------------LinkedStack------------------------------


    // -----------------------ArrayQueue------------------------------
//    LOGD("arrayQueue start");
//    auto *arrayQueue = new ArrayQueue<int>();
//
//    for (int i = 0; i < 10; ++i) {
//        LOGD("arrayQueue gonna add");
//        arrayQueue->add(i);
//    }
//
//    LOGD("arrayQueue->peek():%d", arrayQueue->peek());
//
//    while (!arrayQueue->isEmpty()) {
//        //  arrayQueue->peek();
//        LOGD("arrayQueue->poll():%d", arrayQueue->poll());
//    }

    // -----------------------ArrayQueue------------------------------


    // -----------------------BinaryOperation------------------------------
    //  BinaryOperation *binaryOperation = new BinaryOperation();
    //1101
    // int a[] = {1,1,0,1};
    //  binaryOperation->binaryToDecimal(a, 4);
    //   binaryOperation->decimalToBinary1(13);
    // -----------------------BinaryOperation------------------------------

    // -----------------------BinaryTree------------------------------
//    auto *treeNode1 = new TreeNode<int>(1);
//
//    auto *treeNode2 = new TreeNode<int>(2);
//    auto *treeNode3 = new TreeNode<int>(3);
//    auto *treeNode4 = new TreeNode<int>(4);
//    auto *treeNode5 = new TreeNode<int>(5);
//    auto *treeNode6 = new TreeNode<int>(6);
//    auto *treeNode7 = new TreeNode<int>(7);
//    auto *treeNode8 = new TreeNode<int>(8);



//
//    treeNode1->leftNode = treeNode2;
//    treeNode1->rightNode = treeNode3;
//
    // treeNode2->leftNode = treeNode4;
    //treeNode2->rightNode = treeNode5;

//    treeNode3->leftNode = treeNode6;
//    treeNode3->rightNode = treeNode7;
//
//    treeNode4->leftNode = treeNode8;
//    treeNode7->rightNode = treeNode5;
////
//    auto *binaryTree = new BinaryTree<int>();
//    binaryTree->freeTree(treeNode1);
//
//    bool isBalanced = binaryTree->isBalanceTree(treeNode1);
//    LOGD("binaryTree isBalanced:%d", isBalanced);

    //  int height = binaryTree->getTreeHeight(treeNode1);
    //  LOGD("binaryTree height:%d", height);


    // -----------------------BinaryTree------------------------------


    // -----------------------PriorityQueue------------------------------

//    auto *priorityQueue = new PriorityQueue<int>();
//    priorityQueue->offer(1);
//    priorityQueue->offer(2);
//    priorityQueue->offer(3);
//    priorityQueue->offer(4);
//    priorityQueue->offer(5);
//    priorityQueue->offer(6);
//    priorityQueue->offer(7);
//    priorityQueue->offer(8);
//    priorityQueue->offer(9);
//    priorityQueue->offer(10);
//    priorityQueue->offer(11);
    //  priorityQueue->poll();
//    priorityQueue->poll();
//    for (int i = 0; i < priorityQueue->size(); ++i) {
//        LOGD("priorityQueue factor:%d", priorityQueue->poll());
//    }
//    while (!priorityQueue->isEmpty()) {
//        LOGD_PriorityQueue("priorityQueue factor:%d,size:%d", priorityQueue->poll(),
//                           priorityQueue->size());
//    }
//
//    delete priorityQueue;
    // priorityQueue->printArray();
    // -----------------------PriorityQueue------------------------------


    // -----------------------HeapSort------------------------------
    int a[] = {2, 5, 3, 7, 1, 4, 0, 6};
    auto *heapSort = new HeapSort();
    heapSort->sort(a, 8);

    for (int i = 0; i < 8; ++i) {
        LOGD("arr factor:%d", a[i]);
    }

    // -----------------------HeapSort------------------------------



    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


