import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner tastiera = new Scanner(System.in);
        System.out.print("Inserire numero di operatori: ");
        int N = tastiera.nextInt();
        tastiera.close();

        Operatori operatore[] = new Operatori[N];
        Magazzino magazzino = new Magazzino();

        for (int i = 0; i < N; i ++) {
            operatore[i] = new Operatori(magazzino);
            operatore[i].start();
        }

        for (int i = 0; i < N; i ++) {
            try {
                operatore[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println(magazzino);
    }
}
