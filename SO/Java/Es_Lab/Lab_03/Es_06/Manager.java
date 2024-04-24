import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.PipedInputStream;

public class Manager implements Runnable {
    private PipedInputStream pis = new PipedInputStream();
    private Monitor monitor = null;
    private Sorter sorter = null;

    public Manager (PipedInputStream pis, Monitor monitor, Sorter sorter) {
        this.pis = pis;
        this.monitor = monitor;
        this.sorter = sorter;
    }

    public void run () {
        try {
            ObjectInputStream ois = new ObjectInputStream(pis);
            String message = (String) ois.readObject();

            for (int i = 0; i < 10; i ++) {
                System.out.println(message);
                message = (String) ois.readObject();
            }
            ois.close();
        
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }

        monitor.stopThread();
        sorter.stopThread();
    }
}
