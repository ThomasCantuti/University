import java.util.Random;
import java.util.concurrent.atomic.AtomicBoolean;

public class Monitor implements Runnable {
    private ThreadLoad threadLoad = new ThreadLoad();
    private final AtomicBoolean isRunning = new AtomicBoolean(false);

    public Monitor (ThreadLoad tl) {
        this.threadLoad = tl;
    }

    public void run () {
        isRunning.set(true);

        while (isRunning.get()) {
            Random random = new Random();
            int id = random.nextInt(9);
            double load = random.nextDouble(100);
            threadLoad.setThreadLoad(id, load);
            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void stopThread () {
        isRunning.set(false);
    }
}
