import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

public class Main {

    public static void main(String[] args) {
        ObjectInputStream ois = null;
        PipedOutputStream pos = new PipedOutputStream();
        PipedInputStream pis = null;
        try {
            pis = new PipedInputStream(pos);
        } catch (IOException e) {
            e.printStackTrace();
        }

        ControlloProduzione cp = new ControlloProduzione();
        MacchinaA tA_1 = new MacchinaA(cp);
        MacchinaA tA_2 = new MacchinaA(cp);
        MacchinaB tB = new MacchinaB(pos, cp);
        Thread macchinaA_1 = new Thread(tA_1);
        Thread macchinaA_2 = new Thread(tA_2);
        Thread macchinaB = new Thread(tB);

        macchinaA_1.start();
        macchinaA_2.start();
        macchinaB.start();

        int count = 0;

        while (count < 15) {
            String pezzoPronto = null;
            try {
                ois = new ObjectInputStream(pis);
                pezzoPronto = (String) ois.readObject();
                count ++;
            } catch (IOException | ClassNotFoundException e) {
                e.printStackTrace();
            }
        }

        tA_1.stopThread();
        tA_2.stopThread();
        tB.stopThread();

        try {
            macchinaA_1.join();
            macchinaA_2.join();
            macchinaB.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Prodotti finiti: " + cp.getPezziPronti());
        System.out.println("Semilavorati presenti: " + cp.getSemilavorati());
    }
}
