import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner tastiera = new Scanner(System.in);
        System.out.print("ID macchina: ");
        int id = tastiera.nextInt();
        System.out.print("Obiettivo pezzi prodotti dalla macchina: ");
        int obiettivoPezziProdotti = tastiera.nextInt();
        tastiera.close();

        Macchina macchina = new Macchina(id, 0);
        SimulaProduzione simulaProduzione = new SimulaProduzione(macchina);
        simulaProduzione.start();

        for (int i = 0; i < 10; i ++) {
            try {
                Thread.sleep(10000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("Pezzi attualmente prodotti: " + macchina.getPezziProdotti());
            if (macchina.getPezziProdotti() >= obiettivoPezziProdotti) {
                System.out.println("Obiettivo raggiunto!!!");
                break;
            }
        }

        simulaProduzione.termina();
        try {
            simulaProduzione.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
