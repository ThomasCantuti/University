package EserciziEsame.GestioneProgettiRicerca;

public class ElencoProgetti {
    
    private int codice;
    private double impegnoOrario;

    public ElencoProgetti (int codice, double impegnoOrario) {
        this.codice = codice;
        this.impegnoOrario = impegnoOrario;
    }

    public double getImpegno () {
        return impegnoOrario;
    }

    public String toString () {
        return "(" + codice + "," + impegnoOrario + ")";
    }
}
