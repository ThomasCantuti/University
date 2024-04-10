package EserciziEsame.GestioneProgettiRicerca;

public class Ricerca extends Progetto {
    
    private String codiceArg;
    private int numPartner;
    private double importo;

    public Ricerca (int codice, String titolo, 
    String nomeCognome, String orgCoordinatore,
    String codiceArg, int numPartner, double importo) {

        super(codice, titolo, nomeCognome, orgCoordinatore);
        this.codiceArg = codiceArg;
        this.numPartner = numPartner;
        this.importo = importo;
    }

    public String toString () {
        return "ricerca\t" + super.toString() + codiceArg + 
        "\t" + numPartner + "\t-\t" + importo;
    }
}
