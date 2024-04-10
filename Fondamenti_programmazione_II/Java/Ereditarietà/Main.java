package Ereditarietà;

public class Main {
    public static void main(String[] args){
        Persona p = new Persona("Thomas", 20);
        Studente s = new Studente("Luca", 15, 187515);

        p.setCodiceFiscale("asdfghjkl");
        s.getCodiceFiscale();
    }
}
