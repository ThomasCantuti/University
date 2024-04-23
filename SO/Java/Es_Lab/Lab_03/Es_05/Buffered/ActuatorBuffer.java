import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedInputStream;
import java.nio.charset.Charset;

public class ActuatorBuffer extends Thread {
    private PipedInputStream pis = new PipedInputStream();
    private double soglia;

    public ActuatorBuffer (PipedInputStream pis, double soglia) {
        this.pis = pis;
        this.soglia = soglia;
    }

    public void run () {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(pis));
            double temp = br.read();
            if (temp > soglia) {
                System.out.println("Accendere riscaldamento");
            }
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
