import java.io.PipedOutputStream;

public class FromInput extends Thread {
    private PipedOutputStream pos;

    public FromInput (PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run () {
        
    }
}
