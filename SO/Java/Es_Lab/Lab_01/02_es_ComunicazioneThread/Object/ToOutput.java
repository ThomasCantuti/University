import java.io.PipedInputStream;

public class ToOutput extends Thread {
    private PipedInputStream pis;

    public ToOutput (PipedInputStream pis) {
        this.pis = pis;
    }

    public void run () {
        
    }
}
