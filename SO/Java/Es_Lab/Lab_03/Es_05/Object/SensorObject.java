import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;

public class SensorObject extends Thread {
    private PipedOutputStream pos = new PipedOutputStream();

    public SensorObject (PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run () {
        try {
            Temperature temp = new Temperature();
            System.out.println("Temperatura attuale: " + temp.getValue());
            ObjectOutputStream oos = new ObjectOutputStream(pos);
            oos.writeObject(temp);
            oos.flush();
            oos.close();
            Thread.sleep(300);
        } catch (InterruptedException | IOException e) {
            e.printStackTrace();
        }
    }
}
