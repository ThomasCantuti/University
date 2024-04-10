package EserciziEsame.Autonoleggio;

public class Auto extends Veicolo {
    
    private double capienzaBagagliaio;
    private int cilindrata;
    private String categoria;

    public Auto (int c, String t, String mod, String marca, double costo,
    double capienzaBagagliaio, int cilindrata, String categoria) {
        super(c, t, mod, marca, costo);
        this.capienzaBagagliaio = capienzaBagagliaio;
        this.cilindrata = cilindrata;
        this.categoria = categoria;
    }

    public String toString () {
        return "auto\t" + super.toString() + capienzaBagagliaio +"\t"+
        cilindrata +"\t"+ categoria + "\t-\t-\t-";
    }
}
