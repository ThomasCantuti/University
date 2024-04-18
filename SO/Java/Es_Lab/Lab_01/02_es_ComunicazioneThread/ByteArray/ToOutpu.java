import java.io.PipedInputStream;
import java.util.Scanner;

public class ToOutpu extends Thread {
    private PipedInputStream pis;

    public ToOutpu(PipedInputStream pis) {
        this.pis = pis;
    }

    public void run() {
        try {
            byte[] buffer = new byte[1024];
            int bytesRead = pis.read(buffer);
            String message = new String(buffer, 0, bytesRead);
            while (message != null) {
                System.out.println("Messaggio ricevuto: " + message);
                bytesRead = pis.read(buffer);
                message = new String(buffer, 0, bytesRead);
            }
            pis.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}