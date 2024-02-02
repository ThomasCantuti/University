package SO.Java.Esami.RilevarePollini;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class RilevatoreAria extends Thread {
    
    private PipedOutputStream pos = null;
    private final AtomicBoolean isRunning = new AtomicBoolean(false);

    public RilevatoreAria (PipedOutputStream pos_da_main) {
        pos = pos_da_main;
    }

    public void run () {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = null;

        try {

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void fermaRilevatoreAria () {

    }

}
