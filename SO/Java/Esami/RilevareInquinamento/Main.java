package SO.Java.Esami.RilevareInquinamento;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {
    public static void main(String[] args) {
        
        PipedOutputStream pos = null;
        PipedInputStream pis = new PipedInputStream();

        try {
            pos = new PipedOutputStream(pis);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        int soglia = 0;
        // controllo che soglia è tra 100 e 200
        while (true) {
            System.out.println("Inserire valore di soglia: ");
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

            try {
                soglia = Integer.parseInt(br.readLine());

            } catch (IOException e) {
                e.printStackTrace();
            } catch (NumberFormatException e) {
                System.out.println("La soglia deve essere un intero\n");
                continue;
            }

            if (soglia >= 100 && soglia <= 200)
                break;
            else
                System.out.println("La soglia deve essere tra 100 e 200\n");
        }

        GeneraRilevazioni gr = new GeneraRilevazioni(pos);
        gr.start();

        ObjectInputStream ois = null;
        try {
            ois = new ObjectInputStream(pis);
        } catch (IOException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        Rilevazione r = null;
        int countCons = 0;
        for (int i = 0; i < 10; i ++) {

            try {
                r = (Rilevazione)ois.readObject();
            } catch (IOException e) {
                e.printStackTrace();
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }

            if (r.getValore() <= 50)
                System.out.println("Basso - " + r.getValore());
            else if (r.getValore() <= 100)
                System.out.println("Moderato - " + r.getValore());
            else
                System.out.println("Alto - " + r.getValore());
            
            if (r.getValore() >= soglia)
                countCons ++;
            else
                countCons = 0;
            
            if (countCons >= 3) 
                System.out.println("Warning: valore rilevato ha superato per 3 volte consecutive la soglia\n");

        }

        gr.stopRilveazioni();
        
        try {
            gr.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Il thread GeneraRilevazioni è terminato\n");

    }
}