package Ereditarietà.Dottore;

public class Main {
    public static void main(String[] args){
        
        Dottore dottore, dottore1;
        dottore = new Dottore();

        dottore1 = new Dottore("Luca", "Pediatra", 451678);

        dottore.setNome("Thomas");
        dottore.setSpecializzazione("Medico");
        dottore.setParcella(112345);

        System.out.println("Nome: " + dottore.getNome());
        System.out.println("Specializzazione: " + dottore.getSpecializzazione());
        System.out.println("Parcella: " + dottore.getParcella());

        System.out.println("Nome: " + dottore1.getNome());
        System.out.println("Specializzazione: " + dottore1.getSpecializzazione());
        System.out.println("Parcella: " + dottore1.getParcella());

        System.out.println("\n");

        Paziente p1, p2;
        Dottore d1, d2;
        Fattura f1, f2;

        p1 = new Paziente("Luca", "01");
        p2 = new Paziente("Paolo", "02");
        d1 = new Dottore("Diego", "Medico", 1245);
        d2 = new Dottore("Enrico", "Pediatra", 1200);
        f1 = new Fattura(p1, d1);
        f2 = new Fattura(p2, d2);

        System.out.println("Fattura 1: " + f1.importo(d1));
        System.out.println("Fattura 2: " + f2.importo(d2));
    }
}
