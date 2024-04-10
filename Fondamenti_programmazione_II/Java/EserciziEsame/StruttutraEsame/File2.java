package EserciziEsame.StruttutraEsame;

import java.util.*;

public class File2 {

    private String nome, cognome;
    private List<Aggiunta> aggiunto;
    
    public File2 (String nome, String cognome) {
        this.nome = nome;
        this.cognome = cognome;
        this.aggiunto = new LinkedList<Aggiunta>();
    }

    public String getNome(){
        return nome;
    }

    public String getCognome(){
        return cognome;
    }

    public Aggiunta getMax(){
        double max=0;
        Aggiunta nmax=null;

        for(Aggiunta i : aggiunto){
            if(i.getOre()>max){
                max=i.getOre();
                nmax=i;
            }
        }

        return nmax;
    }

    public void addFile1(File1 p, double ore){
        aggiunto.add(new Aggiunta(p,ore));
    }

    public void addAggiunta (Aggiunta a) {
        aggiunto.add(a);
    }

    public double getTot(){
        double tot=0;

        for(Aggiunta i : aggiunto)
            tot=tot+i.getOre();

        return tot;
    }

    public int getNum(){
        return aggiunto.size();
    }

    public String toString(){
        return nome+" "+cognome+" "+getTot()+" "+getNum()+" "+aggiunto.toString();
    }
}
