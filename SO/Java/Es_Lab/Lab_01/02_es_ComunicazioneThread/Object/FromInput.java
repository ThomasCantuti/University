import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.ObjectOutputStream;
import java.io.PipedOutputStream;

public class FromInput extends Thread {
    private PipedOutputStream pos;

    public FromInput (PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run () {
        try {
            ObjectOutputStream oos = new ObjectOutputStream(pos);
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String line = null;

            while((line = br.readLine()) != null) {
                Message message = new Message(line);
                oos.writeObject(message);
                oos.flush();
            }

            oos.close();
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        
    }
}
