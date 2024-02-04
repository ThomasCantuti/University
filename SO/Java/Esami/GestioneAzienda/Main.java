package SO.Java.Esami.GestioneAzienda;

import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    
    public static void main(String[] args) {
        
        PipedOutputStream pos = new PipedOutputStream();
        PipedInputStream pis = new PipedInputStream();

        try {
            pis = new PipedInputStream(pos);
        } catch (IOException e) {
            e.printStackTrace();
        }

        Machine m = new Machine(pos);
        m.start();
        Quality q = new Quality(pis);
        q.start();

        try{
            Thread.sleep(15000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        m.stopThread();
        q.stopThread();

        try {
            m.join();
            q.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

}
