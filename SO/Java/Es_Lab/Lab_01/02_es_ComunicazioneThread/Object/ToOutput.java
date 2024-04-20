import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.PipedInputStream;

public class ToOutput extends Thread {
    private PipedInputStream pis;

    public ToOutput (PipedInputStream pis) {
        this.pis = pis;
    }

    public void run () {
        try {
            ObjectInputStream ois = new ObjectInputStream(pis);
            Message message = (Message)ois.readObject();

            while (message != null) {
                System.out.println(message.getMess());
                message = (Message)ois.readObject();
            }

            ois.close();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
