package com.soul.jnidemo;

import android.graphics.Bitmap;
import android.widget.SimpleCursorTreeAdapter;

/**
 * @描述：TODO
 * @作者：祝明
 * @项目名:JniDemo
 * @创建时间：2018/12/18 18:20
 */
public class BlurUtil {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public static native Bitmap blur(Bitmap bitmap, int radius);
}
