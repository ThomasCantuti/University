package EserciziEsame.GestioneProgettiRicercaProf;

public class Progetto {
    protected int codice;
    protected String titolo, coordinatore, organizzazione;
    protected double importo;

    public Progetto(int codice, String titolo, String coordinatore, String organizzazione, double importo){
        this.codice=codice;
        this.titolo=titolo;
        this.coordinatore=coordinatore;
        this.organizzazione=organizzazione;
        this.importo=importo;
    }

    public String getTitolo(){
        return titolo;
    }

    public int getCodice(){
        return codice;
    }

    public String toString(){
        return titolo+"\t"+codice+"\t"+coordinatore+"\t"+organizzazione+"\t";
    }
}
