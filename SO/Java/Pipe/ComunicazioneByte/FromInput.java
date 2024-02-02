package SO.Java.Pipe.ComunicazioneByte;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PipedOutputStream;
import java.nio.charset.Charset;

public class FromInput implements Runnable {
    
    private PipedOutputStream pos;

    public FromInput (PipedOutputStream pos_da_main) {
        pos = pos_da_main;
    }

    public void run () {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = null;

        try {
            while((line = br.readLine()) != null) {
                byte[] flusso_bytes = line.getBytes(Charset.forName("UTF-8"));
                pos.write(flusso_bytes,0,flusso_bytes.length);
                pos.flush();
                }
            } catch(IOException e) {
                e.printStackTrace();
            }
    }

}
