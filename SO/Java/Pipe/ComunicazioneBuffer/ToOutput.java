package SO.Java.Pipe.ComunicazioneBuffer;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedInputStream;

public class ToOutput implements Runnable {
    
    private PipedInputStream pis;

    public ToOutput (PipedInputStream pis_da_main) {
        pis = pis_da_main;
    }

    public void run () {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(pis));
            String line = null;

            while ( (line = br.readLine()) != null ) {
                System.out.println("Letto da pipe: " + line);
            }

        } catch (IOException e) {
                e.printStackTrace();
        }
    }
}
