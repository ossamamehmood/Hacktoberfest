package com.example.myfirstapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.widget.EditText;
import android.widget.TextView;

public class InfoActivity extends AppCompatActivity {

    TextView email;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_info);
        email=(TextView)findViewById(R.id.textView2);
        //getting data from login activity
        Intent loginCall=getIntent();
        String displayEmail=loginCall.getStringExtra("Email");
        //displaying it on this activity
        email.setText(displayEmail);
    }
}