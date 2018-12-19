#include <jni.h>
#include <string>
#include <android/bitmap.h>

extern "C" JNIEXPORT jstring

JNICALL
Java_com_soul_jnidemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


