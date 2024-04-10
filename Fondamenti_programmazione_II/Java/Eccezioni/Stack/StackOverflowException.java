package Eccezioni.Stack;

public class StackOverflowException extends Exception {

    public StackOverflowException () {
        super();
    }

    public StackOverflowException (String s) {
        super(s);
    }    
}
