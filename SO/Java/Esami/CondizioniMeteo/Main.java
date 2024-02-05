package SO.Java.Esami.CondizioniMeteo;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    
    public static void main(String[] args) {
        
        PipedInputStream pis = new PipedInputStream();
        PipedOutputStream pos = new PipedOutputStream();

        try {
            pis = new PipedInputStream(pos);
        } catch (IOException e) {
            e.printStackTrace();
        }

        GeneraDati gd = new GeneraDati(pos);
        Thread tgd = new Thread(gd);
        tgd.start();


        ObjectInputStream ois = null;
        try {
            ois = new ObjectInputStream(pis);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        Misure m = null;
        try {
            m = (Misure)ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
        int umidita = 14;

        while (m.getUmidita() + 0.2*m.getUmidita() > umidita) {
            umidita = m.getUmidita();
        }
        
        gd.finisci();

        try {
            tgd.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

}
