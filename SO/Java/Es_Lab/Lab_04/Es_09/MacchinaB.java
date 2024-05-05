import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaB implements Runnable {
    private PipedOutputStream pos = new PipedOutputStream();
    private final AtomicBoolean isRunning = new AtomicBoolean(false);
    private ControlloProduzione cp = new ControlloProduzione();
    
    public MacchinaB (PipedOutputStream pos, ControlloProduzione cp) {
        this.pos = pos;
        this.cp = cp;
    }

    public void run () {
        isRunning.set(true);
        ObjectOutputStream oos = null;

        while (isRunning.get()) {
            if (cp.getSemilavorati() == 0) {
                try {
                    Thread.sleep(2000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            } else {
                cp.decrementaSemilavorati();
                try {
                    Thread.sleep((long) Math.random() * (150 - 100) + 100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                try {
                    oos = new ObjectOutputStream(pos);
                    oos.writeObject("Pezzo pronto");
                    cp.incrementaPezziPronti();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public void stopThread () {
        isRunning.set(false);
    }
}
