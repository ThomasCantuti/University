import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedInputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaB implements Runnable {
    private final AtomicBoolean isRunning = new AtomicBoolean(false);
    private PipedInputStream pis = new PipedInputStream();
    private int prodottiFiniti = 0;

    public MacchinaB (PipedInputStream pis) {
        this.pis = pis;
    }

    public synchronized void run () {
        isRunning.set(true);
        BufferedReader br = new BufferedReader(new InputStreamReader(pis));
        String response = null;
        
        while (isRunning.get()) {
            try {
                response = br.readLine();
                prodottiFiniti ++;
                Thread.sleep(200);
                System.out.println(response + " e fine prodotto finito");
            } catch (InterruptedException | IOException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Numero di prodotti finiti: " + prodottiFiniti);
    }

    public void stopThread () {
        isRunning.set(false);
        //Thread.currentThread().interrupt();
    }
}
