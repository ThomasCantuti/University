package SO.Java.Pipe;

import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

import SO.Java.Pipe.ComunicazioneOggetti.*;

public class Main {
    public static void main(String[] args) {
        try {
            PipedOutputStream pos = new PipedOutputStream();
            PipedInputStream pis = new PipedInputStream(pos);

            Thread from_input = new Thread(new FromInput(pos));
            Thread to_output = new Thread(new ToOutput(pis));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
