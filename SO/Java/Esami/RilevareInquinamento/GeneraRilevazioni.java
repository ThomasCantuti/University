package SO.Java.Esami.RilevareInquinamento;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class GeneraRilevazioni extends Thread {

    private PipedOutputStream pos = null;
    private final AtomicBoolean isRunning = new AtomicBoolean(false);

    public GeneraRilevazioni (PipedOutputStream pos_da_main) {
        pos = pos_da_main;
    }

    public void run () {

        isRunning.set(true);
        ObjectOutputStream oos = null;
        try {
            oos = new ObjectOutputStream(pos);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        while (isRunning.get()) {
            Rilevazione r = new Rilevazione((int)(200*Math.random()), System.currentTimeMillis());

            try {
                oos.writeObject(r);
                oos.flush();
            } catch (IOException e) {
                e.printStackTrace();
            }

            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

    }

    public void stopRilveazioni () {
        isRunning.set(false);
    }
    
}
