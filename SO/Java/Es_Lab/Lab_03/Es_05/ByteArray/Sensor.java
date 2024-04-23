import java.io.IOException;
import java.io.PipedOutputStream;

public class Sensor extends Thread {
    private PipedOutputStream pos = new PipedOutputStream();

    public Sensor (PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run () {
        try {
            double temp = temperatureGeneretor();
            System.out.println("Temperatura attuale: " + temp);
            String stringTemp = temp + "";
            byte[] buffer = stringTemp.getBytes();
            pos.write(buffer);
            pos.flush();

            Thread.sleep(300);
        } catch (InterruptedException | IOException e) {
            e.printStackTrace();
        }
    }

    public double temperatureGeneretor () {
        return Math.random() * (21 - 18) + 18;
    }
}
