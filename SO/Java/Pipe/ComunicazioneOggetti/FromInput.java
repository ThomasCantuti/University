package SO.Java.Pipe.ComunicazioneOggetti;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;

public class FromInput implements Runnable {
    
    private PipedOutputStream pos;

    public FromInput (PipedOutputStream pos_da_main) {
        pos = pos_da_main;
    }

    public void run () {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = null;

        try {
            ObjectOutputStream oos = new ObjectOutputStream(pos);
            while ( (line = br.readLine()) != null ) {
                Message objMessage = new Message(line);
                oos.writeObject(objMessage);
                oos.flush();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

}
