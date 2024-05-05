import java.util.concurrent.atomic.AtomicBoolean;

public class SimulaProduzione extends Thread {
    private final AtomicBoolean isRunning = new AtomicBoolean(false);
    private Macchina macchina = null;

    public SimulaProduzione (Macchina macchina) {
        this.macchina = macchina;
    }

    public void run () {
        isRunning.set(true);

        while (isRunning.get()) {
            try {
                Thread.sleep(2000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            macchina.setPezziProdotti((int) Math.random() + 10);
        }
    }

    public void termina () {
        isRunning.set(false);
    }
}
