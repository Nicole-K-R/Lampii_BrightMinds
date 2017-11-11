package com.lampii.brightminds.lampii;

import android.content.Intent;
import android.os.CountDownTimer;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ProgressBar;

import butterknife.BindView;
import butterknife.ButterKnife;
import butterknife.OnClick;

public class MainActivity extends AppCompatActivity {

    private static final int INCREMENTVALUE = 1;
    @BindView(R.id.progessBar) ProgressBar mProgessBar;
    @BindView(R.id.button) Button mButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ButterKnife.bind(this);
    }

    @Override
    protected void onStart(){
        super.onStart();
        new CountDownTimer(4000, 20) {
            public void onTick(long millisUntilFinished) {
                mProgessBar.incrementProgressBy(INCREMENTVALUE);
            }

            public void onFinish() {
                mProgessBar.setProgress(100);
                mProgessBar.setVisibility(View.INVISIBLE);
                mButton.setVisibility(View.VISIBLE);
            }
        }.start();
    }

    @OnClick(R.id.button)
    public void buttonPress(){
        MainActivity.this.startActivity(new Intent(MainActivity.this, RunActivity.class));
    }

}
