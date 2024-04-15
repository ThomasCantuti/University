import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("Inserire quanti thread mettere: ");
        Scanner tastiera = new Scanner(System.in);
        int numThread = tastiera.nextInt();
        tastiera.close();

        Accumulatore accumulatore = new Accumulatore(0);

        for (int i = 0; i < numThread; i ++) {
            Thread t = new CounterThread(accumulatore);
            t.start();
        }
        
        System.out.println(accumulatore);

    }
}
