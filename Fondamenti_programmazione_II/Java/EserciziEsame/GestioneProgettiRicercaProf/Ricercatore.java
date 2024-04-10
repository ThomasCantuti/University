package EserciziEsame.GestioneProgettiRicercaProf;

import java.util.*;

public class Ricercatore {
    private String nome, cognome;
    private List<Impegno> progetti;
    
    public Ricercatore(String nome, String cognome){
        this.nome=nome;
        this.cognome=cognome;
        this.progetti=new LinkedList<Impegno>();
    }

    public String getNome(){
        return nome;
    }

    public String getCognome(){
        return cognome;
    }

    public Impegno getMax(){
        double max=0;
        Impegno nmax=null;

        for(Impegno i:progetti){
            if(i.getOre()>max){
                max=i.getOre();
                nmax=i;
            }
        }

        return nmax;
    }

    public void addProgetto(Progetto p, double ore){
        progetti.add(new Impegno(p,ore));
    }

    public double getTot(){
        double tot=0;

        for(Impegno i:progetti)
            tot=tot+i.getOre();

        return tot;
    }

    public int getNum(){
        return progetti.size();
    }

    public String toString(){
        return nome+" "+cognome+" "+getTot()+" "+getNum()+" "+progetti.toString();
    }
}
