package SO.Java.Esami.GestioneAzienda;

import java.io.Serializable;

public class Messaggio implements Serializable {

    private int prodotti = 0;
    private float valore = 0;

    public Messaggio (int prodotti, float valore) {
        this.prodotti = prodotti;
        this.valore = valore;
    }

    public int getProdotti () {
        return prodotti;
    }

    public float getValore () {
        return valore;
    }
    
}
