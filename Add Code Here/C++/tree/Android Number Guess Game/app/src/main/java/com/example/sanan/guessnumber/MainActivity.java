package com.example.sanan.guessnumber;

import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.Random;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        Button RollButton = findViewById(R.id.RollButton);
        final ImageView DiceImage = findViewById(R.id.diceImage);
        final TextView Message = findViewById(R.id.Message);

        final int[] DiceImages = {

                R.drawable.dice_one ,
                R.drawable.dice_two ,
                R.drawable.dice_three ,
                R.drawable.dice_four ,
                R.drawable.dice_five ,
                R.drawable.dice_six
        };

        RollButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                EditText Number = findViewById(R.id.EnterNumber);
                int min = 1;
                int max = 6;
                int RandomNumber = new Random().nextInt(max - min + 1) + min;
                String NumberText = Integer.toString(RandomNumber);




                if(Number.getText().toString().isEmpty()){
                    Message.setTextColor(Color.RED);
                    Message.setText("Please Enter a Number");
                }




                else {

                    int a  = Integer.parseInt(Number.getText().toString());

                    if(a>0 && a<7){
                        // Message.setText("Random Number is  "+RandomNumber);

                        DiceImage.setImageResource(DiceImages[(RandomNumber-1)]);

                        if(Number.getText().toString().equals(NumberText)){
                            Message.setText("Congratulations! You Won!");
                             Message.setTextColor(Color.GREEN);
                            Number.setText("");

                        }
                        else {
                            Message.setText("Sorry! You Lose. Try Again.");
                            Message.setTextColor(Color.RED);
                            Number.setText("");
                        }
                    }
                    else{
                        Message.setTextColor(Color.RED);
                        Message.setText("Please Enter a Valid Number");
                    }



                }




//
//                else if(Number.getText().toString().equals("1")){
//
//
//                }
//                else if(Number.getText().toString().equals("2")){
//
//                }
//                else if(Number.getText().toString().equals("3")){
//
//                }
//                else if(Number.getText().toString().equals("4")){
//
//                }
//                else if(Number.getText().toString().equals("5")){
//
//                }
//                else if(Number.getText().toString().equals("6")){
//
//                }
            }
        });



    }
}







