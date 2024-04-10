package EserciziEsame.GestioneProgettiRicerca;

public class Innovazione extends Progetto {

    private int aziende;
    private double importo;

    public Innovazione (int codice, String titolo, 
    String nomeCognome, String orgCoordinatore, int aziende, double importo) {

        super(codice, titolo, nomeCognome, orgCoordinatore);
        this.aziende = aziende;
        this.importo = importo;
    }

    public String toString () {
        return "innovazione\t" + super.toString() + "\t-\t-\t" + 
        aziende + "\t" + importo;
    }
    
}
