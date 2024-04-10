package EserciziEsame.GestionePolisportiva;

public class Pallamano extends Squadra{

    private double goalFatti;

    public Pallamano (int codice, String nomeSquadra, int vittorie,
    int sconfitte, double goal, double goalFatti) {
        
        super(codice, nomeSquadra, vittorie, sconfitte);
        this.goalFatti = goalFatti;
    }

    public String toString () {
        return super.toString() + "\t-\t-\t" + goalFatti +"\t"+ "pallamano";
    }
}
