package SO.Java.Esami.GestioneAzienda;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.PipedInputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class Quality extends Thread {

    private PipedInputStream pis = null;
    private final AtomicBoolean isRunning = new AtomicBoolean(false);

    public Quality (PipedInputStream pis) {
        this.pis = pis;
    }

    public void run () {
        
        isRunning.set(true);

        ObjectInputStream ois = null;
        try {
            ois = new ObjectInputStream(pis);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        while (isRunning.get()) {

            try {
                Messaggio m = (Messaggio)ois.readObject();
                if (m.getValore() < 0)
                    System.out.println("Errore: valore = " + (int)m.getValore() + "\n");
                else
                    System.out.println("OK\n");

            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
                System.exit(-1);
            }

        }

    }

    public void stopThread () {
        isRunning.set(false);
    }
    
}
