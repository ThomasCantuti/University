package SO.Java.Esami.CondizioniMeteo;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    
    public static void main(String[] args) {
        
        PipedOutputStream pos = null;
        PipedInputStream pis = new PipedInputStream();

        try {
            pis = new PipedInputStream(pos);
        } catch (IOException e) {
            e.printStackTrace();
        }

        Thread gd = new Thread(new GeneraDati(pos));
        gd.start();

        try {
            ObjectInputStream ois = new ObjectInputStream(pis);
        } catch (IOException e) {
            e.printStackTrace();
        }

        

        try {
            gd.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

}
