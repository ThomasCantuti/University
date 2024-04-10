package EserciziEsame.GestioneCircoloSportivo;

import java.util.*;

public class Socio {
    
    private int codice, eta, categoria;
    private String nomeCognome;
    protected List<Prenotazione> prenotazioni;

    public Socio (int codice, String nomeCognome, int eta, int categoria) {
        this.codice = codice;
        this.nomeCognome = nomeCognome;
        this.eta = eta;
        this.categoria = categoria;
        prenotazioni = new LinkedList<Prenotazione>();
    }

    public void addPrenotazione (Prenotazione p) {
        prenotazioni.add(p);
    }

    public String toString () {
        return codice + "\t" + nomeCognome + "\t" + 
        eta + "\t" + categoria + "\t" + prenotazioni + "\t";
    }
}
