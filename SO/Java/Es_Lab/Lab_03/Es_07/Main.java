public class Main {
    public static void main(String[] args) {
        Produzione produzione = new Produzione();
        Macchina macchina = new Macchina(produzione);
        Thread[] t_macchina = new Thread[10];

        for (int i = 0; i < 10; i ++) {
            t_macchina[i] = new Thread(macchina);
            t_macchina[i].start();
        }

        for (int i = 0; i < 10; i ++) {
            try {
                t_macchina[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        produzione.stampaProduzione();
    }
}
