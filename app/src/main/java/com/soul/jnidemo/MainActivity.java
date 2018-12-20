package com.soul.jnidemo;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {


    private ImageView mImBlur;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Resources res = getResources();
        mImBlur = findViewById(R.id.iv_blur);
        TextView textView = findViewById(R.id.tv);
        findViewById(R.id.bt_blur).setOnClickListener(view -> {
            Bitmap bitmap = BitmapFactory.decodeResource(res, R.drawable.picture);
            BlurUtil.blur(bitmap, 40);
            mImBlur.setImageBitmap(bitmap);
            //            textView.setText(BlurUtil.blur("fasd", 0));

        });


    }


}
