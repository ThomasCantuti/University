import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("Inserire quanti thread mettere: ");
        Scanner tastiera = new Scanner(System.in);
        int numThread = tastiera.nextInt();
        tastiera.close();

        Accumulatore accumulatore = new Accumulatore(0);
        Thread t[] = new Thread[numThread];

        for (int i = 0; i < numThread; i ++) {
            t[i] = new Thread(new CounterThread(accumulatore));
            t[i].start();
        }

        for(int i=0; i < numThread; i++) {
			try {
				t[i].join();
			} catch(InterruptedException e) {
				e.printStackTrace();
			} 
		}

        System.out.println(accumulatore);

    }
}
