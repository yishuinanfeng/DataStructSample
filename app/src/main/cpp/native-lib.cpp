#include <jni.h>
#include <string>
#include "ArrayList/ArrayList.hpp"
#include "LinkedList/LinkedList.hpp"
#include "BubbleSort/BubbleSort.h"

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,"native_lib",__VA_ARGS__)

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
//
//    delete(list);


//-------------------LinkedList----------------------------
//    LinkedList<int> *list = new LinkedList<int>();
//
//    list->push(2);
//    list->push(3);
//    list->push(4);
//    list->push(6);
//
//
//    LOGD("list get(3:%d", list->get(3)->value);
//
//    for (int i = 0; i < list->size(); ++i) {
//        LOGD("list push:%d", list->get(i)->value);
//    }


// -----------------------BubbleSort------------------------------
    int a[] = {2, 5, 3, 8, 1, 4, 0, 6};
    BubbleSort *bubbleSort = new BubbleSort();
    bubbleSort->sort(a, 8);

    for (int i = 0; i < 8; ++i) {
        LOGD("arr factor:%d", a[i]);
    }

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
