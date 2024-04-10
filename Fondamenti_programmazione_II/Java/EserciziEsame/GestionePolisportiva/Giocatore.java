package EserciziEsame.GestionePolisportiva;

import java.util.*;

public class Giocatore {

    private int codice, eta, maglia;
    private String nome, cognome, ruolo;
    private boolean titolare;
    private List<GiocatoreSquadra> giocatoreSquadra;
    
    public Giocatore (String cognome, String nome, int eta,
    int maglia, String ruolo, boolean titolare) {
        this.nome = nome;
        this.cognome = cognome;
        this.eta = eta;
        this.maglia = maglia;
        this.ruolo = ruolo;
        this.titolare = titolare;
        this.giocatoreSquadra = new LinkedList<GiocatoreSquadra>();
    }

    public void addGiocatoreSquadra(int codice, Squadra s){
        giocatoreSquadra.add(new GiocatoreSquadra(s, codice));
    }

    public void addGiocatoreSquadra (GiocatoreSquadra gs) {
        giocatoreSquadra.add(gs);
    }

    public String toString(){
        return nome +" "+ cognome +"\t"+ eta +"\t"+ maglia +"\t"+ ruolo +"\t"+
        titolare +"\t"+ giocatoreSquadra.get(codice).squadra.nomeSquadra;
    }
}
