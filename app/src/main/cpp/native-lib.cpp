#include <jni.h>
#include <string>
#include "ArrayList/ArrayList.hpp"

extern "C" JNIEXPORT jstring JNICALL
Java_com_haha_datastructuresample_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    auto *list = new ArrayList<int>();

    for (int i = 0; i < 100; ++i) {
        list->add(i);
    }

    delete(list);

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
