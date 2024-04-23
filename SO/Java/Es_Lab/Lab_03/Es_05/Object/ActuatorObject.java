import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.PipedInputStream;
import java.nio.charset.Charset;

public class ActuatorObject extends Thread {
    private PipedInputStream pis = new PipedInputStream();
    private double soglia;

    public ActuatorObject (PipedInputStream pis, double soglia) {
        this.pis = pis;
        this.soglia = soglia;
    }

    public void run () {
        try {
            ObjectInputStream ois = new ObjectInputStream(pis);
            Temperature temp = (Temperature)ois.readObject();
            if (temp.getValue() > soglia) {
                System.out.println("Accendere riscaldamento");
            }
            
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
