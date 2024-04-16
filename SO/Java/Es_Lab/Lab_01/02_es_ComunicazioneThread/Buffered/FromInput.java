import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PipedOutputStream;
import java.io.IOException;
import java.lang.InterruptedException;

public class FromInput extends Thread {
    private PipedOutputStream pos;

    public FromInput (PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run () {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(pos));
            String message = null;
            System.out.println("From-Input: ");
            while ((message = br.readLine()) != null) {
                bw.write(message);
                bw.newLine();
                bw.flush();
                try {
                    sleep(2000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println("From-Input: ");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
