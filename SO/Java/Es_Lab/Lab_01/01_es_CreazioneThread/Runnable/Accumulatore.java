public class Accumulatore {
    double accumulatore;

    public Accumulatore (double value) {
        accumulatore = value;
    }

    public synchronized void addValue (double value) {
        accumulatore += value;
    }

    public double getValue () {
        return accumulatore;
    }

    public String toString () {
        return "Accumulatore = " + getValue();
    }
}
