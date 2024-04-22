import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Magazzino {
    private Map<String, Integer> magazzino = null;

    public Magazzino () {
        magazzino = new HashMap<String, Integer>();
        create("", 0);
    }

    public synchronized String inserimento () {
        Scanner tastiera = new Scanner(System.in);
        System.out.print("Inserire nome da verificare: ");
        tastiera.close();
        return tastiera.next();
    }

    // return true if object exists
    public synchronized boolean exists (String nameObject) {
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return magazzino.containsKey(nameObject);
    }

    public synchronized void create (String nameObject, Integer quantity) {
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        if (!exists(nameObject)) {
            magazzino.put(nameObject, quantity);
        } else {
            System.out.println("Nome già esistente");
        }
    }

    public synchronized void addObject (String nameObject, Integer quantity) {
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        magazzino.replace(nameObject, magazzino.get(nameObject), magazzino.get(nameObject) + quantity);
    }

    public synchronized void deleteObject (String nameObject, Integer quantity) {
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        magazzino.replace(nameObject, magazzino.get(nameObject), magazzino.get(nameObject) - quantity);
    }

    public synchronized String toString () {
        String result = "";
        for (Map.Entry<String, Integer> obj : magazzino.entrySet()) {
            result += obj.getKey() + ": " + obj.getValue();
        }
        return result;
    }
}
