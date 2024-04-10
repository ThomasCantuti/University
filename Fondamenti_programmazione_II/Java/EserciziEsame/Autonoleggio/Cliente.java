package EserciziEsame.Autonoleggio;

import java.util.*;

public class Cliente {
    
    private String nomeCognome;
    List<Noleggio> noleggio = new LinkedList<Noleggio>();

    public Cliente (String nomeCognome) {
        this.nomeCognome = nomeCognome;
        this.noleggio = new LinkedList<Noleggio>();
    }

    public void addNoleggio (String targa, int giorni, double costo) {
        noleggio.add(new Noleggio(targa, giorni, costo));
    }

    public double getMax () {

        double max = 0.0;

        for (Noleggio n : noleggio) {
            double costo = n.getTot();
            if (costo > max)
                max = costo;
        }

        return max;
    }

    public String toString () {
        return nomeCognome +"\t"+ getMax() +"\t"+ noleggio.size();
    }
}
