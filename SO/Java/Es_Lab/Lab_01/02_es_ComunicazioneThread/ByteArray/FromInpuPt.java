import java.io.PipedOutputStream;
import java.nio.charset.Charset;
import java.util.Scanner;

public class FromInpuPt extends Thread {
    private PipedOutputStream pos;

    public FromInpuPt(PipedOutputStream pos) {
        this.pos = pos;
    }

    public void run() {
        try {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Inserisci un messaggio: ");
            String message = scanner.nextLine();
            while (message != null) {
                byte[] bytes = message.getBytes(Charset.forName("UTF-8"));
                pos.write(bytes, 0, bytes.length);
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