package EserciziEsame.GestioneCircoloSportivo;

public class Campo {
    
    protected int codice, prenotazioni;
    protected String nomeCampo;
    protected float larghezza, lunghezza, costoOrario;

    public Campo (int codice, String nomeCampo,
    float larghezza, float lunghezza, float costoOrario) {
        this.codice = codice;
        this.nomeCampo = nomeCampo;
        this.larghezza = larghezza;
        this.lunghezza = lunghezza;
        this.costoOrario = costoOrario;
        prenotazioni = 0;
    }

    public void addPrenotazione () {
        prenotazioni ++;
    }

    public float incasso () {
        return prenotazioni * costoOrario;
    }

    public String toString () {
        return nomeCampo + "\t" + codice + "\t" + larghezza + "\t" + 
        lunghezza + "\t";
    }

}
