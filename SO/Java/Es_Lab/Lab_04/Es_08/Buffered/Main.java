import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    public static void main(String[] args) {
        PipedOutputStream pos = new PipedOutputStream();
        try {
            PipedInputStream pis = new PipedInputStream(pos);
            MacchinaA t1 = new MacchinaA(pos);
            MacchinaB t2 = new MacchinaB(pis);
            Thread macchinaA = new Thread(t1);
            Thread macchinaB = new Thread(t2);

            macchinaA.start();
            macchinaB.start();

            Thread.sleep(10000);

            t1.stopThread();
            t2.stopThread();

            macchinaA.join();
            macchinaB.join();
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
