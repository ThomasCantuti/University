import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PipedOutputStream;

public class SensorBuffer extends Thread {
    private PipedOutputStream pos = new PipedOutputStream();

    public SensorBuffer (PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run () {
        try {
            double temp = temperatureGeneretor();
            System.out.println("Temperatura attuale: " + temp);
            String stringTemp = temp + "";
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));
            bw.write(stringTemp);
            bw.flush();
            bw.close();
            Thread.sleep(300);
        } catch (InterruptedException | IOException e) {
            e.printStackTrace();
        }
    }

    public double temperatureGeneretor () {
        return Math.random() * (21 - 18) + 18;
    }
}
