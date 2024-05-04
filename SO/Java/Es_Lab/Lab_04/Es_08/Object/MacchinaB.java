import java.io.IOException;
import java.io.PipedInputStream;
import java.util.concurrent.atomic.AtomicBoolean;

import java.io.ObjectInputStream;
public class MacchinaB extends Thread {
    private PipedInputStream pis = new PipedInputStream();
    private final AtomicBoolean isRunning = new AtomicBoolean(false);
    private int prodottiFiniti = 0;

    public MacchinaB (PipedInputStream pis) {
        this.pis = pis;
    }    

    public void run () {
        isRunning.set(true);
        try {
            ObjectInputStream ois = new ObjectInputStream(pis);
            Message msg = null;

            while (isRunning.get()) {
                msg = (Message) ois.readObject();
                Thread.sleep(200);
                prodottiFiniti ++;
                System.out.println(msg.getMessage() + "ricevuto e terminato");
            }
        } catch (IOException | ClassNotFoundException | InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Prodotti finiti: " + prodottiFiniti);
    }

    public void stopThread () {
        isRunning.set(false);
    }
}
