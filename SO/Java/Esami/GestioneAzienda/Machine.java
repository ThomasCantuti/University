package SO.Java.Esami.GestioneAzienda;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;
import java.lang.Math;

public class Machine extends Thread {
    
    private PipedOutputStream pos = null;
    private final AtomicBoolean isRunning = new AtomicBoolean(false);
    private int prodotti = 0;
    private float valore  = 0;

    public Machine (PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run () {

        isRunning.set(true);
        
        ObjectOutputStream oos = null;
        try {
            oos = new ObjectOutputStream(pos);
        } catch (IOException e) {
            e.printStackTrace();
        }

        while (isRunning.get()) {

            prodotti ++;
            valore = (float)Math.random() * 2000 - 1000;

            Messaggio m = new Messaggio(prodotti, valore);

            try {
                oos.writeObject(m);
                //oos.flush();
            } catch (IOException e) {
                e.printStackTrace();
            }

            try {
                Thread.sleep(750);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

        }

    }

    public void stopThread () {
        isRunning.set(false);
    }

}
