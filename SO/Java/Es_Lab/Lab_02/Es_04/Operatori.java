import java.util.concurrent.atomic.AtomicBoolean;

public class Operatori extends Thread {
    private Magazzino magazzino = null;

    public Operatori (Magazzino magazzino) {
        this.magazzino = magazzino;
    }

    public void run () {
        String name = "bulloni";
        //String name = magazzino.inserimento();
        magazzino.create(name, 0);
        magazzino.addObject(name, 1000);
        magazzino.deleteObject(name, 500);
    }
}
