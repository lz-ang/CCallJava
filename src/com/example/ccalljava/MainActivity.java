package com.example.ccalljava;

import android.os.Bundle;
import android.app.Activity;
import android.app.AlertDialog.Builder;
import android.view.Menu;
import android.view.View;

public class MainActivity extends Activity {
	
	static{
		System.loadLibrary("hello");
	}

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void click(View v){
    	helloC();
    }

    public native void helloC();
    
    
    public void show(String msg){
    	Builder builder = new Builder(this); //注意导包是android.app.AlertDialog.Builder;
    	builder.setTitle("提示！");
    	builder.setMessage(msg);
    	builder.show();
    }
}
