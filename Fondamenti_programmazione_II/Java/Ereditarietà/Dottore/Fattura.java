package Ereditarietà.Dottore;

public class Fattura {

    private Paziente paziente;
    private Dottore dottore;

    public Fattura() {

        paziente = new Paziente();
        dottore = new Dottore();
    }

    public Fattura(Paziente paziente, Dottore dottore) {

        paziente = new Paziente();
        dottore = new Dottore();
    }

    public void setPaziente(Paziente newPaziente) {
        paziente = newPaziente;
    }

    public Paziente getPaziente() {
        return paziente;
    }

    public void setDottore(Dottore newDottore) {
        dottore = newDottore;
    }

    public Dottore getDottore() {
        return dottore;
    }

    public double importo(Dottore dottore) {
        return dottore.getParcella();
    }
}
