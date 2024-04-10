package EserciziEsame.GestioneCircoloSportivo;

public class CampoTennis extends Campo{
    
    private float temperaturaMedia;
    private String terreno;

    public CampoTennis (int c, String n, float larg, 
        float lung, float costo, float temperaturaMedia, String terreno) {
        
        super(c, n, larg, lung, costo);
        this.temperaturaMedia = temperaturaMedia;
        this.terreno = terreno;
    }

    public String toString () {
        return "tennis\t" + super.toString() + temperaturaMedia + "\t" + terreno + "\t-\t-\t" + costoOrario;
    }
}
