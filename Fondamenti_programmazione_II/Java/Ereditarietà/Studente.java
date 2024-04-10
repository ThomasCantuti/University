package Ereditarietà;

public class Studente extends Persona{
    public int matricola;

    public Studente(String n, int e, int m){
        super(n, e);
        matricola = m;
    }

    // overriding
    public void saluta(){
        super.saluta();
        System.out.println("Il mio numero di matricola è " + matricola);
    }
}