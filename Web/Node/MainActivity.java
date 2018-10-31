package com.example.harsha.stocks;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.KeyEvent;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;
import android.widget.SimpleAdapter;
import android.widget.Toast;

import com.android.volley.Request;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonArrayRequest;

import org.json.JSONArray;
import org.json.JSONException;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    SimpleAdapter adapter;
    AutoCompleteTextView textView;
    String[] countries = {"Africa", "India", "Afghanisthan", "Indonesia", "West Indies"};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
                R.layout.list_detail, countries);
        textView = (AutoCompleteTextView)
                findViewById(R.id.autoCompleteTextView);
        textView.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
            final String url = "http://harsha-env.us-east-2.elasticbeanstalk.com/autocomplete/" + textView.getText().toString();

            }

            @Override
            public void afterTextChanged(Editable editable) {

            }
        });
        textView.setAdapter(adapter);


    }
    private static final String[] COUNTRIES = new String[] {
            "Belgium", "France", "Italy", "Germany", "Spain"
    };
}
