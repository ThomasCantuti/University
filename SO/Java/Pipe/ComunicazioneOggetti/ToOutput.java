package SO.Java.Pipe.ComunicazioneOggetti;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.PipedInputStream;

public class ToOutput implements Runnable {

    private PipedInputStream pis;

    public ToOutput (PipedInputStream pis_da_main) {
        pis = pis_da_main;
    }

    public void run () {
        
        try {
            while ( true ) {
                ObjectInputStream ois = new ObjectInputStream(pis);
                Message objRead = (Message)ois.readObject();
                if (objRead == null) break;
                System.out.println("ToOutput: " + objRead.getMessage());
            }
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

    }
    
}
