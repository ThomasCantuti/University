import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        PipedOutputStream pos = new PipedOutputStream();
        try {
            PipedInputStream pis = new PipedInputStream(pos);
            Scanner tastiera = new Scanner(System.in);
            System.out.print("Inserire valore soglia: ");
            double soglia = tastiera.nextDouble();
            tastiera.close();

            Thread sensor = new Thread(new Sensor(pos));
            Thread actuator = new Thread(new Actuator(pis, soglia));

            sensor.start();
            actuator.start();

            sensor.join();
            actuator.join();

        } catch (IOException | InterruptedException e) {
           e.printStackTrace(); 
        }
    }
}
