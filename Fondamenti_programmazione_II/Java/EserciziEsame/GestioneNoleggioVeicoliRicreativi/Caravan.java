package EserciziEsame.GestioneNoleggioVeicoliRicreativi;

public class Caravan extends Veicolo{

    private int potenza;
  
    public Caravan (int codice, String marca, float larghezza, float lunghezza,  
    float costo, int posti, int potenza) {
        super(codice,marca,larghezza,lunghezza,costo,posti);
		this.potenza = potenza;
    }

    public String toString () {
		return "caravan\t" + super.toString() + "-\t-\t"+
        potenza + "\t"  + costo;
	}
}
