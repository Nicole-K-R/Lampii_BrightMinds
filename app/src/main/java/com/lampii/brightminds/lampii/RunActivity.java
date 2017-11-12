package com.lampii.brightminds.lampii;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.graphics.drawable.ColorDrawable;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.RadioButton;

import javax.inject.Inject;

import butterknife.BindView;
import butterknife.ButterKnife;
import butterknife.OnCheckedChanged;
import butterknife.OnClick;

public class RunActivity extends Activity{

    public boolean yellow;
    public boolean onB;
    public int curBright;
    private static final int INCREMENTVALUE = 50;
    @BindView(R.id.progBar) ProgressBar mProg;
    @BindView(R.id.yellowButton) RadioButton mRadY;
    @BindView(R.id.whiteButton) RadioButton mRadW;
    @BindView(R.id.button2) Button onOff;
    @BindView(R.id.circ) ImageView circle;
    SharedPreferences mDefaultPreferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mDefaultPreferences = PreferenceManager.getDefaultSharedPreferences(this);
        setContentView(R.layout.activity_run);
        ButterKnife.bind(this);
        //circle.setImageResource(R.drawable.circlew);
        yellow = mDefaultPreferences.getBoolean(getString(R.string.current_yellow), getResources().getBoolean(R.bool.default_yellow));
        onB = mDefaultPreferences.getBoolean(getString(R.string.current_on), getResources().getBoolean(R.bool.on));
        curBright = mDefaultPreferences.getInt(getString(R.string.current_intensity), getResources().getInteger(R.integer.default_brightness));
        mProg.setProgress(curBright);
        mRadW.setChecked(!yellow);
        mRadY.setChecked(yellow);
        circle.setImageResource(yellow? R.drawable.circley:R.drawable.circlew);
        onOff.setText(onB? getString(R.string.on) : getString(R.string.off));
        circle.setVisibility(onB? View.VISIBLE: View.GONE);
    }


    @OnClick(R.id.increase)
    public void increase(View view) {
        curBright+= curBright >= 100 ? 0 : INCREMENTVALUE;
        mProg.setProgress(curBright);
        mDefaultPreferences.edit().putInt(getString(R.string.current_intensity), curBright).apply();
    }


    @OnClick(R.id.decrease)
    public void decrease(View view) {
        curBright-= curBright <= 0 ? 0 : INCREMENTVALUE;
        mProg.setProgress(curBright);
        mDefaultPreferences.edit().putInt(getString(R.string.current_intensity), curBright).apply();
    }

    @OnClick(R.id.yellowButton)
    public void onYellowSelected(View view){
        yellow = !yellow;
        mRadW.setChecked(false);
        circle.setImageResource(R.drawable.circley);
        mDefaultPreferences.edit().putBoolean(getString(R.string.current_yellow), true).apply();
    }

    @OnClick(R.id.whiteButton)
    public void onWhiteSelected(View view){
        yellow = !yellow;
        mRadY.setChecked(false);
        circle.setImageResource(R.drawable.circlew);
        mDefaultPreferences.edit().putBoolean(getString(R.string.current_yellow), false).apply();
    }

    @OnClick(R.id.button2)
    public void onOnOffSelected(View view){
        onB = !onB;
        onOff.setText(onB? getString(R.string.on) : getString(R.string.off));
        circle.setVisibility(onB? View.VISIBLE: View.GONE);
        mDefaultPreferences.edit().putBoolean(getString(R.string.current_on), onB).apply();
    }

    @OnClick(R.id.button3)
    public void btSelected(View view){
        this.startActivity(new Intent(this, LaunchActivity.class));
    }
}