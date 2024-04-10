package EserciziEsame.StruttutraEsame;

public class Tipo1 extends File1{

    private float temperaturaMedia;
    private String terreno;

    public Tipo1 (int codice, String nomeCampo, float larghezza, 
        float lunghezza, float costoOrario, float temperaturaMedia, String terreno) {
        
        super(codice, nomeCampo, larghezza, lunghezza, costoOrario);
        this.temperaturaMedia = temperaturaMedia;
        this.terreno = terreno;
    }

    public String toString () {
        return "tennis\t" + super.toString() + temperaturaMedia + "\t" + terreno + "\t-\t-\t" + costoOrario;
    }
}
