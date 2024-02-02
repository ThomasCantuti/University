package SO.Java.Esami.RilevarePollini;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {

    public static void main(String[] args) {
        
        PipedOutputStream pos = new PipedOutputStream();

        try {
            PipedInputStream pis = new PipedInputStream(pos);
            BufferedReader br = new BufferedReader(new InputStreamReader(pis));
            RilevatoreAria ra = new RilevatoreAria(pos);
            ra.start();

            long oldTime = 0;
            for (int i = 0; i < 8; i ++) {
                int val = Integer.parseInt(br.readLine());
                long newTime = Long.parseLong(br.readLine());

                if (val < 20)
                    System.out.println("Basso (" + val + ")");
                else if (val < 75)
                    System.out.println("Medio (" + val + ")");
                else
                    System.out.println("Alto (" + val + ")");
                
                long elapsedTime = newTime - oldTime;
                if (elapsedTime > 15 && oldTime != 0)
                    System.out.println("Attenzione (" + elapsedTime + ")");
                oldTime = newTime;
            }

            ra.fermaRilevatoreAria(); // stop thread safe
            try {
                ra.join(); // in attesa di terminazione
                System.out.println("Il thread RilevatoreAria è terminato dopo aver prodotto");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            System.out.println("Il thread Main ha completato la sua esecuzione");

            br.close();

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

}