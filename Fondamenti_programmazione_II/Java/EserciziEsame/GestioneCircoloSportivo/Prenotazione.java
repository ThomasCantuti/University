package EserciziEsame.GestioneCircoloSportivo;

public class Prenotazione {

    protected int codiceCampo, ora;

    public Prenotazione (int codiceCampo, int ora) {
        this.codiceCampo = codiceCampo;
        this.ora = ora;
    }

    public String toString () {
        return "(" + codiceCampo + "," + ora + ")";
    }
}
