import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaA implements Runnable {
    private final AtomicBoolean isRunning = new AtomicBoolean(false);
    private ControlloProduzione cp = new ControlloProduzione();

    public MacchinaA (ControlloProduzione cp) {
        this.cp = cp;
    }
    
    public void run () {
        isRunning.set(true);
        Random random = new Random();

        while (isRunning.get()) {
            try {
                Thread.sleep(random.nextInt((500 - 400) + 400));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            cp.incrementaSemilavorati();
        }
    }

    public void stopThread () {
        isRunning.set(false);
    }
}
