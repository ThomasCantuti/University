package EserciziEsame.GestioneNoleggioVeicoliRicreativi;

import java.util.*;

public class Veicolo {

    protected int codice, posti;
	protected String marca;
	protected float larghezza, lunghezza, costo;
	protected List<Prenotazione> prenotazioni;
	
	public Veicolo (int codice, String marca, float larghezza, float lunghezza,  
    float costo, int posti) {
    	this.codice = codice;
        this.marca = marca;
		this.larghezza = larghezza;
		this.lunghezza = lunghezza;
		this.costo = costo;
		this.posti= posti;
    	prenotazioni = new LinkedList<Prenotazione>();
	}
  
    public void addPrenotazione (Prenotazione p) {
	    prenotazioni.add(p);
    }		
  
    public float incasso () {
	    int giorni=0;
        for (Prenotazione p : prenotazioni) {
            giorni += p.getGiorni();
        }
        return giorni*costo;
    }
	
    public int getCod () {
		  return codice;
	}

	public String toString () {
		return codice + "\t"+ marca +"\t"+larghezza+"\t"+lunghezza+"\t"+posti+"\t";
    }
}
