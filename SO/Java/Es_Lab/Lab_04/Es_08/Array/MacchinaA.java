import java.io.IOException;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaA implements Runnable {
    private PipedOutputStream pos = new PipedOutputStream();
    private AtomicBoolean isRunning = new AtomicBoolean(false);

    public MacchinaA (PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run () {
        isRunning.set(true);
        byte[] msg = null;
        String msgString = null;

        while (isRunning.get()) {
            System.out.println("Inizio semilavorato");
            try {
                Thread.sleep(200);
                System.out.println("Fine semilavorato");
                msgString = "Pezzo-grezzo";
                msg = msgString.getBytes("UTF-8");
                pos.write(msg);
                pos.flush();
            } catch (InterruptedException | IOException e) {
                e.printStackTrace();
            }
        }
    }

    public void stopThread () {
        isRunning.set(false);
    }
}
