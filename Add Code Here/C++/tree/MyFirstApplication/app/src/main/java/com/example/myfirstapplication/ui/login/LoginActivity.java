package com.example.myfirstapplication.ui.login;

import android.app.Activity;

import androidx.lifecycle.Observer;
import androidx.lifecycle.ViewModelProviders;

import android.content.Intent;
import android.os.Bundle;

import androidx.annotation.Nullable;
import androidx.annotation.StringRes;
import androidx.appcompat.app.AppCompatActivity;

import android.text.Editable;
import android.text.TextWatcher;
import android.view.KeyEvent;
import android.view.View;
import android.view.inputmethod.EditorInfo;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import com.example.myfirstapplication.InfoActivity;
import com.example.myfirstapplication.R;
import com.example.myfirstapplication.ui.login.LoginViewModel;
import com.example.myfirstapplication.ui.login.LoginViewModelFactory;

public class LoginActivity extends AppCompatActivity {

    private LoginViewModel loginViewModel;
    EditText email;
    EditText password;
    String originalEmail;
    String originalPassword;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        email=(EditText)findViewById(R.id.username);
        password=(EditText)findViewById(R.id.password);
        Intent signupCall=getIntent();
        originalEmail=signupCall.getStringExtra("originalEmail");
        originalPassword=signupCall.getStringExtra("originalPassword");

    }

    public void info(View view) {
        if(email.getText().toString().trim().equals(originalEmail)&&(password.getText().toString().trim().equals(originalPassword))){
            Intent callInfo=new Intent(getApplicationContext(), InfoActivity.class);
            callInfo.putExtra("Email",email.getText().toString().trim());
            startActivity(callInfo);
        }
    }
}