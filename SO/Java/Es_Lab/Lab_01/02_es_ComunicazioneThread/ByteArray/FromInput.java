import java.io.PipedOutputStream;
import java.nio.charset.Charset;
import java.util.Scanner;

public class FromInput extends Thread {
    private PipedOutputStream pos;

    public FromInput(PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run() {
        try {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Inserisci un messaggio: ");
            String message = scanner.nextLine();
            while (message != null && !message.equals("fine")) {
                byte[] bytes = message.getBytes(Charset.forName("UTF-8"));
                pos.write(bytes, 0, bytes.length);
                sleep(2000);
                System.out.print("Inserisci un messaggio: ");
                message = scanner.nextLine();
            }
            pos.close();
            scanner.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}