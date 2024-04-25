import java.util.Random;

public class Produzione {
    private int prodotti;

    public Produzione () {
        this.prodotti = 0;
    }

    public synchronized void incrementa () {
        try {
            if (interrupt() <= 25)
                Thread.sleep(200);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        this.prodotti ++;
    }

    public void stampaProduzione () {
        System.out.println("Numero di prodotti: " + this.prodotti);
    }

    private synchronized int interrupt () {
        Random random = new Random();
        return random.nextInt(100);
    }
}
