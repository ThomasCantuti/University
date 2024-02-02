package SO.Java.Pipe.ComunicazioneByte;

import java.io.IOException;
import java.io.PipedInputStream;
import java.nio.charset.Charset;
import java.util.Arrays;

public class ToOutput implements Runnable {
    
    private PipedInputStream pis;

    public ToOutput (PipedInputStream pis_da_main) {
        pis = pis_da_main;
    }

    public void run () {
        try {
            int nread;
            byte lettura_bytes[] = new byte[1024];
            while ((nread = pis.read(lettura_bytes)) > 0) {
                byte effettivamente_letti[] = Arrays.copyOfRange(lettura_bytes, 0, nread);
                String message = new String(effettivamente_letti, Charset.forName("UTF-8"));
                System.out.println("Letto da pipe: " + message);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
