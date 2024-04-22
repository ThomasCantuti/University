import java.util.Scanner;

public class MainInterrupt {
    public static void main (String args[]) {
        Scanner tastiera = new Scanner(System.in);
        System.out.print("Numero = ");
        int N = tastiera.nextInt();
        WorkerThreadInterrupt wt[] = new WorkerThreadInterrupt[N];
        boolean terminated[] = new boolean[N];
        Thread t = null;

        for (int i = 0; i < N; i ++) {
            t = new Thread(wt[i] = new WorkerThreadInterrupt(i));
            t.start();
            terminated[i] = false;
        }

        while (checkTermination(terminated)) {
            System.out.print("Inserire id processo da terminare: ");
            int id = tastiera.nextInt();
            if (id >= 0 && id < N) {
                if (!terminated[id]) {
                    terminated[id] = true;
                    wt[id].stopThread();
                }
            }
        }
        
        tastiera.close();
        System.out.println("Tutti i processi sono terminati.");
    }

    public static boolean checkTermination (boolean terminated[]) {
        int counterTermination = 0;
        for (int i = 0; i < terminated.length; i ++) {
            if (terminated[i] == false) {
                counterTermination ++;
            }
        }

        // ritorna false se tutti i terminated sono true -> tutti i processi stoppati
        // se terminated[i] == false -> processo in running
        // se terminated[i] == true -> processo stoppato
        if (counterTermination == 0)
            return false;
        else
            return true;
    }
}
