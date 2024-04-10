package EserciziEsame.GestioneCircoloSportivo;

public class CampoSquash extends Campo{

    private float altezza;
    private int piano;

    public CampoSquash (int c, String n, float larg, float lung, 
                        float altezza, int piano, float costo) {

        super(c, n, larg, lung, costo);
        this.altezza = altezza;
        this.piano = piano;
    }

    public String toString () {
        return "squash\t" + super.toString() + "\t-\t-\t" + altezza + "\t" + piano + "\t" + costoOrario;
    }
}
