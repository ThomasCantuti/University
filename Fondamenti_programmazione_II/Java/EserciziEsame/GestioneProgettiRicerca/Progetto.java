package EserciziEsame.GestioneProgettiRicerca;

public class Progetto {

    protected int codice;
    protected String titolo, nomeCognome, orgCoordinatore;

    public Progetto (int codice, String titolo, 
    String nomeCognome, String orgCoordinatore) {

        this.codice = codice;
        this.titolo = titolo;
        this.nomeCognome = nomeCognome;
        this.orgCoordinatore = orgCoordinatore;
    }

    public String toString () {
        return titolo + "\t" + codice + "\t" + nomeCognome + "\t" + 
        orgCoordinatore + "\t";
    }
    
}
