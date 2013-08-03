package com.example.home_auto;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;

public class Home_Auto extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home__auto);
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.home__auto, menu);
        return true;
    }
    
}
