package EserciziEsame.GestioneProgettiRicercaProf;

public class Impegno {
    protected Progetto progetto;
    protected double impegno;
    
    public Impegno(Progetto progetto, double impegno){
        this.progetto=progetto;
        this.impegno=impegno;
    }

    public double getOre(){
        return impegno;
    }

    public Progetto getProgetto(){
        return progetto;
    }

    public String toString(){
        return "(" + progetto.getCodice() + "," + impegno + ")";
    }
}
