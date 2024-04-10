package EserciziEsame.GestioneProgettiRicercaProf;

public class Ricerca extends Progetto{
    private int partner;
    private String argomento;

    public Ricerca(int codice, String titolo, String coordinatore, String organizzazione, String argomento, int partner, double importo){
        super(codice,titolo,coordinatore,organizzazione,importo);
        this.partner=partner;
        this.argomento=argomento;
    }

    public String toString(){
        return "ricerca\t"+super.toString()+argomento+"\t"+partner+"\t-\t"+importo*1000;
    }
}
