package EserciziEsame.GestionePolisportiva;

public class Hockey extends Squadra{

    private double mediaGoal, falli;

    public Hockey (int codice, String nomeSquadra, int vittorie,
    int sconfitte, double goal, double mediaGoal, double falli) {
        
        super(codice, nomeSquadra, vittorie, sconfitte);
        this.falli = falli;
        this.mediaGoal = mediaGoal;
    }

    public String toString () {
        return super.toString() + mediaGoal + "\t" + falli + "\t-\t" + "hockey";
    }
}
