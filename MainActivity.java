package com.example.andro.mysecondapplication;

import android.content.SharedPreferences;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ProgressBar;
import android.widget.SeekBar;
import android.widget.TextView;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.lang.reflect.Method;
import java.util.UUID;
import android.app.Activity;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;





public class MainActivity extends AppCompatActivity {

    private TextView text_view1;
    private ProgressBar progress_bar1;
    private TextView text_view2;
    private ProgressBar progress_bar2;
    private TextView text_view3;
    private ProgressBar progress_bar3;
    private static final String TAG = "bluetooth1";
    private State state;
    public  class State {
        int btn1;
        int btn2;
        int btn3;
        int slider1;
        int slider2;
        int slider3;
        double a0;
        double a1;
        double a2;
        double b0;
        double b1;
        double b2;


        public State(int btn1, int btn2, int btn3, int slider1, int slider2, int slider3, double a0, double a1, double a2, double b0, double b1, double b2) {
            this.btn1 = btn1;
            this.btn2 = btn2;
            this.btn3 = btn3;
            this.slider1 = slider1;
            this.slider2 = slider2;
            this.slider3 = slider3;
            this.a0 = a0;
            this.a1 = a1;
            this.a2 = a2;
            this.b0 = b0;
            this.b1 = b1;
            this.b2 = b2;
        }

        public int isBtn2() {
            return btn2;
        }

        public int isBtn1() {
            return btn1;
        }

        public int isBtn3() {
            return btn3;
        }

        public int getSlider1() {
            return slider1;
        }

        public int getSlider2() {
            return slider2;
        }

        public int getSlider3() {
            return slider3;
        }

        public double a0() {return a0;}
        public double a1() {return a1;}
        public double a2() {return a2;}
        public double b0() {return b0;}
        public double b1() {return b1;}
        public double b2() {return b2;}


        public void setBtn1(int btn1) {
            this.btn1 = btn1;
        }

        public void setBtn2(int btn2) {
            this.btn2 = btn2;
        }

        public void setBtn3(int btn3) {
            this.btn3 = btn3;
        }

        public void setSlider1(int slider1) {
            this.slider1 = slider1;
        }

        public void setSlider2(int slider2) {
            this.slider2 = slider2;
        }

        public void setSlider3(int slider3) {
            this.slider3 = slider3;
        }


        public void seta0 (double a0) {this.a0 = a0; }
        public void seta1 (double a1) {this.a1 = a1; }
        public void seta2 (double a2) {this.a2 = a2; }
        public void setb0 (double b0) {this.b0 = b0; }
        public void setb1 (double b1) {this.b1 = b1; }
        public void setb2 (double b2) {this.b2 = b2; }

        @Override
        public String toString() {
            return (this.isBtn1() + " " +this.isBtn2() + " " +this.isBtn3() + " " + this.getSlider1() +
                     " " + this.getSlider2() + " " + this.getSlider3() +  " " + this.a0() + " " + this.a1() + " " + this.a2() + " " + this.b0() + " " + this.b1() + " " + this.b2() + "\r\n");
        }
    }
    Button btnOn, btnOff, button1, button2, button3;

    private BluetoothAdapter btAdapter = null;
    public BluetoothSocket btSocket = null;
    private OutputStream outStream = null;

    // SPP UUID service
    private static final UUID MY_UUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

    // MAC-address of Bluetooth module (you must edit this line)
    private static String address = "20:15:08:13:09:33";

    /** Called when the activity is first created. */





    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        button1 = (Button) findViewById(R.id.button1);
        button2 = (Button) findViewById(R.id.button2);
        button3 = (Button) findViewById(R.id.button3);

        btAdapter = BluetoothAdapter.getDefaultAdapter();


        checkBTState();
        state = new State(0, 0, 0, 0, 0, 0 ,0 ,0, 0,0,0,0);

        button1.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                if(state.isBtn1() == 1) {
                    button3.setBackgroundColor(0x0000FF00);
                    button2.setBackgroundColor(0x0000FF00);
                    button1.setBackgroundColor(0x0000FF00);
                    state.setBtn1(0);
                    state.setBtn2(0);
                    state.setBtn3(0);
                } else {
                    button1.setBackgroundColor(0xFF00FF00);
                    button2.setBackgroundColor(0x0000FF00);
                    button3.setBackgroundColor(0x0000FF00);
                    state.setBtn1(1);
                    state.setBtn2(0);
                    state.setBtn3(0);
                }
                sendData(state);
            }
        });
        button2.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                if(state.isBtn2() == 1) {
                    state.setBtn1(0);
                    state.setBtn2(0);
                    state.setBtn3(0);
                    button3.setBackgroundColor(0x0000FF00);
                    button2.setBackgroundColor(0x0000FF00);
                    button1.setBackgroundColor(0x0000FF00);
                } else {
                    state.setBtn1(0);
                    state.setBtn2(1);
                    state.setBtn3(0);
                    button2.setBackgroundColor(0xFF00FF00);
                    button3.setBackgroundColor(0x0000FF00);
                    button1.setBackgroundColor(0x0000FF00);
                }
                sendData(state);
            }
        });
        button3.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                if(state.isBtn3() == 1) {
                    state.setBtn1(0);
                    state.setBtn2(0);
                    state.setBtn3(0);
                    button3.setBackgroundColor(0x0000FF00);
                    button2.setBackgroundColor(0x0000FF00);
                    button1.setBackgroundColor(0x0000FF00);
                } else {
                    state.setBtn1(0);
                    state.setBtn2(0);
                    state.setBtn3(1);
                    button3.setBackgroundColor(0xFF00FF00);
                    button1.setBackgroundColor(0x0000FF00);
                    button2.setBackgroundColor(0x0000FF00);
                    button1.setBackgroundColor(0x0000FF00);
                }
                sendData(state);
            }
        });

        SeekBar seek_bar1 = findViewById(R.id.seekBar1);
        text_view1 =findViewById(R.id.textView1);
        progress_bar1 =  findViewById(R.id.progressBar1);
        text_view1.setText("progress1" );

        SeekBar seek_bar2;
        seek_bar1.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar1, int progress1, boolean b) {
                progress_bar1.setProgress(progress1);
                text_view1.setText("" + progress1);
                state.setSlider1(progress1);

            }
            @Override
            public void onStartTrackingTouch(SeekBar seekBar1) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar1) {
                sendData(state);

            }
        });

        seek_bar2 = findViewById(R.id.seekBar2);
        text_view2 = findViewById(R.id.textView2);
        progress_bar2 = findViewById(R.id.progressBar2);
        text_view2.setText("progress2" );

        SeekBar seek_bar3;
        seek_bar2.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar2, int progress2, boolean b) {
                progress_bar2.setProgress(progress2);
                text_view2.setText("" + progress2);
                state.setSlider2(progress2);
            }
            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {
            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                sendData(state);

            }
        });

        seek_bar3 = findViewById(R.id.seekBar3);
        text_view3 = findViewById(R.id.textView3);
        progress_bar3 = findViewById(R.id.progressBar3);
        text_view3.setText("progress3" );

        seek_bar3.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar3, int progress3, boolean b) {

                progress_bar3.setProgress(progress3);
                text_view3.setText("" + progress3);
                state.setSlider3(progress3);

                double value_a0=0;
                double value_a1=0;
                double value_a2=0;
                double value_b0=0;
                double value_b1=0;
                double value_b2=0;
                double w0;
                double Fs = 48000;
                double pi = 3.141592;
                double alpha;
                double Q = 1;
                if (progress3 > 20000)
                    //filtriraj sve ispod frekvencije variables[5]-20000
                    w0 = 2 * pi * (progress3 - 20000) / Fs;
                else
                    //filtriraj sve iznad frekvencije variables[5]
                    w0 = 2 * pi * progress3 / Fs;

                alpha = Math.sin(w0) / (2 * Q);

            //HPF  H(s) = s^2 / (s^2 + s/Q + 1)


		if (progress3 >20000) {

             value_a0 = 1 + alpha;
             value_a1 = -2 * Math.cos(w0);
             value_a2 = 1 - alpha;
             value_b0 = (1 + Math.cos(w0)) / 2;
             value_b1 = -(1 + Math.cos(w0));
             value_b2 = (1 + Math.cos(w0)) / 2;
        }

          //LPF    H(s) = 1 / (s^2 + s/Q + 1)
		else if (progress3<20000) {

             value_a0 = 1 + alpha;
             value_a1 = -2 * Math.cos(w0);
             value_a2 = 1 - alpha;
             value_b0 = (1 - Math.cos(w0)) / 2;
             value_b1 = 1 - Math.cos(w0);
             value_b2 = (1 - Math.cos(w0)) / 2;


        }
                state.a0=value_a0;
                state.a1=value_a1;
                state.a2=value_a2;
                state.b0=value_b0;
                state.b1=value_b1;
                state.b2=value_b2;
            }
            @Override
            public void onStartTrackingTouch(SeekBar seekBar3) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar3) {
                sendData(state);

            }
        });




    }


    private BluetoothSocket createBluetoothSocket(BluetoothDevice device) throws IOException {
        if(Build.VERSION.SDK_INT >= 10){
            try {
                final Method  m = device.getClass().getMethod("createInsecureRfcommSocketToServiceRecord", new Class[] { UUID.class });
                return (BluetoothSocket) m.invoke(device, MY_UUID);
            } catch (Exception e) {
                Log.e(TAG, "Could not create Insecure RFComm Connection",e);
            }
        }
        return  device.createRfcommSocketToServiceRecord(MY_UUID);
    }

    @Override
    public void onResume() {
        super.onResume();

        Log.d(TAG, "...onResume - try connect...");

        // Set up a pointer to the remote node using it's address.
        BluetoothDevice device = btAdapter.getRemoteDevice(address);

        // Two things are needed to make a connection:
        //   A MAC address, which we got above.
        //   A Service ID or UUID.  In this case we are using the
        //     UUID for SPP.

        try {
            btSocket = createBluetoothSocket(device);
        } catch (IOException e1) {
            errorExit("Fatal Error", "In onResume() and socket create failed: " + e1.getMessage() + ".");
        }

        // Discovery is resource intensive.  Make sure it isn't going on
        // when you attempt to connect and pass your message.
        btAdapter.cancelDiscovery();

        // Establish the connection.  This will block until it connects.
        Log.d(TAG, "...Connecting...");
        try {
            btSocket.connect();
            Log.d(TAG, "...Connection ok...");
        } catch (IOException e) {
            try {
                btSocket.close();
            } catch (IOException e2) {
                errorExit("Fatal Error", "In onResume() and unable to close socket during connection failure" + e2.getMessage() + ".");
            }
        }

        // Create a data stream so we can talk to server.
        Log.d(TAG, "...Create Socket...");

        try {
            outStream = btSocket.getOutputStream();
        } catch (IOException e) {
            errorExit("Fatal Error", "In onResume() and output stream creation failed:" + e.getMessage() + ".");
        }
    }

    @Override
    public void onPause() {
        super.onPause();

        Log.d(TAG, "...In onPause()...");

        if (outStream != null) {
            try {
                outStream.flush();
            } catch (IOException e) {
                errorExit("Fatal Error", "In onPause() and failed to flush output stream: " + e.getMessage() + ".");
            }
        }

        try     {
            btSocket.close();
        } catch (IOException e2) {
            errorExit("Fatal Error", "In onPause() and failed to close socket." + e2.getMessage() + ".");
        }
    }

    private void checkBTState() {
        // Check for Bluetooth support and then check to make sure it is turned on
        // Emulator doesn't support Bluetooth and will return null
        if(btAdapter==null) {
            errorExit("Fatal Error", "Bluetooth not support");
        } else {
            if (btAdapter.isEnabled()) {
                Log.d(TAG, "...Bluetooth ON...");
            } else {
                //Prompt user to turn on Bluetooth
                Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
                startActivityForResult(enableBtIntent, 1);
            }
        }
    }

    private void errorExit(String title, String message){
        Toast.makeText(getBaseContext(), title + " - " + message, Toast.LENGTH_LONG).show();
        finish();
    }

    private void sendData(State state) {
        String msgBuffer = state.toString();
        byte[] line = msgBuffer.getBytes();
        Log.d(TAG, "...Send data: " + msgBuffer + "...");

        try {
            outStream.write(line);
        } catch (IOException e) {
            String msg = "In onResume() and an exception occurred during write: " + e.getMessage();
            if (address.equals("00:00:00:00:00:00"))
                msg = msg + ".\n\nUpdate your server address from 00:00:00:00:00:00 to the correct address on line 35 in the java code";
            msg = msg +  ".\n\nCheck that the SPP UUID: " + MY_UUID.toString() + " exists on server.\n\n";

            errorExit("Fatal Error", msg);
        }
    }
}



