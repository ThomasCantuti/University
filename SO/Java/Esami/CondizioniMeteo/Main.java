package SO.Java.Esami.CondizioniMeteo;

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

        Thread t = new Thread(new GeneraDati(pos));
        t.start();

    }

}
