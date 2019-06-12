package protect.babymonitor;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class TempType extends AppCompatActivity {

    Button b1,b2,b3;

    String bachaType;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_temp_type);

        bachaType = (String) getIntent().getStringExtra("bachaType","");

        b1 = (Button)findViewById(R.id.rectal);
        b2 = (Button)findViewById(R.id.armpit);
        b3 = (Button)findViewById(R.id.oral);

        b1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });

        b2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });

        b3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
    }
}
