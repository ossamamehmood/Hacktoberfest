package com.example.myfirstapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.provider.ContactsContract;
import android.view.View;
import android.widget.EditText;

import com.example.myfirstapplication.ui.login.LoginActivity;

public class SignupActivity extends AppCompatActivity {

    EditText email;
    EditText password;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_signup);
        email=(EditText)findViewById(R.id.editTextTextEmailAddress);
        password=(EditText)findViewById(R.id.editTextTextPassword);
        Intent mainCall=getIntent();
    }

    public void signUp(View view) {
        if(email.getText().toString().trim().equals("abc")&&(password.getText().toString().trim().equals("abc"))){
            Intent callLogin=new Intent(getApplicationContext(), LoginActivity.class);
            callLogin.putExtra("originalEmail",email.getText().toString().trim());
            callLogin.putExtra("originalPassword",password.getText().toString().trim());
            startActivity(callLogin);
        }
    }
}