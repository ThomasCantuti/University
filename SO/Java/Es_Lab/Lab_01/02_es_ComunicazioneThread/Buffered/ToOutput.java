import java.io.PipedInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class ToOutput extends Thread {
    private PipedInputStream pis;

    public ToOutput (PipedInputStream pis) {
        this.pis = pis;
    }

    public void run () {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(pis));
            String message = null;
            System.out.println("From-Output: ");
            while ((message = br.readLine()) != null) {
                System.out.println(message);
                System.out.println("From-Output: ");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
