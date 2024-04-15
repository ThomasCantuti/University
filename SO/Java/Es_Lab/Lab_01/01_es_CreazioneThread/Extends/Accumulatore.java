public class Accumulatore {
    double num;
    
    public Accumulatore (double num) {
        this.num = num;
    }

    public void addValue (double value) {
        num += value;
    }

    public double getValue () {
        return num;
    }
    
    public String toString () {
        return "Accumulatore = " + num;
    }
}
