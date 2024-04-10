package EserciziEsame.GestioneProgettiRicerca;

import java.util.*;

public class Ricercatore {
    
    protected String nome, cognome;
    protected List<ElencoProgetti> elencoProgetti;

    public Ricercatore (String nome, String cognome) {
        this.nome = nome;
        this.cognome = cognome;
        elencoProgetti = new LinkedList<ElencoProgetti>();
    }

    public void addElencoProgetti (int codice, double impegnoOrario) {
        elencoProgetti.add(new ElencoProgetti(codice, impegnoOrario));
    }

    public double impegnoTot () {
        double impegnoTotale = 0.0;
        for (ElencoProgetti ep : elencoProgetti) {
            double impegno = ep.getImpegno();
            impegnoTotale += impegno;
        }
        return impegnoTotale;
    }

    public double impegnoMax () {
        double max = 0.0;

        for (ElencoProgetti ep : elencoProgetti) {
            double impegno = ep.getImpegno();
            if (impegno > max)
                max = impegno;
        }

        return max;
    }

    public String toString () {
        return nome +"\t"+ cognome +"\t"+ impegnoTot() +"\t"+ 
        elencoProgetti.size() +"\t"+ elencoProgetti.toString();
    }
}
