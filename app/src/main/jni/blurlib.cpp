//
// Created by soul on 2018/12/19.
//
#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <android/log.h>
#include <android/bitmap.h>
#include "stackblur.c"


#ifndef _Included_com_soul_jnidemo_BlurUtil
#define _Included_com_soul_jnidemo_BlurUtil
#ifdef __cplusplus


#define TAG "com_soul_blur"
#define LOG_D(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__)

extern "C" {
#endif
/*
 * Class:     com_soul_jnidemo_BlurUtil
 * Method:    blur
 * Signature: (Ljava/lang/Object;I)Ljava/lang/String;
 */
JNIEXPORT void JNICALL Java_com_soul_jnidemo_BlurUtil_blur
        (JNIEnv *env, jclass obj, jobject bitmapIn, jint r) {

    AndroidBitmapInfo infoIn;
    void *pixels;

//    Get image info
    if (AndroidBitmap_getInfo(env, bitmapIn, &infoIn) != ANDROID_BITMAP_RESULT_SUCCESS) {
        LOG_D("AndroidBitmap_getInfo failed!");
        return;
    }

    // Check image
    if (infoIn.format != ANDROID_BITMAP_FORMAT_RGBA_8888 &&
        infoIn.format != ANDROID_BITMAP_FORMAT_RGB_565) {
        LOG_D("Only support ANDROID_BITMAP_FORMAT_RGBA_8888 and ANDROID_BITMAP_FORMAT_RGB_565");
        return;
    }

    // Lock all images
    if (AndroidBitmap_lockPixels(env, bitmapIn, &pixels) != ANDROID_BITMAP_RESULT_SUCCESS) {
        LOG_D("AndroidBitmap_lockPixels failed!");
        return;
    }
    // height width
    int h = infoIn.height;
    int w = infoIn.width;

    // Start
    if (infoIn.format == ANDROID_BITMAP_FORMAT_RGBA_8888) {
        pixels = blur_ARGB_8888((int *) pixels, w, h, r);
    } else if (infoIn.format == ANDROID_BITMAP_FORMAT_RGB_565) {
        pixels = blur_RGB_565((short *) pixels, w, h, r);
    }

    // End

    // Unlocks everything
    AndroidBitmap_unlockPixels(env, bitmapIn);


}

#ifdef __cplusplus
}
#endif
#endif











