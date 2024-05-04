import java.io.IOException;
import java.io.PipedInputStream;
import java.nio.charset.Charset;
import java.util.concurrent.atomic.AtomicBoolean;

public class MacchinaB implements Runnable {
    private PipedInputStream pis = new PipedInputStream();
    private AtomicBoolean isRunning = new AtomicBoolean(false);

    public MacchinaB (PipedInputStream pis) {
        this.pis = pis;
    }

    public void run () {
        isRunning.set(true);
        byte[] buffer = new byte[128];
        int nread = 0;
        String message = null;

        while (isRunning.get()) {
            try {
                nread = pis.read(buffer);
                message = new String(buffer, 0, nread, Charset.forName("UTF-8"));
                Thread.sleep(200);
                System.out.println(message + " arrivato");
            } catch (IOException | InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void stopThread () {
        isRunning.set(false);
    }
}
