package EserciziEsame.Es1;

import java.util.*;

public class Pazienti {

    private String cognome;
    private ArrayList<Patologie> patologie;

    public Pazienti (String cogn) {
        cognome = cogn;
        this.patologie = new ArrayList<Patologie>();
    }

    public String getCognome() {
        return cognome;
    }

    public void aggiungiPatologia (Patologie p) {
        // se p non presente la aggiunge
        if (!patologie.contains(p))
            patologie.add(p);
    }

    public boolean rimuoviPatologia (Patologie p) {
        // verifica se p già presente
        // se p presente -> true + rimuove p
        return patologie.contains(p);
    }

    public String toString () {
        patologie.toString();
        return "Cognome: " + cognome + "\nPatologie: " + patologie;
    }
}
