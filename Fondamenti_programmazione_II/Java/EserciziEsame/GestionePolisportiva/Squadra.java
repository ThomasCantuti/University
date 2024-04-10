package EserciziEsame.GestionePolisportiva;

public class Squadra {
    protected int codice, vittorie, sconfitte;
    protected String nomeSquadra;

    public Squadra (int codice, String nomeSquadra, int vittorie,
    int sconfitte) {
        this.codice = codice;
        this.nomeSquadra = nomeSquadra;
        this.vittorie = vittorie;
        this.sconfitte = sconfitte;
    }

    public int getVittorie () {
        return vittorie;
    }

    public int getSconfitte () {
        return sconfitte;
    }

    public String toString () {
        return nomeSquadra + "\t" + codice + "\t" + vittorie + "\t" + sconfitte + "\t";
    }
}
