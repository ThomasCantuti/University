package EserciziEsame.Autonoleggio;

public class Noleggio {
    
    protected String targa;
    protected int giorni;
    protected double costo;

    public Noleggio (String targa, int giorni, double costo) {

        this.targa = targa;
        this.giorni = giorni;
        this.costo = costo;
    }

    public double getTot () {

        return giorni * costo;
    }

    public String toString () {
        return "(" + targa + "," + giorni + ")";
    }
}
