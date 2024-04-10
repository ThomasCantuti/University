package EserciziEsame.Es1;

public class Main {
    public static void main (String[] args) {

        Patologie pat1 = new Patologie("asma", 10);
        Patologie pat2 = new Patologie("allergia alle graminacee", 2);
        
        Pazienti paz1 = new Pazienti("Rossi");

        paz1.aggiungiPatologia(pat1);
        paz1.aggiungiPatologia(pat2);
        System.out.println(paz1);

        try {
            pat1.aggrava();
        } catch (MoltoGraveException e) {
            System.out.println("\nException: "+ e.getMessage());
        }

        try {
            pat2.attenua();
            pat2.attenua();
        } catch (GuaritaException e) {
            System.out.println("\nException: "+ e.getMessage() + "\n");
        }

        System.out.println(paz1);
    }
}
