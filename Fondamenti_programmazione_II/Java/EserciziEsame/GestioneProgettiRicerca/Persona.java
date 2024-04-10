package EserciziEsame.GestioneProgettiRicerca;

public class Persona {
    
    String nome, cognome;
    double impegnoMax;
    String titolo;

    public Persona (String nome, String conogme,
    double impegnoMax, String titolo) {
        this.nome = nome;
        this.cognome = conogme;
        this.impegnoMax = impegnoMax;
        this.titolo = titolo;
    }

    public double getImpegnoMax (Ricercatore r) {
        return impegnoMax = r.impegnoMax();
    }

    public String getTitle (Progetto p) {
        return p.titolo;
    }

    public String toString () {
        return nome +"\t"+ cognome +"\t"+ 
        impegnoMax +"\t"+ titolo;
    }
}
