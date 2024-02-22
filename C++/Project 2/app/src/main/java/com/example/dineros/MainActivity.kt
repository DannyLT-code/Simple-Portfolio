package com.example.dineros

import android.R
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.ArrayAdapter
import android.widget.TextView
import android.widget.Toast
import com.example.dineros.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {
    lateinit var binding: ActivityMainBinding

    // Conversion rates
    val conversionRates = mapOf(
        "USD" to 1.0,
        "MXN" to 17.0,
        "CAD" to 1.25,
        "EUR" to 0.85,
        "YEN" to 110.0
    )

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        var lista = listOf("USD", "MXN", "CAD", "EUR", "YEN")

        val adapter = ArrayAdapter(this@MainActivity, android.R.layout.simple_spinner_item, lista)
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)

        binding.spMoney.adapter = adapter
        binding.spDinero.adapter = adapter

        binding.btnConvert.setOnClickListener {
            val fromCurrency = binding.spMoney.selectedItem.toString()
            val toCurrency = binding.spDinero.selectedItem.toString()
            val amount = binding.edtText.text.toString().toDouble()

            val convertedAmount = convertCurrency(amount, fromCurrency, toCurrency)
            binding.txtView.text = convertedAmount.toString()
        }
    }

    private fun convertCurrency(amount: Double, fromCurrency: String, toCurrency: String): Double {
        val fromRate = conversionRates[fromCurrency] ?: 1.0
        val toRate = conversionRates[toCurrency] ?: 1.0
        return (amount / fromRate) * toRate
    }
}
