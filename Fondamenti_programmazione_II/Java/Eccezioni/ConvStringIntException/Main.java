package Eccezioni.ConvStringIntException;

public class Main {
    public static void main(String[] args) {
        try {
            ConvStringIntEx obj = new ConvStringIntEx(args);
        } catch (NumberFormatException e1) {
            // messaggio predefinito di errore
            System.out.println("Format Exception 1: " + e1.getMessage());
        } catch (IllegalArgumentException e2) {
            // messaggio di errore definito in ConvStringIntEx
            System.out.println("Format Exception 2: " + e2.getMessage());
        }
    }
}
