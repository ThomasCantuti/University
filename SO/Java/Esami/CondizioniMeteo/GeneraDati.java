package SO.Java.Esami.CondizioniMeteo;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;
import java.lang.Math;

public class GeneraDati implements Runnable {

    PipedOutputStream pos = null;
    private final AtomicBoolean isRunning = new AtomicBoolean(false);

    public GeneraDati (PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run () {

        ObjectOutputStream oos = null;
        try {
            oos = new ObjectOutputStream(pos);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        Misure m = new Misure((float)Math.random() * 30 - 5, (int)Math.random() * (85 - 15) - 15);

        try {
            oos.writeObject(m);
            oos.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }

        try {
            Thread.sleep(250);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

    public void finisci () {
        isRunning.set(false);
    }
    
}
