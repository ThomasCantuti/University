package SO.Java.Pipe.ComunicazioneBuffer;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
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
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));
            while ( (line = br.readLine()) != null ) {
                bw.write(line);
                bw.newLine();
                bw.flush();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
