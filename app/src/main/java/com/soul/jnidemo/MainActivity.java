package com.soul.jnidemo;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {


    private ImageView mImBlur;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Resources res = getResources();
        mImBlur = findViewById(R.id.iv_blur);
        findViewById(R.id.bt_blur).setOnClickListener(view -> {
            Bitmap bitmap = BitmapFactory.decodeResource(res, R.drawable.picture);
            mImBlur.setImageBitmap(BlurUtil.blur(bitmap,10));
        });
    }


}
