import java.io.PipedInputStream;
import java.io.PipedOutputStream;
import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        PipedOutputStream pos = new PipedOutputStream();
        try {
            PipedInputStream pis = new PipedInputStream(pos);

            Thread t_fi = new FromInput(pos);
            Thread t_to = new ToOutput(pis);
    
            t_fi.start();
            t_to.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
