package com.virtual_pen;

import android.util.Log;
import android.view.MotionEvent;
import android.view.View;

import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.Locale;

public class TouchListener {
    private final FileOutputStream fileOutputStream;

    public TouchListener(FileOutputStream fileOutputStream) {
        this.fileOutputStream = fileOutputStream;
    }

    public View.OnTouchListener handleTouch = new View.OnTouchListener() {
        @Override
        public boolean onTouch(View v, MotionEvent event) {
            int x = (int) event.getX();
            int y = (int) event.getY();
            String inputString = String.format("%s,%s,%s,",
                    event.getAction(),
                    x,
                    y);
            try {
                fileOutputStream.write(inputString.getBytes(StandardCharsets.UTF_8));
            } catch (IOException e) {
                throw new RuntimeException(e);
            }

            return true;
        }
    };
}
