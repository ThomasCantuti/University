package SO.Java.Esami.CondizioniMeteo;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;
import java.lang.Math;
import java.util.concurrent.atomic.AtomicBoolean;

public class GeneraDati implements Runnable {

    private PipedOutputStream pos = null;
    private final AtomicBoolean isRunning = new AtomicBoolean(false);

    public GeneraDati (PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run () {

        isRunning.set(true);

        ObjectOutputStream oos = null;

        try {
            oos = new ObjectOutputStream(pos);
        } catch (IOException e) {
            System.err.println(e);
            System.exit(-1);
        }

        while (isRunning.get()) {

            Misure m = new Misure((float)Math.random()*(25 - (-5)) - 5, (int)Math.random()*(85 - 15) + 15);
            System.out.println("GeneraDati: Temp = " + m.getTemperatura() + " Umidita' = " + m.getUmidita() + "\n");

            try {
                oos.writeObject(m);
                oos.flush();
            } catch (IOException e) {
                e.printStackTrace();
            }

            try {
                Thread.sleep(2500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }

    public void finisci () {
        isRunning.set(false);
    }

}
