package Eccezioni;

public class Thousand {
    public static int parseInt(String s) 
     throws NumberFormatException,
            NumberTooBigException{

        // throws -> dichiara che un metodo rilancia all'esterno un'eccezione
        int a = Integer.parseInt(s);
        if (a >= 1000){
            NumberTooBigException e = new NumberTooBigException();
            throw e; // throw -> genera un'eccezione
        }
        return a;
    }
}
