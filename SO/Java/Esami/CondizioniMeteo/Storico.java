package SO.Java.Esami.CondizioniMeteo;

public class Storico {
    
    private int cambiRepentini = 0;

    public synchronized void incrementaCambiRepentini () {
        this.cambiRepentini ++;
    }

    public synchronized int getCambiRepentini () {
        return cambiRepentini;
    }

}
