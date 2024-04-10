package Eccezioni.ConversioneStringaToIntero;

public class Main {
    public static void main (String[] args) {

        ConversioneStringToInt s = new ConversioneStringToInt(args);
        try {
            s.Conversione();
        } catch (OutOfRangeException re) {
            System.out.println("Il numero è fuori dal range");
        }
    }
}
