import java.util.concurrent.atomic.AtomicBoolean;

public class WorkerThreadInterrupt implements Runnable {
    private final AtomicBoolean isRunning = new AtomicBoolean(false);
    private int i;

    public WorkerThreadInterrupt (int i) {
        this.i = i;
    }

    public void run () {
        isRunning.set(true);

        while (isRunning.get()) {
            try {
                System.out.println("Thread: " + i);
                Thread.sleep(10000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void stopThread () {
        isRunning.set(false);
    }

    public void interrupt () {
        isRunning.set(false);
        Thread.currentThread().interrupt();
    }
}
