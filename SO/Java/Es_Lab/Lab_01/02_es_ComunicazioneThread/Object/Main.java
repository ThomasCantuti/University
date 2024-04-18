import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    public static void main(String[] args) {
        PipedOutputStream pos = new PipedOutputStream();
        try {
            PipedInputStream pis = new PipedInputStream(pos);
        
            Thread t_in = new FromInput(pos);
            Thread t_out = new ToOutput(pis);

            t_in.start();
            t_out.start();

            t_in.join();
            t_out.join();

        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
