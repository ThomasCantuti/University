import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaA implements Runnable {
    private final AtomicBoolean isRunning = new AtomicBoolean(false);
    private PipedOutputStream pos = new PipedOutputStream();
    private int semilavoratiFiniti = 0;

    public MacchinaA (PipedOutputStream pos) {
        this.pos = pos;
    }

    public synchronized void run () {
        isRunning.set(true);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));

        while (isRunning.get()) {
            try {
                System.out.println("Inizio semilavorato");
                Thread.sleep(200);
                semilavoratiFiniti ++;
                bw.write("Fine semilavorato");
                bw.newLine();
                bw.flush();
            } catch (InterruptedException | IOException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Prodotti semilavorati finiti: " + semilavoratiFiniti);
    }

    public void stopThread () {
        isRunning.set(false);
        //Thread.currentThread().interrupt();
    }
}
