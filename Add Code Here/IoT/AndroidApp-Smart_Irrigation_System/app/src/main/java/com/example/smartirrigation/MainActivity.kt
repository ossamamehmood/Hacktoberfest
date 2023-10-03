package com.example.smartirrigation

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.text.Editable
import android.widget.TextView
import com.google.firebase.database.*

class MainActivity : AppCompatActivity() {

    private lateinit var database: DatabaseReference
    private lateinit var sensor1EditText: TextView
    private lateinit var sensor2EditText: TextView
    private lateinit var sensor3EditText: TextView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        // Initialize Firebase database reference
        database = FirebaseDatabase.getInstance().getReference("Sensor")

        // Initialize EditText views
        sensor1EditText = findViewById(R.id.temp)
        sensor2EditText = findViewById(R.id.humidity)
        sensor3EditText = findViewById(R.id.moisture)

        // Read data from Firebase database and update EditText views
        database.addValueEventListener(object : ValueEventListener {
            override fun onDataChange(dataSnapshot: DataSnapshot) {
                val sensor1Value = dataSnapshot.child("temperature").value.toString()
                sensor1EditText.text = Editable.Factory.getInstance().newEditable("TEMPERATURE = $sensor1Value °C")
                val sensor2Value = dataSnapshot.child("humidity").value.toString()
                sensor2EditText.text = Editable.Factory.getInstance().newEditable("HUMIDITY = $sensor2Value %")
                val sensor3Value = dataSnapshot.child("moisture").value.toString()
                sensor3EditText.text = Editable.Factory.getInstance().newEditable("SOIL MOISTURE = $sensor3Value %")
            }

            override fun onCancelled(error: DatabaseError) {
                // Failed to read value
                error.toException().printStackTrace()
            }
        })
    }

    override fun onDestroy() {
        super.onDestroy()
        // Remove Firebase database listener to avoid memory leaks
        database.removeEventListener(object : ValueEventListener {
            override fun onDataChange(dataSnapshot: DataSnapshot) {}

            override fun onCancelled(error: DatabaseError) {}
        })
    }
}
