package com.yash.savy

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView


class HomeActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_home)

        val recyclerView = findViewById<RecyclerView>(R.id.recyclerView)
        recyclerView.apply {
            layoutManager = LinearLayoutManager(this@HomeActivity)
            adapter = RecyclerViewAdapter()
        }






    }
}