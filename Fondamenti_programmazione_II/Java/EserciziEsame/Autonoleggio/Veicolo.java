package EserciziEsame.Autonoleggio;

public class Veicolo {

    protected int codice;
    protected String targa, modello, marca;
    protected double costo;

    public Veicolo (int codice, String targa, String modello, String marca, double costo) {
        this.codice = codice;
        this.targa = targa;
        this.modello = modello;
        this.marca = marca;
        this.costo = costo;
    }

    public String toString () {
        return targa +"\t"+ codice +"\t"+ modello +"\t"+ marca +"\t"+ costo +"\t";
    }
}
