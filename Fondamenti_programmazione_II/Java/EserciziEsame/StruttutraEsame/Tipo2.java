package EserciziEsame.StruttutraEsame;

public class Tipo2 extends File1{

    private float altezza;
    private int piano;

    public Tipo2 (int codice, String nomeCampo, float larghezza, 
    float lunghezza, float costoOrario, float altezza, int piano) {

        super(codice, nomeCampo, larghezza, lunghezza, costoOrario);
        this.altezza = altezza;
        this.piano = piano;
    }

    public String toString () {
        return "squash\t" + super.toString() + "\t-\t-\t" + altezza + "\t" + piano + "\t" + costoOrario;
    }
}
