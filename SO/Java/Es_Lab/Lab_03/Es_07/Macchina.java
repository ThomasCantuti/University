public class Macchina implements Runnable {
    private Produzione produzione = null;

    public Macchina (Produzione p) {
        this.produzione = p;
    }

    public void run () {
        for (int i = 0; i < 35; i ++) {
            produzione.incrementa();
            try {
                Thread.sleep(generateRandomSleep());
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    private int generateRandomSleep () {
        return (int) Math.random() * (600 - 500) + 500;
    }
}
