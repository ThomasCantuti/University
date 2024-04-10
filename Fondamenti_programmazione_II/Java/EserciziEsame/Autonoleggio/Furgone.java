package EserciziEsame.Autonoleggio;

public class Furgone extends Veicolo {
    
    boolean rimorchio, vanoCarico;
    int posti;

    public Furgone (int c, String t, String mod, String marca, double costo,
    boolean rimorchio, boolean vanoCarico, int posti) {
        super(c, t, mod, marca, costo);
        this.rimorchio = rimorchio;
        this.vanoCarico = vanoCarico;
        this.posti = posti;
    }

    public String toString () {
        return "furgone\t" + super.toString() + "-\t-\t-\t" + rimorchio +"\t"+
        posti +"\t"+ vanoCarico;
    }
}
