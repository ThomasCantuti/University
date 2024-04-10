package EserciziEsame.GestioneProgettiRicercaProf;

public class Innovazione extends Progetto{
    private int aziende;

    public Innovazione(int codice, String titolo, String coordinatore, String organizzazione, int aziende, double importo){
        super(codice,titolo,coordinatore,organizzazione,importo);
        this.aziende=aziende;
    }

    public String toString(){
        return "innovazione\t"+super.toString()+"-\t-\t"+aziende+"1t"+importo*1000;
    }
}
