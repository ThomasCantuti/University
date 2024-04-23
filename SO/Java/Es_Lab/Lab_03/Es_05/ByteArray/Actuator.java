import java.io.IOException;
import java.io.PipedInputStream;
import java.nio.charset.Charset;

public class Actuator extends Thread {
    private PipedInputStream pis = new PipedInputStream();
    private double soglia;

    public Actuator (PipedInputStream pis, double soglia) {
        this.pis = pis;
        this.soglia = soglia;
    }

    public void run () {
        try {
            byte buffer[] = new byte[256];
            int nread = 0;
            nread = pis.read(buffer);
            String stringReceived = new String(buffer, 0, nread, Charset.forName("UTF-8"));
            double temp = Double.parseDouble(stringReceived);
            if (temp > soglia) {
                System.out.println("Accendere riscaldamento");
            }
            
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
