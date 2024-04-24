import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    public static void main(String[] args) {
        PipedOutputStream pos = new PipedOutputStream();
        try {
            PipedInputStream pis = new PipedInputStream(pos);

            ThreadLoad threadLoad = new ThreadLoad();
            Monitor monitor = new Monitor(threadLoad);
            Sorter sorter = new Sorter(pos, threadLoad);
            Thread t_monitor = new Thread(monitor);
            Thread t_sorter = new Thread(sorter);
            Thread t_manager = new Thread(new Manager(pis, monitor, sorter));

            t_monitor.start();
            t_sorter.start();
            t_manager.start();
        
            t_monitor.join();
            t_sorter.join();
            t_manager.join();
        } catch (InterruptedException | IOException e) {
            e.printStackTrace();
        }
    }
}
