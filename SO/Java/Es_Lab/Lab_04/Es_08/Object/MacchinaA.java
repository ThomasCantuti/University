import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaA extends Thread {
    private PipedOutputStream pos = new PipedOutputStream();
    private final AtomicBoolean isRunning = new AtomicBoolean(false);
    private int semilavorati = 0;
    
    public MacchinaA (PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run () {
        isRunning.set(true);
        try {
            ObjectOutputStream oos = new ObjectOutputStream(pos);
            String msg = null;

            while (isRunning.get()) {
                System.out.println("Inizio semilavorato");
                semilavorati ++;
                Thread.sleep(200);
                System.out.println("Fine semilavorato");
                Message message = new Message ("Semilavorato " + semilavorati + " finito");
                oos.writeObject(message);
                oos.flush();
            }

            oos.close();
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Prodotti semilavorati finiti: " + semilavorati);
    }

    public void stopThread () {
        isRunning.set(false);
    }
}
