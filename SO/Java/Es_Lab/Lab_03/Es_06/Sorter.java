import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;
import java.util.concurrent.atomic.AtomicBoolean;


public class Sorter implements Runnable {
    private PipedOutputStream pos = new PipedOutputStream();
    private ThreadLoad threadLoad = new ThreadLoad();
    private final AtomicBoolean isRunning = new AtomicBoolean(false);

    public Sorter (PipedOutputStream pos, ThreadLoad tl) {
        this.pos = pos;
        this.threadLoad = tl;
    }

    public void run () {
        isRunning.set(true);

        try {
            ObjectOutputStream oos = new ObjectOutputStream(pos);

            while (isRunning.get()) {
                String threadLoadMax = "";
                int maxId = this.threadLoad.getMaxId();
                double maxLoad = this.threadLoad.getMaxLoad(maxId);
                threadLoadMax += "id: " + maxId + " CPU Load: " + maxLoad + "\n";
                oos.writeObject(threadLoadMax);
                oos.flush();
                Thread.sleep(150);
            }
            oos.close();
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
        
    }

    public void stopThread () {
        isRunning.set(false);
    }
}
