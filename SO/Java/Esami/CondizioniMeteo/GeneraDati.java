package SO.Java.Esami.CondizioniMeteo;

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
        Misure m = new Misure((float)Math.random()*(25 - (-5)) - 5, (int)Math.random()*(85 - 15) + 15);

        while (isRunning.get()) {

        }

    }

    public void finisci () {
        isRunning.set(false);
    }

}
