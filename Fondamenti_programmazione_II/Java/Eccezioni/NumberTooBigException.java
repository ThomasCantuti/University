package Eccezioni;

public class NumberTooBigException extends Exception {

    // definire un'eccezione specifica per il nostro scopo

    public NumberTooBigException(){
        super();
    }
    
    public NumberTooBigException(String s){
        super(s);
    }
}
