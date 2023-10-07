package com.example.smartirrigation


import android.annotation.SuppressLint
import android.content.Intent
import android.os.Bundle
import android.widget.Switch
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.Button
import com.example.smartirrigation.databinding.FragmentSecondBinding

import com.google.firebase.database.*

/**
 * A simple [Fragment] subclass as the second destination in the navigation.
 */
class SecondFragment : Fragment() {

    private var _binding: FragmentSecondBinding? = null
    private lateinit var databaseRef: DatabaseReference
    private lateinit var databaseR: DatabaseReference

    private lateinit var on: Button
    private lateinit var off: Button
    @SuppressLint("UseSwitchCompatOrMaterialCode")
    private lateinit var switch: Switch

    private var b = false
    private var a = true

    private val binding get() = _binding!!

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View {
        _binding = FragmentSecondBinding.inflate(inflater, container, false)
        on = binding.button
        off = binding.button2
        switch = binding.switch2

        databaseRef = FirebaseDatabase.getInstance().getReference("pump_status")
        databaseR = FirebaseDatabase.getInstance().getReference("flag")

//        on.setOnClickListener {
//            val msg2 = if (flagStatus) "Please enable manual function !" else "Manual function turned on"
//            val toast = Toast.makeText(requireContext(), msg2, Toast.LENGTH_SHORT)
//            toast.setGravity(Gravity.CENTER_VERTICAL , 0, 50)
//            toast.show()
//            databaseRef.setValue(a)
//        }
//
//        off.setOnClickListener {
//            databaseRef.setValue(b)
//        }

        switch.setOnCheckedChangeListener { _, isChecked ->
            if (isChecked) {
                databaseR.setValue(a)

                on.setOnClickListener {
                    databaseRef.setValue(a)
                }

                off.setOnClickListener {
                    databaseRef.setValue(b)
                }
            }
            else{
                databaseR.setValue(b)
                databaseRef.setValue(b)
            }
        }
        return binding.root
    }

//    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
//        super.onViewCreated(view, savedInstanceState)
//
//        binding.buttonSecond.setOnClickListener {
//            findNavController().navigate(R.id.action_SecondFragment_to_FirstFragment)
//        }
//    }


    override fun onViewCreated(view: View, savedInstanceState: Bundle?) {
        super.onViewCreated(view, savedInstanceState)

        binding.buttonSecond.setOnClickListener {
            val intent = Intent(activity, MainActivity::class.java)
            startActivity(intent)
        }
    }


    override fun onDestroyView() {
        super.onDestroyView()
        _binding = null
    }
}
