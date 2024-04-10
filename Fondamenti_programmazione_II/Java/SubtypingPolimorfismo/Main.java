package SubtypingPolimorfismo;

public class Main {
    public static void main(String[] args){
        int n = 7;
        long l = 14;
        double d = 7.5;

        // typecast -> mettere il tipo per evitare di perdere informazioni
        n = (int)l;
        n = (int)d;
        l = (long)d;

        Persona p = new Persona("Thomas", 20);
        Studente s = new Studente("Luca", 15, 187515);

        // eredita tutto ciò che è in Persona ma non accede ai metodi in Studente
        // Attenzione: se c'è overriding accede al metodo sovrascritto
        Persona p1 = new Studente(null, 0, 0); // polimorfismo
        
        p.saluta();
        s.saluta();
        p1.saluta(); // polimorfismo
        // in p1 non c'è il metodo voti quindi -> downcasting
        Studente p2 = (Studente)p1;
        p2.voti();
    }
}
